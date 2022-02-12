#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int a[101];
bool visited[101];
vector<int> v;

int dfs(int target, int current)
{
    if (!visited[current])
    {
        visited[current] = true;
        return dfs(target, a[current]);
    }
    else
    {
        if(current == target)
            return 1;
        else
            return 0;
    }
}

int main()
{
    int n;
    cin >> n;

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        if (dfs(i, i))
            v.push_back(a[i]);
        
        fill(&visited[0], &visited[0] + n + 1, false);
    }

    sort(v.begin(), v.end());
    cout << v.size() << '\n';
    for (auto x : v)
        cout << x << '\n';

    return 0;
}