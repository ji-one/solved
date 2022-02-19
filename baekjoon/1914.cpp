// https://www.acmicpc.net/problem/1914
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
    }
    else
    {
        hanoi(num - 1, from, to, by);
        v.push_back({from, to});
        hanoi(num - 1, by, from, to);ß
    }
}
int main()
{
    cin >> n >> k;

    hanoi(n, 1, 2, 3);
    cout << v.size() << '\n';
    for (int i = 0; i < v.size(); i++)
    {
        cout << v[i].first << ' ' << v[i].second << '\n';
    }
}