/******************************************************************************

                              Online C++ Compiler.
               Code, Compile, Run and Debug C++ program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

// Online C++ compiler to run C++ program online
#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

// Function to find the maximum
// length of equal subarray

vector<string> findLongestCommonUrlHistory(vector<string> h1, vector<string> h2) {
    const int m = h1.size();
    const int n = h2.size();
    vector<string> res;
    vector<vector<int>> dp(m + 1, vector<int>(n+1, 0));
    int maxLen = 0;
    int pos = -1;
    for(int i = m - 1; i >=0; --i) {
        for(int j = n - 1; j >= 0; --j) {
            if(h1[i] == h2[j]) {
                dp[i][j] = dp[i+1][j+1] + 1;
                if(dp[i][j] > maxLen) {
                    maxLen = dp[i][j];
                    pos = i;
                }
            }
        }
    }
    
    if(pos == -1) return res;
    for(int i = pos; i < pos + maxLen; ++i) {
        res.push_back(h1[i]);
    }
    return res;
}


// Driver Code
int main()
{
	vector<string> vect1{ "3234.html", "xys.html", "7hsaa.html" };
	vector<string> vect2{ "3234.html", "sdhsfjdsh.html", "xys.html", "7hsaa.html" };

	// Function call to find
	// maximum length of subarray
	auto res = findLongestCommonUrlHistory(vect1, vect2);
	for(auto s: res) {
	    cout << s << endl;
	}
}
