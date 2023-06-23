/**
 * is_numeric - Checks if a string contains only numeric characters
 * @str: The string to be checked
 *
 * Return: 1 if the string is purely numeric. Otherwise return 0.
 */
int is_numeric(char *str)
{
	unsigned int i = 0;

	if (!str)
		return (0);

	while (str[i] != '\0')
	{
		/* Check for minus character - negative numbers */
		if (i == 0 && str[i] == '-')
		{
			i++;
			continue;
		}
		/* Check for non-numeric characters */
		if (str[i] < '0' || str[i] > '9')
			return (0);
		i++;
	}
	return (1);
}
