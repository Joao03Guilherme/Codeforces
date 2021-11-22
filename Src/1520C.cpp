#include <bits/stdc++.h>

using namespace std;

void preencher(int n)
{
    if (n == 2)
    {
        cout << -1 << endl;
        return;
    }
    int matriz[n][n] = {0};

    // Preencher os índices pares
    int last = 1;
    for (int i = 0; i < n*n; i++)
    {
        if (i%2 == 0)
        {
            matriz[i/n][i%n] = last;
            last++;
        }
    }

    // Preencher os indices impares
    for (int i = 0; i < n*n; i++)
    {
        if (i%2 != 0)
        {
            matriz[i/n][i%n] = last;
            last++;
        }
    }

    for (int i = 0; i< n; i++)
    {
        for (int  j = 0; j < n; j++)
        {
            cout << matriz[i][j] << " ";
        }
        cout <<  "\n";
    }

}

int main()
{
    ios_base::sync_with_stdio(false);

    int T;
    cin >> T;

    while(T--)
    {
        int n;
        cin >> n;
        preencher(n);
    }
}
