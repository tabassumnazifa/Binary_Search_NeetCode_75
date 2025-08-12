#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t;
    cin >> t;
    while (t--)
    {
        int n,k;
        cin >> n>>k;
        vector<ll> cow(n);
        for (int i = 0; i < n; i++)
            cin >> cow[i];

        sort(cow.begin(), cow.end());

        ll lo = 0, hi = 1e9 + 5;
        while (hi - lo > 1)
        {
            ll mid = lo + (hi - lo) / 2;
            int goru = 1;
            ll prothomgoru = cow[0];

            for (int i = 1; i < n; i++)
            {
                if (cow[i] - prothomgoru >= mid)
                {
                    goru++;
                    prothomgoru = cow[i];
                }
            }

            if (goru >= k)
                lo = mid;
            else
                hi = mid;
        }
        cout << lo << "\n";
    }

    return 0;
}
