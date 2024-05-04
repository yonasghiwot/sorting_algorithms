#include "sort.h"

/**
* shift_down_heapify - change a binary tree into a complete binary heap
* using recurrssive shift down heapSort algorithmn
* @array: An array of integers representing a binary tree.
* @heap: size of heap data
* @i: index node of the binary tree.
* @size: ize of the array/tree.
*/

void shift_down_heapify(int *array, int heap, int i, int size)
{
	int large = i, left = 2 * i + 1, right = 2 * i + 2, t;

	if (left < heap && array[left] > array[large])
		large = left;
	if (right < heap && array[right] > array[large])
		large = right;
	if (large != i)
	{
		t = array[i], array[i] = array[large], array[large] = t;
		print_array(array, size);
		shift_down_heapify(array, heap, large, size);
	}
}

/**
* heap_sort - sorts array with shift down heap sort algorithm
* @array: array to sort
* @size: Size of array to sort
*/

void heap_sort(int *array, size_t size)
{
	int i = size / 2 - 1, temp;

	if (array == NULL || size < 2)
		return;
	for (; i >= 0; i--)
		shift_down_heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		temp = array[0];
		array[0] = array[i];
		array[i] = temp;
		if (i > 0)
			print_array(array, size);
		shift_down_heapify(array, i, 0, size);
	}

}
