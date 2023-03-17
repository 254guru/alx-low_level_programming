#include <stdlib.h>

/**
 * multiply - multiplies two positive numbers
 * @num1: first number to be multiplied
 * @num2: second number to be multiplied
 *
 * Return: 0 on success, 98 on failure
 */

char *multiply(char *num1, char *num2);
void *memset(void *s, int c, size_t n);
void *malloc(size_t size);
void free(void *ptr);
void exit(int status);

/**
 * main - checks result
 * @argc: argument count
 * @argv: argument vector
 *
 * Return: 0
 */

int main(int argc, char **argv)
{
    char *result;

    if (argc != 3) {
        write(1, "Error\n", 6);
        exit(98);
    }

    result = multiply(argv[1], argv[2]);
    write(1, result, _strlen(result));
    write(1, "\n", 1);
    free(result);

    return (0);
}

char *multiply(char *num1, char *num2)
{
    char *result;
    int len1, len2, i, j, k, carry, n1, n2, sum;

    len1 = _strlen(num1);
    len2 = _strlen(num2);
    result = malloc(len1 + len2);
    if (result == NULL) {
        exit(98);
    }

    memset(result, '0', len1 + len2);

    for (i = len1 - 1; i >= 0; i--) {
        carry = 0;
        n1 = num1[i] - '0';

        for (j = len2 - 1; j >= 0; j--) {
            n2 = num2[j] - '0';
            k = i + j + 1;
            sum = n1 * n2 + carry + (result[k] - '0');
            carry = sum / 10;
            result[k] = (sum % 10) + '0';
        }

        if (carry > 0) {
            result[i] += carry;
        }
    }

    if (*result == '0') {
        result++;
    }

    return (result);
}

int _strlen(char *s)
{
    int len = 0;

    while (*s != '\0') {
        len++;
        s++;
    }

    return (len);
}
