#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
#include <set>
#include <queue>

using namespace std;

vector<vector<vector<int>>> connected_map;
int min_value = 2000000000;

void get_distance_map(int from, map<int, int> &distance_map)
{
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> process_edge;

    process_edge.push({0, from});

    while (process_edge.empty() == false)
    {
        int current_dis = process_edge.top().first;
        int current_n = process_edge.top().second;
        process_edge.pop();

        if (distance_map.count(current_n) == 1 && distance_map[current_n] <= current_dis)
            continue;
        
        distance_map[current_n] = current_dis;
        for (auto each : connected_map[current_n])
        {
            if (distance_map.find(each[0]) != distance_map.end())
            {
                continue;
            }
            process_edge.push({current_dis + each[1], each[0]});
        }
    }
}

int solution(int n, int s, int a, int b, vector<vector<int>> fares) {
    connected_map.resize(n+1);
    for (int i = 0; i < fares.size(); i++)
    {
        connected_map[fares[i][0]].push_back({fares[i][1], fares[i][2]});
        connected_map[fares[i][1]].push_back({fares[i][0], fares[i][2]});
    }
    map<int, int> s_distance_map;
    get_distance_map(s, s_distance_map);

    map<int, int> a_distance_map;
    get_distance_map(a, a_distance_map);
    
    map<int, int> b_distance_map;
    get_distance_map(b, b_distance_map);
    
    for (auto each : s_distance_map)
    {
        if (a_distance_map.find(each.first) == a_distance_map.end())
            continue;
        if (b_distance_map.find(each.first) == b_distance_map.end())
            continue;

        int i = each.first;
        int val = s_distance_map[i] + a_distance_map[i] + b_distance_map[i];
        if (min_value > val)
            min_value = val;
    }

    return min_value;
}