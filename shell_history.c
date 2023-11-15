#include "main.h"

/**
 *get_history_file - get history file
 *@info: structure argument
 *
 *Return: allocat hist
 *
 */
char *get_history_file(info_t *info)
{
	char *buffer, *direct;

	direct = _getenv(info, "HOME=");
	if (!direct)
		return (NULL);
	buffer = malloc(sizeof(char) * (_strlen(direct) + _strlen(HIST_FILE) + 2));
	if (!buffer)
		return (NULL);
	buffer[0] = 0;
	_strcpy(buffer, direct);
	_strcat(buffer, "/");
	_strcat(buffer, HIST_FILE);
	return (buffer);
}
/**
 *write_history - creaates a file
 *@info: structure
 *
 *Return: 1 or 0
 */
int write_history(info_t *info)
{
	ssize_t fd;
	char *file_name = get_history_file(info);
	list_t *node = NULL;

	if (!file_name)
		return (-1);

	fd = open(file_name, O_CREAT | O_TRUNC | O_RDWR, 0644);
	free(file_name);
	if (fd == -1)
		return (-1);
	for (node = info->history; node; node = node->next)
	{
		_putsfd(node->str, fd);
		_putfd('\n', fd);
	}
	_putfd(BUF_FLUSH, fd);
	close(fd);
	return (1);
}
/**
 * read_history - reads history from file
 * @info: the parameter struct
 *
 * Return: histcount on success, 0 otherwise
 */
int read_history(info_t *info)
{
	int x, lt = 0, l_count = 0;
	ssize_t fd, rdlen, fsize = 0;
	struct stat st;
	char *buffer = NULL, *filename = get_history_file(info);

	if (!filename)
		return (0);

	fd = open(filename, O_RDONLY);
	free(filename);
	if (fd == -1)
		return (0);
	if (!fstat(fd, &st))
		fsize = st.st_size;
	if (fsize < 2)
		return (0);
	buffer = malloc(sizeof(char) * (fsize + 1));
	if (!buffer)
		return (0);
	rdlen = read(fd, buffer, fsize);
	buffer[fsize] = 0;
	if (rdlen <= 0)
		return (free(buffer), 0);
	close(fd);
	for (x = 0; x < fsize; x++)
		if (buffer[x] == '\n')
		{
			buffer[x] = 0;
			build_history_list(info, buffer + lt, l_count++);
			lt = x + 1;
		}
	if (lt != x)
		build_history_list(info, buffer + lt, l_count++);
	free(buffer);
	info->histcount = l_count;
	while (info->histcount-- >= HIST_MAX)
		delete_node_at_index(&(info->history), 0);
	renumber_history(info);
	return (info->histcount);
}

/**
 * build_history_list - adds entry to a history linked list
 * @info: Structure containing potential arguments. Used to maintain
 * @buf: buffer
 * @linecount: the history linecount, histcount
 *
 * Return: Always 0
 */
int build_history_list(info_t *info, char *buffer, int l_count)
{
	list_t *node = NULL;

	if (info->history)
		node = info->history;
	add_node_end(&node, buffer, l_count);

	if (!info->history)
		info->history = node;
	return (0);
}

/**
 * renumber_history - renumbers the history linked list after changes
 * @info: Structure containing potential arguments. Used to maintain
 *
 * Return: the new histcount
 */
int renumber_history(info_t *info)
{
	list_t *node = info->history;
	int x = 0;

	while (node)
	{
		node->num = x++;
		node = node->next;
	}
	return (info->histcount = x);
}
