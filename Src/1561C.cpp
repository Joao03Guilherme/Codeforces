#include <bits/stdc++.h>
using namespace std;

/*
    A IDEIA DESTE EXERCÍCIO É PRIMEIRO CALCULAR O PODER MÍNIMO PARA CADA CAVE
    DEPOIS ORDENA-SE AS CAVES E ENCONTRA-SE O PODER MÍNIMO PARA AS EXPLORAR
*/

// ALGUMA COISA ESTÁ ERRADA COM ISTO


void solve()
{
    int N;
    cin >> N;

    vector <int> caves[N];
    int K;
    int KI;
    for (int i = 0; i < N; i++){
        cin >> K;
        for (int j = 0; j < K; j++){
            cin >> KI;
            caves[i].push_back(KI);
        }
    }

    int real[N];
    for (int i = 0; i < N; i++)
    {
        int power = 0;
        int j = 0;
        for (int armour: caves[i]){
            power = max(power, armour - j);
            j++;
        }
        real[i] = power;
    }

    sort(real, real+N);

    int sum = 0;
    int power = 0;
    for (int i = 0; i < N; i++){
        power = max(real[i]-sum, power);
        sum += real[i];
    }

    cout << power + 1 << "\n";
}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int T;
    cin >> T;

    while(T--)
    {
        solve();
    }
    return 0;
}
