#include <iostream>

using namespace std;

void swap(int* a, int *b) {
    int aux = *a;
    *a = *b;
    *b = aux;
}

int* partition(int arr[], int length) {
    int pivot = arr[0];
    int j = 0;

    for (int i = 1; i < length; i++) {
        if (arr[i] < pivot) {
            swap(arr + i, arr + j);
            j++;
        }
    }

    swap(arr + j, arr + length - 1);

    return arr + j;
}

void quick_sort(int arr[], int length) {
    if (length > 1 && arr) {
        int* subarray = partition(arr, length);

        quick_sort(arr, subarray - arr);
        quick_sort(subarray + 1, length - (subarray - arr) - 1);
    }
}

int main()
{

    int arr[] = {10,9,8,7,6,5,4,3,2};
    // int arr[] = {0,4,3,2,1};
    // int arr[] = {4,3,1,5,6,2};

    int n = sizeof(arr) / sizeof(arr[0]);
    
    quick_sort(arr, n);

    for (int i = 0; i < n; i ++) {
        cout << arr[i] << " ";
    }

    return 0;
}

