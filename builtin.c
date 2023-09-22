#include "shell.h"

/**
 * _myexit - exits the shell
 * @data: Structure containing potential arguments used to
 * maintain constant function prototype.
 * Return: exits with a given exit status
 * (0) if data.argv[0] != "exit"
 */
int _myexit(data_t *data)
{
	int checkforexit;

	if (data->argv[1]) /* If there is an exit arguement */
	{
		checkforexit = _erratoi(data->argv[1]);
		if (checkforexit == -1)
		{
			data->status = 2;
			print_error(data, "Illegal number: ");
			_eputs(data->argv[1]);
			_eputchar('\n');
			return (1);
		}
		data->err_num = _erratoi(data->argv[1]);
		return (-2);
	}
	data->err_num = -1;
	return (-2);
}

/**
 * _mycd - changes the current directory of the process
 * @data: Structure containing potential arguments used to
 * maintain constant function prototype.
 * Return: Always 0
 */
int _mycd(data_t *data)
{
	char *x, *y, buffer[1024];
	int chdir_ret;

	x = getcwd(buffer, 1024);
	if (!x)
		_puts("TODO: >>getcwd failure emsg here<<\n");
	if (!data->argv[1])
	{
		y = _getenv(data, "HOME=");
		if (!y)
			chdir_ret = /* TODO: what should this be? */
				chdir((y = _getenv(data, "PWD=")) ? y : "/");
		else
			chdir_ret = chdir(y);
	}
	else if (_strcmp(data->argv[1], "-") == 0)
	{
		if (!_getenv(data, "OLDPWD="))
		{
			_puts(x);
			_putchar('\n');
			return (1);
		}
		_puts(_getenv(data, "OLDPWD=")), _putchar('\n');
		chdir_ret = /* TODO: what should this be? */
			chdir((y = _getenv(data, "OLDPWD=")) ? y : "/");
	}
	else
		chdir_ret = chdir(data->argv[1]);
	if (chdir_ret == -1)
	{
		print_error(data, "can't cd to ");
		_eputs(data->argv[1]), _eputchar('\n');
	}
	else
	{
		_setenv(data, "OLDPWD", _getenv(data, "PWD="));
		_setenv(data, "PWD", getcwd(buffer, 1024));
	}
	return (0);
}

/**
 * _myhelp - changes the current directory of the process
 * @data: Structure containing potential arguments used to
 * maintain constant function prototype.
 * Return: Always 0
 */
int _myhelp(data_t *data)
{
	char **arg_array;

	arg_array = data->argv;
	_puts("help call works. Function not yet implemented \n");
	if (0)
		_puts(*arg_array); /* temp att_unused workaround */
	return (0);
}
