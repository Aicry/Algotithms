#include <iostream>
#include <vector>
using namespace std;
void merge() {}

void mergeSort() {}

void bubbleSort() {}

void shellSort() {}

void selectSort() {}

void quickSort(vector<int> &arr, int left, int right)
{
    if (left >= right)
        return;
    int midValue = arr[right];
    int last_pos = left - 1;
    for (int cur = left; cur <= right - 1; cur++)
    {
        if (arr[cur] <= midValue)
        {
            last_pos++;
            swap(arr[last_pos], arr[cur]);
        }
    }
    swap(arr[++last_pos], arr[right]);
    quickSort(arr, left, last_pos - 1);
    quickSort(arr, last_pos + 1, right);
}
int main()
{
    vector<int> arr = {1, 2, 8, 9, 6, 3, 4, 7, 8, 2};
    quickSort(arr, 0, arr.size() - 1);
    for (auto a : arr)
        cout << a << " ";
}