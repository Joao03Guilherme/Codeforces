#include <bits/stdc++.h>
using namespace std;
typedef long long int lli;
typedef vector<int> vi;

void ans(void)
{
    int m, n; cin >> n >> m;
    vi f(n);
    unordered_map <int, int> c;
    for (int i = 0; i < n; i++)
    {
        cin >> f[i];
        c[f[i]] = i;
    }

    // Verificar restrições a m
    if (!(m>2 && m>=n)){
        cout << -1 << "\n";
        return;
    }

    int ans = 0;
    // Ligar os vértices todos
    for (int i = 0; i < n; i++)
    {
        ans += f[i] + f[(i+1)%n];
        m--;
    }

    if (m < 0) {cout << -1 << "\n"; return;}

    sort(f.begin(), f.end());
    while(m--){
        ans += f[0] + f[1];
        cout << c[f[0]] + 1 << " " << c[f[1]] + 1 << "\n";
    }

    cout << ans << "\n";
    for (int i = 0; i < n; i++)
        cout << i+1 << " " << (i+1)%n + 1 << "\n";
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T; cin>>T;
    while(T--) ans();

    return 0;
}
