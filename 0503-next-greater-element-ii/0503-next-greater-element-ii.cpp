class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int> nums2 = nums;
        vector<int> ans(nums.size(), -1);
        for(int i = 0; i < nums.size(); i++){
            nums2.push_back(nums[i]);
        }
        stack<int> st;
        int n = nums.size();
        for(int j = nums2.size()-1; j>=0; j--){
            while(!st.empty() && st.top() <= nums2[j]){
                st.pop();
            }
            if(!st.empty()){
                ans[j%n] = st.top();
            }
            st.push(nums2[j]);
        }
        return ans;
        
    }
};