#define MAX_N 1000
bool canSplit(char* num_str, int target, int index, int current_sum)
{
    int length = strlen(num_str);
    if(index == length)
    {
        return current_sum == target;
    }

    int part = 0;
    for(int i = index; i < length; i++)
    {
        part = part * 10 + (num_str[i] - '0');

        if(canSplit(num_str, target, i + 1, current_sum + part))
        {
            return true;
        }
    }
    return false;

}


int punishmentNumber(int n) 
{
    int total = 0;
    char square_str[20];

    for(int i = 1; i <= n; i++)
    {
        int square = i * i;
        sprintf(square_str, "%d", square);

        if(canSplit(square_str, i, 0, 0))
        {
            total += square;
        }
    }
    return total;


}
