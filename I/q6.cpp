#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <string>
#include <stack>
#include <queue>
#include <list>
#include <algorithm>
#include <iostream>

using namespace std;

string intToRoma(int num)
{
    string map[4][10] = {{"", "I", "II", "III", "IV", "V", "VII", "VIII", "IX"},
                         {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
                         {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
                         {"", "M", "MM", "MMM"}};
    string res = "";
    int count = 0;
    while (num > 0)
    {
        int temp = num % 10;
        res = map[count][temp] + res;
        num /= 10;
        count++;
    }
    return res;
}

int main()
{
    int num1 = 3, num2 = 4, num3 = 9, num4 = 58, num5 = 1994;
    cout<<intToRoma(num1)<<endl;
    cout<<intToRoma(num2)<<endl;
    cout<<intToRoma(num3)<<endl;
    cout<<intToRoma(num4)<<endl;
    cout<<intToRoma(num5)<<endl;
    return 0;
}
