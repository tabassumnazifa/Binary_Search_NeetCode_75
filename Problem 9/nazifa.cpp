class Solution
{
public:
    vector<int> successfulPairs(vector<int>& spell, vector<int>& potion, long long s)
    {
        int n = spell.size();
        int m = potion.size();
        vector<int> vec;

        sort(potion.begin(), potion.end());

        for (int i = 0; i < n; i++)
        {
            int l = -1, r = m;
            while (r - l > 1)
            {
                int mid = (l + r) / 2;
                if ((long long)potion[mid] * spell[i] >= s)
                {
                    r = mid;
                }
                else
                {
                    l = mid;
                }
            }
            int res = m - r;
            vec.push_back(res);
        }

        return vec;
    }
};
