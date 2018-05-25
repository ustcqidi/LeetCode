### Longest Substring Without Repeating Characters 
- [题目链接](https://leetcode.com/problems/longest-substring-without-repeating-characters/description/)
- 字符串匹配、最长子串、无重复

### 基本思路
- KMP ？
- 滑动窗口：HashMap 保存每个字母在字符串中的索引i，遍历字符串，字符跟HashMap比较
- 不要构造字符串！！！
- 注意边界条件
- Your runtime beats 35.15 % of cpp submissions.
- Runtime: 47 ms
- 时间复杂度: O(n)
- 空间复杂度: O(n)