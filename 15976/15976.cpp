#include <iostream>

// 이진 탐색 함수 사용을 위해 전역 번수로 선언
int* xIndexArray;

// 찾아야 하는 Index 값을 이진 탐색하는 함수
// isReturnFront: 동일한 값을 찾지 못하였을 때 더 작은 값을 Return할 것인지, 큰 값을 Return할 것인지 여부
int BinarySearch(int target, int min, int max, bool isReturnFront)
{
    // min, max 사이에 값이 없을 경우 min과 max 중 하나를 Return 함.
    if (min + 1 == max)
    {
        // 찾는 값이 없으면 가장 인접한 값을 반환하는데, min과 max 사이에 target이 있으면 isReturnFront 값을 사용해 결정함.
        if (xIndexArray[min] >= target)
        {
            return min;
        }
        else if (xIndexArray[max] <= target)
        {
            return max;
        }
        else
        {
            return isReturnFront ? min : max;
        }
    }

    int middleIndex = (max + min) / 2;

    if (xIndexArray[middleIndex] == target)
    {
        return middleIndex;
    }
    else if (xIndexArray[middleIndex] > target)
    {
        return BinarySearch(target, min, middleIndex, isReturnFront);
    }
    else
    {
        return BinarySearch(target, middleIndex, max, isReturnFront);
    }
}

int main()
{
    int xSize, ySize;
    std::cin >> xSize;

    xIndexArray = new int[xSize];
    int* xValueArray = new int[xSize];
    unsigned long long* xPreSumArray = new unsigned long long[xSize];

    int inputIndex, inputValue;

    int inputMinDis, inputMaxDis;

    // 합산 초기값 설정
    std::cin >> inputIndex >> inputValue;
    xIndexArray[0] = inputIndex;
    xValueArray[0] = inputValue;
    xPreSumArray[0] = inputValue;

    for (int i = 1; i < xSize; i++)
    {
        std::cin >> inputIndex >> inputValue;
        xIndexArray[i] = inputIndex;
        xValueArray[i] = inputValue;
        xPreSumArray[i] = xPreSumArray[i-1] + inputValue;
    }

    std::cin >> ySize;

    int* yIndexArray = new int[ySize];
    int* yValueArray = new int[ySize];

    for (int i = 0; i < ySize; i++)
    {
        std::cin >> inputIndex >> inputValue;
        yIndexArray[i] = inputIndex;
        yValueArray[i] = inputValue;
    }

    std::cin >> inputMinDis >> inputMaxDis;

    unsigned long long result = 0;
    int serchMinIndex;
    int serchMaxIndex;

    int xMinIndex = xIndexArray[0];
    int xMaxIndex = xIndexArray[xSize - 1];

    for (int i = 0; i < ySize; i++)
    {
        // x를 좌우로 이동하는 연산이므로 y를 기준으로 min, max가 바뀜
        serchMinIndex = yIndexArray[i] - inputMaxDis;
        serchMaxIndex = yIndexArray[i] - inputMinDis;

        // 찾아야 하는 범위가 존재하지 않음
        if (xMaxIndex < serchMinIndex || xMinIndex > serchMaxIndex)
        {
            continue;
        }

        // x배열에서 사용되는 범위를 이진 탐색으로 구함.
        int startIndex = BinarySearch(serchMinIndex, 0, xSize - 1, false);
        int endIndex = BinarySearch(serchMaxIndex, 0, xSize - 1, true);

        // 미리 계산된 xPreSumArray에서 Min, Max 사이의 합을 구해 y값을 곱함. (startIndex에 -1을 해야 시작값을 포함한 합을 얻을 수 있음)
        result += (xPreSumArray[endIndex] - (startIndex > 0 ? xPreSumArray[startIndex - 1] : 0)) * yValueArray[i];
    }

    std::cout << result;
    return 0;
}