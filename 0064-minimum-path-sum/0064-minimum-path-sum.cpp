class Solution {
public:
    int helper(int i,int j,vector<vector<int>>& grid,vector<vector<int>> &dp){
        if(i==0 && j==0)return grid[0][0];
        if(i<0 || j<0)return 1e9;
        if(dp[i][j]!=-1)return dp[i][j];
        int up=grid[i][j]+helper(i-1,j,grid,dp);
        int left=grid[i][j]+helper(i,j-1,grid,dp);
        return dp[i][j]=min(up,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m,vector<int>(n,-1));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(i==0 && j==0) dp[i][j]=grid[0][0];
                else{
                    int up = i > 0 ? dp[i-1][j] : 1e9;
                    int left = j > 0 ? dp[i][j-1] : 1e9;
                    dp[i][j]=grid[i][j]+min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
};