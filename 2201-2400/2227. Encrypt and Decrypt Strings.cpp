class Encrypter {
public:
    unordered_map<char, string> enc;
    unordered_map<string, int> cnt;
    Encrypter(vector<char>& keys, vector<string>& values, vector<string>& dictionary) {
        for(int i = 0; i < keys.size(); ++i) {
            enc[keys[i]] = values[i];
        }
        
        for(const string& w: dictionary) {
            cnt[encrypt(w)]++;
        }
    }
    
    string encrypt(string word1) {
        string res ="";
        for(char c: word1) {
            res += enc[c];
        }
        
        return res;
    }
    
    int decrypt(string word2) {
        return cnt[word2];
    }
};
