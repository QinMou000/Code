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

template<class Type>
void insert_sort(vector<Type>& arr)
{
    for (int i = 1; i < arr.size(); i++)
    {
        int end = i;
        int tmp = arr[end]; 
        while (end)
        {
            if (Greater<Type>()(arr[end - 1], tmp))
            {
                arr[end] = arr[end - 1];
                end--;
            }
            else
                break;
        }
        arr[end] = tmp;
    }
}

int main()
{
    vector<int> arr{10,5,6,9,4,2,3,1,8,7};
    //bubble_sort(arr);
    insert_sort(arr);
    for(auto e : arr)
        cout<< e << " ";
    cout<<endl;
    return 0;
}