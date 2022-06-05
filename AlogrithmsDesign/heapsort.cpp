#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
void Heap_build(int a[], int root, int length)
{
    int lchild = root * 2 + 1;
    if (lchild < length)
    {
        int flag = lchild;
        int rchild = lchild + 1;
        if (rchild < length)
        {
            if (a[rchild] > a[flag])
            {
                flag = rchild;
            }
        }
        if (a[root] < a[flag])
        {
         
            swap(a[root], a[flag]);
            Heap_build(a, flag, length);
        }
    }
}

void Heap_sort(int a[], int len)
{
    for (int i = len / 2; i >= 0; --i) 
    {
        Heap_build(a, i, len);
    }

    for (int j = len - 1; j > 0; --j)
    {
        swap(a[0], a[j]);   
        Heap_build(a, 0, j);
    }
}
int main(int argc, char **argv)
{

    int a[10] = {12, 45, 748, 12, 56, 3, 89, 4, 48, 2};
    Heap_sort(a, 10);
    for (size_t i = 0; i != 10; ++i)
    {
        cout << a[i] << " ";
    }
    cout << endl;
    return 0;
}