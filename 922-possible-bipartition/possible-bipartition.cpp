class Solution {
public:

    bool bfsCheck(unordered_map<int, vector<int>> &adj, vector<int>& color, int node){
        queue<int> q;
        q.push(node);
        color[node] = 1;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : adj[u]){
                if(color[v] == color[u]){
                    return false;
                }
                if(color[v] == -1){
                    q.push(v);
                    color[v] = 1 - color[u];
                }
            }
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int, vector<int>> adj;
        for(vector<int> &vec : dislikes){
            int u = vec[0];
            int v = vec[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        vector<int> color(n+1, -1);

        for(int i=1; i<=n; i++){
            if(color[i] == -1){
                if(bfsCheck(adj, color, i) == false){
                    return false;
                }
            }
        }
        return true;
    }
};