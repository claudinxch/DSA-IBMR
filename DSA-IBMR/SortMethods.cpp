#include <iostream>
#include <ctime>

class SortMethods {
public:
	SortMethods() {}

	void BubbleSort(int* arr, int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			for (int j = 0; j < size - i - 1; j++)
			{
				if(arr[j] > arr[j+1])
				{
					int temp = arr[j];
					arr[j] = arr[j+1];
					arr[j+1] = temp;
				}
			}
		}
	}

	void SelectionSort(int* arr, int size)
	{
		for (int i = 0; i < size - 1; i++)
		{
			int min = i;
			for (int j = i + 1; j < size; j++)
			{
				if (arr[j] < arr[min])
				{
					min = j;
				}
			}
			if (min != i)
			{
				int temp = arr[i];
				arr[i] = arr[min];
				arr[min] = temp;
			}
		}
	}

	void InsertionSort(int* arr, int size)
	{
		for (int i = 1; i <= size - 1; i++)
		{
			int temp = arr[i];
			int j = i - 1;
			while (j>=0 && arr[j] > temp)
			{
				arr[j + 1] = arr[j];
				j--;
			}
			arr[j + 1] = temp;
		}
	}

};