#include <iostream>

using namespace std;
bool f(int a)
{
    if (a >= 0 && a <= 255)
        return true;
    return false;
}
int main()
{
    int a, b, c, d;
    char j, k, l;
    while (cin >> a >> j >> b >> k >> c >> l >> d)
    {
        if (f(a) && f(b) && f(c) && f(d))
            cout << "Yes!" << endl;
        else
            cout << "No!" << endl;
    }
}