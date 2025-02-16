/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
bool build(int index, int length, int n, int* result, int* hash)
{
    if(index == length)
    {
        return true;
    }
    if(result[index] != 0)
    {
        return build(index + 1, length, n, result, hash);
    }
    for(int i = n; i > 0; i--)
    {
        if(hash[i] != 0)
        {
            continue;
        }

        if(i == 1)
        {
            result[index] = 1;
            hash[1]++;
            if(build(index + 1, length, n, result, hash))
            {
                return true;
            }
            result[index] = 0;
            hash[1]--;
        }
        else
        {
            if(index + i < length && result[index + i] == 0)
            {
                result[index] = result[index + i] = i;
                hash[i] += 2;
                if(build(index + 1, length, n, result, hash))
                {
                    return true;
                }
                result[index] = result[index + i] = 0;
                hash[i] -= 2;
            }
            
            
        }
    }
    return false;
}

int* constructDistancedSequence(int n, int* returnSize) 
{
    int length = 2 * n - 1;
    int* result = (int*)malloc(sizeof(int) * length);
    for(int i = 0; i < length; i++)
    {
        result[i] = 0;
    }
    *returnSize = length;
    int* hash = (int*)malloc(sizeof(int) * (n + 1));
    for(int i = 0; i <= n; i++)
    {
        hash[i] = 0;
    }
    build(0, length, n, result, hash);
    free(hash);
    return result;

}
