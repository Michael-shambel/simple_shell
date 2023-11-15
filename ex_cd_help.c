#include "main.h"

/**
 *_myexit - exit the shell
 *@info: structure argument
 *
 * Return: exits with status
 */
int _myexit(info_t *info)
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
 *_mycd - change the directory of the process
 *@info: structure argument
 *
 *Return: Always 0
 */
int _mycd(info_t *info)
{
	char *string, *direct, buff[1024];
	int cd_ret;

	string = getcwd(buff, 1024);
	if (!string)
		_puts("TODO: >>getcwd failure emsg her<<\n");
	if (!info->argv[1])
	{
		direct = _getenv(info, "HOME=");
		if (!direct)
			cd_ret =
				chdir((direct = _getenv(info, "PWD=")) ? direct : "/");
		else
			cd_ret = chdir(direct);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(info, "OLDPWD="))
		{
			_puts(string);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		cd_ret =
			chdir((direct = _getenv(info, "PWD=")) ? direct : "/");
	}
	else
		cd_ret = chdir(info->argv[1]);
	if (cd_ret == -1)
	{
		print_error(info, "can't cd to");
		_eputs(info->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(info, "OLDPWD", _getenv(info, "PWD="));
		_setenv(info, "PWD", getcwd(buff, 1024));
	}
	return (0);
}
/**
 *_myhelp - change directory
 *@info: structure argument
 *
 *Return: integer
 */
int _myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array);
	return (0);
}
