#include "hash_tables.h"

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of the array.
 *
 * Return: A pointer to the created sorted hash table, or NULL on failure.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht = NULL;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
	return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
	{
	free(ht);
	return (NULL);
	}

	for (i = 0; i < size; i++)
	ht->array[i] = NULL;

	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - Inserts a key/value pair into the sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key to insert.
 * @value: The value to insert.
 *
 * Return: 1 if successful, 0 otherwise.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node = NULL, *current = NULL, *prev = NULL;

	if (ht == NULL || key == NULL || *key == '\0' || value == NULL)
	return (0);

	/* Calculate the index using djb2 hash function */
	unsigned long int index = key_index((unsigned char *)key, ht->size);

	current = ht->array[index];
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
	prev = current;
	current = current->next;
	}

	new_node = malloc(sizeof(shash_node_t));
	if (new_node == NULL)
	return (0);

	new_node->key = strdup(key);
	if (new_node->key == NULL)
	{
	free(new_node);
	return (0);
	}

	new_node->value = strdup(value);
	if (new_node->value == NULL)
	{
	free(new_node->key);
	free(new_node);
	return (0);
	}

	if (prev == NULL)
	{
	new_node->next = ht->array[index];
	ht->array[index] = new_node;
	}
	else
	{
	new_node->next = prev->next;
	prev->next = new_node;
	}

	/* Insert into the sorted linked list */
	shash_sorted_insert(ht, new_node);

	return (1);
}

/**
 * shash_sorted_insert - Inserts a node into the sorted linked list.
 * @ht: The sorted hash table.
 * @node: The node to insert.
 */
void shash_sorted_insert(shash_table_t *ht, shash_node_t *node)
{
	shash_node_t *current = NULL;

	if (ht == NULL || node == NULL)
	return;

	if (ht->shead == NULL)
	{
	ht->shead = node;
	ht->stail = node;
	node->sprev = NULL;
	node->snext = NULL;
	}
	else
	{
	current = ht->shead;
	while (current != NULL)
	{
	if (strcmp(node->key, current->key) <= 0)
	{
	node->sprev = current->sprev;
	node->snext = current;
	if (current->sprev != NULL)
	current->sprev->snext = node;
	else
	ht->shead = node;
	current->sprev = node;
	return;
	}
	if (current->snext == NULL)
	break;
	current = current->snext;
	}
	current->snext = node;
	node->sprev = current;
	node->snext = NULL;
	ht->stail = node;
	}
}

/**
 * shash_table_get - Retrieves the value associated with a key in a sorted hash table.
 * @ht: The sorted hash table.
 * @key: The key to look for.
 *
 * Return: The value associated with the key, or NULL if key couldn't be found.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	unsigned long int index;
	shash_node_t *current;

	if (ht == NULL || key == NULL || *key == '\0')
	return (NULL);

	/* Calculate the index using djb2 hash function */
	index = key_index((unsigned char *)key, ht->size);

	current = ht->array[index];
	while (current != NULL)
	{
	if (strcmp(current->key, key) == 0)
	return (current->value);
	current = current->next;
	}

	return (NULL);
}

/**
 * shash_table_print - Prints the sorted hash table.
 * @ht: The sorted hash table to print.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *current = ht->shead;
	int first = 1;

	printf("{");
	while (current != NULL)
	{
	if (!first)
	printf(", ");
	printf("'%s': '%s'", current->key, current->value);
	first = 0;
	current = current->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints the sorted hash table in reverse order.
 * @ht: The sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *current = ht->stail;
	int first = 1;

	printf("{");
	while (current != NULL)
	{
	if (!first)
	printf(", ");
	printf("'%s': '%s'", current->key, current->value);
	first = 0;
	current = current->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: The sorted hash table to delete.
 */
void shash_table_delete(shash_table_t *ht)
{
	unsigned long int i;
	shash_node_t *node, *temp;

	if (ht == NULL)
	return;

	for (i = 0; i < ht->size; i++)
	{
	node = ht->array[i];
	while (node != NULL)
	{
	temp = node->next;
	free(node->key);
	free(node->value);
	free(node);
	node = temp;
	}
	}

	free(ht->array);

	while (ht->shead != NULL)
	{
	node = ht->shead;
	ht->shead = ht->shead->snext;
	free(node->key);
	free(node->value);
	free(node);
	}

	free(ht);
}

