// Online C++ compiler to run C++ program online
#include <iostream>
#include <stack>
#include <vector>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        
        for(int i = 0 ; i < tokens.size(); ++i) {
            string token = tokens[i];
            if(isdigit(token.back())) {
                st.push(stoi(token));
            } else {
                if(st.empty()) {
                    throw "error";
                }
                int n1= st.top(); st.pop();
                
                if(token[0] == '!') {
                    int n = 1;
                    for(int i = 2; i <= n1; ++i) n *= i;
                    st.push(n);
                    continue;
                }
                if(st.empty()) {
                    throw "error";
                }
                int n2= st.top(); st.pop();
                
                int n = 0;

                
                switch(token[0]) {
                    case '+': n = n1 + n2; break;
                    case '-': n = n2 - n1; break;
                    case '*': n = n1 * n2; break;
                    case '/':
                        if(n1 == 0) throw "error";
                        n = n2 / n1; break;
                }
                
                st.push(n);
            }
        }
        
        return st.top();
    }
};

int main() {
    // Write C++ code here
    Solution sol = Solution();
    vector<string> input{"2","1","+","3", "!","*"};
    int res = sol.evalRPN(input);
    cout << to_string(res) << endl;

    return 0;
}


class Solution {
public:
  int evalRPN(vector<string>& tokens) {
    stack<int> s;
    for (const string& token : tokens) {
      if (isdigit(token.back())) {
        s.push(stoi(token));
      } else {
        int n2 = s.top(); s.pop();
        int n1 = s.top(); s.pop();        
        int n = 0;
        switch (token[0]) {
          case '+': n = n1 + n2; break;
          case '-': n = n1 - n2; break;
          case '*': n = n1 * n2; break;
          case '/': n = n1 / n2; break;
        }
        s.push(n);
      }
    }
    return s.top();
  }
};
