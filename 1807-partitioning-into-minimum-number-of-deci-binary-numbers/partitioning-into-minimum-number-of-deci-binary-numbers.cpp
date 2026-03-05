class Solution {
public:
    int minPartitions(string n) {
        char maxChar = *max_element(begin(n), end(n));

        return maxChar - '0';
    }
};