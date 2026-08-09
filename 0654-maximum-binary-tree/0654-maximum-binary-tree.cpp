class Solution {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        vector<TreeNode*> st;
        for (int num : nums) {
            TreeNode* curr = new TreeNode(num);
            while (!st.empty() && st.back()->val < num) {
                curr->left = st.back();
                st.pop_back();
            }
            if (!st.empty()) {
                st.back()->right = curr;
            }
            st.push_back(curr);
        }
        return st.front();
    }
};
