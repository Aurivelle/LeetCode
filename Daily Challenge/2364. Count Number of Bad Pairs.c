typedef struct
{
    int key;
    int count;
    UT_hash_handle hh;
} HashMap;
long long countBadPairs(int* nums, int numsSize) 
{
    HashMap* freq_map = NULL;
    long long good_pairs = 0;
    for(int i = 0; i < numsSize; i++)
    {
        int key = nums[i] - i;
        HashMap* entry;
        HASH_FIND_INT(freq_map, &key, entry);

        if(entry)
        {
            good_pairs += entry->count;
            entry->count++;
        }
        else
        {
            entry = (HashMap*)malloc(sizeof(HashMap));
            entry->key = key;
            entry->count = 1;
            HASH_ADD_INT(freq_map, key, entry);
        }
    }
    HashMap* current;
    HashMap* tmp;
    HASH_ITER(hh, freq_map, current, tmp)
    {
        HASH_DEL(freq_map, current);
        free(current);
    }
    long long total_pairs = (long long)numsSize * (long long)(numsSize - 1) / 2;
    return total_pairs - good_pairs;
}
