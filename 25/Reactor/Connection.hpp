#pragma once

class Connection // 连接基类
{
public:
    Connection() {}
    ~Connection() {}

    // 子类们就必须实现各自的读写操作
    virtual Recver() = 0;   // 处理读操作
    virtual Sender() = 0;   // 处理写操作
    virtual Excepter() = 0; // 处理异常操作

private:
    uint_32_t _events; // 要关心的时间 会被每一个连接继承
    Reactor *_owner;   // 回指指针 也会被每一个连接继承
}