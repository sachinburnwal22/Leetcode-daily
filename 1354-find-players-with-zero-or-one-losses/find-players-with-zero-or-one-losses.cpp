class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        int n = matches.size();
        unordered_map<int, int> lostPl;
        for(int i=0; i<n; i++){
            int lost = matches[i][1];
            lostPl[lost]++;
        }

        vector<int> noLose;
        vector<int> oneLose;

        for(int i=0; i<n; i++){
            int loser = matches[i][1];
            int winner = matches[i][0];
            if(lostPl.find(winner) == lostPl.end()){
                noLose.push_back(winner);
                lostPl[winner] = 2; //So there should be any repetion
            }
            if(lostPl[loser] == 1){
                oneLose.push_back(loser);
            }
        }

        sort(noLose.begin(), noLose.end());
        sort(oneLose.begin(), oneLose.end());

        return {{noLose, oneLose}};
    }
};