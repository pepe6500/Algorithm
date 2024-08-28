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
			
			// 기준 Point보다 한칸 뒤에 있는 Point
			std::set<long>::const_iterator backPoint = currentPoint;
			backPoint++;

			// 기준 Point보다 한칸 앞에 있는 Point
			std::set<long>::const_iterator frontPoint = currentPoint;
			// 접근하는 Point가 Set중 가장 앞에 있는 Point라면 그 전의 Point가 없으므로 end를 넣어줌
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