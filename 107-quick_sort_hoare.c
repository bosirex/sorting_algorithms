#include "sort.h"

void swap(int *a, int *b);
int hoare_partitioning(int *array, size_t size, int left, int right);
void hoare_sorting(int *array, size_t size, int left, int right);
void quick_sort_hoare(int *array, size_t size);

/**
 * swap - Swap two integers in an array.
 * @a: The first integer to swap.
 * @b: The second integer to swap.
 */
void swap(int *a, int *b)
{
	int tmp;

	tmp = *a;
	*a = *b;
	*b = tmp;
}

/**
 * hoare_partitioning - Order a subset of an array of integers
 *                   according to the hoare partition scheme.
 * @array: The array of integers.
 * @size: The size of the array.
 * @left: The starting index of the subset to order.
 * @right: The ending index of the subset to order.
 *
 * Return: The final partition index.
 *
 * Description: Uses the last element of the partition as the driver.
 * Prints the array after each swap of two elements.
 */
int hoare_partitioning(int *array, size_t size, int left, int right)
{
	int driver, up, down;

	driver = array[right];
	for (up = left - 1, down = right + 1; up < down;)
	{
		do {
			up++;
		} while (array[up] < driver);
		do {
			down--;
		} while (array[down] > driver);

		if (up < down)
		{
			swap(array + up, array + down);
			print_array(array, size);
		}
	}

	return (up);
}

/**
 * hoare_sorting - Implement the quicksort algorithm through recursion.
 * @array: An array of integers to sort.
 * @size: The size of the array.
 * @left: The starting index of the array partition to order.
 * @right: The ending index of the array partition to order.
 *
 * Description: Uses the Hoare partition scheme.
 */
void hoare_sorting(int *array, size_t size, int left, int right)
{
	int belong;

	if (right - left > 0)
	{
		belong = hoare_partitioning(array, size, left, right);
		hoare_sorting(array, size, left, belong - 1);
		hoare_sorting(array, size, belong, right);
	}
}

/**
 * quick_sort_hoare - Sort an array of integers in ascending
 *                    order using the quicksort algorithm.
 * @array: An array of integers.
 * @size: The size of the array.
 *
 * Description: Uses the Hoare partition scheme. Prints
 * the array after each swap of two elements.
 */
void quick_sort_hoare(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	hoare_sorting(array, size, 0, size - 1);
}
