#include <iostream>

class PrizeTable
{
public:
	PrizeTable(int prize, int rank)
	{
		this->prize = prize;
		this->rank = rank;
	};

	int prize;
	int rank;
};

const int firstPrizeTableSize = 6;
PrizeTable* firstPrizeTable = new PrizeTable[firstPrizeTableSize] {
	PrizeTable(5000000, 1),
	PrizeTable(3000000, 3),
	PrizeTable(2000000, 6),
	PrizeTable(500000, 10),
	PrizeTable(300000, 15),
	PrizeTable(100000, 21)
};

const int secondPrizeTableSize = 5;
PrizeTable* secondPrizeTable = new PrizeTable[secondPrizeTableSize]{
	PrizeTable(5120000, 1),
	PrizeTable(2560000, 3),
	PrizeTable(1280000, 7),
	PrizeTable(640000, 15),
	PrizeTable(320000, 31)
};

int main()
{
	int n;
	std::cin >> n;
	for (int i = 0; i < n; i++)
	{
		int firstRank, secondRank;

		std::cin >> firstRank >> secondRank;

		int firstIndex = 0, secondIndex = 0;
		if (firstRank != 0)
		{
			while (true)
			{
				if (firstPrizeTable[firstIndex].rank >= firstRank)
				{
					break;
				}
			
				if (firstIndex < firstPrizeTableSize - 1)
				{
					firstIndex++;
				}
				else
				{
					firstIndex = -1;
					break;
				}
			}
		}

		if (secondRank != 0)
		{
			while (true)
			{
				if (secondPrizeTable[secondIndex].rank >= secondRank)
				{
					break;
				}

				if (secondIndex < secondPrizeTableSize - 1)
				{
					secondIndex++;
				}
				else
				{
					secondIndex = -1;
					break;
				}
			}
		}

		int result = 0;
		result += firstRank != 0 && firstIndex >= 0 ? firstPrizeTable[firstIndex].prize : 0;
		result += secondRank != 0 && secondIndex >= 0 ? secondPrizeTable[secondIndex].prize : 0;

		std::cout << result << std::endl;
	}
}