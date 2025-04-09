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
    ThreadPool<func_t> *tp = ThreadPool<func_t>::GetInstance();
    int cnt = 5;
    // LOG(LogLevel::INFO) << "for test1";
    while (cnt--)
    {
        LOG(LogLevel::INFO) << "压入一个上传任务...";
        // tp.Equeue(download);
        tp->Equeue(download);
        // LOG(LogLevel::INFO) << "for test2";
        sleep(1);
        LOG(LogLevel::INFO) << "压入一个下载任务...";
        // tp.Equeue(upload);
        tp->Equeue(upload);
        // LOG(LogLevel::INFO) << "for test3";
        sleep(1);
    }
    return 0;
}