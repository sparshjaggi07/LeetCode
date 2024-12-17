class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        map<char, int> freq;
        for (char c : s) {
            freq[c]++;
        }

        priority_queue<pair<char, int>> maxHeap;
        for (auto it : freq) {
            maxHeap.push({it.first, it.second});
        }

        string result;

        while (!maxHeap.empty()) {
            auto [currentChar, currentFreq] = maxHeap.top();
            maxHeap.pop();

            int useCount = min(repeatLimit, currentFreq);
            result.append(useCount, currentChar);
            currentFreq -= useCount;

            if (currentFreq > 0) {
                if (maxHeap.empty()) {
                    break;
                }

                auto [nextChar, nextFreq] = maxHeap.top();
                maxHeap.pop();

                result.push_back(nextChar);
                nextFreq--;

                maxHeap.push({currentChar, currentFreq});
                if (nextFreq > 0) {
                    maxHeap.push({nextChar, nextFreq});
                }
            }
        }

        return result;
    }
};
