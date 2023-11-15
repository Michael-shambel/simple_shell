#include "main.h"

/**
 *is_chain - test if current char
 *@info: structure argument
 *@buf: the  char buffer
 *@p: adress
 *
 * Return: 1 or 0
 */
int is_chain(info_t *info, char *buf, size_t *pointer)
{
	size_t y = *pointer;

	if (buf[y] == '|' && buf[y + 1] == '|')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_OR;
	}
	else if (buf[y] == '&' && buf[y + 1] == '&')
	{
		buf[y] = 0;
		y++;
		info->cmd_buf_type = CMD_AND;
	}
	else if (buf[y] == ';')
	{
		buf[y] = 0;
		info->cmd_buf_type = CMD_CHAIN;
	}
	else
		return (0);
	*pointer = y;
	return (1);
}
/**
 *check_chain - check for continue
 *@info: structure argument
 *@buf: char buffer
 *@p: adress of position
 *@i: starting postion in buf
 *@len: length
 *
 * Return: nothing
 */
void check_chain(info_t *info, char *buf, size_t *pointer, size_t i, size_t len)
{
	size_t y = *pointer;

	if (info->cmd_buf_type == CMD_AND)
	{
		if (info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}
	if (info->cmd_buf_type == CMD_OR)
	{
		if (!info->status)
		{
			buf[i] = 0;
			y = len;
		}
	}

	*pointer = y;
}
/**
 *replace_alias - replace an aliases
 *@info: structure argument
 *
 *Return: 1 if replaced, 0 otherwise
 */
int replace_alias(info_t *info)
{
	int x;
	list_t *node;
	char *pointer;

	for (x = 0; x < 10; x++)
	{
		node = node_starts_with(info->alias, info->argv[0], '=');
		if (!node)
			return (0);
		free(info->argv[0]);
		pointer = _strchr(node->str, '=');
		if (!pointer)
			return (0);
		pointer = _strdup(pointer + 1);
		if (!pointer)
			return (0);
		info->argv[0] = pointer;
	}
	return (1);
}
/**
 *replace_vars - replace vars
 *@info: structure argument
 *
 *Return: 1 or 0
 */
int replace_vars(info_t *info)
{
	int x = 0;
	list_t *node;

	for (x = 0; info->argv[x]; x++)
	{
		if (info->argv[x][0] != '$' || !info->argv[x][1])
			continue;

		if (!_strcmp(info->argv[x], "$?"))
		{
			replace_string(&(info->argv[x]),
					_strdup(convert_number(info->status, 10, 0)));
			continue;
		}
		if (!_strcmp(info->argv[x], "$$"))
		{
			replace_string(&(info->argv[x]), _strdup(convert_number(getpid(), 10, 0)));
			continue;
		}
		node = node_starts_with(info->env, &info->argv[x][1], '=');
		if (node)
		{
			replace_string(&(info->argv[x]),
					_strdup(_strchr(node->str, '=') + 1));
			continue;
		}
		replace_string(&info->argv[x], _strdup(" "));
	}
	return (0);
}
/**
 *replace_string - replace string
 *@old: old string
 *@new: new string
 *
 * Return: 1 if placed, 0
 */
int replace_string(char **old, char *new)
{
	free(*old);
	*old = new;
	return (1);
}
