/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize)
{
    int n = strlen(boxes);
    
    int* answer = (int*)malloc(sizeof(int) * n);
    *returnSize = 0;
    for(int i = 0; i < n; i++)
    {
        answer[i] = 0;
        int count = 0;
        for(int j = 0; j < n; j++)
        {
            if(boxes[j] == '1')
            {
                count += abs(j - i);
            }
        }
        answer[*returnSize] = count;
        (*returnSize)++;
    }
    return answer;  
}
