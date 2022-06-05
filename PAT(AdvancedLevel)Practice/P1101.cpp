/*#include <iostream>
#include <algorithm>
#include <vector>
int v[100000];
using namespace std;
int main() {
    int n, max = 0, cnt = 0;
    scanf("%d", &n);
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        b[i] = a[i];
    }
    sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
        if(a[i] == b[i] && b[i] > max)
            v[cnt++] = b[i];
        if (b[i] > max)
            max = b[i];
    }
    printf("%d\n", cnt);
    for(int i = 0; i < cnt; i++) {
        if (i != 0) printf(" ");
        printf("%d", v[i]);
    }
    printf("\n");
    return 0;
}*/

#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

vector<int> list;
vector<int> res;

int main(){
    int n;
    cin >> n;
    if(n==1){
        int t;
        cin >> t;
        cout << t;
        return 0;
    }
    list.resize(n+1);
    for (int i = 1; i <= n;++i){
        cin >> list[i];
    }
    vector<int> left_max(n+2);
    for (int i = 1; i <= n;++i){
        left_max[i] = max(left_max[i - 1], list[i]);
    }

    vector<int> right_min(n+2);
    right_min[n + 1] = 2147483647;
    for (int i = n; i > 0; --i)
    {
        right_min[i] = min(right_min[i + 1], list[i]);
    }
   
    for (int i = 1; i <= n;++i){
        if(list[i]>=left_max[i]&&list[i]<=right_min[i])
            res.push_back(list[i]);
        }

    sort(res.begin(), res.end());
    int sum = res.size();
    cout << sum << endl;
    for (int i = 0; i <sum;++i){
        if(i==sum-1)
            cout << res[i]<<endl;
        else
            cout << res[i] << " ";
    }
    
}

