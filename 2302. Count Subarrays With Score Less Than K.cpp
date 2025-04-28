//Sliding Window Approach

class Solution {
public:
    long long countSubarrays(vector<int>& nums, long long k) 
    {
        int n = nums.size();
        long long count = 0;
        int i=0,j=0;

        long long sum = 0;

        while(j<n)
        {
            sum+=nums[j];
            int l = j-i+1;

            while((sum*l)>=k and i<=j)
            {
                sum-=nums[i];
                i++;
                l--;
            }

            count += l;
            j++;
        }
        return count;
    }
};

//TC : O(2*n) Every element visit two times;
//SC : O(1)
