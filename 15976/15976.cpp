#include <iostream>

// ���� Ž�� �Լ� ����� ���� ���� ������ ����
int* xIndexArray;

// ã�ƾ� �ϴ� Index ���� ���� Ž���ϴ� �Լ�
// isReturnFront: ������ ���� ã�� ���Ͽ��� �� �� ���� ���� Return�� ������, ū ���� Return�� ������ ����
int BinarySearch(int target, int min, int max, bool isReturnFront)
{
    // min, max ���̿� ���� ���� ��� min�� max �� �ϳ��� Return ��.
    if (min + 1 == max)
    {
        // ã�� ���� ������ ���� ������ ���� ��ȯ�ϴµ�, min�� max ���̿� target�� ������ isReturnFront ���� ����� ������.
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

    // �ջ� �ʱⰪ ����
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
        // x�� �¿�� �̵��ϴ� �����̹Ƿ� y�� �������� min, max�� �ٲ�
        serchMinIndex = yIndexArray[i] - inputMaxDis;
        serchMaxIndex = yIndexArray[i] - inputMinDis;

        // ã�ƾ� �ϴ� ������ �������� ����
        if (xMaxIndex < serchMinIndex || xMinIndex > serchMaxIndex)
        {
            continue;
        }

        // x�迭���� ���Ǵ� ������ ���� Ž������ ����.
        int startIndex = BinarySearch(serchMinIndex, 0, xSize - 1, false);
        int endIndex = BinarySearch(serchMaxIndex, 0, xSize - 1, true);

        // �̸� ���� xPreSumArray���� Min, Max ������ ���� ���� y���� ����. (startIndex�� -1�� �ؾ� ���۰��� ������ ���� ���� �� ����)
        result += (xPreSumArray[endIndex] - (startIndex > 0 ? xPreSumArray[startIndex - 1] : 0)) * yValueArray[i];
    }

    std::cout << result;
    return 0;
}