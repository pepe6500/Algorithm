#include <iostream>
#include <set>

struct Point
{
	long position;
	long color;
};

Point* pointArray;
long pointCount;

int main()
{
	std::cin >> pointCount;
	pointArray = new Point[pointCount];

	std::set<long>* pointSets = new std::set<long>[pointCount + 1];

	for (int i = 0; i < pointCount; i++)
	{
		long position, color;
		std::cin >> position >> color;
		pointArray[i].color = color;
		pointArray[i].position = position;
		pointSets[color].insert(position);
	}

	long long result = 0;

	for (long i = 0; i < pointCount; i++)
	{
		Point point = pointArray[i];
		if (pointSets[point.color].size() >= 2)
		{

			std::set<long>::const_iterator currentPoint = pointSets[point.color].find(point.position);
			
			// ���� Point���� ��ĭ �ڿ� �ִ� Point
			std::set<long>::const_iterator backPoint = currentPoint;
			backPoint++;

			// ���� Point���� ��ĭ �տ� �ִ� Point
			std::set<long>::const_iterator frontPoint = currentPoint;
			// �����ϴ� Point�� Set�� ���� �տ� �ִ� Point��� �� ���� Point�� �����Ƿ� end�� �־���
			if (currentPoint == pointSets[point.color].begin())
			{
				frontPoint = pointSets[point.color].end();
			}
			else
			{
				frontPoint--;
			}

			long frontPointDistance = frontPoint != pointSets[point.color].end() ? point.position - *frontPoint : 2147483647L;
			long backPointDistance = backPoint != pointSets[point.color].end() ? *backPoint - point.position : 2147483647L;

			result += frontPointDistance < backPointDistance ? frontPointDistance : backPointDistance;
		}
	}
	
	std::cout << result;
}