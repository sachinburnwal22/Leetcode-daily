class Solution {
public:
    long long smallestNumber(long long num) {
        if(num == 0) return num;
        else if(num > 0){
            string nums = to_string(num);
            sort(nums.begin(), nums.end());
            int i = 0;
            while(nums[i] == '0'){
                i++;
            }

            swap(nums[i], nums[0]);
            return stoll(nums);
        }else{
            long long pos = num * (-1);
            string strpos = to_string(pos);
            sort(strpos.begin(), strpos.end(), greater<char>());
            long long num = stoll(strpos);
            return num*(-1);
        }

    }
};