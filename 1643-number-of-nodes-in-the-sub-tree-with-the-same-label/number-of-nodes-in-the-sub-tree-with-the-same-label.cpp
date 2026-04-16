class Solution {
public:
    void dfs(unordered_map<int, vector<int>>& mp, int curr, int parent, string& labels, vector<int>& results, vector<int>& count){
        int mLab = labels[curr];

        int cntBeforeVisiting = count[mLab - 'a'];
        count[mLab - 'a']++;

        for(auto &a : mp[curr]){
            if(a == parent) continue;

            dfs(mp, a, curr, labels, results, count);
        }

        int cntAfterVisiting = count[mLab - 'a'];

        results[curr] = cntAfterVisiting - cntBeforeVisiting;
    }

    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> mp;
        for(auto &edge: edges){
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<int> results(n, 0);
        vector<int> count(26, 0);

        dfs(mp, 0, -1, labels, results, count);

        return results;
    }
};