#include <string>
#include <iostream>

using namespace std;

bool solution(string s)
{
    int n = 0;
    bool answer = true;

    if (s[0] == ')' || s[s.length() - 1] == '(')
    {
        return false;
    }
    for (int i = 0 ; i < s.length(); i++)
    {
        if (s[i] == '(')
            n++;
        else if (s[i] == ')')
            n--;

        if (n < 0)
            return false;
    }

    return n == 0;
}