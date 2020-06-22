// PAT B1095

/*
string��substr������str.substr(��ʼ���ַ���Ŀ)

STL��map��ʹ�ã�
    ��1�����壺map<string, int> map0;
    ��2�����룺map0.insert(pair<string, int>("grade", 99));
    ��3������/���£�ֱ����key���±꣺map0["grade] = 98;
    ��4����ѯ�Ƿ����ĳ��key��map0.count("grade") == 0��
    for(auto it : output) {
        result.push_back({it.first, it.second});
    }
    �����漰��
    ��5�������ļ��д��for(auto it: output);
    ��6�����pair�ķ��ʣ�it.first, it.second;
    ��7��pushʱֱ����{string, int}�����Զ���Ľṹ���ʽ

    ע�⣬map���ܱ�sort�Զ����������Խ���ת�浽vector������
*/

#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
#include <cstring>
#include <algorithm>

using namespace std;

struct Info {
// in command type 1, used as id and grade
// in command type 3, used as roomId and population
    string s;
    int value;
};

bool cmp(Info a, Info b) {
// for command type 1
    if(a.value != b.value) {
        return a.value > b.value;
    }
    else {
        return a.s < b.s;
    }
}

int main() {
    int n, m;
    Info temp;
    vector<Info> data;
    cin >> n >> m;

    // data input
    for(int i = 0; i < n; i++) {
        cin >> temp.s >> temp.value;
        data.push_back(temp);
    }

    // tackle commands
    int type;
    string command;
    for(int i = 0; i < m; i++) {
        cin >> type >> command;
        vector<Info> answer;
        int stuNum = 0, gradeSum = 0;
        // print Case #: command
        printf("Case %d: %d %s\n", i + 1, type, command.c_str());
        if(type == 1) {
        // command type 1
            for(int j = 0; j < n; j++) {
                if(data[j].s[0] == command[0]) {
                    answer.push_back(data[j]);
                }
            }
        }
        else if(type == 2) {
        // command type 2
            for(int j = 0; j < n; j++) {
                if(data[j].s.substr(1, 3) == command) {
                    stuNum++;
                    gradeSum += data[j].value;
                }
            }
            // print result type 2
            if(stuNum != 0) {
                printf("%d %d\n", stuNum, gradeSum);
            }
        }
        else if(type == 3) {
        // command type 3
            unordered_map<string, int> output;
            for(int j = 0; j < n; j++) {
                if(data[j].s.substr(4, 6) == command) {
                    output[data[j].s.substr(1,3)]++;
                }
            }
            for(auto it : output) {
                answer.push_back({it.first, it.second});
            }
        }

        // sort data
        sort(answer.begin(), answer.end(), cmp);

        // print sorted result
        for(int j = 0; j < answer.size(); j++) {
            printf("%s %d\n", answer[j].s.c_str(), answer[j].value);
        }
        // NA situation
        if(answer.size() == 0 && (type == 1 || type == 3)
           || type == 2 && stuNum == 0) {
            printf("NA\n");
        }
    }

    return 0;
}