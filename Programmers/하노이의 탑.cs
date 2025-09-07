using System.Collections.Generic;
using System.Linq;
using System;
using System.IO;

public class Solution {


    List<int[]> actions = new List<int[]>();
    public void Hanoi(int from, int to, int other, int count)
    {
        if (count <= 0)
        {
            return;
        }
        Hanoi(from, other, to, count - 1);
        actions.Add(new int[] { from, to });
        Hanoi(other, to, from, count - 1);
    }

    public int[][] solution(int n)
    {
        int[][] answer;

        Hanoi(1, 3, 2, n);
        answer = actions.ToArray();

        return answer;
    }
}