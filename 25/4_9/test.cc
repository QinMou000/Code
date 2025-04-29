#include <iostream>
#include <queue>
#include "httplib.h"

int main()
{

    // HTTP
    httplib::Server svr;

    // HTTPS
    httplib::SSLServer svr;

    svr.Get("/hi", [](const httplib::Request &, httplib::Response &res)
            { res.set_content("Hello World!", "text/plain"); });

    svr.listen("0.0.0.0", 8080);

    //     std::queue<int> q;
    //     q.push(1);
    //     q.push(2);
    //     q.push(3);
    //     q.push(4);
    //     std::cout << q.front() << std::endl;
    //     std::cout << q.back() << std::endl;

    //     return 0;
}