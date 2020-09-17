/* 
0647. Palindromic Substrings

给定一个字符串，数出这个字符串里有多少回文子串。
只要子串的开始和结束位置不同，即便它们内容相同，也算作是两个不同的子串。

Example 1:
Input: "abc"
Output: 3
Explanation: Three palindromic strings: "a", "b", "c".
 

Example 2:
Input: "aaa"
Output: 6
Explanation: Six palindromic strings: "a", "a", "a", "aa", "aa", "aaa".

思路：动态规划
dp[i][j]表示i开头，j结尾的字符串是否是回文字符串
1） 如果i == j，也就是单个字符，一定是回文串
2） 如果j-i == 1, 而且s[i] == s[j]，两个连续相同字符，也算回文串
3） 如果j-i > 1, 而且s[i] == s[j] 而且dp[i+1][j-1]也是回文串，则dp[i][j]也是回文串
*/

#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int len = s.size();
        int result = 0;
        vector<vector<int>> dp(len, vector<int>(len));

        // 注意外层是j，里层才是i，j表示结束位置，i表示开始位置，开始位置不能超过结束位置
        for (int j = 0; j < len; j++)
            for (int i = 0; i <= j; i++) {
                // 如果i == j，也就是单个字符，一定是回文串
                if (i == j ||
                // 如果j-i == 1, 而且s[i] == s[j]，两个连续相同字符，也算回文串
                (j - i == 1 && s[i] == s[j]) ||
                // 如果j-i > 1, 而且s[i] == s[j] 而且dp[i+1][j-1]也是回文串，则dp[i][j]也是回文串
                (j - i > 1 && s[i] == s[j] && dp[i + 1][j - 1] == 1)) {
                    dp[i][j] = 1;
                    result++;
                }
            }
        
        return result;
    }
};