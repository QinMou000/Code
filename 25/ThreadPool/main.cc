#include "threadpool.hpp"

void download()
{
    LOG(LogLevel::INFO) << "执行下载任务...";
}

void upload()
{
    LOG(LogLevel::INFO) << "执行上传任务...";
}

int main()
{
    ThreadPool<func_t> tp;
    tp.Start();
    int cnt = 5;
    while (cnt--)
    {
        LOG(LogLevel::INFO) << "压入一个上传任务...";
        tp.Equeue(download);
        // sleep(1);
        LOG(LogLevel::INFO) << "压入一个下载任务...";
        tp.Equeue(upload);
        // sleep(1);
    }
    return 0;
}