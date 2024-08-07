#include <iostream>

int main()
{
    int xSize, ySize;
    std::cin >> xSize;

    int* xIndex = new int[xSize];
    int* xValue = new int[xSize];

    int inputIndex, inputValue;

    int inputMinDis, inputMaxDis;

    for (int i = 0; i < xSize; i++)
    {
        std::cin >> inputIndex >> inputValue;
        xIndex[i] = inputIndex;
        xValue[i] = inputValue;
    }

    std::cin >> ySize;

    int* yIndex = new int[ySize];
    int* yValue = new int[ySize];

    for (int i = 0; i < ySize; i++)
    {
        std::cin >> inputIndex >> inputValue;
        yIndex[i] = inputIndex;
        yValue[i] = inputValue;
    }

    std::cin >> inputMinDis >> inputMaxDis;

    long result = 0;
    int serchMinIndex;
    int serchMaxIndex;

    for (int i = 0; i < xSize; i++)
    {
        serchMinIndex = xIndex[i] + inputMinDis;
        serchMaxIndex = xIndex[i] + inputMaxDis;

        for (int j = 0; j < ySize; j++)
        {
            if (yIndex[j] >= serchMinIndex && yIndex[j] <= serchMaxIndex)
            {
                result += xValue[i] * yValue[j];
            }
            if (yIndex[j] > serchMaxIndex)
            {
                break;
            }
        }
    }

    std::cout << result;
    return 0;
}