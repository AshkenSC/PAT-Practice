// PAT B1080

/*
����������STL mapȥ����id�ַ����ҵ�ѧ����Ϣ��
map��ֵ��Ϊ(string, int)����(ѧ��id������λ��)
 
��ÿ�������У����ȼ���map���Ƿ����и�ѧ��
��û������������������Ŀ������������ԭ����Ŀ������Ϣ
������Ϻ�Ҫ����㡢����������� 
 
map��ʹ�ã�
������map<string, int> idMap;
����Ԫ�أ�idMap.insert(pair<string, int>(name, 123));
�ж�ĳkeyֵ�Ƿ������map�� ������set�Ĳ�������=1����=0����idMap.count(idString) 
����ѧ���ַ�����ȡλ�ã�����ֱ�Ӱ����鷽ʽȡ��ֵ ��idMap[idString] 
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

