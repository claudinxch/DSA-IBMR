#include <iostream>
#include <vector>
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

	void MergeSort(int* arr, int size)
	{
		if (size <= 1) return;

		int middle = size / 2;
		int* leftArr = new int[middle];
		int* rightArr = new int[size - middle];

		int i = 0, j = 0;

		for (; i < size; i++)
		{
			if (i < middle) {
				leftArr[i] = arr[i];
			}
			else
			{
				rightArr[j] = arr[i];
				j++;
			}
		}

		MergeSort(leftArr, middle);
		MergeSort(rightArr, size - middle);
		Merge(leftArr, middle, rightArr, size - middle, arr);

		delete[] leftArr;
		delete[] rightArr;
	}

	void QuickSort(int* arr, int start, int end)
	{
		if (end <= start) return;

		int pivot = Partition(arr, start, end);
		QuickSort(arr, start, pivot - 1);
		QuickSort(arr, pivot + 1, end);
	}
private:
	void Merge(int* leftArr, int leftSize, int* rightArr, int rightSize, int* arr)
	{
		int i = 0, l = 0, r = 0;

		while (l < leftSize && r < rightSize)
		{
			if (leftArr[l] < rightArr[r])
			{
				arr[i] = leftArr[l];
				l++;
			}
			else
			{
				arr[i] = rightArr[r];
				r++;
			}
			i++;
		}

		while (l < leftSize)
		{
			arr[i] = leftArr[l];
			i++;
			l++;
		}

		while (r < rightSize)
		{
			arr[i] = rightArr[r];
			i++;
			r++;
		}
	}

	int Partition(int* arr, int start, int end)
	{
		int pivot = arr[end];
		int i = start - 1;

		for (int j = start; j < end; j++)
		{
			if (arr[j] < pivot) {
				i++;
				int temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
		i++;
		int temp = arr[i];
		arr[i] = arr[end];
		arr[end] = temp;

		return i;
	}
};