// PAT B1085

/*
对学校信息建立结构体，采用vector记录各个学校的数据 
一边输入数据一边创建map(学校名, 数组位置)映射，用来更新每个学校的分数
输入完毕后，按照规则排序输出即可。 
*/ 

#include <cmath>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

struct School {
    string id;
    int testeeNum;
    float top;
    float advanced;
    float basic;
    long total;
    long realTotal;

    School() {
        testeeNum = 0;
        top = 0;
        advanced = 0;
        basic = 0;
        total = 0;
        realTotal = 0;
    }
};

string LowerCase(string s);
School UpdateSchoolGrades(School school, string id, float grade);
long GetTotal(float top, float advanced, float basic);
bool cmp(School a, School b);

int main() {
    vector<School> data;
    map<string, int> saveLoc;
    string idTemp, schoolIdTemp;
    float gradeTemp;
    int stuNum;

    cin >> stuNum;
    for(int i = 0; i < stuNum; i++) {
        cin >> idTemp >> gradeTemp >> schoolIdTemp;
        // add to school's total score
        schoolIdTemp = LowerCase(schoolIdTemp);
        if(saveLoc.count(schoolIdTemp) == 0) {
        // school appeared for the first time
            School newSchool;
            newSchool.id = schoolIdTemp;
            newSchool = UpdateSchoolGrades(newSchool, idTemp, gradeTemp);
            data.push_back(newSchool);
            saveLoc.insert(pair<string, int>(schoolIdTemp, data.size()-1));
        }
        else {
        // school appeared before
            data[saveLoc[schoolIdTemp]] = UpdateSchoolGrades(data[saveLoc[schoolIdTemp]], idTemp, gradeTemp);
        }

    }

    // calculate total score and sort
    for(int i = 0; i < data.size(); i++) {
        //data[i].total = GetTotal(data[i]);
        data[i].total = data[i].basic + data[i].advanced + data[i].top;
    }
    sort(data.begin(), data.end(), cmp);

    // print result
    cout << data.size() << endl;
    int rankNum = 1, sameRank = 1;
    for(int i = 0; i < data.size(); i++) {
        if(i != 0) {
            if(data[i].total == data[i-1].total) {
                sameRank++;
            }
            else {
                rankNum += sameRank;
                sameRank = 1;
            }
        }
        cout << rankNum << " ";
        cout << data[i].id << " ";
        cout << data[i].total << " ";
        cout << data[i].testeeNum << endl;
    }

    return 0;
}

string LowerCase(string s) {
    string out = s;
    for(int i = 0; i < out.size(); i++) {
        if(out[i] >= 'A' && out[i] <= 'Z') {
            out[i] = out[i] - 'A' + 'a';
        }
    }
    return out;
}

School UpdateSchoolGrades(School school, string id, float grade) {
    School updated = school;
    if(id[0] == 'T') {
        updated.top += grade * 1.5;
    }
    else if(id[0] == 'A') {
        updated.advanced += grade;
    }
    else {
        updated.basic += grade / 1.5;
    }
    updated.testeeNum++;
    updated.realTotal += grade;
    return updated;
}

long GetTotal(School sc) {
    long result;
    result = sc.basic/1.5 + sc.advanced + sc.top*1.5;
    result = result / sc.testeeNum;
    return result;
}

bool cmp(School a, School b) {
    if(a.total != b.total) {
        return a.total > b.total;
    }
    else if(a.testeeNum != b.testeeNum) {
        return a.testeeNum < b.testeeNum;
    }
    else {
        return a.id < b.id;
    }
}

