class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        int n = score.size();
        vector<string> ans(n);
        map<int, int, greater<int>> mp;
        for(int i=0; i<n; i++){
            mp[score[i]] = i;
        }
        int rank = 1;
        for(auto it : mp){
            int index = it.second;
            if(rank == 1){
                ans[index] = "Gold Medal";
            }else if(rank == 2){
                ans[index] = "Silver Medal";
            }else if(rank == 3){
                ans[index] = "Bronze Medal";
            }else{
                ans[index] = to_string(rank);
            }

            rank++;
        }

        return ans;
    }
};