#include <bits/stdc++.h>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while(T--)
    {
        int n;
        cin >> n;

        vector <int> a;
        vector <int> b;

        long long soma = 0;
        // Mapa para guardar os Xs
        unordered_map <int, int> mp; // (Elemento, last indice)

        int hold;
        for (int i = 0; i < n+2; i++)
        {
            cin >> hold;
            b.push_back(hold);

            soma += b[i];
            mp[b[i]] == i;
        }

        for (int i = 0; i < n+2; i++)
        {
            // SE existe o x e este é diferente do atual
            if (mp.count(soma - b[i]) > 0 && mp[soma - b[i]] != i)
            {
                int in = mp[soma - b[i]];
                b.erase(b.begin() + in);
                b.erase(b.begin() + i);
                for (int j = 0; j < b.size(); j++)
                {
                    a.push_back(b[i]);
                }
            }
        }

        if (a.size() > 0)
        {
            for (int i = 0; i< a.size(); i++)
            {
                cout << a[i] << " ";
            }
        }
        else
        {
            cout << -1 << endl;
        }
    }
}
