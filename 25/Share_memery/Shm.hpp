#include <iostream>
#include <sys/shm.h>
#include <sys/ipc.h>
#include <unistd.h>

#define SIZE 4096
#define PATHNAEM "."
#define PROJ_ID 666

#define CLIENT 0
#define SERVER 1

#define EXIT(m)             \
    do                      \
    {                       \
        perror(m);          \
        exit(EXIT_FAILURE); \
    } while (0)

class Shm
{
private:
    void GetShm()
    {
        _shm_id = shmget(_key, SIZE, IPC_CREAT); // 共享内存不存在，创建后返回，若存在则获取后返回
        if (_shm_id < 0)
            EXIT("shmget");
    }
    void CreateShm()
    {
        _shm_id = shmget(_key, SIZE, IPC_CREAT | IPC_EXCL | 0666); // 共享内存不存在，创建后返回，若存在则报错
        if (_shm_id < 0)
            EXIT("shmget");
    }
    void Destroy()
    {
        int n = shmctl(_shm_id, IPC_RMID, nullptr); // 删除共享内存段
        if (n == 0)
            std::cout << "shmctl IPC_RMID success" << std::endl;
        else if (n == -1)
            std::cout << "shmctl IPC_RMID fail" << std::endl;
    }

public:
    Shm(int usr)
        : _usr(usr)
    {
        _key = ftok(PATHNAEM, PROJ_ID); // 生成公共key
        if (_key == -1)
            EXIT("ftok");
        if (_usr == CLIENT)
            GetShm();
        if (_usr == SERVER)
            CreateShm();
    }
    char* GetAddress()
    {
        if (_usr == CLIENT)
            _m = (char *)shmat(_shm_id, NULL, 0); // 默认读写
        if (_usr == SERVER)
            _m = (char *)shmat(_shm_id, NULL, SHM_RDONLY); // 只读
        return _m;
    }
    ~Shm()
    {
        shmdt(_m); // 进程与共享内存段脱离
        if (_usr == SERVER)
            Destroy();
    }

private:
    key_t _key;
    int _shm_id;
    int _usr;
    char* _m;
};