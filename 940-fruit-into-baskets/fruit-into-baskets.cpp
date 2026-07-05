class Solution {
public:
    int totalFruit(vector<int>& f) 
    {
        map<int, int> b;
        int l = 0, h = 0;
        int ans = 0;

        while (h < f.size())
        {
            b[f[h]]++;

            while (b.size() > 2)
            {
                b[f[l]]--;

                if (b[f[l]] == 0)
                    b.erase(f[l]);

                l++;
            }

            ans = max(ans, h - l + 1);
            h++;
        }

        return ans;
    }
};