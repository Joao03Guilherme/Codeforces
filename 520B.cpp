#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;

/*
    Se n > m, subtrair até n == m
    Se n < m, fazer bfs com a árvore

    Either way, dá para fazer bfs nos dois
    UPDATE THIS CODE!

*/

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int n, m; cin >> n >> m;
    if (n >= m) {cout << n - m << "\n"; return 0;}
    queue <int> q; vi d(2*m+1, 0); vi v(2*m+1, 0);
    q.push(n);
    while(!q.empty())
    {

        int curr = q.front(); q.pop();

        v[curr] = 1;
        if (curr == m) break;

        if (curr < m && !v[curr*2]) {
            q.push(curr*2);
            if (!d[curr*2]) d[curr*2] = d[curr] + 1; // Connected branches
        }

        if (curr > 0 && !v[curr-1]) {
            q.push(curr-1);
            if (!d[curr-1]) d[curr-1] = d[curr] + 1;
        }
    }
    cout << d[m] << endl;
    return 0;
}
