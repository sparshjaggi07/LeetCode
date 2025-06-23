class Solution {
public:
    vector<string> divideString(string s, int k, char fill) {
        vector<string> res;
        string str = "";
        
        for (int i = 0; i < s.size(); ++i) {
            str += s[i];
            if (str.size() == k) {
                res.push_back(str);
                str = "";
            }
        }
        if (!str.empty()) {
            while (str.size() < k) {
                str += fill;
            }
            res.push_back(str);
        }

        return res;
    }
};