class Solution {
public:
    long long pickGifts(vector<int>& gifts, int k) {
        // Use a max heap to efficiently pick the pile with the maximum gifts
        priority_queue<int> maxHeap(gifts.begin(), gifts.end());

        // Perform k operations
        for (int i = 0; i < k; ++i) {
            if (maxHeap.empty()) break; // Safety check if heap is empty

            int maxGifts = maxHeap.top(); // Get the maximum gifts
            maxHeap.pop();

            // Calculate remaining gifts after taking the floor of the square root
            int remainingGifts = floor(sqrt(maxGifts));

            // Push the remaining gifts back into the heap
            maxHeap.push(remainingGifts);
        }

        // Calculate the total number of gifts remaining
        long long totalGifts = 0;
        while (!maxHeap.empty()) {
            totalGifts += maxHeap.top();
            maxHeap.pop();
        }

        return totalGifts;
    }
};