#include "main.h"

/**
 * **strtow - split string into words
 *@str: string to be splited
 *@d: delimiter
 *
 * Return: arrray of string
 */
char **strtow(char *str, char *d)
{
	int x, y, z, i, num_word = 0;
	char **string;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!is_delim(str[x], d) && (is_delim(str[x + 1], d) || !str[x + 1]))
			num_word++;

	if (num_word == 0)
		return (NULL);
	string = malloc((1 + num_word) * sizeof(char *));
	if (!string)
		return (NULL);
	for (x = 0, y = 0; y < num_word; y++)
	{
		while (is_delim(str[x], d))
			x++;
		z = 0;
		while (!is_delim(str[x + z], d) && str[x + z])
			z++;
		string[y] = malloc((z + 1) * sizeof(char));
		if (!string[y])
		{
			for (z = 0; z < y; z++)
				free(string[z]);
			free(string);
			return (NULL);
		}
		for (i = 0; i < z; i++)
			string[y][i] = str[x++];
		string[y][i] = 0;
	}
	string[y] = NULL;
	return (string);
}
/**
 * **strtow2 - splits a string into words
 * @string: string to be splited
 *@f: the delimeter
 *
 *
 *Return: araray of a string
 *
 */
char **strtow2(char *string, char f)
{
	int x, y, z, a, n_words = 0;
	char **st;

	if (string == NULL || string[0] == 0)
		return (NULL);
	for (x = 0; string[x] != '\0'; x++)
		if ((string[x] != f && string[x + 1] == f) ||
		    (string[x] != f && !string[x + 1]) || string[x + 1] == f)
			n_words++;
	if (n_words == 0)
		return (NULL);
	st = malloc((1 + n_words) * sizeof(char *));
	if (!st)
		return (NULL);
	for (x = 0, y = 0; y < n_words; y++)
	{
		while (string[x] == f && string[x] != f)
			x++;
		z = 0;
		while (string[x + z] != f && string[x + z] && string[x + z] != f)
			z++;
		st[y] = malloc((z + 1) * sizeof(char));
		if (!st[y])
		{
			for (z = 0; z < y; z++)
				free(st[z]);
			free(st);
			return (NULL);
		}
		for (a = 0; a < z; a++)
			st[y][a] = string[x++];
		st[y][a] = 0;
	}
	st[y] = NULL;
	return (st);
}
