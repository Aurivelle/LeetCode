
int minimumRecolors(char* blocks, int k) 
{
    int len = strlen(blocks);
    int white = 0;
    for(int i = 0; i < k; i++)
    {
        if(blocks[i] == 'W')
        {
            white++;
        }
    }
    int current = white;
    for(int i = k; i < len; i++)
    {
        if(blocks[i - k] == 'W')
        {
            current--;
        }
        if(blocks[i] == 'W')
        {
            current++;
        }
        white = current < white ? current : white;
    }
    return white;
}
