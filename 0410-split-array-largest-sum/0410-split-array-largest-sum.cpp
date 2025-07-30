class Solution {
public:
    int func(vector<int>& arr,int mid){
        int stu=1,ps=0;
        for(int i=0;i<arr.size();i++){
            if(ps+arr[i]<=mid)ps+=arr[i];
            else {stu++;ps=arr[i];}
        }
        return stu;
    }
    int splitArray(vector<int>& nums, int k) {
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=(low+high)/2;
            int nostu=func(nums,mid);
            if(nostu>k)low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};