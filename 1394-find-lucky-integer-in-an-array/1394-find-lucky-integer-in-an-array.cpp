class Solution {
public:
    int findLucky(vector<int>& arr) {
        map<int,int> mpp;
        for(int i=0;i<arr.size();i++){
            mpp[arr[i]]++;
        }
        int maxi=-1e9;
        for(int i=0;i<arr.size();i++){
            if(mpp[arr[i]]==arr[i] && mpp[arr[i]]>maxi) maxi=mpp[arr[i]];       
        }
        if(maxi==-1e9) return -1;
        return maxi;
    }
};