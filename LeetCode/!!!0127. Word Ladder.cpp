/*
0127. Word Ladder

给定两个单词（beginWord 和 endWord）和一个字典，
找到从 beginWord 到 endWord 的最短转换序列的长度。转换需遵循如下规则：
每次转换只能改变一个字母。
转换过程中的中间单词必须是字典中的单词。

思路：
参考https://leetcode-cn.com/problems/word-ladder/solution/yan-du-you-xian-bian-li-shuang-xiang-yan-du-you-2/

1）想不到转化为图去存储；
2）想不到用这种遍历每个位置26个字母的方式去构建图；
3）想不到BFS就直接能得到最短路线。觉得还需要数学证明。
    直觉上，我是能理解的：如果不走BFS的路线，那么你一定是会走回在BFS中walked的结点，那么就不是最短了。
    但是让我自己想，我是想不出来的！

而且本题要注意的细节太多：
1）有哪些特殊情况在BFS前就要排除？（end不在wordList里，wordList长度为0）
2）为什么开始时step要设为1？
3）（注释了以后好像没影响）为什么在BFS开始前要把beginWord从wordSet里删除？
4）step何时+1？
5）如果不能在队列中return，最后该return什么？
等等等等……需要仔细思考！
*/

#include <string>
#include <vector>
#include <queue>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_set<string> wordSet;
    unordered_set<string> visited;
    int step;

    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        step = 0;

        if (wordList.size() == 0)
            return 0;

        // 将wordList转为set
        for (auto word : wordList)
            wordSet.emplace(word);
        if (wordSet.count(endWord) == 0)
            return 0;
        
        //wordSet.erase(beginWord);

        // BFS找最短长度
        queue<string> q;
        q.emplace(beginWord);
        visited.emplace(beginWord);
        step = 1;

        while (q.empty() == false) {
            int currentSize = q.size();
            // 要找到当前队列中所有单词的下一步单词，加入队列。
            for (int i = 0; i < currentSize; i++) {
                string currentWord = q.front();
                q.pop();
                // 如何找下一步单词？依次只修改每个单词的一位，从a尝试变化到z
                // 检查修改以后的单词是否在wordSet中
                for (int j = 0; j < currentWord.size(); j++) {
                    string nextWord = currentWord;
                    char originalJ = nextWord[j];
                    for (int k = 0; k < 26; k++) {
                        nextWord[j] = 'a' + k;
                        if (wordSet.count(nextWord) > 0) {
                            // 如果修改以后的单词已经等于结束单词了，则直接返回step+1
                            if (nextWord == endWord)
                                return step + 1;
                            // 如果不等于结束单词，且没有访问过，就将其放入队列继续找下一个单词
                            if (visited.count(nextWord) == 0) {
                                q.emplace(nextWord);
                                visited.emplace(nextWord);
                            }
                        }    
                    }
                    // 必须记得还原这一轮改变的nextWord[j]
                    nextWord[j] = originalJ;
                }
            }
            
            // 不论从当前队列中单词走到它们的下一步单词，
            // 步数都只是增加1，
            // 因此只能在这里增加步数。
            step++;
        }

        return 0;
    }
};
