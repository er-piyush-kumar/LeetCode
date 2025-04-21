class Solution {
public:
    int numberOfArrays(vector<int>& diff, int l, int u) 
    {
        int n = diff.size();
        int curr = 0;
        int minVal = 0;
        int maxVal = 0;

        for(int i = 0;i<n;i++)
        {
            curr = curr + diff[i];
            minVal = min(minVal,curr);
            maxVal = max(maxVal,curr);

            if((u - maxVal) - (l-minVal) +1 <= 0)
                return 0;

        }
        return (u - maxVal) - (l-minVal) +1;
    }
};

//TC : O(n)
//SC : O(1)
