#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int compare(vector<int> a, vector<int> b)
{
    if (a[1] < b[1])
        return 1;
    else if (a[1] == b[1])
        if (a[0] < b[0])
            return 1;
        else
            return 0;
    else
        return 0;
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    long current_time = 0;
    int job_count = jobs.size();

    sort(jobs.begin(), jobs.end(), compare);
    
    while (jobs.empty() == false)
    {
        int min_starttime = 999999;
        int min_startindex = -1;
        for (int i = 0; i < jobs.size(); i++)
        {
            if (min_starttime > jobs[i][0])
            {
                min_startindex = i;
                min_starttime = jobs[i][0];
            }
            if (current_time >= jobs[i][0])
            {
                answer += (current_time - jobs[i][0]) + jobs[i][1];
                current_time += jobs[i][1];
                jobs.erase(jobs.begin() + i);

                break;
            }
            
            if (i >= jobs.size() - 1)
            {
                answer += jobs[min_startindex][1];
                current_time = min_starttime + jobs[min_startindex][1];
                jobs.erase(jobs.begin() + min_startindex);
            }
        }
    }

    answer /= job_count;


    return answer;
}