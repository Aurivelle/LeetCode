int lengthOfLongestSubstring(char* s) 
{
    int len = strlen(s);
    if(!len)
    {
        return 0;
    }
    int left = 0;
    int right = 0;
    int max = 1;
    int map[255] = {0};
    map[s[left]] = 1;
    while(right < len - 1)
    {
        if(map[s[right + 1]] == 1)
        {
            
            while(left < right && s[left] != s[right + 1])
            {
                map[s[left]] = 0;
                left++;
            }
            map[s[left]] = 0;
            left++;
        }
        else
        {
            right++;
            map[s[right]] = 1;
        }
        if(max < right - left + 1)
        {
            max = right - left + 1;
        }
    }
    return max;
}
