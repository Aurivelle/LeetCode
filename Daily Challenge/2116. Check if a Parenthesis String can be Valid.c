bool canBeValid(char* s, char* locked) 
{
    int len = strlen(s);
    if(len % 2)
    {
        return false;
    }

    int count = 0;
    for(int i = 0; i < len; i++)
    {
        if(s[i] == '(' || locked[i] == '0')
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count < 0)
        {
            return false;
        }
    }
    count = 0;    
    for(int i = len - 1; i >= 0; i--)
    {
        if(s[i] == ')' || locked[i] == '0')
        {
            count++;
        }
        else
        {
            count--;
        }
        if(count < 0)
        {
            return false;
        }
    }
    return true;
}
