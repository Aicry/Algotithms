#include<iostream>
#include<vector>
#include<limits>
using namespace std;
vector<vector<int>> lists2;
vector<int> initial;

void merge(vector<int> &a,int l,int r,int mid)
{
     vector<int> LeftSuba(a.begin() + l, a.begin() + mid + 1);
    vector<int> RightSuba(a.begin() + mid + 1, a.begin() + r + 1);
    int idxLeft = 0, idxRight = 0;
    LeftSuba.insert(LeftSuba.end(), numeric_limits<int>::max());
    RightSuba.insert(RightSuba.end(), numeric_limits<int>::max());
    for (int i = l; i <= r; i++) {
        if (LeftSuba[idxLeft] < RightSuba[idxRight]) {
            a[i] = LeftSuba[idxLeft];
            idxLeft++;
        } else {
            a[i] = RightSuba[idxRight];
            idxRight++;
        }
    }
}
void merge_sort(vector<int> &a,int l,int r)
{
    
    if(l>=r)
        return;
    int mid=(l+r)/2;
	merge_sort(a,l,mid);
	merge_sort(a,mid+1,r);
	merge(a,l,r,mid);
    lists2.push_back(a);
}

int main(){
    int n;
    cin >> n;
    int t;
    for (int i = 0; i < n;++i){
        cin >>t;
        initial.push_back(t);
    }
    merge_sort(initial, 0, n - 1);
    for (int i = 0; i < lists2.size();++i){
        for (int j = 0; j < n;++j){
            cout << lists2[i][j] <<ends;
        }
        cout << endl;
    }

    cout << endl;
    for (int i = 0; i < n;++i){
        cout << initial[i] << " ";
    }
}