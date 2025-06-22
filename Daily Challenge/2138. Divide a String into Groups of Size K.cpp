class Solution {
public:
    vector<string> divideString(string s, int k, char fill) 
    {
        vector<string> ans;
        string current;
        for(char c : s)
        {
            current += c;
            if(current.size() == k)
            {
                ans.push_back(current);
                current.clear();
            }
        }
        if(!current.empty())
        {
            current.append(k - current.size(), fill);
            ans.push_back(current);
        }
        return ans;
    }
};
