#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int maximumLength(string s) {
        int n = s.size();
        int maxLength = -1;

        // Iterate over possible lengths of special substrings
        for (int len = 1; len <= n; ++len) {
            unordered_map<string, int> substringCount;
            
            // Count all substrings of the current length `len`
            for (int i = 0; i + len <= n; ++i) {
                string substring = s.substr(i, len);
                // Check if the substring is special
                if (isSpecial(substring)) {
                    substringCount[substring]++;
                }
            }

            // Check if any substring of this length occurs at least 3 times
            for (auto& [substring, count] : substringCount) {
                if (count >= 3) {
                    maxLength = len;
                }
            }
        }

        return maxLength;
    }

private:
    bool isSpecial(const string& s) {
        // Check if all characters in the string are the same
        char first = s[0];
        for (char c : s) {
            if (c != first) return false;
        }
        return true;
    }
};
