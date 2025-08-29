#include <iostream>
#include <string>
#include <vector>
#include <set>

using namespace std;

vector<vector<int>> info_data;
int min_n = 99999;
int max_n;
int max_m;
int infosize;

set<tuple<int, int, int>> check_set;

void find_min_value(int current_n = 0, int current_m = 0, int index = 0)
{
    if (check_set.find(tuple<int, int, int>(current_n, current_m, index)) != check_set.end())
        return;
    check_set.insert(tuple<int, int, int>(current_n, current_m, index));

    if (min_n <= current_n)
    {
        return;
    }
    if (max_n < current_n || max_m < current_m)
    {
        return;
    }
    if (index >= infosize)
    {
        min_n = current_n;
        return;
    }
    
    find_min_value(current_n, current_m + info_data[index][1], index + 1);
    find_min_value(current_n + info_data[index][0], current_m, index + 1);
}

int solution(vector<vector<int>> info, int n, int m) {
    int answer = 0;
    info_data = info;
    max_n = n - 1;
    max_m = m - 1;
    infosize = info.size();
    
    find_min_value();
    
    answer = min_n == 99999 ? -1 : min_n;
    
    return answer;
}