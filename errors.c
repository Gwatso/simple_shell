#include "shell.h"

/**
 * _eputs - Displays a given string to the standard error output.
 * @str: The string to be shown.
 *
 * Return: Nothing.
 */
void _eputs(char *str)
{
    int index = 0;

    /* Check for a NULL string */
    if (!str)
        return;

    /* Output each character in the string to standard error */
    while (str[index] != '\0')
    {
        _eputchar(str[index]);
        index++;
    }
}

/**
 * _eputchar - Writes a character to the standard error output.
 * @c: The character to print.
 *
 * Return: On success, returns 1.
 *         On error, returns -1, and errno is set appropriately.
 */
int _eputchar(char c)
{
    static int bufferIndex;
    static char buffer[WRITE_BUF_SIZE];

    /* Flush buffer if instructed or if it's full */
    if (c == BUF_FLUSH || bufferIndex >= WRITE_BUF_SIZE)
    {
        write(2, buffer, bufferIndex);
        bufferIndex = 0;
    }

    /* Store the character in the buffer, if not a flush */
    if (c != BUF_FLUSH)
        buffer[bufferIndex++] = c;

    return 1;
}

/**
 * _putfd - Writes a character to a specified file descriptor.
 * @c: The character to print.
 * @fd: The file descriptor to write to.
 *
 * Return: On success, returns 1.
 *         On error, returns -1, and errno is set appropriately.
 */
int _putfd(char c, int fd)
{
    static int bufferIndex;
    static char buffer[WRITE_BUF_SIZE];

    /* Flush buffer if instructed or if it's full */
    if (c == BUF_FLUSH || bufferIndex >= WRITE_BUF_SIZE)
    {
        write(fd, buffer, bufferIndex);
        bufferIndex = 0;
    }

    /* Store the character in the buffer, if not a flush */
    if (c != BUF_FLUSH)
        buffer[bufferIndex++] = c;

    return 1;
}

/**
 * _putsfd - Displays a given string to a specified file descriptor.
 * @str: The string to be shown.
 * @fd: The file descriptor to write to.
 *
 * Return: The number of characters written.
 */
int _putsfd(char *str, int fd)
{
    int charCount = 0;

    /* Check for a NULL string */
    if (!str)
        return 0;

    /* Output each character in the string to the specified file descriptor */
    while (*str)
    {
        charCount += _putfd(*str++, fd);
    }

    return charCount;
}

