// PAT B1077

/*
用一变量stuJudgeSum记录学生总打分，在记录时剔除非法输入
用validJudgeNum记录有效输入数量，用两个变量记录最大和最小输入
用stuJudgeSum减去min和max得到最终有效学生总分，除以有效输入数，得学生均分
再和教师打分相加除以2，记得对最终结果四舍五入即可 
*/ 

#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <vector>

using namespace std;

int main() {

    int groupNum, fullMark;
    int teacherJudge;
    float stuJudgeSum;
    int validJudgeNum;
    float finalScore;

    cin >> groupNum >> fullMark;
    for(int i = 0; i < groupNum; i++) {
        stuJudgeSum = 0;
        validJudgeNum = 0;
        int maxGrade = -1, minGrade = 101;
        // data input and calculate
        cin >> teacherJudge;
        for(int j = 0; j < groupNum - 1; j++) {
            int tempInput;
            cin >> tempInput;
            if(tempInput >= 0 && tempInput <= fullMark) {
                stuJudgeSum += tempInput;
                validJudgeNum++;
                // record max and min grade
                if(tempInput > maxGrade) {
                    maxGrade = tempInput;
                }
                if(tempInput < minGrade) {
                    minGrade = tempInput;
                }
            }
        }
        stuJudgeSum = (float)(stuJudgeSum - maxGrade - minGrade) / (float)(validJudgeNum - 2);
        finalScore = (stuJudgeSum + (float)teacherJudge) / 2.0;
        if(finalScore - (int)finalScore >= 0.5) {
            finalScore = (int)finalScore + 1;
        }
        else {
            finalScore = (int)finalScore;
        }
        // print result
        cout << finalScore << endl;
    }

    return 0;
}

