/*11 3
1 3 3 3 5 7 9 11 13 15 15
1 3 6*/
//递归
/*
int findpos(int a[], int l, int r, int k)
{
	if (l == r)
	{
		if (a[l] == k)
			return l;
		else
			return -1;
	}
	int mid = (l + r) / 2;
	if (k <= a[mid])
		findpos(a, l, mid, k);
	else
		findpos(a, mid + 1, r, k);
}
*/
#include<iostream>
#include<vector>
using namespace std;
vector<int> arr;
int m, n;



//找到第一次出现的目标值
/*int binasearch(int targe){
    int l = 0, r = m;
    while(l<r){
        int mid = l + (r - l) / 2;
        if(arr[mid]==targe)
            return mid + 1;
        if(arr[mid]<targe)
                l = mid + 1;
        if(arr[mid]>targe)
                r = mid ;
    }
    if(arr[l]==targe)
        return l + 1;

    return -1;
}
   */

//找到最左边的目标值
   int binasearch(int targe){
    int l = 0, r = m-1;
    while(l<r){
        int mid = l + (r - l) / 2;
        if(arr[mid]>=targe)
            r = mid;
        if(arr[mid]<targe)
                l = mid + 1;
    }
    if(arr[l]==targe)
        return l+1;
        else
        {
            return -1;
        }
        
}
int main(){
    
    cin >> m >> n;
     int t;
    for (int i = 0; i < m;++i){
        cin >> t;
        arr.push_back(t);
    }
    for (int i = 0; i < n;++i){
        cin >> t;
        cout << binasearch(t) <<" ";
    }
    return 0;
}


