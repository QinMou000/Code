#include <iostream>
#include <queue>

int main()
{
    std::queue<int> q;
    q.push(1);
    q.push(2);
    q.push(3);
    q.push(4);
    std::cout << q.front() << std::endl;
    std::cout << q.back() << std::endl;

    return 0;
}