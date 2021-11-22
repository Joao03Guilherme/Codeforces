#include <iostream>
#include <bits/stdc++.h>

using namespace std;

void solve()
{
    int n;
    string enemy;
    string gregor;

    cin >> n;
    cin.get();
    getline(cin, enemy);
    getline(cin, gregor);

    int ans = 0;

    for (int i = 0; i < n; i++)
    {
        if (gregor[i] == '1')
        {
            if (i-1 > 0 && enemy[i-1] == '1')
            {
                ans++;
                enemy[i-1] = '2';
            }
            else if (i+1 < n && enemy[i+1] == '1')
            {
                ans++;
                enemy[i+1] = '2';
            }
            else if (enemy[i] == '0')
            {
                ans++;
            }
        }
    }
    cout << ans << endl;

}
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
    }
}
