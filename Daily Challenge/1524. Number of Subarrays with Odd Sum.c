int numOfSubarrays(int* arr, int arrSize) 
{
    int odd = 0;
    int even = 1;
    int sum = 0;
    long long answer = 0;
    int mod = 1000000007;
    for(int i = 0; i < arrSize; i++)
    {
        sum += arr[i];
        if(sum % 2)
        {
            answer = (answer % mod + even % mod) % mod;
            odd++;
        }
        else
        {
            answer = (answer % mod + odd % mod) % mod;
            even++;
        }
        
    }
    return answer;
}
