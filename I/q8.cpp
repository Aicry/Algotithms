#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
long getsum(vector<int> &arr, int l, int r)
{
    long sum = 0;
    for (int i = l; i <= r; i++)
    {
        sum += arr[i];
    }
    return sum;
}
long findMaxSubArr(vector<long> &arr, long K)
{
    int l = 0;
    int r = arr.size() - 1;
    while (l <= r)
    {
        long temp = getsum(arr, l, r);
        if (temp == K)
            return r - l + 1;
        if(temp>K){
            while (temp-)
            {
                /* code */
            }
            
        }
    }

    return 0;
}

int main()
{
    long N, K;
    cin >> N >> K;
    vector<long> arr(N);
    for (long i = 0; i < N; i++)
    {
        long t;
        cin >> t;
        arr[i] = t;
    }
    sort(arr.begin(), arr.end());
    cout << findMaxSubArr(arr, K);
}