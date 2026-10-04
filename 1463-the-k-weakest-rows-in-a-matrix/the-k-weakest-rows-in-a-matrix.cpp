class Solution {
public:
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        int r = mat.size();
        int c = mat[0].size();

        unordered_map<int, int> mp;

        for(int i=0; i<r; i++){
            int cnt = 0;
            for(int j=0; j<c; j++){
                if(mat[i][j] == 1){
                    cnt++;
                }
            }
            mp[i] = cnt;
        }
        vector<int> ans;
        priority_queue<pair<int, int>> pq;
        for(auto it : mp){
            pq.push({it.second, it.first});
            if(pq.size() > k){
                pq.pop();
            }
        }

        while(!pq.empty()){
            auto it = pq.top();
            ans.push_back(it.second);
            pq.pop();
        };

        reverse(ans.begin(), ans.end());

        return ans;
    }
};