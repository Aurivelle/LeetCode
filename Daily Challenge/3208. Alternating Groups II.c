int numberOfAlternatingGroups(int* colors, int colorsSize, int k) 
{
    int ans = 0;
    int count = 0;
    for(int i = 0; i < 2 * colorsSize; i++)
    {
        if(i > 0 && colors[i % colorsSize] == colors[(i - 1) % colorsSize])
        {
            count = 1;
        }
        else
        {
            count++;
        }
        if(i >= colorsSize && count >= k)
        {
            ans++;
        }
    }   
    return ans;
}
