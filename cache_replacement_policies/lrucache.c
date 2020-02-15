#define CACHE_BLOCK_DATA_SIZE 2

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stddef.h>

typedef struct {
	int age_bit;
	char data;
} CacheBlock;

typedef struct {
	CacheBlock * blocks;
	int block_count;
	int hits;
	int misses;
} LRUCache;

_Bool cache_write(CacheBlock block);

CacheBlock cache_read(char data_to_read);

void print_cache_stats(LRUCache cache)
{
	printf("\n");
	printf("Cache block count: %d\n", cache.block_count);
	printf("Cache size: %lu bytes\n", cache.block_count * sizeof(CacheBlock));
	printf("Cache hits count: %d\n", cache.hits);
	printf("Cache misses count: %d\n", cache.misses);
	printf("\n");
}

int main(int argc, char *argv[])
{
	LRUCache *cache = calloc(1, sizeof(LRUCache));
	print_cache_stats(*cache);

	char* cache_max_elements_input = malloc(3*sizeof(char));

	printf("Enter max elements of the cache: ");
	scanf("%2c", cache_max_elements_input);

	printf("Entered max cache elements %s", cache_max_elements_input);

	free(cache);
	free(cache_max_elements_input);

	return EXIT_SUCCESS;
}
