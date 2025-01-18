#define _CRT_SECURE_NO_WARNINGS 1

#include<iostream>
#include<vector>
using namespace std;

int main()
{
    vector<vector<int>>V;
    for (int i = 0; i < 5; i++)
    {
        vector<int> v(i + 1, 1);
        V.push_back(v);
    }
    for (int i = 2; i < 5 - 1; i++)
    {
        for (int j = 1; j < V[i].size() - 1; j++)
        {
            V[i][j] = V[i - 1][j - 1] + V[i - 1][j];
        }
    }

	return 0;
}