class Solution {
public:
    double calDist(vector<int> dis){
        int a = dis[0]*dis[0];
        int b = dis[1]*dis[1];
        int c = a + b;
        return sqrt(c);
    }
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<double, vector<int>>> pq;
        for(auto it : points){
            double dist = calDist(it);
            pq.push({dist, it});
            if(pq.size() > k){
                pq.pop();
            }
        }
        vector<vector<int>> ans;
        while(!pq.empty()){
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};