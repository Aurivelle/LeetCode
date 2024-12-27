int maxScoreSightseeingPair(int* values, int valuesSize)
{
    int max = INT_MIN;
    for(int i = 0; i < valuesSize - 1; i++)
    {
        for(int j = i + 1; j < valuesSize; j++)
        {
            int score = values[i] + values[j] + i - j;
            if(score > max)
            {
                max = score;
            }
        }
    }
    return max;    
}
