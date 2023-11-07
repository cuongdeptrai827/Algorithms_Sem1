#include <iostream>
using namespace std;

int main()
{
    unsigned int n, m, q, mua, tap, k = 0;
    cin >> n >> m >> q;

    bool Array[n + 1][m + 1] = {false};

    for (int i = 0; i < q; i++)
    {
        cin >> tap >> mua;
        if (!Array[mua][tap])
        {
            k++;
        }
        Array[mua][tap] = true;
    }

    cout << (m * n - k) << "\n";

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (!Array[i][j])
            {
                cout << j << " " << i << "\n";
            }
        }
    }

    return 0;
}