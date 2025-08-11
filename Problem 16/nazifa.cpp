class Solution
{
public:
    using ll = long long;

    int shipWithinDays(vector<int>& weights, int d)
    {
        int n = weights.size();
        ll sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += weights[i];
        }

        ll l = *max_element(weights.begin(), weights.end()) - 1;
        ll r = sum + 1;

        while (r - l > 1)
        {
            ll mid = (l + r) / 2;
            ll total = 0;
            ll day = 1;

            for (int i = 0; i < n; i++)
            {
                if (weights[i] + total <= mid)
                {
                    total += weights[i];
                }
                else
                {
                    day++;
                    total = weights[i];
                }
            }

            if (day <= d)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }

        return static_cast<int>(r);
    }
};
