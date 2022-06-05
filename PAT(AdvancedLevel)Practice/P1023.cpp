#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    string a;
    cin >> a;
    int n = a.length();
   vector<int> digits;
   vector<int> digits1;
    for (int i = 0; i < n;++i){
        digits.push_back(a[i] - '0');
    }
    int carry = 0;
    for (int i = n - 1; i >= 0;--i){

        int t = digits[i] * 2;
         if(carry)
             t += 1, carry = 0;
        if(t>9)
            carry = 1;
        digits1.push_back(t%10);
    }
    if(carry)
        digits1.push_back(1);
    vector<int> digits2;
    for (int i = digits1.size() - 1; i >= 0;--i){
        digits2.push_back(digits1[i]);
    }
    sort(digits.begin(), digits.end());
    sort(digits1.begin(), digits1.end());
    int m = digits1.size();
    int mark = 1;
    if(m==n)
    {
        for (int i = 0; i < n;++i){
            if(digits1[i]!=digits[i])
                mark = 0;
        }
        if(mark)
            cout << "Yes"<<endl;
        else
            cout << "No" << endl;
    }
   
    else
        cout << "No" << endl;

    for (int i = 0; i < m;++i){
        cout << digits2[i];
    }
}