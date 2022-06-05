#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main(){
    string a;
    cin >> a;
    int sum = 0;
    for (int i = 0; i < a.size();++i){
        sum += (int)a[i]-48;
    }
    int temp = 0;
    vector<string> res;
    while (sum != 0)
    {
        temp = sum % 10;
        sum = sum / 10;
        switch (temp)
        {
            case 0:
            res.push_back("zero");
            break;
            case 1:
            res.push_back("one");
            break;
            case 2:
            res.push_back("two");
            break;
            case 3:
            res.push_back("three");
            break;
            case 4:
            res.push_back("four");
            break;
            case 5:
            res.push_back("five");
            break;
            case 6:
            res.push_back("six");
            break;
            case 7:
            res.push_back("seven");
            break;
            case 8:
            res.push_back("eight");
            break;
            case 9:
            res.push_back("nine");
            break;
        default:
            break;
        }
    }
    int n = res.size();
    for (int i = n-1; i >0;--i){
        cout << res[i] << " ";
    }
    cout << res[0];
}