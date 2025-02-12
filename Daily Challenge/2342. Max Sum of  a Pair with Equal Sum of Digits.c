typedef struct
{
    int key;
    int value;
    UT_hash_handle hh;
} HashMap;

int maximumSum(int* nums, int numsSize) 
{
    HashMap* map = NULL;
    
    HashMap* tmp;
    int max = -1;
    for(int i = 0; i < numsSize; i++)
    {
        int original = nums[i];
        int sum = 0;
        HashMap* entry;
        while(nums[i] > 0)
        {
            sum += (nums[i] % 10);
            nums[i] /= 10;
        }
        HASH_FIND_INT(map, &sum, entry);
        if(entry == NULL)
        {
            HashMap* entry = (HashMap*)malloc(sizeof(HashMap));
            entry->key = sum;
            entry->value = original;
            HASH_ADD_INT(map, key, entry);
        }
        else
        {
            max = max > entry->value + original ? max : entry->value + original;
            if(original > entry->value)
            {
                entry->value = original;
            }
        }
    }
    return max;
}
