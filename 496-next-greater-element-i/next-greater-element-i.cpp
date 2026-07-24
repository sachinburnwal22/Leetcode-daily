class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int n1 = nums1.size();
        int n2 = nums2.size();
        vector<int> ans;
        for(int i=0; i<n1; i++){
            int pivot = nums1[i];
            int level = 1;
            int p = 0;
            for(int j=0; j<n2; j++){
                if(level==1 && nums2[j] == pivot){
                    level = 2;
                }else if(level == 2 && nums2[j] > pivot){
                    ans.push_back(nums2[j]);
                    level = 3;
                    break;
                }
            }
            if(level != 3){
                ans.push_back(-1);
            }
        }
        return ans;

    }
};