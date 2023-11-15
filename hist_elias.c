#include "main.h"

/**
 *_myhistory - display the history list
 *@info: structure argument
 *
 *Return: Always 0
 */
int _myhistory(info_t *info)
{
	print_list(info->history);
	return (0);
}
/**
 *unset_alias - sets alias
 *@info: structure argument
 *@str: alias string
 *
 * Return: success
 */
int unset_alias(info_t *info, char *str)
{
	char *pointer, car;
	int resp;

	pointer = _strchr(str, '=');
	if (!pointer)
		return (1);
	car = *pointer;
	*pointer = 0;
	resp = delete_node_at_index(&(info->alias),
	     get_node_index(info->alias, node_starts_with(info->alias, str, -1)));
	*pointer = car;
	return (resp);
}
/**
 *set_alias - set alias
 *@info: structure argument
 *@str: slias string
 *
 *Return: always sucess
 */
int set_alias(info_t *info, char *str)
{
	char *pointer;

	pointer = _strchr(str, '=');
	if (!pointer)
		return (1);
	if (!*++pointer)
		return (unset_alias(info, str));
	unset_alias(info, str);
	return (add_node_end(&(info->alias), str, 0) == NULL);
}
/**
 *print_alias - print an alias
 *@node: alias node
 *
 *Return: Always 0 on sucess
 */
int print_alias(list_t *node)
{
	char *pointer = NULL, *a = NULL;

	if (node)
	{
		pointer = _strchr(node->str, '=');
		for (a = node->str; a <= pointer; a++)
			_putchar(*a);
		_putchar('\'');
		_puts(pointer + 1);
		_puts("'\n");
		return (0);
	}
	return (1);
}
/**
 *_myalias - emulate the alias command
 *@info: structure argument
 *Return: zero
 */
int _myalias(info_t *info)
{
	int x = 0;
	char *pointer = NULL;
	list_t *node = NULL;

	if (info->argc == 1)
	{
		node = info->alias;
		while (node)
		{
			print_alias(node);
			node = node->next;
		}
		return (0);
	}
	for (x = 1; info->argv[x]; x++)
	{
		pointer = _strchr(info->argv[x], '=');
		if (pointer)
			set_alias(info, info->argv[x]);
		else
			print_alias(node_starts_with(info->alias, info->argv[x], '='));
	}
	return (0);
}
