class Solution {
public:
    bool hasAlternatingBits(int n) {
        string str = bitset<32>(n).to_string();

        int switchh = 0;
        for(int i=0; i<str.size()-1; i++){
            if(str[i] == '1' && switchh == 0){
                switchh = 1;
            }
            if((str[i] == str[i+1]) && (switchh == 1)){
                return false;
            }else{
                continue;
            }
        }
        return true;
    }
};