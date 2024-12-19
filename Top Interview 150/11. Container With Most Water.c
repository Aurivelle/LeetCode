int min(int a, int b)
{
    return a < b? a : b;
}
int max(int a, int b)
{
    return a > b? a : b;
}
int maxArea(int* height, int heightSize) 
{
    int left = 0;
    int right = heightSize - 1;
    int ret = INT_MIN;
    while(left < right)
    {
        int min_height = min(height[left], height[right]);
        ret = max(ret, min_height * (right - left));
        if(height[left] > height[right])
        {
            right--;
        }
        else
        {
            left++;
        }
    }
    return ret;
}
