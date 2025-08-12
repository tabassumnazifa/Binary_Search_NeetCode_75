class Solution
{
public:
    int minDays(vector<int>& bloom, int m, int k)
    {
        int n = bloom.size();
        if ((long long)m * k > n) return -1;

        int low = *min_element(bloom.begin(), bloom.end());
        int high = *max_element(bloom.begin(), bloom.end()) + 1;

        while (high - low > 1)
        {
            int mid = (low + high) / 2;
            int cnt = 0, total = 0;
            for (int i = 0; i < n; i++)
            {
                if (bloom[i] <= mid)
                {
                    cnt++;
                }
                else
                {
                    total += cnt / k;
                    cnt = 0;
                }
            }
            total += cnt / k;
            if (total >= m)
            {
                high = mid;
            }
            else
            {
                low = mid;
            }
        }

        return high;
    }
};
