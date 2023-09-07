#include "hash_tables.h"

/**
 * key_index - Calculates the index for a given key in a hash table array.
 * @key: The key to calculate the index for.
 * @size: The size of the hash table array.
 *
 * Return: The calculated index for the key.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	unsigned long int hash_value;

    /* Calculate the hash value using hash_djb2 function */
	hash_value = hash_djb2(key);

    /* Calculate the index by taking the modulus of hash_value with size */
	return (hash_value % size);
}

