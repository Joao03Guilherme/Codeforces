#include <bits/stdc++.h>
using namespace std;


void solve()
{
    int a,b,c;
    cin >> a >> b >> c;
    int diff = abs(a-b);
    int n_max = 2*diff;

    // Verificar se o cícrulo é válido
    if (max(a, b) > n_max){
        cout << "-1" << "\n";
    }
    else if (c - diff > 0 && c - diff <= n_max){
        cout << c - diff << "\n";
    }
    else if (c + diff <= n_max){
        cout << c + diff << "\n";
    }
    else {
        cout << "-1" << "\n";
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);


    int T;
    cin >> T;
    while(T--){
        solve();
    }
    return 0;
}
