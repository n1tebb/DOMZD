#include <iostream>
#include <Windows.h>
#include <cstdlib>
#include <climits>


// Задание 1
const int size = 100;
const int length = 10;

int findMinSum(int arr[], int index, int minSum, int currIndex = 0, int currSum = 0)
{
	if (index > size - length)
	{
		return currIndex;
	}

	if (index == 0)
	{
		for (int i = 0; i < length; i++)
		{
			currSum += arr[i];
		}
		minSum = currSum;
	}
	else
	{
		currSum = currSum - arr[index - 1] + arr[index + length + 1];
	}

	if (currSum < minSum)
	{
		minSum = currSum;
		currIndex = index;
	}

	return findMinSum(arr, index + 1, minSum, currIndex, currSum);
}

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	srand(time(NULL));


	int arr[size];
	for (int i = 0; i < size; i++)
	{
		arr[i] = rand() % 200 - 100;
	}

	int minSum = INT_MAX;
	int minPos = findMinSum(arr, 0, minSum);

	std::cout << "Позиция с минимальной суммой последовательности длинной 10: " << minPos << "\n";
	std::cout << "Минимальная сумма: " << minSum << "\n";
	
	return 0;
}

//Задание 2
