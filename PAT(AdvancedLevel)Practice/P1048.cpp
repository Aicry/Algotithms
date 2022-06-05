#include <iostream>
using namespace std;
int a[1001];
int main() {
    int n, m, temp;
    scanf("%d %d", &n, &m);
    for(int i = 0; i < n; i++) {
        scanf("%d", &temp);
        a[temp]++;
    }
    for(int i = 0; i < 1001; i++) {
        if(a[i]) {
            a[i]--;
            if(m > i && a[m-i]) {
                printf("%d %d", i, m - i);
                return 0;
            }
          //  a[i]++;
        }
    }
    printf("No Solution");
    return 0;
}

/*
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,sum;
vector<int> m;
bool binary(int i){
    int left = i+1, right = n - 1;
    while(left<=right){
        int mid = (left + right) / 2;
        if((m[mid]+m[i])==sum){
            cout << m[i] << " " << m[mid];
             return true;
        }
        if((m[mid]+m[i])>sum)
            right = mid-1;
        if((m[mid]+m[i])<sum)
            left = mid + 1;
    }
    return false;
}
int main(){
    cin >> n>>sum;
    for (int i = 0; i < n;++i){
        int t;
        cin >> t;
        m.push_back(t);
    }
    sort(m.begin(), m.end());

    for (int i = 0; i < n;++i){
        bool a=binary(i);
        if(a)
            return 0;
    }
    cout << "No Solution";
    return 0;
}
*/