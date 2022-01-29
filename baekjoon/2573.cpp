#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int a[300][300];
bool visited[300][300];
vector<pair<int, int> > v;
int n, m, year;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool check()
{
    fill(&visited[0][0], &visited[n - 1][m], false);
    queue<pair<int, int> > q;

    q.push({v[0].first, v[0].second});
    visited[v[0].second][v[0].first] = true;

    int cnt = 0;
    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();
        ++cnt;
        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if (nx >= 0 && nx < m && ny >= 0 && ny < n)
            {
                if (a[ny][nx] > 0 && !visited[ny][nx])
                {
                    q.push({nx, ny});
                    visited[ny][nx] = true;
                }
            }
        }
    }
    if (v.size() != cnt)
        return true;
    else
        return false;
}

void melting()
{
    vector<pair<pair<int, int>, int> > adj;
    for (int i = 0; i < v.size(); i++)
    {
        int x = v[i].first;
        int y = v[i].second;
        int cnt = 0;
        for (int i = 0; i < 4; i++)
        {
            if (x + dx[i] >= 0 && x + dx[i] < m && y + dy[i] >= 0 && y + dy[i] < n)
            {
                if (a[y + dy[i]][x + dx[i]] == 0)
                    ++cnt;
            }
        }
        adj.push_back({{x, y}, cnt});
    }

    v.clear();

    for (int i = 0; i < adj.size(); i++)
    {
        int x = adj[i].first.first;
        int y = adj[i].first.second;
        int cnt = adj[i].second;

        if (a[y][x] - cnt > 0)
        {
            a[y][x] -= cnt;
            v.push_back({x, y});
        }
        else
            a[y][x] = 0;
    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> a[i][j];
            if (a[i][j] != 0)
                v.push_back({j, i});
        }
    }

    while (true)
    {
        year++;
        melting();
        if (v.empty())
        {
            cout << 0;
            break;
        }
        else
        {
            if (check())
            {
                cout << year;
                break;
            }
        }
    }
}