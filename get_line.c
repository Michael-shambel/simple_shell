#include "shell.h"

/**
 * input_buff - function that buffers chained commands
 * @info: pointer to structure
 * @buff: pointer to pointer to char array
 * @len: pointer to buffer length
 *
 * Return: number of bytes read
 */

ssize_t input_buff(info_t *info, char **buff, size_t *len)
{
	ssize_t t = 0;
	size_t len_s = 0;

	if (!*len)
	{
		free(*buff);
		*buff = NULL;
		signal(SIGINT, sigintHandler);


		t = getline(buff, &len_s, stdin);

		t = _getline(info, buff, &len_s);

		if (t > 0)
		{
			if ((*buff)[t - 1] == '\n')
			{

				(*buff)[t - 1] = '\0';

				r--;
			}
			info->linecount_flag = 1;
			remove_comments(*buff);
			build_history_list(info, *buff, info->histcount++);
			{
				*len = t;
				info->cmd_buff = buff;
			}
		}
	}
	return (t);
}

/**
 * get_input - function that retrieves a line of input
 * @info: pointer to structure
 *
 * Return: number of bytes read
 */
ssize_t get_input(info_t *info)
{
	static char *buff;
	static size_t j, k, len;
	ssize_t s = 0;
	char **buff_q = &(info->arg), *q;

	_putchar(BUF_FLUSH);
	s = input_buff(info, &buff, &len);
	if (s == -1)
		return (-1);
	if (len)
	{
		k = j;
		q = buff + j;

		check_chain(info, buff, &k, j, len);
		while (k < len)
		{
			if (is_chain(info, buff, &k))
				break;
			k++;
		}

		j = k + 1;

		if (j >= len)
		{
			j = len = 0;

			info->cmd_buff_type = CMD_NORM;
		}

		*buff_q = q;

		return (_strlen(q));
	}

	*buff_q = buff;
	return (s);
}

/**
 * read_buff - function that reads a buffer
 * @info: pointer to structure
 * @buff: charactar array (buffer)
 * @j: pointer to size of buffer
 *
 * Return: number of bytes read
 */
ssize_t read_buff(info_t *info, char *buff, size_t *j)
{
	ssize_t s = 0;

	if (*j)
		return (0);
	s = read(info->readfd, buff, READ_BUFF_SIZE);
	if (s >= 0)
		*j = s;
	return (s);
}

/**
 * get_line - function that gets the next line of input from STDIN
 * @info: pointer to structure
 * @ptr: pointer to preallocated buffer or NULL
 * @length: size of preallocated buffer if not NULL
 *
 * Return: integer s
 */

int get_line(info_t *info, char **ptr, size_t *length)
{
	static char buff[READ_BUFF_SIZE];
	static size_t j, len;
	size_t l;
	ssize_t s = 0, t = 0;
	char *q = NULL, *new_q = NULL, *d;

	q = *ptr;
	if (q && length)
		t = *length;
	if (j == len)
		j = len = 0;

	s = read_buff(info, buff, &len);
	if (s == -1 || (s == 0 && len == 0))
		return (-1);

	d = _strchr(buff + j, '\n');
	l = d ? 1 + (unsigned int) (c - buff) : len;
	new_q = _realloc(q, t, t ? t + l : l + 1);
	if (!new_q)
		return (q ? free(q), -1 : -1);

	if (s)
		_strncat(new_q, buff + j, l - j);
	else
		_strncpy(new_q, buff + j, l - j + 1);

	t += l - j;
	j = l;
	q = new_q;

	if (length)
		*length = s;
	*ptr = q;
	return (t);
}

/**
 * sigintHandler - serves as signal handler for Ctrl-C signal
 * @sig_num: signal number(marked as unused)
 *
 * Return:-
 */
void sigintHandler(__attribute__((unused))int sig_num)
{
	_puts("\n");
	_puts("s ");
	_putchar(BUF_FLUSH);
}
