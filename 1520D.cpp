#include <bits/stdc++.h>

using namespace std;

int main()
{
    // Fast I/O
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;
        int a[n];
        unordered_map <int, int> mp;
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
            if (!mp[a[i] - i])
            {
                mp[a[i] - i] = 1;
            }
            else
            {
                mp[a[i] - i]++;
            }
        }

        long long int pairs = 0;
        for (int i = 0; i < n; i++)
        {
            if (mp[a[i] - i])
            {
                mp[a[i] - i]--;
                if (mp[a[i] - i] > 0)
                {
                    pairs += mp[a[i] - i];
                }
            }
        }
        cout << pairs << "\n";
    }
}
