#include<iostream>
#include<vector>
using namespace std;

vector<int> A{1, 5, -5, -5, 8, 9, -11, 5, 6, 3, 1, -5, 10, -2};
//vector<int> A{-5, 2,-1,3};
//vector<int> A{1,-2, -1};
int MaxsubSlow1(vector<int> &a){
    int n = a.size();
    int max =INT_MIN;
    int temp = 0;
    for (int i = 0; i < n;++i){
        for (int j = i; j < n;++j){
            temp += a[j];
            if(temp>max)
                max = temp;
        }
        temp = 0;
    }
    return max;
}

int MaxsubSlow2(vector<int> &a){
    int n = a.size();
    vector<int> S(n, 0);
    int temp = 0;
    for (int i = 0; i < n;++i){
        temp += a[i];
        S[i] = temp;
    }
    int res = S[0];
     for (int i = 0; i < n;++i){
        for (int j = i+1; j < n;++j){
            res = max(res, S[j] - S[i]);
        }
    }

    return res;
}

int MaxsubSlow3(vector<int> &a){
    
    int n = a.size();
    if(n==0)
        return -1;
    if(n==2)
        return max(a[0], a[1]);
    vector<int> m(n, 0);
    m[0] = a[0];
    for (int i = 1; i < n; ++i)
    {
        m[i] = max(m[i - 1] + a[i], a[i]);
    }
    int res=INT_MIN;
    for (int i = 0; i < n;++i){
        res = max(res, m[i]);
    }
    return res;
}

int MaxsubSlow4(vector<int> &a){
    
    int n = a.size();
    if(n==0)
        return -1;
    if(n==2)
        return max(a[0], a[1]);
    int m = a[0];
    int res = a[0];
    int begin = 0;
    int end = 0;
    for (int i = 1; i < n; ++i)
    {
       m = max(m+ a[i], a[i]);

        if(m>res&&m!=a[i])
            end = i;
        if(m>res&&m==a[i])
             begin = i, end = i;

        
        res = max(res, m);
        
    }
    cout << begin << ends << end << endl;
    return res;
}

int main(){
    cout << MaxsubSlow1(A) << endl;
    cout << MaxsubSlow2(A) << endl;
    cout << MaxsubSlow3(A) << endl;
    cout << MaxsubSlow4(A) << endl;
}