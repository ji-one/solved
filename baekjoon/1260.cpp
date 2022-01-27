#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

int n, m, start;
vector<int> v[1001];
bool edgeCheck[1001][1001];
bool nodeCheck[1001];

void dfs(int node)
{
    cout << node << " ";
    nodeCheck[node] = true;
    bool isPossible = false;
    for (int i = 0; i < v[node].size(); i++)
    {
        if (!edgeCheck[node][v[node][i]] && !nodeCheck[v[node][i]])
        {
            edgeCheck[node][v[node][i]] = true;
            edgeCheck[v[node][i]][node] = true;
            isPossible = true;
            dfs(v[node][i]);
        }
    }

    if (!isPossible)
        return;
}

void init()
{
    fill(&nodeCheck[0], &nodeCheck[0] + (n + 1), 0);
}

void bfs(int node)
{
    queue<int> q;
    q.push(node);
    nodeCheck[node] = true;
    while (!q.empty())
    {
        int x = q.front();
        q.pop();
        cout << x << " ";

        for (int i = 0; i < v[x].size(); i++)
        {
            if (!nodeCheck[v[x][i]])
            {
                nodeCheck[v[x][i]] = true;
                q.push(v[x][i]);
            }
        }
    }
}

int main()
{
    cin >> n >> m >> start;

    while (m--)
    {
        int x, y;
        cin >> x >> y;
        v[x].push_back(y);
        v[y].push_back(x);
    }

    for (int i = 1; i <= n; i++)
        sort(v[i].begin(), v[i].end());

    dfs(start);
    init();
    cout << '\n';
    bfs(start);

    return 0;
}