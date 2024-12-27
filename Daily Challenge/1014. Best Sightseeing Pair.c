int max(int a, int b)
{
    return a > b ? a : b;
}
int maxScoreSightseeingPair(int* values, int valuesSize)
{
    int prev = values[valuesSize - 1] - (valuesSize - 1);
    int cur = INT_MIN;
    int maxx = INT_MIN;
    for(int i = valuesSize - 2; i >= 0; i--)
    {
        cur = max(prev, cur);
        prev = values[i] - i;
        int score = values[i] + i + cur;
        if(score > maxx)
        {
            maxx = score;
        }
    }
    return maxx;
}
