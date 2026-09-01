// Name: Pranay Bhardwaj
// Roll Number: 25/DA/051
// 1. Write a program to implement Merge Sort using both recursive and iterative methods.

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    vector<int> L(n1);
    vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];

    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
            arr[k++] = L[i++];
        else
            arr[k++] = R[j++];
    }

    while (i < n1)
        arr[k++] = L[i++];

    while (j < n2)
        arr[k++] = R[j++];
}

void recursiveMergeSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    recursiveMergeSort(arr, left, mid);
    recursiveMergeSort(arr, mid + 1, right);

    merge(arr, left, mid, right);
}

void iterativeMergeSort(vector<int> &arr)
{
    int n = arr.size();

    for (int size = 1; size < n; size *= 2)
    {
        for (int left = 0; left < n - 1; left += 2 * size)
        {
            int mid = min(left + size - 1, n - 1);
            int right = min(left + 2 * size - 1, n - 1);

            if (mid < right)
                merge(arr, left, mid, right);
        }
    }
}

void display(const vector<int> &arr)
{
    for (int x : arr)
        cout << x << " ";

    cout << endl;
}

int main()
{
    int n;

    cout << "Enter number of elements: ";
    cin >> n;

    vector<int> arr(n);
    vector<int> arr1;
    vector<int> arr2;

    cout << "Enter elements: ";

    for (int i = 0; i < n; i++)
        cin >> arr[i];

    arr1 = arr;
    arr2 = arr;

    recursiveMergeSort(arr1, 0, n - 1);

    iterativeMergeSort(arr2);

    cout << "\nSorted array using Recursive Merge Sort: ";
    display(arr1);

    cout << "Sorted array using Iterative Merge Sort: ";
    display(arr2);

    return 0;
}