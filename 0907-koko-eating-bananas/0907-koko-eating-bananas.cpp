class Solution {
public:
    long long calcTotalHours(vector<int>& arr,int h){
        long long total=0;
        int n=arr.size();
        for(int i=0;i<n;i++){
            total+=ceil((double)arr[i]/(double)h);
        }
        return total;
    }
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,high=*max_element(piles.begin(),piles.end());
        while(low<=high){
            int mid=(low+high)/2;
            long long total=calcTotalHours(piles,mid);
            if(total<=h)high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};