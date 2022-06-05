/*回溯超时*/
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
vector<int> nums{1, 2, 3, 5,9,5};
int n = nums.size();
bool dfs(int half_sum,int start,int total,vector<int>& nums){
    

     for (int i = start; i < n;++i){
        if(total+nums[i]==half_sum) return true;
            if(total+nums[i]>half_sum) continue;
            if(dfs(half_sum,i+1,total+nums[i],nums)) return true;
     }
   return false;
}

int main(){
    int sum;
    for (int x : nums)
        sum += x;
    if (sum % 2)
        cout <<false;
    sum /= 2;
    sort(nums.begin(), nums.end());
    if (nums.back() > sum)
        cout <<false;
    int n = nums.size();
    for (int i =0; i < n; ++i)
    {
        if (nums[i] == sum)
           cout<< true;
        if (dfs(sum, 0, 0, nums))
            cout <<true;
     }
        
}

/*#include<iostream>
#include<vector>
using namespace std;
vector<int> test{1, 2, 3, 5,9};
int n = test.size();
int sum(vector<int> a){
    int res=0;
    int i=0;
    for ( ; i < n - 1;i+=2)
    {
        res += a[i] + a[i + 1];
    }
    for (; i < n;++i){
        res += a[i];
    }
    return res;
}

void dfs(int half_sum,int start,int total,int & res){
     if(half_sum==total){
         res = 1;
         return;

     }
     if(half_sum<total)
             return;

     for (int i = start; i < n;++i){
         total += test[i];
       

         dfs(half_sum, i + 1, total,res);
         if(res==1)
             return;
         total -= test[i];
     }

}


int main(){
    int k = sum(test);
    cout << k << endl;
    if(k%2==1){
        cout << 0;
        return 0;
    }
    int half_sum = sum(test) / 2;
    int res = 0;
    
    dfs(half_sum, 0, 0, res);
    cout << res;
    return 0;
}*/