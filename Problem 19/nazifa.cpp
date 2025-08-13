#include <bits/stdc++.h>
using namespace std;

int main()
{
    int N, B;
    cin >> N >> B;
    vector<int> A(N);
    for (int i = 0; i < N; i++) cin >> A[i];

    if (B > N)
    {
        cout << -1;
        return 0;
    }

    int low = *max_element(A.begin(), A.end());
    int high = accumulate(A.begin(), A.end(), 0);
    int ans = high;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int studentCount = 1;
        int pageSum = 0;
        bool possible = true;

        for (int i = 0; i < N; i++)
        {
            if (pageSum + A[i] > mid)
            {
                studentCount++;
                pageSum = A[i];
                if (studentCount > B)
                {
                    possible = false;
                    break;
                }
            }
            else
            {
                pageSum += A[i];
            }
        }

        if (possible)
        {
            ans = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    cout << ans;
    return 0;
}

