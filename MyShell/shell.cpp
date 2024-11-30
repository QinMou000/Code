#include<iostream>
#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
#include<cstring>
#include<sys/wait.h>

#define max_arg 128
#define max_env 100

// 命令行参数表
char* g_argv[max_arg];
size_t g_argc = 0;

// 环境变量表
char* g_env[max_env];
size_t g_envs = 0;

void env_init() // 从父shell获取环境变量到当前shell并维护这张表
{
    extern char** environ;// 外部环境变量表
    memset(g_env,0,sizeof(g_env));
    g_envs = 0;
    // 原本的shell的环境变量是从配置文件来的，这里直接继承父shell
    for(int i = 0; environ[i]; i++)
    {
        g_env[i] = (char*)malloc(strlen(g_env[i])+1);// 申请空间
        strcpy(g_env[i],environ[i]); // 拷贝环境变量到当前shell
        g_envs++;
    }
    //g_env[g_envs++] = (char*)"WQ=for_test";
    g_env[g_envs] = NULL;

    for(int i = 0; g_env[i]; i++)
        putenv(g_env[i]); // 导成当前shell的环境变量
    environ = g_env;
}

const char* get_host_name()
{
    return getenv("LOGNAME");
}

const char* get_user()
{
    return getenv("USER");
}

char cwd[100];//应该在当前shell的环境变量表里
const char* get_pwd()
{
    const char* pwd = getcwd(cwd,sizeof(cwd));
    if(pwd == NULL) return NULL;
    return pwd;
}

std::string dir_name(const char* pwd)
{
    #define SLASH "/"
    std::string dir = pwd;
    if(dir == SLASH) return SLASH;
    auto pos = dir.rfind(SLASH);
    if(pos == std::string::npos/*npos == -1*/) return "BUG!";
    return dir.substr(pos+1);
}

const char* get_home()
{
    return getenv("HOME");
}

void print_commandprompt()
{
    std::cout<<get_host_name() << "@VM-4-4-" << get_user() << ":" << dir_name(get_pwd())<< "#";
}

bool get_cmd(char* cmd)
{
    memset(cmd,0,max_arg); // 清除
    char* ret = fgets(cmd,max_arg,stdin);
    if(ret == NULL) return false;
    cmd[strlen(cmd) - 1] = 0; // 我们在输入时会多输入一个 '\n' 需要清除
    if(strlen(cmd) == 0) return false; // 如果只输入"\n"返回false什么也不做，下一次循环
    return true;
}

#define GAP " "
bool analyse_cmd(char* cmd)
{
    g_argc = 0;// 初始化
    g_argv[g_argc++] = strtok(cmd,GAP);
    while(g_argv[g_argc++] = strtok(nullptr,GAP));
    g_argc--;// 减掉多的1
    return g_argc > 0?true:false;
}

void print_argv()// 打印处理过的命令行参数表
{
    for(int i = 0; g_argv[i]; i++)
        printf("%s\n",g_argv[i]);
    printf("%zd\n",g_argc);
}

void Cd()
{
    if(g_argc == 1)
    {
        chdir(get_home()); // 只有cd那就转到家目录下
    }
    else
    {
        std::string where = g_argv[1]; //
        if(where == "-") // 需要保存最近工作路径
        {
            // ...
        }
        else if(where == "~") // 根目录
        {
            // ...
        }
        else
            chdir(where.c_str());
    }

}
// last_exit_code
int lastcode;
void Echo()
{
    if(g_argc >= 2)
    {
        std::string opt = g_argv[1];
        if(opt == "$?")// 打印退出码
        {
            std::cout<< lastcode << std::endl;
            lastcode = 0;
        }
        else if(opt[0] == '$')// 打印环境变量
        {
            std::string env_name = opt.substr(1);
            const char* env_value = getenv(env_name.c_str());
            if(env_value) 
                std::cout << env_value << std::endl;
        }
        else
            std::cout << opt << std::endl;
    }
}

bool check_and_execute_builtin()
{
    std::string cmd = g_argv[0];
    if(cmd == "cd")
    {
        Cd();
        return true;
    }
    else if(cmd == "echo")
    {
        Echo();
        return true;
    }
    else
    {
        // ...
    }
    return false;
}

bool execute_cmd()
{
    pid_t id = fork();
    if(id == 0)
    {
        // child
        execvp(g_argv[0],g_argv);
        exit(1);
    }
    // parent
    int status;
    pid_t rid = waitpid(id,&status,0);
    if(rid > 0)// 等待成功
    {
        lastcode = WEXITSTATUS(status);
    }
    return true;
}
int main()
{
    //env_init();// 初始化当前shell的环境变量表
    while(1)
    {
        // 1、打印命令行提示符
        print_commandprompt();

        // 2、获取输入命令
        char command[1024];
        if(!get_cmd(command)) continue;

        // 3、分析输入命令
        if(!analyse_cmd(command)) continue;

        // 4、检测执行内键命令
        if(check_and_execute_builtin()) continue;

        // 5、执行输入命令
        execute_cmd();
    }
    return 0;
}
