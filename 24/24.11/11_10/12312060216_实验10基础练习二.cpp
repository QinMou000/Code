#define _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <cstdlib>
#include <ctime>

// 直接插入排序
void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

// 选择排序
void selectionSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        int minIndex = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            std::swap(arr[i], arr[minIndex]);
        }
    }
}

// 冒泡排序
void bubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                std::swap(arr[j], arr[j + 1]);
            }
        }
    }
}

// 快速排序的分区函数
int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = low - 1;
    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

// 快速排序
void quickSort(int arr[], int low, int high) {
    if (low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}
#define n 100

int main() {
    srand(time(nullptr));

    int arr[n];
    std::cout << "随机生成的顺序表：";
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 1000;
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;

    // 直接插入排序
    int insertionSortedArr[n];
    for (int i = 0; i < n; i++) {
        insertionSortedArr[i] = arr[i];
    }
    insertionSort(insertionSortedArr, n);
    std::cout << "直接插入排序后：";
    for (int i = 0; i < n; i++) {
        std::cout << insertionSortedArr[i] << " ";
    }
    std::cout << std::endl;

    // 选择排序
    int selectionSortedArr[n];
    for (int i = 0; i < n; i++) {
        selectionSortedArr[i] = arr[i];
    }
    selectionSort(selectionSortedArr, n);
    std::cout << "选择排序后：";
    for (int i = 0; i < n; i++) {
        std::cout << selectionSortedArr[i] << " ";
    }
    std::cout << std::endl;

    // 冒泡排序
    int bubbleSortedArr[n];
    for (int i = 0; i < n; i++) {
        bubbleSortedArr[i] = arr[i];
    }
    bubbleSort(bubbleSortedArr, n);
    std::cout << "冒泡排序后：";
    for (int i = 0; i < n; i++) {
        std::cout << bubbleSortedArr[i] << " ";
    }
    std::cout << std::endl;

    // 快速排序
    int quickSortedArr[n];
    for (int i = 0; i < n; i++) {
        quickSortedArr[i] = arr[i];
    }
    quickSort(quickSortedArr, 0, n - 1);
    std::cout << "快速排序后：";
    for (int i = 0; i < n; i++) {
        std::cout << quickSortedArr[i] << " ";
    }
    std::cout << std::endl;

    return 0;
}