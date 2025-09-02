#include <string>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    set<string> used_words;

    char last;
    last = words[0][0];
    answer.push_back(0);
    answer.push_back(0);
    for (int i = 0; i < words.size(); i++)
    {
        if (used_words.find(words[i]) != used_words.end() || words[i][0] != last)
        {
            answer[0] = i % n + 1;
            answer[1] = i / n + 1;
            break;
        }

        used_words.insert(words[i]);
        last = words[i][words[i].size() - 1];
    }

    return answer;
}