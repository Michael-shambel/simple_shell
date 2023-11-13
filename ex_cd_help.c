#include "main.h"

/**
 *exit_shell - exit the shell
 *@info: structure argument
 *
 * Return: exits with status
 */
int exit_shell(info_t *info)
{
	int chext;

	if (info->argv[1])
	{
		chext = _erratoi(info->argv[1]);
		if (chext == -1)
		{
			info->status = 2;
			print_error(info, "Illegal number: ");
			_eputs(info->argv[1]);
			_eputchar('\n');
			return (1);
		}
		info->err_num = _erratoi(info->argv[1]);
		return (-2);
	}
	info->err_num = -1;
	return (-2);
}
/**
 *chenge_directory - change the directory of the process
 *@info: structure argument
 *
 *Return: Always 0
 */
int chenge_directory(info_t *info)
{
	char *s, *dir, buff[1024];
	int cd_ret;

	s = getcwd(buff, 1024);
	if (!s)
		_puts("TODO: >>getcwd failure emsg her<<\n");
	if (!info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!dir)
			ch_ret =
				chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
		else
			ch_ret = chdir(dir);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cd_ret =
			chdir((dir = _getenv(info, "PWD=")) ? dir : "/");
	}
	else
		ch_ret = chdir(info->argv[1]);
	if (ch_ret == -1)
	{
		print_error(info, "can't cd to");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}
/**
 *help_shell - change directory
 *@info: structure argument
 *
 *Return: integer
 */
int help_shell(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
