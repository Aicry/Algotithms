#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int n,m;
    cin >> n;
    int t;
    vector<int> coupon(n);
    vector<int> value(m);
    for (int i = 0; i < n;++i)
        cin>>coupon[i];
    cin >> m;
    for (int i = 0; i < m;++i)
        cin >> value[i];

    sort(coupon.begin(), coupon.end());
    sort(value.begin(), value.end());
    int p = 0, q = 0;
    int sum = 0;
    while (p < n && q < m && coupon[p] < 0 && value[q] < 0)
    {
        sum += coupon[p++] * value[q++];
    }
    p = n - 1, q = m - 1;
    while (p >= 0 && q >= 0 && coupon[p] > 0 && value[q] > 0)
    {
        sum += coupon[p--] * value[q--];
    }
    cout << sum;
}

