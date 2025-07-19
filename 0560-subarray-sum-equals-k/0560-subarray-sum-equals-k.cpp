class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int ans=0;
        for(int i=0;i<nums.size();i++){
            int sum=nums[i];
            if(sum==k)ans++;
            for(int j=i+1;j<nums.size();j++){
                sum+=nums[j];
                if(sum==k)ans++;
            }
        }
        return ans;
    }
};