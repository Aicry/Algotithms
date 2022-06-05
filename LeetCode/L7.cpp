#include<iostream>
using namespace std;

/* int reverse(int x) {
       long ans=0;  //注意是long类型 
        while (x!=0){
            ans=ans*10+x%10;
            x=x/10;
        }
        return (int)ans==ans?(int)ans:0;
    }
*/
int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;//int_max =2147483647  int_min=-2147483648
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }


int main(){
    cout << INT_MAX + 1;
    cout << endl;
    cout << INT_MIN - 1;
    cout << endl;
    cout << INT_MIN + 1;

}