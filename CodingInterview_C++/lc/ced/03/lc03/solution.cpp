#include <iostream>
#include <set>

using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int len = s.length();
        set<char> chars;
        int right = -1;
        int maxLen = 0;
        for (int i = 0; i < len; i++) {
            if (i > 0) {
                chars.erase(s[i - 1]);
            }
            while (right + 1 < len && chars.find(s[right + 1]) == chars.end()) {
                chars.insert(s[right + 1]);
                right++;
            }
            maxLen = max(maxLen, right - i + 1);
        }
        return maxLen;
    }
};
