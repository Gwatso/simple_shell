#include "shell.h"

/**
 * _strcpy - Copies a string from source to destination.
 * @dest: The destination string.
 * @src: The source string to copy.
 *
 * Returns: A pointer to the destination string.
 */
char *_strcpy(char *dest, char *src) {
    int index = 0;

    // Check for self-copy or null source
    if (dest == src || src == 0)
        return dest;

    // Copy characters until null terminator is encountered
    while (src[index]) {
        dest[index] = src[index];
        index++;
    }

    // Null-terminate the destination string
    dest[index] = '\0';

    return dest;
}

/**
 * _strdup - Duplicates a string by allocating memory for a new copy.
 * @str: The string to duplicate.
 *
 * Returns: A pointer to the duplicated string. Returns NULL on failure or if
 *          the input string is NULL.
 */
char *_strdup(const char *str) {
    int length = 0;
    char *duplicate;

    // Calculate the length of the input string
    if (str == NULL)
        return NULL;
    
    while (*str++)
        length++;

    // Allocate memory for the duplicated string
    duplicate = malloc(sizeof(char) * (length + 1));

    // Check for memory allocation failure
    if (!duplicate)
        return NULL;

    // Copy the string in reverse order
    for (length++; length--;) 
        duplicate[length] = *--str;

    return duplicate;
}

/**
 * _puts - Prints a string to the standard output (stdout).
 * @str: The string to print.
 *
 * Returns: Nothing.
 */
void _puts(char *str) {
    int index = 0;

    // Check for a NULL string
    if (!str)
        return;

    // Print each character in the string
    while (str[index] != '\0') {
        _putchar(str[index]);
        index++;
    }
}

/**
 * _putchar - Writes a character to the standard output (stdout).
 * @c: The character to write.
 *
 * Returns: 1 on success. On error, -1 is returned, and errno is set.
 */
int _putchar(char c) {
    static int bufferIndex;
    static char buffer[WRITE_BUF_SIZE];

    // Flush buffer if instructed or if it's full
    if (c == BUF_FLUSH || bufferIndex >= WRITE_BUF_SIZE) {
        write(1, buffer, bufferIndex);
        bufferIndex = 0;
    }

    // Store the character in the buffer, if not a flush
    if (c != BUF_FLUSH)
        buffer[bufferIndex++] = c;

    return 1;
}

