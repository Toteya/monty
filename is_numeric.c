/**
 * is_numeric - Checks if a string contains only numeric characters
 * @str: The string to be checked
 *
 * Return: 1 if the string is purely numeric. Otherwise return 0.
 */
int is_numeric(char *str)
{
	if (!str)
		return (0);

	while (*str != '\0')
	{
		if (*str < '0' || *str > '9')
			return (0);
		str++;
	}
	return (1);
}
