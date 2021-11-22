#include <bits/stdc++.h>
using namespace std;

void solve(void)
{
    int n;
    string N;
    cin >> n;
    cin >> N;

    bool par = false, impar = false;
    for (int i = 0; i < n; i++){
        if ((int)N[i] % 2 == 0 && (i+1)%2 == 0){
            par = true;
        }
        else if ((int)N[i] % 2 != 0 && (i+1)%2 != 0){
            impar = true;
        }
    }

    if (n%2 == 0){
        if (par){
            cout << 2 << endl;
        } else {cout << 1 << endl;}
    }
    else {
        if (impar){
            cout << 1 << endl;
        } else {cout << 2 << endl;}
    }
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int t;
    cin >> t;

    while(t--){
        solve();
    }
    return 0;
}
