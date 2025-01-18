#define _CRT_SECURE_NO_WARNINGS 1
#include<iostream>
using namespace std;
int* findPeaks(int* mountain, int mountainSize) {
    int i = 1;
    int j = 0;
    int* ans = (int*)malloc(sizeof(int) * 100);
    while (i < mountainSize-1)
    {
        if (mountain[i] > mountain[i + 1] && mountain[i] > mountain[i - 1])
        {
            ans[j] = i;
            j++;
        }
        i++;
    }
    return ans;
}

int main()
{

    int arr[] = { 1,3,2,4,6,5 };
    int* a = findPeaks(arr, sizeof(arr) / sizeof(int));
    int i = 0;
    while (i < sizeof(a) / sizeof(int))
    {
        cout << a[i] << endl;
        i++;
    }
    return 0;
}
