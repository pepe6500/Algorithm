#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;

    sort(score.begin(), score.end());

    int score_size = score.size();
    for (int i = 1; i <= score_size/m; i++)
    {
        int box = 0;
        box = score[score_size - i * m] * m;
        answer += box;
    }

    return answer;
}