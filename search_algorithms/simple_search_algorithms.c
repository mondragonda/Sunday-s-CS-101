#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

const int LIST_NUMBER_OF_ELEMENTS = 200000000;

unsigned short execute_search_function_with_benchmark(bool (*search_function)(int *, int), int * list, int element)
{
	time_t starting_time = time(NULL);
	search_function(list, element);
	time_t ending_time = time(NULL);

	return ending_time - starting_time; 
}

bool linear_search(int * list, int element)
{
	for (int i = 0; i < LIST_NUMBER_OF_ELEMENTS; i++) {
		if(list[i] == element) {
			return true;
		}
	}

	return false;
}

bool binary_search(int * list, int element) 
{
	return false;
}


int main(int argc, char **argv)
{
	int* list = calloc(LIST_NUMBER_OF_ELEMENTS, sizeof(int));

	unsigned short took_seconds = execute_search_function_with_benchmark(&linear_search, list, LIST_NUMBER_OF_ELEMENTS - 1);
	printf("Linear search took: %d seconds", took_seconds);
	
	took_seconds = execute_search_function_with_benchmark(&binary_search, list, LIST_NUMBER_OF_ELEMENTS - 1);
	printf("Binary search took: %d seconds", took_seconds);
}
