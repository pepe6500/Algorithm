#include <string>
#include <vector>

using namespace std;

vector<vector<int>> main_arr;

void get_count(int x, int y, int size, int &one_count, int &zero_count)
{
    if (size == 1)
    {
        if (main_arr[x][y] == 1)
            one_count++;
        else
            zero_count++;
        return;
    }

    bool is_zero = true;
    bool is_one = true;
    bool is_nothing = false;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (is_zero && main_arr[x+i][y+j] == 1)
            {
                is_zero = false;
                if (is_one == false)
                {
                    is_nothing = true;
                    break;
                }
            }
            if (is_one && main_arr[x+i][y+j] == 0)
            {
                is_one = false;
                if (is_zero == false)
                {
                    is_nothing = true;
                    break;
                }
            }
        }

        if (is_nothing)
            break;
    }

    if (is_nothing)
    {
        int new_size = size / 2;
        get_count(x, y, new_size, one_count, zero_count);
        get_count(x + new_size, y, new_size, one_count, zero_count);
        get_count(x, y + new_size, new_size, one_count, zero_count);
        get_count(x + new_size, y + new_size, new_size, one_count, zero_count);
    }
    else if (is_zero)
    {
        zero_count++;
    }
    else
    {
        one_count++;
    }

    return;
}

vector<int> solution(vector<vector<int>> arr) {
    main_arr = arr;

    int zero_count = 0;
    int one_count = 0;
    get_count(0, 0, arr.size(), one_count, zero_count);

    vector<int> answer{zero_count, one_count};
    return answer;
}