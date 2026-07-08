class Solution {
public:
    void solve(int& num){
        if(num < 10){
            return;
        }
        int sum = 0;
        int nNum = num;
        while(nNum){
            sum += nNum%10;
            nNum = nNum/10;
        }

        if(sum < 10){
            num = sum;
            return;
        }else{
            num = sum;
            solve(num);
        }
    }

    int addDigits(int num) {
        if(num < 10){
            return num;
        }

        solve(num);

        return num;
    }
};