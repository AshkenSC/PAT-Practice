// PAT B1058

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {

    int stuNum, questionNum;
    scanf("%d %d", &stuNum, &questionNum);
    vector< set<char> > answers(questionNum);
    vector<int> questionGrades(questionNum);
    vector<int> questionWrongCnt(questionNum);
    vector<int> stuGrades(stuNum);

    // input correct answers
    for(int i = 0; i < questionNum; i++) {
        int optionNum, correctNum;
        char charTemp;
        scanf("%d %d %d", &questionGrades[i], &optionNum, &correctNum);
        for(int j = 0; j < correctNum; j++) {
            scanf(" %c", &charTemp);
            answers[i].insert(charTemp);
        }
    }

    // input student's answers
    for(int i = 0; i < stuNum; i++) {
        scanf("\n");
        int tempStuGrades = 0;
        for(int j = 0; j < questionNum; j++) {
            int tempOptionNum;
            char tempChar;
            set<char> stuAnswer;

            // scan student's answer
            scanf("(%d", &tempOptionNum);
            for(int k = 0; k < tempOptionNum; k++) {
                scanf(" %c", &tempChar);
                stuAnswer.insert(tempChar);
            }
            scanf(")");
            if(j != questionNum - 1) {
                scanf(" ");
            }

            // compare student answer and correct answer
            if(stuAnswer == answers[j]) {
                tempStuGrades += questionGrades[j];
            }
            else {
                questionWrongCnt[j]++;
            }
        }
        stuGrades[i] = tempStuGrades;
    }

    // print result
    for(int i = 0; i < stuNum; i++) {
        printf("%d\n", stuGrades[i]);
    }
    int maxWrongCnt = 0;
    for(int i = 0; i < questionNum; i++) {
        if(questionWrongCnt[i] > maxWrongCnt) {
            maxWrongCnt = questionWrongCnt[i];
        }
    }
    if(maxWrongCnt == 0) {
        printf("Too simple");
    }
    else {
        printf("%d", maxWrongCnt);
        for(int i = 0; i < questionNum; i++) {
            if(questionWrongCnt[i] == maxWrongCnt) {
                printf(" %d", i + 1);
            }
        }
    }

    return 0;
}

