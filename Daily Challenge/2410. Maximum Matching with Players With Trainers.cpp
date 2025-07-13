class Solution {
public:
    int matchPlayersAndTrainers(vector<int>& players, vector<int>& trainers) 
    {
        sort(players.begin(), players.end());
        sort(trainers.begin(), trainers.end());   

        int a = players.size();
        int b = trainers.size(); 

        int i = 0;
        int j = 0;
        int sum = 0;
         
        while(i < a && j < b)
        {
            if(players[i] <= trainers[j])
            {
                ++sum;
                ++i;
                ++j;
            }
            else
            {
                j++;
            }
        }
        return sum;
    }
};
