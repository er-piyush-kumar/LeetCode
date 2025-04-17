class Solution {
public:
    int countPairs(vector<int>& nums, int k) 
    {
        int count = 0;
        
        //store all the indices of equal elements
        unordered_map<int,vector<int>> indexmap;
        for(int i = 0;i<nums.size();i++) //O(n)
        {
            indexmap[nums[i]].push_back(i);
        }

        //store all the factors of k
        unordered_set<int> fact;
        for(int f = 1;f*f<=k;f++) //O(sqrt(k))
        {
            if(k%f==0)
            {
                fact.insert(f);
                fact.insert(k/f);
            }

        }

        //check every number
        for(auto &[num,indices] : indexmap) //O(n)
        {
            unordered_map<int,int> factmap;
            for(auto &i : indices)
            {
                int GCD = gcd(i,k); //log(k)
                int j = k/GCD;
                
                //if j is already stored --> pair exist
                count += factmap[j];

                //store all the possible j
                for(auto &f : fact) //(sqrt(k))
                {
                    if(i%f==0)
                        factmap[f]++;
                }
            }
        }
        return count;
    }
};

//TC : O(n)* O(sqrt(k) + log(k))
//SC : O(n)
