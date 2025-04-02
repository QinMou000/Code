#include <iostream>
#include <fstream>
#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include "mutex.hpp"

namespace LogModule
{
    class LogStrategy
    {
    public:
        ~LogStrategy() = default;
        virtual void SyncLog(const std::string &messege) = 0; // 表示纯虚函数，基类中不提供方法
    };

    const std::string gsep = "\r\n"; // separator分隔符

    class ConsoleLogStrategy : public LogStrategy
    {
    public:
        ConsoleLogStrategy()
        {
        }
        void SyncLog(const std::string &messege) override
        {
            global_mutex glock(_mutex); // 加锁保证多线程打印的原子性
            std::cout << messege << gsep;
        }
        ~ConsoleLogStrategy()
        {
        }

    private:
        Mutex _mutex;
    };

    const std::string DefaultPath = "./";       // 默认路径
    const std::string DefaultFile = "test.log"; // 默认日志文件名
    class FileLogStrategy : public LogStrategy
    {
    public:
        FileLogStrategy(const std::string path = DefaultPath, const std::string file = DefaultFile)
            : _path(path),
              _file(file)
        {
        }
        void SyncLog(const std::string &messege) override
        {
            global_mutex glock(_mutex);

            std::string filename = _path + (_path.back() == '/' ? "" : "/") + _file; // 将路径和文件名拼成完整的文件名
            std::ofstream out(filename, std::ios::app);                              // 以追加打开文件
            if (!out.is_open())
                return;
            out << messege << gsep;
            out.close();
        }
        ~FileLogStrategy()
        {
        }

    private:
        std::string _path;
        std::string _file;
        Mutex _mutex;
    };

    enum class LogLevel // 定义日志等级
    {
        DEBUG,
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    std::string Level2Str(enum class loglevel) // 获取日志等级字符串
    {
        switch (loglevel)
        {
        case LogLevel::DEBUG:
            return "DEBUG";
        case LogLevel::INFO:
            return "INFO";
        case LogLevel::WARNING:
            return "WARNING";
        case LogLevel::ERROR:
            return "ERROR";
        case LogLevel::FATAL:
            return "FATAL";
        default:
            return "UNDEF"; // undef
        }
    }

    std::string GetTimeStamp()
    {
        time_t curr = time(nullptr);
        struct tm curr_tm;
        localtime_r(&curr, &curr_tm);
        char res[128];
        snprintf(res, sizeof(res), "%04d-%02d-%02d %02d:%02d:%02d",
                 curr_tm.tm_year + 1900, // 是从1900年开始算的
                 curr_tm.tm_mon + 1,     // [0,11] 表示12个月份
                 curr_tm.tm_mday,
                 curr_tm.tm_hour,
                 curr_tm.tm_min,
                 curr_tm.tm_sec);
        return res;
    }
    class Logger
    {
    };
}
