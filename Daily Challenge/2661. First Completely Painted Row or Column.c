int firstCompleteIndex(int* arr, int arrSize, int** mat, int matSize, int* matColSize) 
{
    int row_count[matSize];
    int col_count[*matColSize];
    for(int i = 0; i < matSize; i++)
    {
        row_count[i] = 0;
    }
    for(int i = 0; i < *matColSize; i++)
    {
        col_count[i] = 0;
    }
    for(int i = 0; i < arrSize; i++)
    {
        for(int j = 0; j < matSize; j++)
        {
            for(int k = 0; k < *matColSize; k++)
            {
                if(arr[i] == mat[j][k])
                {
                    row_count[j]++;
                    col_count[k]++;
                }
                if(row_count[j] == *matColSize || col_count[k] == matSize)
                {
                    return i;
                }
            }
        }
    }
    return -1;
    

}
