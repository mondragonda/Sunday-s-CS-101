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
	int last_age_bit;
} LRUCache;

CacheBlock cache_write(LRUCache * cache, char data_to_write);
CacheBlock cache_read(LRUCache * cache, char data_to_read);

void print_cache_stats(LRUCache cache)
{
	printf("\n");
	printf("Cache block count: %d\n", cache.block_count);
	printf("Cache size: %lu bytes\n", cache.block_count * sizeof(CacheBlock));
	printf("Cache hits count: %d\n", cache.hits);
	printf("Cache misses count: %d\n", cache.misses);
	printf("\n");
}

CacheBlock cache_read(LRUCache * cache, char data_to_read)
{
	int block_index = 1;

	while (block_index <= cache->block_count) {
		if(cache->blocks[block_index].data == data_to_read){
			cache->hits += 1;
			printf("\n");
			printf("Cache block hit\n");
			printf("Cache block data: %c\n", cache->blocks[block_index].data);
			printf("Cache block age bit: %d\n", cache->blocks[block_index].age_bit);
			printf("\n");
			return cache->blocks[block_index];
		}

		block_index += 1;
	}

	cache->misses = cache->misses + 1;

	return cache_write(cache, data_to_read);
}

CacheBlock cache_write(LRUCache * cache, char data_to_write)
{
	CacheBlock * new_cache_block = calloc(1, sizeof(CacheBlock));
	new_cache_block->age_bit = cache->last_age_bit + 1;
	new_cache_block->data = data_to_write;

	cache->blocks = (CacheBlock*) realloc(cache->blocks, (sizeof(cache->blocks) + sizeof(CacheBlock)));

	cache->block_count = cache->block_count + 1;
	cache->blocks[cache->block_count] = *new_cache_block;
	cache->last_age_bit = new_cache_block->age_bit;

	printf("\n");
	printf("Written cache block\n");
	printf("Cache block data: %c\n", cache->blocks[cache->block_count].data);
	printf("Cache block age bit: %d\n", cache->blocks[cache->block_count].age_bit);
	printf("\n");

	return *new_cache_block;
}

int main(int argc, char **argv)
{
	LRUCache * cache = calloc(1, sizeof(LRUCache));

	print_cache_stats(*cache);

	cache_read(cache, 'D');

	print_cache_stats(*cache);

	cache_read(cache, 'D');

	print_cache_stats(*cache);

	free(cache);

	return EXIT_SUCCESS;
}
