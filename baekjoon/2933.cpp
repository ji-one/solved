#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string cave[100];
int R, C, N;
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
bool visited[100][100];
bool compare(pair<int, int> a, pair<int, int> b)
{
    if (a.second > b.second)
        return true;
    else
        return false;
}
void bfs(int startX, int startY)
{
    bool isSeparate = true;
    fill(&visited[0][0], &visited[R - 1][C], false);
    queue<pair<int, int> > q;
    vector<pair<int, int> > v;
    q.push({startX, startY});
    v.push_back({startX, startY});
    visited[startY][startX] = true;

    while (!q.empty())
    {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (y == R - 1)
        {
            isSeparate = false;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];

            if (nx >= 0 && nx < C && ny >= 0 && ny < R && !visited[ny][nx] && cave[ny][nx] == 'x')
            {
                visited[ny][nx] = true;
                q.push({nx, ny});
                v.push_back({nx, ny});
            }
        }
    }
    if (isSeparate)
    {
        int dist = 100;
        sort(v.begin(), v.end(), compare);

        bool check[100] = {
            false,
        };

        for (int i = 0; i < v.size(); i++)
        {
            if (!check[v[i].first])
            {
                check[v[i].first] = true;
                for (int j = v[i].second + 1; j <= R; j++)
                {
                    if (j == R)
                    {
                        dist = min(dist, R - v[i].second - 1);
                        break;
                    }

                    if (cave[j][v[i].first] == 'x')
                    {
                        dist = min(dist, j - v[i].second - 1);
                        break;
                    }
                }
            }
        }

        for (int i = 0; i < v.size(); i++)
        {
            cave[v[i].second][v[i].first] = '.';
        }

        for (int i = 0; i < v.size(); i++)
        {
            cave[v[i].second + dist][v[i].first] = 'x';
        }
    }
}

void throwStick(int dir, int h)
{
    h = R - h;
    if (dir == 0)
    {
        for (int i = 0; i < C; i++)
        {
            if (cave[h][i] == 'x')
            {
                cave[h][i] = '.';
                if (h != 0 && cave[h - 1][i] == 'x')
                {
                    bfs(i, h - 1);
                }

                if (h != R - 1 && cave[h + 1][i] == 'x')
                {
                    bfs(i, h + 1);
                }

                if (i + 1 != C && cave[h][i + 1] == 'x')
                {
                    bfs(i + 1, h);
                }
                break;
            }
        }
    }
    else
    {
        for (int i = C - 1; i >= 0; i--)
        {
            if (cave[h][i] == 'x')
            {
                cave[h][i] = '.';
                if (h != 0 && cave[h - 1][i] == 'x')
                {
                    bfs(i, h - 1);
                }

                if (h != R - 1 && cave[h + 1][i] == 'x')
                {
                    bfs(i, h + 1);
                }
                if (i - 1 != -1 && cave[h][i - 1] == 'x')
                {
                    bfs(i - 1, h);
                }
                break;
            }
        }
    }
}
int main()
{

    cin >> R >> C;
    for (int i = 0; i < R; i++)
    {
        cin >> cave[i];
    }
    cin >> N;
    for (int i = 0; i < N; i++)
    {
        int h;
        cin >> h;
        throwStick(i % 2, h);
    }

    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            cout << cave[i][j];
        }
        cout << '\n';
    }
}