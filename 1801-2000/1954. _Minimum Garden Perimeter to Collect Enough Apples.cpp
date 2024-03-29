// Approach 1: https://leetcode.com/problems/minimum-garden-perimeter-to-collect-enough-apples/discuss/1375478/JavaC%2B%2BPython-Binary-Search-and-O(1)-Soluitons
// in distance = 1, we can see top side is 2 1
// in distance = 2, top side is 4 3 2 3
// in distance = 3, top side is 6 5 4 3 4 5
// 6 5 4 3 => (x + 2x) * (x + 1) /2
// 4 5 => (x + 2x -1) * x / 2 - x
// add together 3 x* x


// Now the pattern here is that, we start from 2*d and elements decrease by 1 and there will be (d+1) elements
// then (d-1) elements will increase, so there are 2 APs
class Solution {
public:
    long long minimumPerimeter(long long neededApples) {
        long long x = 0;
        long long we_have = 0;
 
        while(we_have < neededApples) {
            x++;
            long long s = (3LL * x*  x);
            we_have += 4 * s;
        }
        
        return 8 * x;
    }
};

// https://baike.baidu.com/item/%E5%B9%B3%E6%96%B9%E5%92%8C%E5%85%AC%E5%BC%8F/3264126
// Use Approach No 1's conclusion, when distance = n, total is 3n*n. 
// We need to calculate "distance=1" + "distance=2" + ... + "distance=n"
// We can convert it to 12*(1^2 + 2^2 + ... +  n^2). => don't forget each square have 4 edges.
// since sum of squares of consecutive numbers is (2n^3 + 3n^2 + n) / 6
// combine together it is 4n^3 + 6n^2 + 2n
// Then binary search
class Solution {
public:
    long long minimumPerimeter(long long x) {
        long long l = 1,  r = 100000, m;
        while (l < r) {
            m = (l + r) / 2;
            if (m * m * m * 4 + m * m * 6 + m * 2 >= x)
                r = m;
            else
                l = m + 1;
        }
        return l * 8;
    }
};
