class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int maxElement = 0, chunks = 0;
        for (int i = 0; i < arr.size(); ++i) {
            maxElement = max(maxElement, arr[i]);
            if (maxElement == i) {
                ++chunks;
            }
        }
        return chunks;
    }
};
