int dfs(int hash[])
{
    int total = 0;
    for(int i = 0; i < 26; i++)
    {
        if(hash[i] > 0)
        {
            total++;
            hash[i]--;
            total += dfs(hash);
            hash[i]++;
        }
    }
    return total;
}

int numTilePossibilities(char* tiles) 
{
    int len = strlen(tiles);
    int hash[26] = {0};
    for(int i = 0; i < len; i++)
    {
        hash[tiles[i] - 'A']++;
    }
    return dfs(hash);
}
