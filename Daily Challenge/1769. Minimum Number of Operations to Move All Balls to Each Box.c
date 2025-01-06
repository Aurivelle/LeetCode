/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* minOperations(char* boxes, int* returnSize)
{
    int n = strlen(boxes);
    int count = 0;
    int left[n];
    left[0] = 0;
    if(boxes[0] == '1')
    {
        count++;
    }
    for(int i = 1; i < n; i++)
    {
        left[i] = left[i - 1] + count;
        if(boxes[i] == '1')
        {
            count++;
        }
    }
    count = 0;
    int right[n];
    right[n - 1] = 0;
    if(boxes[n - 1] == '1')
    {
        count++;
    }
    for(int i = n - 2; i >= 0; i--)
    {
        right[i] = right[i + 1] + count;
        if(boxes[i] == '1')
        {
            count++;
        }
    }
    int* answer = (int*)malloc(sizeof(int) * n);
    for(int i = 0; i < n; i++)
    {
        answer[i] = left[i] + right[i];
    }
    *returnSize = n;
    return answer;
}
