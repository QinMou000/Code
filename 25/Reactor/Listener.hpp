#pragma once
#include "Connection.hpp"

class Listener : public Connection
{
public:
    Listener() {}
    
    ~Listener() {}

private:
    int _listensockfd;
};
