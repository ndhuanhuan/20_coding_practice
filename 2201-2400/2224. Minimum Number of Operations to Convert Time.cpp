class Solution {
public:
    int convertTime(string current, string correct) {
        int curHour = stoi(current.substr(0, 2));
        int corHour = stoi(correct.substr(0, 2));
        int curMin = stoi(current.substr(3, 2));
        int corMin = stoi(correct.substr(3, 2));
        int totalMin = (corHour-curHour)*60 + corMin - curMin;
        int res = 0;

        res += totalMin / 60;
        totalMin %= 60;
        res += totalMin / 15;
        totalMin %= 15;
        res += totalMin / 5;
        totalMin %= 5;
        res += totalMin;
        
        
        return res;
    }
};
