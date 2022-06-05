#include <iostream>
#include <vector>
using namespace std;
vector<int> plusOne(vector<int> &digits)
{
    int n = digits.size() - 1;
    digits[n] += 1;
    if (digits[n] < 10)
        return digits;

    for (int i = digits.size() - 1; i > 0; i--)
    {
        if (digits[i] == 10)
        {
            digits[i] = 0;
            digits[i - 1] += 1;
        }
    }
    if (digits[0] == 10)
    {
        digits.insert(digits.begin(), 1);
        digits[1] = 0;
    }
    return digits;
}
int main()
{
    vector<int> arr = {9, 9};
    plusOne(arr);

}
