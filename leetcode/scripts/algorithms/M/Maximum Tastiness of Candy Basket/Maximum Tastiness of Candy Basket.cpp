class Solution
{
public:
    bool isPossible(vector<int> &p, int minDist, int k)
    {
        int take = 1; 
        int lastCowPosition = p[0];
        for (int i = 1; i < p.size(); i++)
        {
            if (p[i] - lastCowPosition >= minDist)
            {
                take++;
                lastCowPosition = p[i];
                if (take >= k)
                    return true;
            }
        }
        return false;
    }
    int maximumTastiness(vector<int> &p, int k)
    {
        int n = p.size();
        sort(p.begin(), p.end());
        int l = 1, h = p[n - 1] - p[0];
        int ans = 0;
        while (l <= h)
        {
            int m = (l + h) / 2;
            if (isPossible(p, m, k))
            {
                ans = m;
                l = m + 1;
            }
            else
                h = m - 1;
        }
        return ans;
    }
};