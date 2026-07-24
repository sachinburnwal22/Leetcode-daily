class Solution {
public:
    bool isPalindrome(int x) {
        int d = x;
        double k = 0;
        if(x > 0){
            while(x != 0){
                int di = x % 10;
                k = k * 10 + di;
                x /= 10;
            }
            if(k == d){
                return true;
            }
            else{
                return false;
            }
        }
        else if(x == 0){
            return true;
        }
        else{
            return false;
        }
    }
};