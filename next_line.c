#include <stdio.h>
#include <stdlib.h>

/**
 * next_line - Reads the next line of a monty bytecode file
 * @filename: The filename of the file containing the bytecode
 *
 * Return: A string buffer containing the next line read from the file.
 */
char *next_line(char *filename)
{
	char c1, c2, *buff;
	/* char *filename = "file.txt"; */
	static FILE *fp1, *fp2;
	size_t len = 0, i = 0;

	if (fp1 == NULL)
		fp1 = fopen(filename, "r");
	if (fp2 == NULL)
		fp2 = fopen(filename, "r");

	while ((c1 = fgetc(fp1)) != EOF)
	{
		if (c1 == '\n')
			break;
		len++;
	}
	if (c1 == EOF)
	{
		fclose(fp1);
		fclose(fp2);
		return (NULL);
	}

	buff = malloc(sizeof(char) * len);
	if (buff == NULL)
		exit(EXIT_FAILURE);

	for (i = 0; i <= len && (c2 = fgetc(fp2)) != '\n'; i++)
	{
		buff[i] = c2;
	}
	buff[i] = '\0';

	return (buff);
}
