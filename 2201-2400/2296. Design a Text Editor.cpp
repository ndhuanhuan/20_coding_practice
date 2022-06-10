
class TextEditor {
    int MAXLEN = 10;
    
    deque<char> left;
    deque<char> right;

   public:
        TextEditor() {}
    
        

        string helper() {
            string res;
            auto it = left.rbegin();

            for (int i = 0; i < MAXLEN && it != left.rend(); it++, i++) {
                res.push_back(*it);
            }
            reverse(res.begin(), res.end());
            return res;
        }
        
        void addText(string text) {
            
            for(auto ch: text) {
                left.push_back(ch);
            }
        }

        int deleteText(int k) {
            int res = min((int)left.size(), k);
            for (int i = 0; i < res; i++) left.pop_back();
            return res;
        }

        string cursorLeft(int k) {
            int actualMove = min(k, (int)left.size());
            for(int i = 0; i < actualMove; ++i) {
                char c = left.back();
                left.pop_back();
                right.push_front(c);
            }
            return helper();
        }

        string cursorRight(int k) {
            int actualMove = min(k, (int)right.size());
            for (int i = 0; i < actualMove; i++) {
                char c = right.front();
                right.pop_front();
                left.push_back(c);
            }
            return helper();
        }


};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */
