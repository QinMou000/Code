#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>

using namespace std;

int main()
{
    while (1)
    {
        cout << "ÊäÈëUh£º";
        double Uh;
        cin >> Uh;
        cout << "ÊäÈëUb£º";
        double Ub;
        cin >> Ub;
        double H = (50 * Uh * 0.001) / (0.06 * 2.5);
        cout << "H:" << H << endl;
        double B = (0.00001 * 10000 * Ub * 0.001) / (150 * 0.00008);
        cout << "B:" << B << endl;
    }
    return 0;
}