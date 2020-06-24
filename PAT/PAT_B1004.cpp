// PAT B1004

/*
用循环逐条检查学生信息
用maxGrade maxName maxId记录检查过的信息中的最高分的分数 姓名 学号
用minGrade minName minId记录检查过的信息中的最低分的分数 姓名 学号
若当前条目分数高于maxGrade，则更新最高分三个变量信息
若当前条目分数低于minGrade，则更新最低分三个变量信息

注意：maxGrade初始化为-1，minGrade初始化为101
否则，当出现某些极端情况时，信息将无法正常记录（例如，所有人都是0分，或所有人都是100分）
*/

#include <iostream>
using namespace std;

int main()
{
    int num, grade;
    int maxGrade = -1, minGrade = 101;
    string maxName, maxId, minName, minId;
    string name, id;

    cin >> num;
    for(int i = 0; i < num; i++) {
        cin >> name >> id >> grade;
        if(grade > maxGrade) {
            maxGrade = grade;
            maxName = name;
            maxId = id;
        }
        if(grade < minGrade) {
            minGrade = grade;
            minName = name;
            minId = id;
        }
    }

    cout << maxName << " " << maxId << endl;
    cout << minName << " " << minId << endl;

    return 0;
}
