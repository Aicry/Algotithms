#include <iostream>
#include <vector>
#include<queue>
#include<stack>
using namespace std;

stack<int> s;
int getNodes(vector<vector<int>> map)
{
    vector<int> node(map.size());
    for (int i = 0; i < map.size(); i++)
    {
        for (int j = 0; j < map[0].size(); j++)
        {
            if (map[i][j] == 1)
            {
                node[i] = 1;
                node[j] = 1;
            }
        }
    }
    int count = 0;
    for (auto i : node)
    {
        if (i == 1)
            count++;
    }
    return count;
}

void getList(vector<vector<int>> map)
{
    int count = getNodes(map);
    vector<int> temp;
    for (int i = 1; i <= count;i++){
        for (int j = 1; j <= count;j++){
            if(map[i][j]==1)
                {
                    s.push(i);
                    temp.push_back(i);
                    break;
                }
        }
    }
    for (int i = 1; i <= count;i++){
        int flag = 0;
        for(auto j:temp){
            if(i==j)
                flag = 1;
        }
        if(!flag)
            cout << count;
    }
        while (!s.empty())
        {
            cout << s.top();
            s.pop();
        }
    
}

int main()
{

    vector<vector<int>> map(6, vector<int>(6, 0));
    map[1][2] = 1;
    map[2][3] = 1;
    map[2][4] = 1;
    map[3][4] = 1;
    map[4][5] = 1;
    //cout << getNodes(map);
    getList(map);
}