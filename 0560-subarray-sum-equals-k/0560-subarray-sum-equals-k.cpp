class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(nums.size(),0);
        prefix[0]=nums[0];
        for(int i=1;i<nums.size();i++){
            prefix[i]=nums[i]+prefix[i-1];
        }
        unordered_map<int,int>mp;
        int ans=0;
        for(int i=0;i<nums.size();i++){
            if(prefix[i]==k)ans++;
            if(mp.find(prefix[i]-k)!=mp.end())ans+=mp[prefix[i]-k];
            mp[prefix[i]]++;
        }
        return ans;
    }
};