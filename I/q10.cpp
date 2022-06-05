#include <iostream>
#include <string>
#include <map>
#include<algorithm>
using namespace std;

int main()
{

    char s;
    int count = 0;
    int other = 0;
    map<char, int> m;
    while (cin>>s)
    {
        
        if ('a' <= s <= 'z' || 'A' <= s <= 'Z')
        {
           

            m[_tolower(s)]++;
        }
        else
            other++;
    }
    for (map<char, int>::iterator it = m.begin(); it != m.end(); it++)
    {
        if (it->second % 2 == 1)
            count++;
    }
    if (other % 2 == 1)
        count++;
    if (count > 1)
        cout << "false";
    else
        cout << "true";
}

/*

9 6
....#.
.....#
......
......
......
......
......
#@...#
.#..#.

45




*/