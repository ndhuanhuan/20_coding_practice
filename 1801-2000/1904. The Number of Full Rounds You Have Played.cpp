// https://leetcode.com/problems/the-number-of-full-rounds-you-have-played/discuss/1284240/C%2B%2B-straightforward-3-lines
class Solution {
public:
    int numberOfRounds(string s, string f) {
        int start = 60 * stoi(s.substr(0, 2)) + stoi(s.substr(3)), finish = 60 * stoi(f.substr(0, 2)) + stoi(f.substr(3));
        if (start > finish) finish += 60 * 24; // If `finishTime` is earlier than `startTime`, add 24 hours to `finishTime`.
        return max(0, finish / 15 - (start + 14) / 15); // max(0, floor(finish / 15) - ceil(start / 15))
    }
};
