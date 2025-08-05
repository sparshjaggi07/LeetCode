class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> ngeMap; 
        stack<int> st;  
        
        
        for (int i = 0; i < nums2.size(); i++) {
            int current = nums2[i];
            
            
            while (!st.empty() && current > st.top()) {
                ngeMap[st.top()] = current;
                st.pop();
            }
            
            st.push(current);
        }
        
        while (!st.empty()) {
            ngeMap[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for (int num : nums1) {
            ans.push_back(ngeMap[num]);
        }
        
        return ans;
    }
};
