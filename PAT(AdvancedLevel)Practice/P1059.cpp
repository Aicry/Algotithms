#include<iostream>
#include<vector>
#include<map>
using namespace std;
map<long,long> prime;      
bool p[50000];
long pnum=0;
void eulerSieve(long n)
{
    for(long i=2;i<=n;i++)
    {
        if(p[i]==false){
            prime[pnum] = i, ++pnum;
        }
        for(long j=0;j<pnum;j++)
        {
            if(i*prime[j]>n){
                break;
            }
            p[i * prime[j]] = true;
            if(i%prime[j]==0){
                break;
            }
        }
    }
}

int main(){
    int n;
    cin >> n;
        if(n==1)
    {
        cout<<"1=1";
        return 0;
    }
    cout << n << "=";
    eulerSieve(50000);
    vector<long> res;
   
    for (int i = 0; i < pnum;++i){
            if(n%prime[i]==0)
                n = n / prime[i], res.push_back(prime[i]), i--;
        }
    
        int l = res.size();
        int count;
        for (int i = 0; i < l;++i){
            count = 1;
            for (int j = i+1; j < l;++j){
                if(res[i]==res[j])
                    count++, i = j;
                else
                    break;
            }
            if(count==1)
                cout << res[i];
            if(count>1)
                cout << res[i] << "^" << count;
            if(i<l-1)
                cout << "*";
        }
}