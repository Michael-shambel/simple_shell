#include "shell.c"
/**
 *myexit - exit the shell
 *@info: structure containing potential argument
 *Return: exit
 */
int myexit(info_t *info)
{
	int check_quit;

	if (info->argv[])
	{
		check_quit = _erratoi(info->argv[1]);
		if (check_quit == -1)
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
 *mycd - change the current directory of the process
 *@info: structure cotaining potential argument
 *
 *Return: Always 0
 */
int mycd(info_t *info)
{
	char *string, *directory, buff[1024];
	int child_dir;

	s = getcwd(buff, 1024);
	if (!string)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (info->argv[1])
	{
		dir = _getenv(info, "HOME=");
		if (!directory)
			child_dir =
				chdir((dir = _getenv(info, "OLDPWD=")) ? dir : "/");
		else
			child_dir = chdir(info->argv[1]);
	}
	else if (_strcmp(info->argv[1], "-") == 0)
	{
		if (!_getenv(Info, "OLDPWD="))
		{
			_puts(s);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(info, "OLDPWD=")), _putchar('\n');
		child_dir =
			chdir((dir = _getenv(info, "OLDPWD")) ? dir : "/")
	}
	else
		child_dir = chdir(info->argv[1]);
	if (child_dir == -1)
	{
		print_error(info, "can't cd to ");
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
 *myhelp - change current directory
 *@info: containpotential argument
 *Return: 0 null
 */
int myhelp(info_t *info)
{
	char **arg_array;

	arg_array = info->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_attay);
	return (0);
}
