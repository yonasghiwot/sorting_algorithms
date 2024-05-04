#include "sort.h"
/**
 * _swap_numbers - swap two numbers
 * @a: integer numbers to be swapped
 * @b: integer numbers to be swaped
 **/
void _swap_numbers(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}
/**
 * selection_sort - sort array using selection sort algorithm
 * @array: array to be sorted
 * @size: array size
 **/

void selection_sort(int *array, size_t size)
{
	unsigned int i, j, min;

	if (array == NULL || size < 2)
		return;

	for (i = 0; i < size; i++)
	{
		min = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[min] > array[j])
				min = j;
		}
		if (min != i)
		{
			_swap_numbers(&array[i], &array[min]);
			print_array(array, size);
		}
	}

}
