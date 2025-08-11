class Solution
{
public:
    int maximumCandies(vector<int>& vec, long long k)
    {
        int n = (int)vec.size();
        int l = 0, r = *max_element(vec.begin(), vec.end()) + 1;

        while (r - l > 1)
        {
            int mid = (l + r) / 2;
            long long res = 0;
            for (int i = 0; i < n; i++)
            {
                res += vec[i] / mid;
            }
            if (res >= k)
            {
                l = mid;
            }
            else
            {
                r = mid;
            }
        }
        return l;
    }
};
