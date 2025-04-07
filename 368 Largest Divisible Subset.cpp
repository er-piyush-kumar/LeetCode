// 1 Method - Bruteforce 

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





//Second Method -> Optimied Method
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) 
    {
        int n = nums.size();

        sort(begin(nums), end(nums));

        vector<int> count(n, 1);  // To store the length of the largest divisible subset at each index
        vector<int> prevIndex(n, -1);  // To track the previous index in the subset

        int maxL = 1;  // Maximum length of the subset
        int index = 0; // The index at which the largest subset ends

        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0) {  // If nums[i] is divisible by nums[j]
                    if (count[i] < count[j] + 1) {  // If including nums[i] creates a longer subset
                        count[i] = count[j] + 1;
                        prevIndex[i] = j;
                    }

                    if (count[i] > maxL) {  // Update maxL and the index of the largest subset
                        maxL = count[i];
                        index = i;
                    }
                }
            }
        }

        // Construct the largest divisible subset
        vector<int> ans;
        while (index != -1) {
            ans.push_back(nums[index]);
            index = prevIndex[index];
        }

        // The subset was constructed in reverse order, so reverse it
        reverse(ans.begin(), ans.end());

        return ans;
    }
};

