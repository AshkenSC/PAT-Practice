// PAT B1069

#include <iostream>
#include <cstdio>
#include <cstring>
#include <vector>

using namespace std;

vector<string> winners;

bool AlreadyWon(string user);

int main() {

    // data input
    int repostNum, offset, firstWinner;
    scanf("%d%d%d\n", &repostNum, &offset, &firstWinner);
    vector<string> input(repostNum);
    for(int i = 0; i < repostNum; i++) {
        getline(cin, input[i]);
    }

    // print result
    bool nobodyWins = true;
    for(int i = firstWinner - 1; i < repostNum;) {
        nobodyWins = false;
        if(AlreadyWon(input[i]) == true) {
            i++;
            continue;
        }
        else {
            cout << input[i] << endl;
            winners.push_back(input[i]);
            i += offset;
        }
    }
    if(nobodyWins) {
        cout << "Keep going...";
    }

    return 0;
}

bool AlreadyWon(string user) {
    bool result = false;
    for(int i = 0; i < winners.size(); i++) {
        if(user == winners[i]) {
            result = true;
            break;
        }
    }
    return result;
}

