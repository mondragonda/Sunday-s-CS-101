#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>
#include <math.h>

const int LIST_NUMBER_OF_ELEMENTS = 1000000000;

void fill_list(int * list)
{
	printf("Filling the list with values...\n");
	int counter = 0;
	while(counter < LIST_NUMBER_OF_ELEMENTS)
	{
		list[counter] = counter;
		counter++;
	}
	printf("Finished filling the list\n");
}

long double execute_search_function_with_benchmark(bool (*search_function)(int *, int), int * list, int element)
{
	time_t starting_time = time(NULL);
	printf("Search started\n");
	search_function(list, element);
	time_t ending_time = time(NULL);
	printf("Search finished\n");

	return ending_time - starting_time;
}

bool linear_search(int * list, int element)
{
	for (int i = 0; i < LIST_NUMBER_OF_ELEMENTS; i++) {
		if(list[i] == element) {
			printf("Found element in linear search\n");
			return true;
		}
	}

	return false;
}

bool binary_search(int * list, int element)
{
	int left = 0, right = LIST_NUMBER_OF_ELEMENTS - 1, mid;

	while(left < right) {
		mid = (left + right) / 2;
		if (element > list[mid]) {
			left = mid + 1;
		} else {
			right = mid;
		}
	}

	if(list[left] == element) {
		printf("Found element in binary search\n");
		return true;
	}

	return false;
}


int main(int argc, char **argv)
{
	int* list = calloc(LIST_NUMBER_OF_ELEMENTS, sizeof(int));

	fill_list(list);

	long double took_seconds = execute_search_function_with_benchmark(&binary_search, list, LIST_NUMBER_OF_ELEMENTS - 1);
	printf("Binary search took: %.19Lf seconds\n", took_seconds);

	took_seconds = execute_search_function_with_benchmark(&linear_search, list, LIST_NUMBER_OF_ELEMENTS - 1);
	printf("Linear search took: %.19Lf seconds\n", took_seconds);

	free(list);
}
