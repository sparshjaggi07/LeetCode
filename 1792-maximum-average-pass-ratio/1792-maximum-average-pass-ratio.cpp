#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    double maxAverageRatio(vector<vector<int>>& classes, int extraStudents) {
        // Priority queue to store the classes with the highest potential gain in pass ratio
        auto compare = [](const pair<int, int>& a, const pair<int, int>& b) {
            double gainA = ((double)(a.first + 1) / (a.second + 1)) - ((double)a.first / a.second);
            double gainB = ((double)(b.first + 1) / (b.second + 1)) - ((double)b.first / b.second);
            return gainA < gainB; // Max-heap based on gain
        };
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(compare)> pq(compare);
        
        // Add all classes to the priority queue
        for (const auto& cls : classes) {
            pq.push({cls[0], cls[1]});
        }
        
        // Assign extra students
        while (extraStudents > 0) {
            auto [pass, total] = pq.top();
            pq.pop();
            pq.push({pass + 1, total + 1});
            extraStudents--;
        }
        
        // Calculate the final average pass ratio
        double totalRatio = 0.0;
        while (!pq.empty()) {
            auto [pass, total] = pq.top();
            pq.pop();
            totalRatio += (double)pass / total;
        }
        
        return totalRatio / classes.size();
    }
};
