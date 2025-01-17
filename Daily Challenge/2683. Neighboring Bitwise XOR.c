bool doesValidArrayExist(int* derived, int derivedSize) 
{
    int count = derived[0];
    for(int i = 1; i < derivedSize; i++)
    {
        count ^= derived[i];
    }
    return !count;
}
