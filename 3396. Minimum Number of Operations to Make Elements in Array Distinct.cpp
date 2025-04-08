//First Method -> BruteForce

class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        int count = 0;

        unordered_map<int,int> mp;
        for(int i = 0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }

        int i = 0;
        while(i<nums.size())
        {
            if(mp[nums[i]]>1)
            {
                count++;

                if(nums.size()<3)
                    break;
                else 
                {
                    int j = 0;
                    while(j<3 and j<nums.size())
                        mp[nums[j++]]--;
                    nums.erase(nums.begin(),nums.begin()+3);
                    i = -1;
                }
            }
            i++;
        }
        return count;
    }
};

//Time COmplexity : O(n)
//Space Complexity : O(n)



// Second Method -> OPtimised
class Solution {
public:
    int minimumOperations(vector<int>& nums) 
    {
        vector<int> temp(101,0);
        int last_index = 0;
        for(int i = nums.size()-1;i>=0;i--)
        {
            if(temp[nums[i]]>0)
            {
                last_index = i+1;
                break;
            }
            else
                temp[nums[i]]++;
        }

        if(last_index%3==0)
            return last_index/3;
        else
            return last_index/3 + 1;
    }
};

//Time Complexity : O(n)
//space Complexity : O(1)
