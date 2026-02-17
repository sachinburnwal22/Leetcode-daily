class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> result;
        for(int HH=0; HH<12; HH++){
            for(int MM=0; MM<60; MM++){
                if(__builtin_popcount(HH)+__builtin_popcount(MM) == turnedOn){
                    string hr = to_string(HH);
                    string min = (MM<10?"0":"") + to_string(MM);

                    result.push_back(hr + ":" + min);
                }
            }
        }
        return result;
    }
};