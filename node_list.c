#include "main.h"

/**
 * add_node - adds a node to the start
 * @head: address of pointer to head node
 * @string: string field
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node(list_t **head, const char *string, int num)
{
	list_t *new_head;

	if (!head)
		return (NULL);
	new_head = malloc(sizeof(list_t));
	if (!new_head)
		return (NULL);
	_memset((void *)new_head, 0, sizeof(list_t));
	new_head->num = num;
	if (string)
	{
		new_head->str = _strdup(string);
		if (!new_head->str)
		{
			free(new_head);
			return (NULL);
		}
	}
	new_head->next = *head;
	*head = new_head;
	return (new_head);
}

/**
 * add_node_end - adds a node to the end of the list
 * @head: address of pointer to head node
 * @string: str field of node
 * @num: node index used by history
 *
 * Return: size of list
 */
list_t *add_node_end(list_t **head, const char *string, int in_num)
{
	list_t *new_node, *node;

	if (!head)
		return (NULL);

	node = *head;
	new_node = malloc(sizeof(list_t));
	if (!new_node)
		return (NULL);
	_memset((void *)new_node, 0, sizeof(list_t));
	new_node->num = in_num;
	if (string)
	{
		new_node->str = _strdup(string);
		if (!new_node->str)
		{
			free(new_node);
			return (NULL);
		}
	}
	if (node)
	{
		while (node->next)
			node = node->next;
		node->next = new_node;
	}
	else
		*head = new_node;
	return (new_node);
}

/**
 * print_list_str - prints the str element of a list_t
 * @n: pointer to first node
 *
 * Return: size of list
 */
size_t print_list_str(const list_t *n)
{
	size_t x = 0;

	while (n)
	{
		_puts(n->str ? n->str : "(nil)");
		_puts("\n");
		n = n->next;
		x++;
	}
	return (x);
}

/**
 * delete_node_at_index - deletes node at index
 * @h: address of pointer to first node
 * @ind: index of node to delete
 *
 * Return: 1 on success, 0 on failure
 */
int delete_node_at_index(list_t **h, unsigned int ind)
{
	list_t *n, *prev_n;
	unsigned int x = 0;

	if (!h || !*h)
		return (0);

	if (!ind)
	{
		n = *h;
		*h = (*h)->next;
		free(n->str);
		free(n);
		return (1);
	}
	n = *h;
	while (n)
	{
		if (x == ind)
		{
			prev_n->next = n->next;
			free(n->str);
			free(n);
			return (1);
		}
		x++;
		prev_n = n;
		n = n->next;
	}
	return (0);
}

/**
 * free_list - frees all nodes of a list
 * @head_ptr: address of pointer to head node
 *
 * Return: void
 */
void free_list(list_t **head_ptr)
{
	list_t *n, *next_n, *h;

	if (!head_ptr || !*head_ptr)
		return;
	h = *head_ptr;
	n = h;
	while (n)
	{
		next_n = n->next;
		free(n->str);
		free(n);
		n = next_n;
	}
	*head_ptr = NULL;
}
