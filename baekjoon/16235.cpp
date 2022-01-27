#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

vector<int> age[11][11];                 // 나이
int land[11][11];                        // 양분
int a[11][11];                           // 추가되는 양분
vector<pair<pair<int, int>, int> > dead; // 생존 여부
int dr[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dc[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
int answer;

int n, m, k;
int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> n >> m >> k;
    for (int r = 1; r <= n; r++)
    {
        for (int c = 1; c <= n; c++)
        {
            cin >> a[r][c];
            land[r][c] = 5;
        }
    }

    for (int i = 0; i < m; i++)
    {
        int x, y, z;
        cin >> x >> y >> z;
        age[x][y].push_back(z);
        answer++;
    }

    while (k--)
    {
        // 봄
        for (int r = 1; r <= n; r++)
        {
            for (int c = 1; c <= n; c++)
            {
                sort(age[r][c].begin(), age[r][c].end());
                int idx = INT_MAX;
                for (int i = 0; i < age[r][c].size(); i++)
                {
                    if (land[r][c] - age[r][c][i] >= 0)
                    {
                        land[r][c] -= age[r][c][i];
                        age[r][c][i]++;
                    }
                    else
                    {
                        idx = idx > i ? i : idx;
                        dead.push_back({{r, c}, age[r][c][i]});
                    }
                }
                if (idx != INT_MAX)
                    age[r][c].erase(age[r][c].begin() + idx, age[r][c].end());
            }
        }

        // 여름
        while (!dead.empty())
        {
            pair<pair<int, int>, int> tree = dead.back();
            land[tree.first.first][tree.first.second] += (tree.second / 2);
            dead.pop_back();
            answer--;
        }

        // 가을
        for (int r = 1; r <= n; r++)
        {
            for (int c = 1; c <= n; c++)
            {
                for (int i = 0; i < age[r][c].size(); i++)
                {
                    if (age[r][c][i] % 5 == 0)
                    {
                        for (int j = 0; j < 8; j++)
                        {
                            int nr = r + dr[j];
                            int nc = c + dc[j];
                            if (nr >= 1 && nr <= n && nc >= 1 && nc <= n)
                            {
                                age[nr][nc].push_back(1);
                                answer++;
                            }
                        }
                    }
                }
            }
        }

        // 겨울
        for (int r = 1; r <= n; r++)
        {
            for (int c = 1; c <= n; c++)
            {
                land[r][c] += a[r][c];
            }
        }
    }
    cout << answer;
}