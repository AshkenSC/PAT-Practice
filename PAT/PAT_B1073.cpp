// PAT B1073

#include <iostream>
#include <cstdio>
#include <cstring>
#include <set>
#include <vector>

using namespace std;

struct Question {
    int fullScore;
    int optionNum;
    int correctOptionNum;
    int correctAnswers[5] = {0};
};

int main() {
    // input correct answers
    int stuNum, questionNum;
    scanf("%d%d", &stuNum, &questionNum);
    vector<Question> qList(questionNum);
    for(int i = 0; i < questionNum; i++) {
        char tempChar;
        scanf("%d %d %d",
              &qList[i].fullScore,
              &qList[i].optionNum,
              &qList[i].correctOptionNum);
        for(int j = 0; j < qList[i].correctOptionNum; j++) {
            scanf(" %c", &tempChar);
            qList[i].correctAnswers[tempChar - 'a'] = 1;
        }
    }

    // input student's answers and print their scores
    int maxWrongTime = 0;                           // store max wrong time
    vector< vector<int> > wrongTime(questionNum);   // store wrong time
    vector< vector<int> > stuAnswers(questionNum);  // store current student's answer
    for(int i = 0; i < questionNum; i++) {
    // resize 2d arrays
        wrongTime[i].resize(5);
        stuAnswers[i].resize(5);
    }

    float stuTotalScore;        // store current student's total score
    float correctness = 1.0;    // correctness coefficient
    char tempChar;              // temp var to store input answer chars
    for(int i = 0; i < stuNum; i++) {
        // reset student's total score
        stuTotalScore = 0;

        for(int j = 0; j < questionNum; j++) {
        // reset student's answers
            for(int k = 0; k < 5; k++) {
                stuAnswers[j][k] = 0;
            }
        }
        scanf("\n");        // absorb end of the line

        for(int j = 0; j < questionNum; j++) {
        // student answer input
            int tempOptionNum;
            if(j > 0) {
                scanf(" "); // absorb space between answers
            }
            scanf("(%d", &tempOptionNum);
            for(int k = 0; k < tempOptionNum; k++) {
            // input student's answer of question j
                scanf(" %c", &tempChar);
                // set input char position from 0 to 1
                stuAnswers[j][tempChar - 'a'] = 1;
            }
            scanf(")");     // absorb ) at the end of an answer
        }

        for(int j = 0; j < questionNum; j++) {
        // compare student's answer and the correct answer
            correctness = 1.0;
            for(int k = 0; k < 5; k++) {
            // judge and decide correctness
                if(qList[j].correctAnswers[k] == 0 && stuAnswers[j][k] == 1) {
                // student picks a wrong answer
                // set to wrong, and count this option's wrong time
                    correctness = 0.0;
                    wrongTime[j][k]++;
                    if(wrongTime[j][k] > maxWrongTime) {
                    // update max wrong time
                        maxWrongTime = wrongTime[j][k];
                    }
                }
                else if(qList[j].correctAnswers[k] == 1 && stuAnswers[j][k] == 0) {
                // student does not pick a correct answer
                // if he has not picked a wrong answer, set to semi-correct
                // count this option's wrong time
                    if(correctness == 1.0) {
                        correctness = 0.5;
                    }
                    wrongTime[j][k]++;
                    if(wrongTime[j][k] > maxWrongTime) {
                    // update max wrong time
                        maxWrongTime = wrongTime[j][k];
                    }
                }
            }

            // update full score
            stuTotalScore += correctness * (float)qList[j].fullScore;
        }

        // print student's final score
        printf("%.1f\n", stuTotalScore);
    }

    // print max wrong time statistics
    if(maxWrongTime == 0) {
        printf("Too simple");
        return 0;
    }
    for(int i = 0; i < questionNum; i++) {
        for(int j = 0; j < 5; j++) {
            if(wrongTime[i][j] == maxWrongTime) {
                printf("%d %d-%c\n", maxWrongTime, i+1, 'a'+j);
            }
        }
    }
    return 0;
}

