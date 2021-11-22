#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    int N;
    cin >> N;

    int paridade[2] = {0,0};
    int par = 0;
    int hold;
    for (int i = 0; i < N; i++)
    {
        cin >> hold;
        paridade[hold%2] = i+1;
        if (hold%2 == 0)
        {
            par++;
        }
    }

    if (par == 1)
    {
        cout << paridade[0] << "\n";
    }
    else {
        cout << paridade[1] << "\n";
    }
}
