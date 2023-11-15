#include "main.h"

/**
 *shell - shell loop
 *@info: structure argumetn
 *@av: argument vector
 *
 * Return: success or error
 */
int hsh(info_t *info, char **av)
{
	ssize_t r = 0;
	int builtin_resp = 0;

	while (r != -1 && builtin_resp != -2)
	{
		clear_info(info);
		if (interactive(info))
			_puts("$ ");
		_eputchar (BUF_FLUSH);
		r = get_input(info);
		if (r != -1)
		{
			set_info(info, av);
			builtin_resp = find_builtin(info);
			if (builtin_resp == -1)
				find_cmd(info);
		}
		else if (interactive(info))
			_putchar('\n');
		free_info(info, 0);
	}
	write_history(info);
	free_info(info, 1);
	if (!interactive(info) && info->status)
		exit(info->status);
	if (builtin_resp == -2)
	{
		if (info->err_num == -1)
			exit(info->status);
		exit(info->err_num);
	}
	return (builtin_resp);
}
/**
 *find_builtin - search a builtin command
 *@info: structure argument to be checked
 *
 * Return: -1, or 0 or 1 or 2 based on the builtin command
 */
int find_builtin(info_t *info)
{
	int x, builtin_resp = -1;
	builtin_table builtintbl[] = {
		{"exit", _myexit},
		{"env", _myenv},
		{"help", _myhelp},
		{"history", _myhistory},
		{"setenv", _mysetenv},
		{"unsetenv", _myunsetenv},
		{"cd", _mycd},
		{"alias", _myalias},
		{NULL, NULL}
	};

	for (x = 0; builtintbl[x].type; x++)
		if (_strcmp(info->argv[0], builtintbl[x].type) == 0)
		{
			info->line_count++;
			builtin_resp = builtintbl[x].func(info);
			break;
		}
	return (builtin_resp);
}
/**
 *find_cmd - finds a command in PATH
 *@info: structure argument
 *
 *Return: VOID
 */
void find_cmd(info_t *info)
{
	char *way = NULL;
	int x, y;

	info->path = info->argv[0];
	if (info->linecount_flag == 1)
	{
		info->line_count++;
		info->linecount_flag = 0;
	}
	for (x = 0, y = 0; info->arg[x]; x++)
		if (!is_delim(info->arg[x], "\t\n"))
			y++;
	if (!y)
		return;
	way = find_path(info, _getenv(info, "PATH="), info->argv[0]);
	if (way)
	{
		info->path = way;
		fork_cmd(info);
	}
	else
	{
		if ((interactive(info) || _getenv(info, "PATH=")
			|| info->argv[0][0] == '/') && is_cmd(info, info->argv[0]))
			fork_cmd(info);
		else if (*(info->arg) != '\n')
		{
			info->status = 127;
			print_error(info, "not found\n");
		}
	}
}
/**
 *fork_cmd - fork a exec file and rum cmd
 *@info: the structure argument
 *
 *
 * Return: void
 */
void fork_cmd(info_t *info)
{
	pid_t child_pid;

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error:");
		return;
	}
	if (child_pid == 0)
	{

		if (execve(info->path, info->argv, get_environ(info)) == -1)
		{
			free_info(info, 1);
			if (errno == EACCES)
				exit(126);
			exit(1);
		}
	}
	else
	{
		wait(&(info->status));
		if (WIFEXITED(info->status))
		{
			info->status = WEXITSTATUS(info->status);
			if (info->status == 126)
				print_error(info, "Permission denied\n");
		}
	}
}
