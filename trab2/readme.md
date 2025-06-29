# João Pedro Rocha da Silva - M1

# 1717. Maximum Score From Removing Substrings

You are given a input string and two integers x and y. You can perform two types of operations any number of times.

Remove substring "ab" and gain x points.
For example, when removing "ab" from "cabxbae" it becomes "cxbae".
Remove substring "ba" and gain y points.
For example, when removing "ba" from "cabxbae" it becomes "cabxe".
Return the maximum points you can gain after applying the above operations on s.

 
Example 1:

Input: s = "cdbcbbaaabab", x = 4, y = 5
Output: 19
Explanation:
- Remove the "ba" underlined in "cdbcbbaaabab". Now, s = "cdbcbbaaab" and 5 points are added to the score.
- Remove the "ab" underlined in "cdbcbbaaab". Now, s = "cdbcbbaa" and 4 points are added to the score.
- Remove the "ba" underlined in "cdbcbbaa". Now, s = "cdbcba" and 5 points are added to the score.
- Remove the "ba" underlined in "cdbcba". Now, s = "cdbc" and 5 points are added to the score.
Total score = 5 + 4 + 5 + 5 = 19.
Example 2:

Input: s = "aabbaaxybbaabb", x = 5, y = 4
Output: 20

Constraints:

1 <= s.length <= 105
1 <= x, y <= 104
s consists of lowercase English letters.

# My Solution 
Push all the characters from input string to a stack while removing the higher value substring,
then do the same operation to the remaining input string while removing the less valuable substring.

# Time Complexity
The algorithim has a two step process with each step having a time complexity of O(n), with n = input string size.
Best and Worst cases:
- Best case is if the input string is composed of only higher value substrings, so it only runs the string length once.
- Worst case is if the input string doesn't have a any higher value substring so it runs the full string length on both loops. 

# Space Complexity
The algorithim uses a auxiliary stack with the same size of the input string, resulting in a space complexity of O(n).