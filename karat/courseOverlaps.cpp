

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>


using namespace std;

// student_course_pairs_1 = [
//   ["58", "Software Design"],
//   ["58", "Linear Algebra"],
//   ["94", "Art History"],
//   ["94", "Operating Systems"],
//   ["17", "Software Design"],
//   ["58", "Mechanics"],
//   ["58", "Economics"],
//   ["17", "Linear Algebra"],
//   ["17", "Political Science"],
//   ["94", "Economics"],
//   ["25", "Economics"],
// ]

vector<vector<string>> findOverlap(vector<vector<string>> studentCoursePairs) {
    unordered_map<string, vector<string>> m;
    vector<vector<string>> res;
    for(auto p: studentCoursePairs) {
        if(!m.count(p[0])) {
            m[p[0]] = {};
        }
        m[p[0]].push_back(p[1]);
    }
    
    for(auto kv1: m) {
        for(auto kv2: m) {
            if(kv1.first == kv2.first) continue;
            vector<string> tmp = {};
            tmp.push_back(kv1.first);
            tmp.push_back(kv2.first);
            for(auto c1: kv1.second) {
                for(auto c2: kv2.second) {
                    if(c1 == c2) {
                        tmp.push_back(c1);
                    }
                }
            }
            
            res.push_back(tmp);
        }
    }
    
    return res;
}


int main()
{
    //   ["58", "Software Design"],
//   ["58", "Linear Algebra"],
//   ["94", "Art History"],
//   ["94", "Operating Systems"],
//   ["17", "Software Design"],
//   ["58", "Mechanics"],
//   ["58", "Economics"],
//   ["17", "Linear Algebra"],
//   ["17", "Political Science"],
//   ["94", "Economics"],
//   ["25", "Economics"],
    vector<vector<string>> input_vec = {
        {"58", "Software Design"},
        {"58", "Linear Algebra"},
        {"94", "Art History"},
        {"94", "Operating Systems"},
        {"17", "Software Design"},
        {"58", "Mechanics"},
        {"58", "Economics"},
        {"17", "Linear Algebra"},
        {"17", "Political Science"},
        {"94", "Economics"},
        {"25", "Economics"}
    };
    auto res = findOverlap(input_vec);
    for (int i = 0; i < res.size(); i++) {
        for (int j = 0; j < res[i].size(); j++)
            cout << res[i][j] << " ";
        cout << endl;
    }
    return 0;
}
