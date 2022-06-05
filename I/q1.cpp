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

int main()
{
    int door;
    int roomK, roomJ;
    cin >> door;
    unordered_map<int, int> house;
    while (door--)
    {
        cin >> roomK >> roomJ;
        house[roomK] += 1;
        house[roomJ] += 0;
    }
    for (auto i : house)
    {
        if (i.second == 0)
        {
            cout << i.first << endl;
        }
    }
    return 0;
}
