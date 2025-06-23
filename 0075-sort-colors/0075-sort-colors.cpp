class Solution {
public:
    int helper(vector<int>& nums,int low,int high){
        int pivot=nums[low];
        int i=low,j=high;
        while(i<j){
            while(nums[i]<=pivot && i<=high-1){
                i++;
            }
            while(nums[j]>pivot && j>=low+1){
                j--;
            }
            if(i<j)swap(nums[i],nums[j]);
        }
        swap(nums[low],nums[j]);
        return j;
    }
    void qs(vector<int>& nums,int low,int high) {
        int pi=0;
        if(low<high){
            pi=helper(nums,low,high);
            qs(nums,low,pi-1);
            qs(nums,pi+1,high);
        }
        }
        void sortColors(vector<int>& nums) {
            int low=0;int high=nums.size()-1;
            qs(nums,low,high);
        }
};