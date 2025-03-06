#include "Shm.hpp"
#include "NamePipe.hpp"

int main()
{
    NamePipe pipe(SERVER);
    pipe.Open();
    Shm shm(SERVER);
    char *m = shm.GetAddress();
    while (true)
    {
        sleep(1);
        printf("%s\n", m);
        std::cout << "have been printf" << std::endl;
        if (pipe.IsSend())
            break;
    }
    std::cout << "break" << std::endl;
    return 0;
}

// int main()
// {
//     key_t key = ftok(PATHNAEM, PROJ_ID); // 生成公共key
//     std::cout << key << std::endl;

//     if (key == -1)
//         EXIT("ftok");
//     int shm_id = shmget(key, SIZE, IPC_CREAT | IPC_EXCL | 0666); // 共享内存不存在，创建后返回，若存在则报错
//     if (shm_id < 0)
//         EXIT("shmget");
//     char *m = (char*)shmat(shm_id, NULL, SHM_RDONLY); //只读

//     while (true)
//     {
//         sleep(1);
//         printf("%s\n", m);
//     }

//     shmdt(m); // 进程与共享内存段脱离

//     int n = shmctl(shm_id, IPC_RMID, nullptr); // 删除共享内存段
//     if (n == 0)
//         std::cout << "shmctl IPC_RMID success" << std::endl;
//     else if (n == -1)
//         std::cout << "shmctl IPC_RMID fail" << std::endl;

//     return 0;
// }