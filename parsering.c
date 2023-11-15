#include "main.h"

/**
 *is_cmd - determine file an executable
 *@info: structure argument
 *@path: path to the file
 *
 * Return: 1 if ok, otherwise 0
 */
int is_cmd(info_t *info, char *path)
{
	struct stat st;

	(void)info;
	if (!path || stat(path, &st))
		return (0);

	if (st.st_mode & S_IFREG)
	{
		return (1);
	}
	return (0);
}
/**
 *dup_chars - duplicate
 *@pathstr: path of the string
 *@start: starting index
 *@stop: stop index
 *
 * Return: pointer to new buffer
 */
char *dup_chars(char *pathstr, int start, int stop)
{
	static char buffer[1024];
	int x = 0, y = 0;

	for (y = 0, x = start; x < stop; x++)
		if (pathstr[x] != ':')
			buffer[y++] = pathstr[x];
	buffer[y] = 0;
	return (buffer);
}
/**
 *find_path - find this cmd in the path
 *@info: structure argument
 *@pathstr: path of string
 *@cmd: cmd to find
 *
 *Return: path of cmd
 */
char *find_path(info_t *info, char *pathstr, char *cmd)
{
	int x = 0, position = 0;
	char *way;

	if (!pathstr)
		return (NULL);
	if ((_strlen(cmd) > 2) && starts_with(cmd, "./"))
	{
		if (is_cmd(info, cmd))
			return (cmd);
	}
	while (1)
	{
		if (!pathstr[x] || pathstr[x] == ':')
		{
			way = dup_chars(pathstr, position, x);
			if (!*way)
				_strcat(way, cmd);
			else
			{
				_strcat(way, "/");
				_strcat(way, cmd);
			}
			if (is_cmd(info, way))
				return (way);
			if (!pathstr[x])
				break;
			position = x;
		}
		x++;
	}
	return (NULL);
}
