#include <unistd.h>
/**
 * main - Prints without printf, puts or man
 * Return: len
 */

int main(void)
{
    const char msg[] = "and that piece of art is useful\" - Dora Korpar, 2015-10-19\n";
    ssize_t len = sizeof(msg) - 1;
    ssize_t n = write(2, msg, len);
    return (n != len);
}
