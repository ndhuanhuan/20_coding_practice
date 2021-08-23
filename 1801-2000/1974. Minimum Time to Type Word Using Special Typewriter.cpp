class Solution {
public:
    int minTimeToType(string word) {
        int seconds = word.length(); //It takes 1 second to print each character
        char prev   = 'a';           //pointer is at 'a' in the beginning
        
        for(const char &curr : word) {
            
            int curr_to_prev = abs(curr-prev);
            int prev_to_curr = 26 - abs(prev-curr);
            
            seconds += min(curr_to_prev, prev_to_curr);
            prev     = curr;
        }
        return seconds;
    }
};
