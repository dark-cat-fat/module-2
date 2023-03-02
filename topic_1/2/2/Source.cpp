#include <iostream>

int func(int* arr, int size, int point)
{
	int left = 0;
	int right = size - 1;
	int label;
	int middle;

	if (point < arr[0])
		label = 0;

	else if (point >= arr[size - 1])
		label = size;

	else
	{
		while (right - left != 1)
		{
			middle = (left + right) / 2;
			
			
			if (point < arr[middle])
			{
				right = middle;
				label = left + 1;
			}

			else if (point > arr[middle])
			{
				left = middle;
				label = left + 1;
			}
		
			else
			{
				left = middle;
				label = middle + 1;
			}
		}
	}
	return size - label;
}


void main()
{
	setlocale(LC_ALL, "Russian");

	int arr[] {14, 16, 19, 32, 32, 32, 56, 69, 72};
	int size = sizeof(arr) / sizeof(arr[0]);

	std::cout << "Введите точку отсчёта: ";
	int point;
	std::cin >> point;

	std::cout << "Количество элементов в массиве больших, чем " << point << ": " << func(arr, size, point);
}