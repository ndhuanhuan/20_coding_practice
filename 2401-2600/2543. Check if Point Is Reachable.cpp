// https://leetcode.cn/problems/check-if-point-is-reachable/solution/wen-ti-zhuan-huan-gcdju-ti-gou-zao-fang-0plx0/
// https://www.bilibili.com/video/BV1jG4y197qD/?spm_id_from=444.41.list.card_archive.click&vd_source=48e4bed01dd155111c1b309b768743f6
/*
* 问题转换 + GCD
* 如果从 (1,1) 能够到达 (x,y) 的话，从 (x,y) 逆推也能够到达 (1,1)
*
* 4 种移动方案：
*     正推         逆推
* (x, y - x)   (x, y + x)
* (x - y, y)   (x + y, y)
* (2 * x, y)   (x / 2, y), x is even
* (x, 2 * y)   (x, y / 2), y is even
*
* 设 g = gcd(x,y)
* 前 2 种移动方案下，(x,y) 能够到达 (ax+by,cx+dy)，根据贝祖定理，g = 1
* 后 2 种移动方案下，g 可以扩大到 2^k
*/
class Solution {
public:
    bool isReachable(int targetX, int targetY) {
        int g = gcd(targetX, targetY);
        return (g & (g - 1)) == 0;
    }
};

