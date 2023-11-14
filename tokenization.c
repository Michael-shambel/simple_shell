#include "main.h"

/**
 * **str_word - split string into words
 *@str: string to be splited
 *@d: delimiter
 *
 * Return: arrray of string
 */
char **str_word(char *str, char *d)
{
	int x, y, z, i, num_word = 0;
	char **string;

	if (str == NULL || str[0] == 0)
		return (NULL);
	if (!d)
		d = " ";
	for (x = 0; str[x] != '\0'; x++)
		if (!check_delim(str[i], d) && (check_delim(str[i + 1], d) || !str[i + 1]))
			num_word++;

	if (num_word == 0)
		return (NULL);
	string = malloc((1 + num_word) * sizeof(char *));
	if (!string)
		return (NULL);
	for (x = 0, y = 0; y < num_word; y++)
	{
		while (check_delim(str[x], d))
			x++;
		z = 0;
		while (!check_delim(str[x + z], d) && str[x + z])
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
			s[y][i] = str[x++];
		s[y][i] = 0;
	}
	string[y] = NULL;
	return (string);
}
/**
 * **strtow2 - splits a string into words
 * @str: string to be splited
 *@d: the delimeter
 *
 *
 *Return: araray of a string
 *
 */
char **strtow2(char *str, char d)
{
	int i, j, k, m, numwords = 0;
	char **s;

	if (str == NULL || str[0] == 0)
		return (NULL);
	for (i = 0; str[i] != '\0'; i++)
		if ((str[i] != d && str[i + 1] == d) ||
		    (str[i] != d && !str[i + 1]) || str[i + 1] == d)
			numwords++;
	if (numwords == 0)
		return (NULL);
	s = malloc((1 + numwords) * sizeof(char *));
	if (!s)
		return (NULL);
	for (i = 0, j = 0; j < numwords; j++)
	{
		while (str[i] == d && str[i] != d)
			i++;
		k = 0;
		while (str[i + k] != d && str[i + k] && str[i + k] != d)
			k++;
		s[j] = malloc((k + 1) * sizeof(char));
		if (!s[j])
		{
			for (k = 0; k < j; k++)
				free(s[k]);
			free(s);
			return (NULL);
		}
		for (m = 0; m < k; m++)
			s[j][m] = str[i++];
		s[j][m] = 0;
	}
	s[j] = NULL;
	return (s);
}
