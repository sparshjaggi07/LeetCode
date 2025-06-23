class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m,vector<int>(n,-1));
        vector<int> prev(n,0);
        int up=0,left=0;
        for(int i=0;i<m;i++){
            vector<int> curr(n,0);
            for(int j=0;j<n;j++){
                if(i==0 && j==0)curr[j]=1;
                else{
                if(i>0) up=prev[j];else up=0;
                if(j>0) left=curr[j-1];else left=0;
                curr[j]=up+left;
                }
            }
            prev=curr;
        }
        return prev[n-1];
    }
};