/*
0096. Unique Binary Search Trees

给定整数n，有多少个不同的储存1-n的二叉搜索树？
二叉搜索树（BST)要求左子树结点都比当前结点小，右子树结点都比当前结点大。

思路：动态规划。
设f(n)为有n个数字时可以构建多少种不同的树，则起始状态为
f(0)=1, f(1)=1, f(2)=2

考虑二叉搜索树的特点，可以发现，对于数列1，2，3，……，n，从中取任意一个，它左边的数都是左子树的结点，右边的数都是右子树的结点。
例如对于1,2,3，如果以3作为根结点，则左子树为1，2构成，共有f(2)种情况，右子树为空，共有f(0)种情况。一共是f(2)*f(0)种。
以此类推，可以推出，f(3) = f(0)*f(2) + f(1)*f(1) + f(2)*f(0);

同理:
f(4) = f(0)*f(3) + f(1)*f(2) + f(2)*f(1) + f(3)*f(0)
f(5) = f(0)*f(4) + f(1)*f(3) + f(2)*f(2) + f(3)*f(1) + f(4)*f(0)

可以发现规律：
f(n) = f(0)*f(n-1) + f(1)*f(n-2) + ... + f(n-2)*f(1) + f(n-1)*f(0)

参考：https://leetcode-cn.com/problems/unique-binary-search-trees/solution/cdong-tai-gui-hua-zhu-bu-fen-xi-zhuang-tai-zhuan-y/
*/

class Solution {
public:
    int numTrees(int n) {
        if (n < 2)
            return 1;
        else {
            vector<int> f(n + 1);
            f[0] = 1; f[1] = 1; f[2] = 2;
            for (int i = 3; i <= n; i++) {
                int temp = 0;
                for (int j = 0; j <= i - 1; j++)
                    temp += f[j] * f[i-1 - j];
                f[i] = temp;
            }
            return f[n];
        }
    }
};

class Solution {
public:
    int numTrees(int n) {
        vector<int> dp(n + 1);
        dp[0] = 1;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= i; j++) {
                dp[i] += dp[j - 1] * dp[i - j];
            }
        }

        return dp[n];
    }
};
