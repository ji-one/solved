// https://www.acmicpc.net/problem/23250 실패

#include <iostream>
#include <vector>
using namespace std;
int n, k;
vector<pair<int, int> > v;
void hanoi(int num, int from, int by, int to)
{
    if (num == 1)
    {
        v.push_back({from, to});
        return;
    }
    else
    {
        hanoi(num - 1, from, to, by);
        v.push_back({from, to});
        hanoi(num - 1, by, from, to);
    }
}
int main()
{
    cin >> n >> k;

    hanoi(n, 1, 2, 3);
    cout << v[k - 1].first << ' ' << v[k - 1].second;
}