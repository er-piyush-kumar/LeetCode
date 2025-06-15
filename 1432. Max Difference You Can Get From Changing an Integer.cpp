class Solution {
public:
    int maxDiff(int num) {
        string str = to_string(num);
        int maxi = 0;
        int mini = 0;
        // maximum number
        int i = 0;
        while (i < str.length() and str[i] == '9') {
            i++;
        }
        if (i < str.length()) {
            char ch = str[i];

            while (i < str.length()) {
                if (str[i] == ch)
                    str[i] = '9';
                i++;
            }
        }
        maxi = stoi(str);

        // minimum number
        str = to_string(num);
        if (str[0] == '1') {
            int i = 1;
            while (i < str.length() and (str[i] == '0' or str[i] == '1')) {
                i++;
            }
            char ch = str[i];
            while (i < str.length()) {
                if (str[i] == ch)
                    str[i] = '0';
                i++;
            }
            mini = stoi(str);
        } else {
            char ch = str[0];
            int i = 0;
            while (i < str.length()) {
                if (str[i] == ch)
                    str[i] = '1';
                i++;
            }
            mini = stoi(str);
        }
        return maxi - mini;
    }
};

// Time COmplexity : O(length of digit)
// Space Complexity : O(1)
