class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size(), n2 = nums2.size();
        vector<int> nums3(n1 + n2); 
        int i = 0, j = 0, k = 0;

        
        while (i < n1 && j < n2) {
            if (nums1[i] < nums2[j]) {
                nums3[k++] = nums1[i++];
            } else {
                nums3[k++] = nums2[j++];
            }
        }
        while (i < n1) {
            nums3[k++] = nums1[i++];
        }
        while (j < n2) {
            nums3[k++] = nums2[j++];
        }

        
        int size = nums3.size();
        if (size % 2 == 0) {
            int mid = size / 2;
            return (nums3[mid - 1] + nums3[mid]) / 2.0; 
        } else {
            return nums3[size / 2];
        }
    }
};
