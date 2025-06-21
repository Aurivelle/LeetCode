class Solution {
public:
    int minimumDeletions(string word, int k) {
        std::array<int, 26> freq = {0};
        for(char c : word)
        {
            freq[c - 'a']++;
        }
        int minimum = std::numeric_limits<int>::max();
        for(int base : freq)
        {
            if(base == 0)
            {
                continue;
            }
            int deletion = 0;
            for(int f : freq)
            {
                if(f < base)
                {
                    deletion += f;
                }
                else if(f > base + k)
                {
                    deletion += f - base - k;
                }
            }
            minimum = std::min(minimum, deletion);
        }
        return minimum;
        
    }
};
