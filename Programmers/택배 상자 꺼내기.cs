using System;

public class Solution
{
    public int solution(int n, int w, int num) {
        int answer;
        int line;

        if (((num - 1) / w) % 2 == 0)
        {
            line = (num - 1) % w;
        }
        else
        {
            line = (w - 1) - (num - 1) % w;
        }


        answer = ((n - 1) / w);
        if (((n - 1) / w) % 2 == 0)
        {
            if (line <= (n - 1) % w)
            {
                answer++;
            }
        }
        else
        {
            if (line >= (w - 1) - (n - 1) % w)
            {
                answer++;
            }
        }

        answer -= (num - 1) / w;
        return answer;
    }
}