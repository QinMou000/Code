#include<iostream>
#include<vector>
using namespace std;    

template<class Type>
struct Less
{
    bool operator()(const Type & L, const Type & R)
    {
        return L < R;
    }
};

template<class Type>
struct Greater
{
    bool operator()(const Type & L, const Type & R)
    {
        return L > R;
    }
};

template<class Type>
void bubble_sort(vector<Type> &arr)
{
    for(int i = arr.size() - 1; i >= 0; i--)
    {
        bool flag = 0;
        for(int j = 0; j < i; j++)
        {
            if(Greater<Type>()(arr[j], arr[j + 1]))
            // if(arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
                flag = 1;
            }
        }
        if(flag == 0)
            break;
    }    
}


int main()
{
    vector<int> arr{5,6,9,4,2,3,1,8,7};
    bubble_sort(arr);
    for(auto e : arr)
        cout<< e << " ";
    cout<<endl;
    return 0;
}