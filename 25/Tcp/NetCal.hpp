#pragma once

#include "Common.hpp"
#include "Protocol.hpp"

class NetCal
{
public:
    Response Cal(Request &req)
    {
        Response res(0, 0);
        switch (req.Oper())
        {
        case '+':
            res.SetRes(req.X() + req.Y());
            break;
        case '-':
            res.SetRes(req.X() - req.Y());
            break;
        case '*':
            res.SetRes(req.X() * req.Y());
            break;
        case '/':
            if (req.Y() == 0)
                res.SetCode(1);
            else
                res.SetRes(req.X() / req.Y());
            break;
        case '%':
            if (req.Y() == 0)
                res.SetCode(1);
            else
                res.SetRes(req.X() % req.Y());
            break;
        default:
            res.SetCode(3);
            break;
        }
        return res;
    }
};