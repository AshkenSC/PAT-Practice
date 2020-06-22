// PAT B1061

#include <iostream>
#include <cstdio>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

int main() {

    int stuNum, questionNum;
    scanf("%d %d", &stuNum, &questionNum);
    vector<int> fullGrades(questionNum);
    vector<int> correctAnswers(questionNum);
    int* ptr = &fullGrades[0];

    // input full grades
    for(int i = 0; i < questionNum; i++) {
        scanf("%d", &fullGrades[i]);
    }
    // input correct answers
    for(int i = 0; i < questionNum; i++) {
        scanf("%d", &correctAnswers[i]);
    }
    // input student answers and calculate grads
    for(int i = 0; i < stuNum; i++) {
        int tempAnswer;
        int totalScore = 0;
        for(int j = 0; j < questionNum; j++) {
            scanf("%d", &tempAnswer);
            if(tempAnswer == correctAnswers[j]) {
                totalScore += fullGrades[j];
            }
        }
        printf("%d\n", totalScore);
    }

    return 0;
}

