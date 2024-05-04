#include "sort.h"

/**
 * shell_sort - a function Sorts an array of integers in
 * in ascending order using the Shell sort algorithm
 * @array: array to be sorted
 * @size: size of the array to sort
 *
 * Return: nothing it is void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, space = 1;
	int insert;

	if (array == NULL || size < 2)
		return;

	while (space < size / 3)
		space = space * 3 + 1;

	while (space > 0)
	{
		for (i = space; i < size; i++)
		{
			insert = array[i];
			for (j = i; j >= space && array[j - space] > insert; j = j - space)
				array[j] = array[j - space];
			array[j] = insert;
		}
		space = (space - 1) / 3;
		print_array(array, size);
	}
}
