class Solution {
public:
    int sumbyD(vector<int>& arr,int mid){
        int total=0;
        for(int i=0;i<arr.size();i++){
            total+=ceil((double)arr[i]/mid);
        }
        return total;
    }
    int smallestDivisor(vector<int>& nums, int threshold) {
        int n=nums.size();
        if(n>threshold)return -1;
        int low=1,high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            int mid=(low+high)/2;
            if(sumbyD(nums,mid)<=threshold)high=mid-1;
            else low=mid+1;
        }   
        return low;
    }
};