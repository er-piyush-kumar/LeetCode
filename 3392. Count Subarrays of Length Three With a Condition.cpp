//Sliding Window Approach

class Solution {
public:
    int countSubarrays(vector<int>& nums) 
    {
        int count = 0;

        int i = 0;
        int j = 2;

        while(j<nums.size())
        {
            float sum = nums[i] + nums[j];
            float middle = nums[(i+j)/2];

            if(sum==middle/2)
                count++;  
                
            i++;
            j++;
        }
        return count;
    }
};

//TC : O(n)
//SC : O(1)
