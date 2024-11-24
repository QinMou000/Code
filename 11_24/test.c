#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>

// int main(int argc,char* argv[])
// {
//     for(int i = 0;i<argc;i++)    
//     {    
//         printf("argv[%d]->%s\n",i,argv[i]);                                            
//     }    
//     return 0;    
// }
// int main(int argc, char *argv[], char *env[])
// {
//     int i = 0;
//     for(i=0; env[i]; i++)
//     {	
//    		printf("[%d]->%s\n",i,env[i]);
//     }
//     return 0;
// }
// int main(int argc, char* argv[])
// {
//     extern char **environ;//先声明外部变量
//     int i = 0;
//     for(i = 0; environ[i]; i++)
//     {
//         printf("%s\n", environ[i]);
//     }
//     return 0;
// }
// int main(int argc, char *argv[], char *env[])
// {
//     printf("%s\n",getenv("PATH"));//获取对应的环境变量
//     return 0;
// }
// int g_unval;
// int g_val = 100;
// int main(int argc,char* argv[],char* env[])
// {
//     const char* str = "hello world";
//     printf("code addr:%p\n",main);//main函数就在代码区
//     printf("string rdonly addr:%p\n",str);//字符常量区
//     printf("init addr:%p\n",&g_val);//已初始化全局数据区
//     printf("uninit addr:%p\n",&g_unval);//未初始化全局数据
	
//     //堆区
//     char* heap1 = (char*)malloc(10);
//     char* heap2 = (char*)malloc(10);                                                                                                               
//     char* heap3 = (char*)malloc(10);    
//     char* heap4 = (char*)malloc(10);    
//     printf("heap1 addr:%p\n",heap1);    
//     printf("heap2 addr:%p\n",heap2);    
//     printf("heap3 addr:%p\n",heap3);    
//     printf("heap4 addr:%p\n",heap4);    
// 	//栈区
//     int a = 10;                    
//     int b = 20;                    
//     printf("stack addr:%p\n",&a);    
//     printf("stack addr:%p\n",&b);    
// 	//命令行参数
//     int i = 0;
//     for( i = 0; argv[i]; i++)    
//     {                              
//         printf("argv[%d]:%p\n", i, argv[i]);    
//     }
// 	//环境变量
//     for(i = 0; env[i]; i++)
//     {
//         printf("env[%d]:%p\n", i, env[i]);
//     }
//     return 0;
// }
#include<stdio.h>
#include<sys/types.h>
#include<unistd.h>
int g_val=100;
int main()
{
    pid_t id=fork();//创建子进程
    if(id==0)
    {
        //child
        g_val=200;
        printf("child PID:%d,PPID:%d,g_val:%d,&g_val:%p\n",getpid(),getppid(),g_val,&g_val);
    }
    else if(id>0)
    {
        //father
        printf("father PID:%d,PPID:%d,g_val:%d,&g_val:%p\n",getpid(),getppid(),g_val,&g_val);
    }
    else
    {
        // fork error
    }
    return 0;
}
