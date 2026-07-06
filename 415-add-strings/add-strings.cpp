class Solution {
public:
    string addStrings(string num1, string num2) {
        int n1 = num1.size();
        int n2 = num2.size();
        int carry = 0;
        string ans = "";
        reverse(num1.begin(), num1.end());
        reverse(num2.begin(), num2.end());

        for(int i=0; i<max(n1, n2); i++){
            int dig1 = (i < n1) ? num1[i] - '0' : 0;
            int dig2 = (i < n2) ? num2[i] - '0' : 0;
            int sum = dig1 + dig2 + carry;

            ans += (sum % 10) + '0';
            carry = sum / 10;
        }

        if(carry){
            ans += carry + '0';
        }

        reverse(ans.begin(), ans.end());
        return ans;
    }
};