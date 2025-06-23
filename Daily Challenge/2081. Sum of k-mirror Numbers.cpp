class Solution {
public:
    bool isPalindrome(const string& s)
    {
        int l = 0;
        int r = s.length() - 1;
        while(l < r)
        {
            if(s[l++] != s[r--])
            {
                return false;
            }
        }
        return true;
    }
    string toBaseK(long long n, int k)
    {
        string res;
        while(n > 0)
        {
            res += char('0' + (n % k));
            n /= k;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    long long createPalindrome(int base, bool odd)
    {
        string s = to_string(base);
        string rev = s;
        if(odd)
        {
            rev.pop_back();
        }
        reverse(rev.begin(), rev.end());
        return stoll(s + rev);
    }
    long long kMirror(int k, int n) {
        long long ans = 0;
        int count = 0;
        int len = 1;
        while(count < n)
        {
            int halfLen = (len + 1) / 2;
            long long start = (len == 1)? 1 : pow(10, halfLen - 1);
            long long end = pow(10, halfLen);
            for(long long prefix = start; prefix < end && count < n; ++prefix)
            {
                long long pal = createPalindrome(prefix, len % 2);
                if(isPalindrome(toBaseK(pal, k)))
                {
                    ans += pal;
                    count++;
                }

            }
            len++;
        }
        return ans;
    }
};
