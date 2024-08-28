#include <iostream>

struct Point
{
	int position;
	int color;
};

struct Distance
{
	int color;
	int distance;
};

Point* pointArray;

int pointCount;

void QuickSort(int start, int end)
{
	// �Էµ� ���Ұ� 1����� ������ �Ϸ�� ���� return ��.
	if (start >= end)
	{
		return;
	}

	int pivotPosition = pointArray[start].position;

	int front = start + 1;
	int back = end;
	// �ڸ� �ٲٴ� �� �ӽ� Point
	Point tempPoint;

	// pivot�� �������� ���� ���� ����, ū ���� ������ ��ġ�ϵ��� ������.
	while (true)
	{
		while (pointArray[front].position <= pivotPosition && front < end)
		{
			front++;
		}

		while (pointArray[back].position >= pivotPosition && back >= front)
		{
			back--;
		}

		if (front >= back)
		{
			break;
		}

		tempPoint = pointArray[front];
		pointArray[front] = pointArray[back];
		pointArray[back] = tempPoint;
	}

	// ���� �� pivot�� �߾����� �̵�
	tempPoint = pointArray[start];
	pointArray[start] = pointArray[back];
	pointArray[back] = tempPoint;

	// ���ĵ��� ���� pivot�� ��, �� �κ��� ���ȣ��� ������.
	QuickSort(start, back - 1);
	QuickSort(back + 1, end);
}

int main()
{
	std::cin >> pointCount;
	pointArray = new Point[pointCount];

	for (int i = 0; i < pointCount; i++)
	{
		int position, color;
		std::cin >> position >> color;
		pointArray[i].position = position;
		pointArray[i].color = color;

	}

	// position �������� ����
	QuickSort(0, pointCount - 1);

	// �� ���󺰷� ���� ���� ��ġ�� ������. (���� ���� ���ٸ� -1)
	int* lastPosition = new int[pointCount + 1];
	// �� ���󺰷� 2��° ���� �ִ� ���� ��ġ�� ������.
	int* secondLeftPosition = new int[pointCount + 1];
	for (int i = 0; i < pointCount + 1; i++)
	{
		lastPosition[i] = -1;
		secondLeftPosition[i] = -1;
	}

	long long result = 0;
	// position�� ���� �ͺ��� ��ȸ�ϸ� lastPosition ���� ������ ������ ����, ���� ���� �Ÿ��� �����ϰ� ����� ���� ����� ����.
	for (int i = 0; i < pointCount; i++)
	{
		int color = pointArray[i].color;
		if (lastPosition[color] >= 0)
		{
			// 2ĭ��, �ٷ� �� ���� ������ ���� �� �ٷ� ������ ����� ���� ã�� ����� ����.
			if (secondLeftPosition[color] >= 0)
			{
				int frontDistance = lastPosition[color] - secondLeftPosition[color];
				int backDistance = pointArray[i].position - lastPosition[color];
				result += frontDistance < backDistance ? frontDistance : backDistance;
			}
			// �� ���󺰷� ù��° ���� �տ� �ִ� ���� �Ÿ��� ���� �� �����Ƿ� �ڿ� �ִ� ������ �Ÿ��� ���Ͽ� ����� ����.
			else
			{
				result += pointArray[i].position - lastPosition[color];
			}
		}

		// Last Data Update
		secondLeftPosition[color] = lastPosition[color];
		lastPosition[color] = pointArray[i].position;
	}

	for (int i = 0; i < pointCount + 1; i++)
	{
		// ���� �� ������ ���� �ڿ� �ִ� ���� �Ÿ��� ���� �� �����Ƿ� �տ� �ִ� ������ �Ÿ��� ���Ͽ� ����� ����.
		if (secondLeftPosition[i] >= 0)
		{
			if (lastPosition[i] >= 0)
			{
				result += lastPosition[i] - secondLeftPosition[i];
			}
		}
	}


	std::cout << result;
}