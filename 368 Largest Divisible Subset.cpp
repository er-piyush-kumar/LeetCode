class Solution {
public:

    void solve(vector<int> &nums,vector<int> &temp,int index,vector<int> &ans)
    {
        //base case
        if(index>=nums.size())
        {
            if(temp.size()>ans.size())
                ans = temp;
            return;
        }

        //Processing

        //take
        if(temp.empty() or (nums[index]%temp.back())==0)
        {
            temp.push_back(nums[index]); //take
            solve(nums,temp,index+1,ans);
            temp.pop_back();  //for Not take
        }

        // Not take
        solve(nums,temp,index+1,ans);
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        sort(begin(nums),end(nums));
        vector<int> ans;
        vector<int> temp;

        solve(nums,temp,0,ans);

        return ans;
    }
};


//Time Complexity : O(2^n)
//Space Complexity : O(n)
