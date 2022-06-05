#include<iostream>
#include<vector>
using namespace std;
vector<int> s;
bool IsPa(){
	int i=0,j=s.size()-1;
	while(i<=j){
		if(s[i]!=s[j]) return false;
		i++,j--;
	}
	return true;
}
void to_radix( int n, int radix)
{

    
     while (n != 0)
     {
       	 s.push_back(n%radix); 
         n = n / radix;
	 }
    if(IsPa())
        cout << "Yes" << endl;
    else
        cout << "No" << endl;

    int m = s.size();
    for ( int i = m-1; i >=0;--i){
        if(i==0) cout<<s[i];
			else cout<<s[i]<<' ';
    }
    
}
int main(){
    int  m, n;
    cin >> m >> n;
    if(m==0)
        cout << "YES" << endl
             << 0 << endl;
    else to_radix(m, n);

}