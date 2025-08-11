class Solution
{
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        auto lb = lower_bound(nums.begin(), nums.end(), target);
        if (lb == nums.end() || *lb != target)
        {
            return {-1, -1};
        }
        int start = lb - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin() - 1;
        return {start, end};
    }
};
