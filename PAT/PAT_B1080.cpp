// PAT B1080

/*
核心是利用STL map去根据id字符串找到学生信息。
map键值对为(string, int)，即(学号id，数组位置)
 
在每轮输入中，都先检索map中是否已有该学生
如没有则在数组中新增条目；如已有则在原有条目更新信息
输入完毕后按要求计算、排序输出即可 
 
map的使用：
声明：map<string, int> idMap;
插入元素：idMap.insert(pair<string, int>(name, 123));
判断某key值是否存在于map中 （类似set的操作，有=1，无=0）：idMap.count(idString) 
根据学号字符串获取位置：可以直接按数组方式取得值 ：idMap[idString] 
*/

#include <cmath>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

struct Info {
    string id;
    float codingGrade;
    float midtermGrade;
    float finalGrade;
    float total;

    Info() {
        codingGrade = -1;
        midtermGrade = -1;
        finalGrade = -1;
    }
};

int GetInt(float num);
bool cmp(Info a, Info b);

vector<Info> data;
map<string, int> idSet;

int main() {
    int codingNum, midtermNum, finalNum;
    cin >> codingNum >> midtermNum >> finalNum;

    // input coding grades
    for(int i = 0; i < codingNum; i++) {
        Info newEntry;
        cin >> newEntry.id >> newEntry.codingGrade;
        data.push_back(newEntry);
        // record current id storage location
        idSet.insert(pair<string, int>(newEntry.id, data.size()-1));
    }
    // input midterm grades
    string tempId;
    for(int i = 0; i < midtermNum; i++) {
        cin >> tempId;
        if(idSet.count(tempId) == 1) {
        // current id has already appeared
            int pos = idSet[tempId];
            cin >> data[pos].midtermGrade;
        }
        else {
        // current id has not appeared before
            Info newEntry;
            newEntry.id = tempId;
            cin >> newEntry.midtermGrade;
            data.push_back(newEntry);
            // record current id storage location
            idSet.insert(pair<string, int>(newEntry.id, data.size()-1));
        }
    }
    // input final grades
    for(int i = 0; i < finalNum; i++) {
        cin >> tempId;
        if(idSet.count(tempId) == 1) {
        // current id has already appeared
            int pos = idSet[tempId];
            cin >> data[pos].finalGrade;
            // calculate total grade
            if(data[pos].finalGrade > data[pos].midtermGrade) {
                data[pos].total = data[pos].finalGrade;
            }
            else {
                data[pos].total = GetInt(0.4*data[pos].midtermGrade + 0.6*data[pos].finalGrade);
            }
        }
        else {
        // current id has not appeared before
            Info newEntry;
            newEntry.id = tempId;
            cin >> newEntry.finalGrade;
            // total grade == final grade (no midterm)
            newEntry.total = newEntry.finalGrade;
            data.push_back(newEntry);
        }
    }

    // sort grade list
    sort(data.begin(), data.end(), cmp);
    // print result
    for(int i = 0; i < data.size(); i++) {
        if(data[i].codingGrade >= 200 && data[i].total >= 60) {
           cout << data[i].id << " " << data[i].codingGrade << " ";
            cout << data[i].midtermGrade << " ";
            cout << data[i].finalGrade << " ";
            cout << data[i].total << endl;
        }
    }

    return 0;
}

int GetInt(float num) {
    if(num - (int)num > 0.500000f) {
        return (int)num + 1;
    }
    else {
        return (int)num;
    }
}

bool cmp(Info a, Info b) {
    if(a.total != b.total) {
        return a.total > b.total;
    }
    else {
        return a.id < b.id;
    }
}

