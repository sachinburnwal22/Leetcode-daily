class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        unordered_map<int, vector<int>> mp;
        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];

            mp[u].push_back(v);
            mp[v].push_back(u);
        }

        vector<int> result(n, 0);
        vector<int> count(26, 0);

        dfs(mp, 0, -1, labels, result, count);

        return result;
    }
    
    void dfs(unordered_map<int, vector<int>>& mp, int curr, int parent, string& labels, vector<int>& result, vector<int>& count){
        char mLab = labels[curr];
        int cntBeforeVisitingCurrChild = count[mLab - 'a'];
        count[mLab - 'a']+=1;
        
        for(int &v : mp[curr]){
            if(v == parent) continue;

            dfs(mp, v, curr, labels, result, count);
        }

        int cntAfterVisitingCurrChild = count[mLab - 'a'];
        result[curr] = cntAfterVisitingCurrChild - cntBeforeVisitingCurrChild;
    }
};