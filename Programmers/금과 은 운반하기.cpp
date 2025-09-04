#include <iostream>
#include <string>
#include <vector>

using namespace std;

int city_count;

bool check_possible(long long time, int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t)
{
    long long possible_g = 0;
    long long possible_s = 0;
    long long possible_total = 0;

    for (int i = 0; i < city_count; i++)
    {
        long long repeat_count = ((time + t[i]) / (t[i] * 2));
        long long max_possible_count = w[i] * repeat_count;
        possible_g += max_possible_count < g[i] ? max_possible_count : g[i];
        possible_s += max_possible_count < s[i] ? max_possible_count : s[i];
        possible_total += max_possible_count < g[i] + s[i] ? max_possible_count : g[i] + s[i];
    }

    return a <= possible_g && b <= possible_s && a + b <= possible_total;
}

long long solution(int a, int b, vector<int> g, vector<int> s, vector<int> w, vector<int> t) {
    long long answer = -1;
    city_count = g.size();

    long long start = 0;
    long long end = 10e9 * 10e5 * 4;
    long long mid;

    while (start < end)
    {
        mid = (start + end) / 2 + 1;

        if (check_possible(mid, a, b, g, s, w, t))
        {
            end = mid - 1;
            answer = mid;
        }
        else
        {
            start = mid + 1;
        }
    }

    return answer;
}