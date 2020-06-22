// 东南大学C++复试
// 求两字符串中最长公共单词

/*

字符串操作相关
（1）strtok(字符串，分割标志字符)
（2）char*可直接存入string；string存为char*需要用c_str()方法

集合操作相关
（1）set.insert()插入元素
（2）set<datatype>::iterator it声明迭代变量

*/

#include <cstdio>
#include <iostream>
#include <set>
#include <cstring>
#include <string>
#include <algorithm>

using namespace std;

int main() {

    char s1[] = "hello this is aaaaaa bbbbbbb";
    char s2[] = "hello i am aaaaaaa bbbbbbb";
    const char *divide = " ";
    char *p;
    set<string> words1, words2, common;

    // 求S1单词集合
    p = strtok(s1, divide);
    while(p) {
        string tmp = p;
        words1.insert(tmp);
        p = strtok(nullptr, divide);
    }

    // 求S2单词集合
    p = strtok(s2, divide);
    while(p) {
        string tmp = p;
        words2.insert(tmp);
        p = strtok(nullptr, divide);
    }

    // 求S1 S2交集（公共单词集合）
    set_intersection(words1.begin(), words1.end(), words2.begin(), words2.end(), inserter(common, common.end()));

    // 找单词最大长度
    int maxLen = -1;
    for(set<string>::iterator it = common.begin(); it != common.end(); it++) {
        if((int)(*it).length() > maxLen) {
            maxLen = (*it).length();
        }
    }

    // 输出最大长度单词
    for(set<string>::iterator it = common.begin(); it != common.end(); it++) {
        if((*it).size() == maxLen) {
            cout << *it << " ";
        }
    }

    return 0;
}
