class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> res;
        vector<int>prev;
        for(int i=0;i<numRows;i++){
            vector<int>currow(i+1,1);
            for(int j=1;j<i;j++){
                currow[j]=prev[j-1]+prev[j];
            }
            res.push_back(currow);
            prev=currow;
        }
        return res;
    }
};