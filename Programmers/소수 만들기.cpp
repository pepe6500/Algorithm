#include <math.h>
#include <vector>
#include <iostream>
using namespace std;

int answer = 0;
bool is_primary(int n)
{
    int max = int(pow(n, 0.5));
    for (int i = 2; i <= max; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

void find_all(vector<int> nums, int current_index = 0, int current_sum = 0, int sum_count = 1)
{
    if (sum_count == 3)
    {
        if (is_primary(current_sum + nums[current_index]))
            answer++;
        return;
    }

    for (int i = current_index + 1; i < nums.size(); i++)
    {
        find_all(nums, i, current_sum + nums[current_index], sum_count + 1);
    }
    return;
}

int solution(vector<int> nums) {

    for (int i = 0; i < nums.size(); i++)
    {
        find_all(nums, i);
    }

    return answer;
}