#include <iostream>
using namespace std;

struct Shark
{
    int s, d, z; // 속력, 이동 방향, 크기
};

Shark a[101][101];
Shark next_a[101][101];

int R, C, M;
int answer;

void fishing(int c)
{
    for (int i = 0; i <= R; i++)
    {
        if (a[i][c].z != 0)
        {
            answer += a[i][c].z;
            a[i][c] = {};
            break;
        }
    }
}

void move()
{
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            if (a[i][j].z != 0)
            {
                int next_c = j, next_r = i, next_d = a[i][j].d;

                if (a[i][j].d == 1)
                {
                    next_r -= a[i][j].s;
                    if (next_r < 0)
                    {
                        next_r *= -1;
                        int step = next_r % (R - 1);
                        if ((next_r / (R - 1)) % 2 == 0)
                        {
                            next_d = 2;
                            next_r = step;
                        }
                        else
                        {
                            next_r = (R - 1) - step;
                        }
                    }
                }
                else if (a[i][j].d == 2)
                {
                    next_r += a[i][j].s;
                    if (next_r >= R)
                    {
                        next_r -= (R-1);
                        int step = next_r % (R - 1);
                        if ((next_r / (R - 1)) % 2 == 0)
                        {
                            next_d = 1;
                            next_r = (R - 1) - step;
                        }
                        else
                        {
                            next_r = step;
                        }
                    }
                }
                else if (a[i][j].d == 3)
                {
                    next_c += a[i][j].s;
                    if (next_c >= C)
                    {
                        next_c -= (C-1);
                        int step = next_c % (C - 1);
                        if ((next_c / (C - 1)) % 2 == 0)
                        {
                            next_d = 4;
                            next_c = (C - 1) - step;
                        }
                        else
                        {
                            next_c = step;
                        }
                    }
                }
                else
                {
                    next_c -= a[i][j].s;
                    if (next_c < 0)
                    {
                        next_c *= -1;
                        int step = next_c % (C-1);
                        if ((next_c / (C-1)) % 2 == 0)
                        {
                            next_d = 3;
                            next_c = step;
                        }
                        else
                        {
                            next_c = (C - 1) - step;
                        }
                    }
                }

                if (a[i][j].z > next_a[next_r][next_c].z)
                {
                    next_a[next_r][next_c] = {a[i][j].s, next_d, a[i][j].z};
                }
            }
        }
    }
    for (int i = 0; i < R; i++)
    {
        for (int j = 0; j < C; j++)
        {
            a[i][j] = next_a[i][j];
            next_a[i][j] = {};
        }
    }
}

int main()
{
    cin.tie(0);
    ios_base::sync_with_stdio(0);

    cin >> R >> C >> M;

    for (int i = 0; i < M; i++)
    {
        int r, c, s, d, z;
        cin >> r >> c >> s >> d >> z;
        a[r - 1][c - 1] = {s, d, z};
    }

    for (int i = 0; i < C; i++)
    {
        fishing(i);
        move();
    }

    cout << answer;
}