class Solution {
public:
    string countAndSay(int n) {
        // base case
        if (n == 1)
            return "1";

        // processing
        string s = countAndSay(n - 1);
        int count = 1;
        int i = 1;
        char ch = s[0];
        string ans = "";
        while (i < s.length()) {
            if (s[i] == ch) {
                count++;
            } else {
                ans += to_string(count);
                ans += ch;
                ch = s[i];
                count = 1;
            }
            i++;
        }
        ans += to_string(count);
        ans += ch;
        return ans;
    }
};

/*
Time Complexity :-

Since each level i of recursion takes O(L_i) time, and you have n levels of recursion, the total time complexity is: O(L₁ + L₂ + L₃ + ... + Lₙ)
Since the lengths grow roughly exponentially, the sum ends up being O(Lₙ).
Therefore, the final time complexity is:
🔺 O(2ⁿ) (worst case upper bound),
🟢 O(1.3ⁿ) (tight bound based on empirical growth)
*/
