//Question : https://leetcode.com/problems/partition-equal-subset-sum/description/

class Solution {
public:

    bool solve(vector<int> &nums,int index,int x,vector<vector<int>> &memo)
    {
        if(x==0)
            return true;
        
        if(index>=nums.size())
            return false;

        if(memo[index][x]!=-1)
            return memo[index][x];

        bool take = false;
        if(nums[index]<=x)
            take = solve(nums,index+1,x-nums[index],memo);
        
        bool not_take = solve(nums,index+1,x,memo);

        return memo[index][x] = (take || not_take);
    }

    bool canPartition(vector<int>& nums) 
    {
        int sum = accumulate(begin(nums),end(nums),0);
        if(sum%2!=0)
            return false;
        else
        {
            int n = nums.size();
            int x = sum/2;
            vector<vector<int>> memo(n+1,vector<int>(x+1,-1)); 
            
            return solve(nums,0,x,memo);
        }
        
    }
};

// x = sum/2

//Time oOmplexity : O(n*x)
//Space Complexity : O(n*x)
