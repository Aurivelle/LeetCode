class Solution {
public:
    int longestSubsequence(string s, int k) 
    {
        int ans = 0;
        for(char c : s)
        {
            if(c =='0')
            {
                ans++;
            }
        }
        int sum = 0;
        for(int i = s.length() - 1; i >= 0; --i)
        {
            if(s[i] == '1')
            {
                if(pow(2, s.length() - 1 - i) > k)
                {
                    break;
                }
                int exp = pow(2, s.length() - 1 - i);
                if(sum + exp <= k)
                {
                    ans++;
                    sum += exp;
                }
            }
        }
        return ans;


    }
};
