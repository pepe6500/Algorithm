#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;

vector<map<int, int>> dice_nums;
vector<int> answer;

void get_combines(vector<vector<int>> &result, vector<int> &check, int end, int start, int count)
{
    if (check.size() == count)
    {
        result.push_back(check);
        return;
    }
    
    for (int i = start; i <= end; i++)
    {
        check.push_back(i);
        get_combines(result, check, end, i+1, count);
        check.pop_back();
    }
    return;
}

void get_sum(map<int, int> &sum_num, vector<int> combine, int current_sum, int current_count, int sum_count)
{
    if (sum_count == combine.size())
    {
        sum_num[current_sum] += current_count;
        return;
    }
    
    for (auto &num : dice_nums[combine[sum_count]])
    {
        sum_count++;
        get_sum(sum_num, combine, current_sum + num.first, current_count * num.second, sum_count);
        sum_count--;
    }
    return;
}

vector<int> solution(vector<vector<int>> dice) {
    
    int dise_size = dice.size();
    for (int i = 0; i < dise_size; i++)
    {
        dice_nums.push_back(map<int, int>());
        auto current_dice = dice[i];
        for (auto num : current_dice)
        {
            dice_nums[i][num]++;
        }
    }
    
    vector<vector<int>> combines;
    vector<int> check;
    get_combines(combines, check, dise_size - 1, 0, dise_size / 2);
    


    vector<int> best_combine = combines[0];

    map<int, int> best_sum_num;
    int best_win_count = 0;
    map<int, int> current_sum_num;
    map<int, int> unselect_sum_num;
    
    get_sum(current_sum_num, combines[0], 0, 1, 0);
    
    vector<int> unselect_combine;
    
    for (int i = 0; i < dise_size; i++)
    {
        bool includedBest = false;
        for (auto each : best_combine)
        {
            if (each == i)
            {
                includedBest = true;
                break;
            }
        }

        if (includedBest == false)
        {
            unselect_combine.push_back(i);
        }
    }
    get_sum(unselect_sum_num, unselect_combine, 0, 1, 0);
    auto it1 = current_sum_num.begin();
    auto it2 = unselect_sum_num.begin();
    int win_count = 0;

    while (true)
    {
        if (it1 == current_sum_num.end())
        {
            break;
        }
        if (it1->first > it2->first)
        {
            win_count += it1->second * it2->second;
            it2++;
        }
        else
        {
            it1++;
            it2 = unselect_sum_num.begin();
        }

        if (it1 == current_sum_num.end())
        {
            break;
        }
        else if (it2 == unselect_sum_num.end())
        {
            it1++;
            it2 = unselect_sum_num.begin();
        }
    }
    best_combine = combines[0];
    best_sum_num = current_sum_num;
    best_win_count = win_count;

    auto conbine_it = combines.begin();
    conbine_it++;
    while (conbine_it != combines.end())
    {
        auto current_combine = *conbine_it;
        current_sum_num.clear();
        unselect_combine.clear();
        unselect_sum_num.clear();
        win_count = 0;
    
        get_sum(current_sum_num, current_combine, 0, 1, 0);
        
        for (int i = 0; i < dise_size; i++)
        {
            bool included = false;
            for (auto each : current_combine)
            {
                if (each == i)
                {
                    included = true;
                    break;
                }
            }

            if (included == false)
            {
                unselect_combine.push_back(i);
            }
        }
        get_sum(unselect_sum_num, unselect_combine, 0, 1, 0);
        it1 = current_sum_num.begin();
        it2 = unselect_sum_num.begin();


        while (true)
        {
            if (it1 == current_sum_num.end())
            {
                break;
            }
            if (it1->first > it2->first)
            {
                win_count += it1->second * it2->second;
                it2++;
            }
            else
            {
                it1++;
                it2 = unselect_sum_num.begin();
            }

            if (it1 == current_sum_num.end())
            {
                break;
            }
            if (it2 == unselect_sum_num.end())
            {
                it1++;
                it2 = unselect_sum_num.begin();
            }
        }

        if (win_count > best_win_count)
        {
            best_combine = current_combine;
            best_sum_num = current_sum_num;
            best_win_count = win_count;
        }

        conbine_it++;
    }
    
    for (auto &each: best_combine)
    {
        answer.push_back(each + 1);
    }
    return answer;
}