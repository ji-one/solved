#include <iostream>
#include <algorithm>
using namespace std;
int a[100000];
int main()
{
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a + n);
    for (int i = 0; i < n; i++)
    {
        if (i > 0 && a[i - 1] == a[i])
            continue;
        cout << a[i] << ' ';
    }
    return 0;
}