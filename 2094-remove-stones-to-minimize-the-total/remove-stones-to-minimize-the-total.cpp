class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int n = piles.size();
        priority_queue<int> q;
        for(auto it : piles){
            q.push(it);
        }
        while(k > 0){
            int up = q.top();
            q.pop();
            int upnew = floor(up/2);
            q.push(up - upnew);
            k--;
        }

        int sum = 0;
        while(!q.empty()){
            sum += q.top();
            q.pop();
        }

        return sum;
    }
};