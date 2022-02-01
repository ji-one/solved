/* 
* https://www.acmicpc.net/problem/17626
*/
#include <iostream>
#include <cmath>
#include <climits>
using namespace std;
int d[50001];
int main()
{
    int n;
    cin >> n;

    d[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        d[i] = INT_MAX;
        for (int j = 1; j * j <= i; j++)
        {
            d[i] = min(d[i], d[i - j * j] + 1);
        }
    }

    cout << d[n];
}