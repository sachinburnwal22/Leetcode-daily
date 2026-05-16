class Solution {
public:
    vector<int> res;
    vector<vector<int>> ans;

    void dfs(int node, vector<vector<int>>& graph){
        res.push_back(node);
        int n = graph.size();
        if(node == n-1){
            ans.push_back(res);
        }else{
            for(int next : graph[node]){
                dfs(next, graph);
            }
        }

        res.pop_back();
    }

    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        dfs(0, graph);
        return ans;
    }
};