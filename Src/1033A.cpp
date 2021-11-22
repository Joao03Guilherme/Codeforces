#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
using vi = vector<int>;

// Complexity O(1)
/*
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int n; cin >> n;
    pair <int, int> a; cin >> a.first >> a.second;
    pair <int, int> b; cin >> b.first >> b.second;
    pair <int, int> c; cin >> c.first >> c.second;

    // Check if both are in same quadrant
    if ((b.first < a.first) == (c.first < a.first))
    {
        if ((b.second < a.second) == (c.second < a.second))
        {
            cout << "YES" << "\n"; return 0;
        }
    }
    cout << "NO" << "\n";
    return 0;
}
*/


// Complexity O(N^2)
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    pair <int, int> a; cin >> a.first >> a.second;
    pair <int, int> b; cin >> b.first >> b.second;
    pair <int, int> c; cin >> c.first >> c.second;

    // Fazer bfs
    queue <pair<int, int>> q; q.push(b);
    int x[n+2]; memset(x, 0, sizeof(x));
    int y[n+2]; memset(y, 0, sizeof(y));
    while (!q.empty()){
        pair <int, int> p = q.front(); q.pop();
        x[p.first] = 1; y[p.second] = 1;

        // Check if found
        if (p.first == c.first && p.second == c.second)
        {
            cout << "YES" << "\n"; return 0;
        }

        for (int i = -1; i <= 1; i++)
        {
            for (int j = -1; j <= 1; j++)
            {
                if (!i && !j) continue; // A posição n muda
                if ((p.first+j==0 || p.second+i==0) || (p.first+j==n-1 || p.second+i==n-1)) continue; // Margens
                if (p.first+j == a.first || p.second+i == a.second) continue; // Mesma linha ou coluna
                if ((p.first+j)-(p.second+i) == a.first-a.second) continue; // Quadrantes impares
                if ((p.first+j)+(p.second+i) == a.first-a.second) continue; // Quadrantes pares
                if (x[p.first+j] && y[p.second+i]) continue; // Já foi visitado

                q.push({p.first+i, p.second+j});
            }
        }
    }

    cout << "NO" << "\n";
    return 0;
}
