#include "Shm.hpp"
#include "NamePipe.hpp"

int main()
{
    NamePipe pipe(CLIENT);
    pipe.Open();
    Shm shm(CLIENT);
    char* m = shm.GetAddress();

    int cnt = 0;
    for (char c = 'A'; c <= 'Z'; c++, cnt++)
    {
        m[cnt] = c;
        std::cout << m[cnt];
        cnt++;
        m[cnt] = c;
        std::cout << m[cnt] << std::endl;
        sleep(1);
    }
    pipe.WakeUp();
    std::cout << "WakeUp" << std::endl;
    return 0;
}


// int main()
// {
//     key_t key = ftok(PATHNAEM, PROJ_ID); // 生成公共key
//     // std::cout << key << std::endl;
//     if (key == -1)
//         EXIT("ftok");
//     int shm_id = shmget(key, SIZE, IPC_CREAT); // 共享内存不存在，创建后返回，若存在则获取后返回
//     if (shm_id < 0)
//         EXIT("shmget");
//     char *m = (char *)shmat(shm_id, NULL, 0);// 默认读写
//     int cnt = 0;
//     for (char c = 'A'; c <= 'Z'; c++, cnt++)
//     {
//         m[cnt++] = c;
//         m[cnt] = c;
//         sleep(1);
//     }

//     shmdt(m); // 进程与共享内存段脱离

//     return 0;
// }