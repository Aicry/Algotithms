#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct moster
{
    int A_i;
    int B_i;
    int H_i;
};

int main()
{
    int T;
    cin >> T;

    while (T--)
    {
        int N;
        int A, B;
        cin >> N >> A >> B;
        vector<moster> arr;
        for (int i = 0; i < N; i++)
        {
            moster temp;
            cin >> temp.A_i;
            cin >> temp.B_i;
            cin >> temp.H_i;
            arr.push_back(temp);
        }
        int need = 0;
        int maxBlood = 0;
        int flag = 1;
        for (int j = 0; j < N; ++j)
        {
            int manHurt = A - arr[j].B_i;
            if (manHurt <= 0)
            {
                
                flag = 0;
                break;
            }
            int monHurt = arr[j].A_i - B;
            if (monHurt < 0)
                monHurt = 0;

            int count = arr[j].H_i / manHurt;
            int res = arr[j].H_i % manHurt;
           if(res==0) need += (count-1) * monHurt;
            else need += count * monHurt;
            maxBlood = max(need, maxBlood);
          if(res)  need -= (manHurt - res);
        }
        if (flag)
            cout << maxBlood + 1 << endl;
        else
            cout << -1 << endl;
    }
}