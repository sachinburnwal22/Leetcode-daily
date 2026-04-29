class Solution {
public:
    vector<int> findOrder(int nC, vector<vector<int>>& pre) {
        unordered_map<int, vector<int>> adj;

        for(auto &it : pre){
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
        }

        vector<int> result;
        queue<int> q;
        vector<int> indegree(nC, 0);

        for(int u = 0; u < nC; u++){
            for(auto &v : adj[u]){
                indegree[v]++;
            }
        }

        for(int i = 0; i < nC; i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }

        while(!q.empty()){
            int node = q.front();
            q.pop();
            result.push_back(node);

            for(auto &v : adj[node]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }

        // 🔥 Cycle detection fix
        if(result.size() != nC){
            return {};
        }

        return result;
    }
};