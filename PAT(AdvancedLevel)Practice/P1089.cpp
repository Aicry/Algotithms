#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int n;
vector<int> initial;
vector<vector<int>> lists1;
void insert(vector<int> a){
    int n = a.size();
    for (int i = 1; i < n; ++i)
    {
        if(a[i]<a[i-1]){
            int t = a[i];
            
            for (int j=i-1; j >= 0;--j){
                if(a[j]>t)
                    a[j + 1] = a[j], a[j] = t;
                else
                  {
                      a[j + 1] = t;
                      break;
                  }
            }
            
        }
        lists1.push_back(a);
    }
}

int main(){
    cin >> n;
    int t;
    for (int i = 0; i < n;++i){
        cin >>t;
        initial.push_back(t);
    }
    insert(initial);
    for (int i = 0; i < lists1.size();++i){
        for (int j = 0; j < n;++j){
            cout << lists1[i][j] << " ";
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < n;++i){
        cout << initial[i] << " ";
    }
}