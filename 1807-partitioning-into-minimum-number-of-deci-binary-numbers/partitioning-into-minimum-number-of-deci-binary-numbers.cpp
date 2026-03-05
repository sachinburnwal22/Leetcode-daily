class Solution {
public:
    int minPartitions(string n) {
        int cnt = 0;
        while(true){
            bool change = false;
            for(char &ch : n){
                if(ch != '0'){
                    ch--;
                    change = true;
                }
            }
            if(!change){
                break;
            }
            cnt++;
        }

        return cnt;
    }
};