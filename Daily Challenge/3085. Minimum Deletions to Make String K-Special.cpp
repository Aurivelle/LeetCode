class Solution {
public:
    int minimumDeletions(string word, int k) {
        int freq[26] = {0};
        int len = word.length();
        for(int i = 0; i < len; i++)
        {
            freq[word[i] - 'a']++;
        }
        int min = INT_MAX;
        for(int i = 0; i < 26; i++)
        {
            int sum = 0;
            if(freq[i] == 0)
            {
                continue;
            }
            for(int j = 0; j < 26; j++)
            {
                if(freq[j] < freq[i])
                {
                    sum += freq[j];
                }
                else if(freq[j] > freq[i] + k)
                {
                    sum += freq[j] - freq[i] - k;
                }
            }
            if(sum < min)
            {
                min = sum;
            }
            
        }
        return min;
        
    }
};
