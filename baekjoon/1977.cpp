// https://www.acmicpc.net/problem/1977
#include <iostream>
#include <climits>
#include <cmath>
#include <algorithm>
using namespace std;
int main()
{
    int m, n;
    cin >> m >> n;

    int sum = 0, smallest = INT_MAX;
    for (int i = m; i <= n; i++)
    {
        int sqr = sqrt(i);
        if (sqr * sqr == i)
        {
            smallest = min(smallest, i);
            sum += i;
        }
    }
    if (sum == 0)
        cout << -1;
    else
        cout << sum << '\n' << smallest;
}