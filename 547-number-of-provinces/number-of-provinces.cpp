class Solution {
public:
    int n;

    void dfs(int u, unordered_map<int, vector<int>>& mp, vector<bool>& visited){
        queue<int> q;
        q.push(u);
        visited[u] = true;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto &it : mp[node]){
                if(!visited[it]){
                    dfs(it, mp, visited);
                }
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        n = isConnected.size();
        vector<bool> visited(n, false);
        unordered_map<int, vector<int>> adj;
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j]){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }

        int cnt = 0;

        for(int i=0; i<n; i++){
            if(!visited[i]){
                dfs(i, adj, visited);
                cnt++;
            }
        }

        return cnt;
    }
};