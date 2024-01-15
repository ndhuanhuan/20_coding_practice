- https://www.bilibili.com/video/BV1Fg4y1Q7wv/?vd_source=48e4bed01dd155111c1b309b768743f6
- https://leetcode.cn/problems/count-the-number-of-powerful-integers/solutions/2595149/shu-wei-dp-shang-xia-jie-mo-ban-fu-ti-da-h6ci/
- old: https://leetcode.cn/problems/number-of-digit-one/solutions/1750339/by-endlesscheng-h9ua/

```
下面代码中 Java/C++/Go 只需要记忆化 (i,cnt1)(i,\textit{cnt}_1)(i,cnt 
1
​
 ) 这个状态，因为：

对于一个固定的 (i,cnt1)(i,\textit{cnt}_1)(i,cnt 
1
​
 )，这个状态受到 isLimit\textit{isLimit}isLimit 的约束在整个递归过程中至多会出现一次，没必要记忆化。
另外，如果只记忆化 (i,cnt1)(i,\textit{cnt}_1)(i,cnt 
1
​
 )，dp\textit{dp}dp 数组的含义就变成在不受到约束时的合法方案数，所以要在 !isLimit 成立时才去记忆化。


```
