#include<iostream>
#include<vector>
#include<ctime>
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

void random(vector<int> &arr)
{
    for(int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 100;
    }
}

int main()
{
    srand((unsigned int)time(NULL));
    vector<int> arr;
    arr.resize(10000);
    random(arr);

    int begin1 = clock();
    bubble_sort(arr);
    int end1 = clock();

    int begin2 = clock();
    insert_sort(arr);
    int end2 = clock();

    cout << "bubble_sort_Time: " << end1 - begin1 << "ms" << endl;
    cout << "insert_sort_Time: " << end2 - begin2 << "ms" << endl;

    return 0;
}