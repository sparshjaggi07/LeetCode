class Solution {
public:
    int maxKDivisibleComponents(int n, vector<vector<int>>& edges, vector<int>& values, int k) {
        vector<vector<int>> graph(n);
        vector<int> visited(n, 0);

        for (auto& edge : edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        int components = 0;

        function<long long(int)> dfs = [&](int node) {
            visited[node] = 1;
            long long subtreeSum = values[node];

            for (int neighbor : graph[node]) {
                if (!visited[neighbor]) {
                    subtreeSum += dfs(neighbor);
                }
            }

            if (subtreeSum % k == 0) {
                components++;
                return 0LL;
            }

            return subtreeSum;
        };

        dfs(0);
        return components;
    }
};
