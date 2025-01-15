int minimizeXor(int num1, int num2) 
{
    int count2 = 0;
    for(int i = num2; i > 0; i >>= 1)
    {
        count2 += (i & 1);
    }    
    int x = 0;
    for(int i = 31; i >= 0 && count2 > 0; i--)
    {
        if(num1 & (1U << i))
        {
            x |= (1 << i);
            count2--;
        }
    }
    for(int i = 0; i <= 31 && count2 > 0; i++)
    {
        if(!(x & (1 << i)))
        {
            x |= (1 << i);
            count2--;
        }
    }
    return x;
}
