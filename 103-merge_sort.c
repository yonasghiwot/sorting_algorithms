#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
void Top_Down_Merge(size_t start, size_t middle, size_t end, int *dest, int *source);
void Top_Down_SplitMerge(size_t start, size_t end, int *array, int *copy);
/**
 * Top_Down_Merge- function taht sorts and merges the sub arrays in source
 * @start: starting index for left sub array
 * @middle: end index for left sub array and
 * starting index for the right sub array
 * @end: end index for the right sub array
 * @dest: destination for data
 * @source: source of data
 *
 * Return: void
 */
void Top_Down_Merge(size_t start, size_t middle, size_t end, int *dest, int *source)
{
	size_t i, j, k;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(source + start, middle - start);
	printf("[right]: ");
	print_array(source + middle, end - middle);
	i = start;
	j = middle;
	for (k = start; k < end; k++)
	{
		if (i < middle && (j >= end || source[i] <= source[j]))
		{
			dest[k] = source[i];
			i++;
		}
		else
		{
			dest[k] = source[j];
			j++;
		}
	}
	printf("[Done]: ");
	print_array(dest + start, end - start);
}

/**
 * Top_Down_SplitMerge - recursively splits the array and merges the sorted arrays
 * @start: starting index (inclusive)
 * @end: end index (exclusive)
 * @array: the array to sort
 * @copy: copy of the array
 *
 * Return: void
 */
void Top_Down_SplitMerge(size_t start, size_t end, int *array, int *copy)
{
	size_t middle;

	if (end - start < 2)
		return;
	middle = (start + end) / 2;
	Top_Down_SplitMerge(start, middle, array, copy);
	Top_Down_SplitMerge(middle, end, array, copy);
	Top_Down_Merge(start, middle, end, array, copy);
	for (middle = start; middle < end; middle++)
		copy[middle] = array[middle];
}

/**
 * merge_sort - sorts an array of integers in ascending
 * order using the Merge sort algorithm
 * @array: array to sort
 * @size: size of the array
 *
 * Return: void
 */
void merge_sort(int *array, size_t size)
{
	size_t i;
	int *copy;

	if (array == NULL || size < 2)
		return;
	copy = malloc(sizeof(int) * size);
	if (copy == NULL)
		return;
	for (i = 0; i < size; i++)
		copy[i] = array[i];
	Top_Down_SplitMerge(0, size, array, copy);
	free(copy);
}
