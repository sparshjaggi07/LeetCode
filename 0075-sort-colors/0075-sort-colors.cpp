class Solution {
public:
        void sortColors(vector<int>& nums) {
            unordered_map<int,int> count;
            for(int i=0;i<nums.size();i++){
                count[nums[i]]++;
            }
            int ind=0;
            for(int i=0;i<3;i++){
                while(count[i]>0){
                    nums[ind]=i;
                    ind++;
                    count[i]--;
                }
                count[i]=0;
            }
        }
};