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
	// 입력된 원소가 1개라면 정렬이 완료된 경우로 return 함.
	if (start >= end)
	{
		return;
	}

	int pivotPosition = pointArray[start].position;

	int front = start + 1;
	int back = end;
	// 자리 바꾸는 용 임시 Point
	Point tempPoint;

	// pivot을 기준으로 작은 값은 좌측, 큰 값은 우측에 위치하도록 정렬함.
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

	// 정렬 후 pivot을 중앙으로 이동
	tempPoint = pointArray[start];
	pointArray[start] = pointArray[back];
	pointArray[back] = tempPoint;

	// 정렬되지 않은 pivot의 좌, 우 부분을 재귀호출로 정렬함.
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

	// position 기준으로 정렬
	QuickSort(0, pointCount - 1);

	// 각 색상별로 이전 점의 위치를 저장함. (이전 점이 없다면 -1)
	int* lastPosition = new int[pointCount + 1];
	// 각 색상별로 2번째 전에 있는 점의 위치를 저장함.
	int* secondLeftPosition = new int[pointCount + 1];
	for (int i = 0; i < pointCount + 1; i++)
	{
		lastPosition[i] = -1;
		secondLeftPosition[i] = -1;
	}

	long long result = 0;
	// position이 작은 것부터 순회하며 lastPosition 기준 동일한 색상의 좌측, 우측 점의 거리를 측정하고 가까운 것을 결과에 더함.
	for (int i = 0; i < pointCount; i++)
	{
		int color = pointArray[i].color;
		if (lastPosition[color] >= 0)
		{
			// 2칸전, 바로 전 점의 정보가 있을 때 바로 전에서 가까운 점을 찾아 결과에 더함.
			if (secondLeftPosition[color] >= 0)
			{
				int frontDistance = lastPosition[color] - secondLeftPosition[color];
				int backDistance = pointArray[i].position - lastPosition[color];
				result += frontDistance < backDistance ? frontDistance : backDistance;
			}
			// 각 색상별로 첫번째 점은 앞에 있는 점의 거리를 구할 수 없으므로 뒤에 있는 점과의 거리를 구하여 결과에 더함.
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
		// 색상 별 마지막 점은 뒤에 있는 점의 거리를 구할 수 없으므로 앞에 있는 점과의 거리를 구하여 결과에 더함.
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