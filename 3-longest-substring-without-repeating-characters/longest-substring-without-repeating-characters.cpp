class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        int hash[256] = {0};

        int l = 0;
        int h = 0;

        int mlen = 0;

        while(h < s.size())
        {
            if(hash[s[h]] == 1)
            {
                hash[s[l]] = 0;
                l++;
                continue;
            }

            hash[s[h]] = 1;
            h++;

            mlen = max(mlen, h - l);
        }

        return mlen;
    }
};