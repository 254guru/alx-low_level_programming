#include "hash_tables.h"

/**
 * hash_table_set - adds or updates a key/value pair in a hash table
 * @ht: hash table to add the key/value pair in
 * @key: key to add
 * @value: value associated with key
 *
 * Return: 1 if successful, 0 otherwise
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int i;
	hash_node_t *new_node, *current;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	i = key_index((unsigned char *)key, ht->size);

	current = ht->array[i];
	while (current != NULL)
	{
		if (strcmp(current->key, key) == 0)
		{
			free(current->value);
			current->value = strdup(value);
			if (current->value == NULL)
				return (0);
			return (1);
		}
		current = current->next;
	}
	new_node = malloc(sizeof(hash_node_t));
	if (new_node == NULL)
		return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
		free(new_node);
		return (0);
	}
	
	new_node->value = strdup(value);
	if (new_node->key == NULL)
	{
		free(new_node->key);
		free(new_node);
		return (0);
	}

	new_node->next = ht->array[i];
	ht->array[i] = new_node;

	return (1);
}
