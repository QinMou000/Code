#pragma once

class NoCopy
{
public:
    NoCopy() {}
    virtual NoCopy(const NoCopy &) = delete;
    virtual const NoCopy &operator=(const NoCopy &) = delete;
    ~NoCopy() {}
}


enum ExitCode
{
    OK = 0,
    USAGE_ERR,
    
}