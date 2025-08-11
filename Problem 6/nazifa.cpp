class Solution
{
public:
    int mySqrt(int x)
    {
        if (x < 2) return x;

        long long left = 0, right = x;

        while (right - left > 1)
        {
            long long mid = (left + right) / 2;
            if (mid * mid <= x)
            {
                left = mid;
            }
            else
            {
                right = mid;
            }
        }

        return (int)left;
    }
};
