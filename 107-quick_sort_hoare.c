#include "sort.h"

void sort_algorithm(int *arr, int left, int right, size_t size);
int pivot_split(int *arr, int left, int right, size_t size);
/**
  * quick_sort_hoare - quicksort algorithm
  * @array: array to be sorted
  * @size: size of array
  */
void quick_sort_hoare(int *array, size_t size)
{
	sort_algorithm(array, 0, size - 1, size);

}

/**
  * sort_algorithm - function that sorting algorithm
  * @arr: array to be sorted
  * @left: leftmost index
  * @right: rightmost index
  * @size: size of full array
  * Return: void
  */
void sort_algorithm(int *arr, int left, int right, size_t size)
{
	int pivot;

	if ((right - left) < 2)
		return;
	pivot = pivot_split(arr, left, right, size);
	sort_algorithm(arr, left, pivot, size);
	sort_algorithm(arr, pivot, right, size);
}

/**
  * pivot_split - function to pivot and split array
  * @arr: array to be sorted
  * @left: leftmost index
  * @right:rightmost index
  * @size: size of full index
  * Return: pivot index
  */
int pivot_split(int *arr, int left, int right, size_t size)
{
	int i, i2, pivot, tmp;

	pivot = arr[right];
	i = left;
	i2 = right;

	while (1)
	{
		do i++;
		while (arr[i] < pivot);
		do i2--;
		while (arr[i2] > pivot);
		if (i < i2)
		{
			tmp = arr[i2];
			arr[i2] = arr[i];
			arr[i] = tmp;
			print_array(arr, size);
		}
		else
			return (i2);
	}
}
