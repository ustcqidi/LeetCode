### Longest Palindromic Substring
- [题目链接](https://leetcode.com/problems/longest-palindromic-substring/description/)
- 字符串匹配、最长子串、回文

### 基本思路
- 暴力搜索
- 注意cornor case
- 两边向中间搜素，否则会TLE
- Your runtime beats 4.81 % of cpp submissions.
- Runtime: 1052 ms
- 暴力搜素简单优化
- 过滤无用循环
- Your runtime beats 6.31 % of cpp submissions.
- Runtime: 889 ms
- 时间复杂度：O(n^3)