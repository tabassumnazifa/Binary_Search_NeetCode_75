class Solution
{
public:
    typedef long long ll;

    int minEatingSpeed(vector<int>& piles, int h)
    {
        ll l = 0;
        ll r = *max_element(piles.begin(), piles.end());

        while (r - l > 1)
        {
            ll mid = (l + r) / 2;
            ll total = 0;
            for (ll p : piles)
            {
                total += (p + mid - 1) / mid;
                if (total > h) break;
            }
            if (total <= h)
            {
                r = mid;
            }
            else
            {
                l = mid;
            }
        }
        return (int)r;
    }
};
