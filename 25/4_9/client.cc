#define CPPHTTPLIB_OPENSSL_SUPPORT
#include "httplib.h"

int main()
{
    // HTTP
    httplib::Client cli("http://yhirose.github.io");

    // HTTPS
    httplib::Client cli("https://yhirose.github.io");

    auto res = cli.Get("/hi");
    res->status;
    res->body;
}
