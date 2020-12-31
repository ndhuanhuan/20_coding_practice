// https://zxi.mytechroad.com/blog/simulation/leetcode-1700-number-of-students-unable-to-eat-lunch/
class Solution {
public:
  int countStudents(vector<int>& students, vector<int>& sandwiches) {
    const int n = students.size();
    vector<int> c(2);
    for (int p : students) ++c[p];
    for (int i = 0; i < n; ++i)
      if (--c[sandwiches[i]] < 0) return n - i;
    return 0;
  }
};
