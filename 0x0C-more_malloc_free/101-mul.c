#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * multiply - multiply two positive integers
 * @num1: the first number to be multiplied
 * @num2: the second number to be multiplied
 *
 * Return: the result of multiplication
 */
int multiply(const char *num1, const char *num2)
{
    int len1 = 0, len2 = 0, i, j, res_len, carry = 0, sum = 0;
    int *result;

    while (num1[len1])
        len1++;
    while (num2[len2])
        len2++;

    res_len = len1 + len2;
    result = calloc(res_len, sizeof(int));

    if (!result)
        exit(98);

    for (i = len1 - 1; i >= 0; i--)
    {
        carry = 0;
        for (j = len2 - 1; j >= 0; j--)
        {
            sum = (num1[i] - '0') * (num2[j] - '0') +
                  result[i + j + 1] + carry;
            carry = sum / 10;
            result[i + j + 1] = sum % 10;
        }
        result[i + j + 1] = carry;
    }

    i = 0;
    while (result[i] == 0 && i < res_len - 1)
        i++;

    for (; i < res_len; i++)
        printf("%d", result[i]);

    printf("\n");

    free(result);

    return (0);
}

/**
 * main - multiply two positive integers
 * @argc: the number of arguments passed
 * @argv: an array of pointers to the arguments
 *
 * Return: 0 on success, 98 on error
 */
int main(int argc, char **argv)
{
    int i;

    if (argc != 3)
    {
        printf("Error\n");
        return (98);
    }

    for (i = 1; i < argc; i++)
    {
        int j = 0;
        while (argv[i][j])
        {
            if (!isdigit(argv[i][j]))
            {
                printf("Error\n");
                return (98);
            }
            j++;
        }
    }

    multiply(argv[1], argv[2]);

    return (0);
}

