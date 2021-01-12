/* passgen */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h> /* Leaving out throws warnings on some systems */
#include <getopt.h>

/* Generates a password of given length */
void generate(int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        /* Prints each character of password to console */
        printf("%c", 33 + rand() % 94); /* ASCII 33 - 126 */
    }
    printf("\n");
}

void fail(char *name)
{
    fprintf(stderr, "Usage: %s [-l length] [-a amount]\n", name);
    exit(EXIT_FAILURE);
}

int main(int argc, char **argv)
{
    /* Internal variables, including password length and amount to generate */
    int i, opt, length = 12, amount = 1;

    /* Sets seed of the random based on program's process ID */
    srand(getpid());

    /* Loops through command line arguments */
    while ((opt = getopt(argc, argv, "l:a:")) != -1)
    {
        int val = atoi(optarg);

        if (val < 1)
        {
            fail(argv[0]);
        }

        switch (opt)
        {
        case 'l':
            length = val;
            break;
        case 'a':
            amount = val;
            break;
        default:
            fail(argv[0]);
            break;
        }
    }

    for (i = 0; i < amount; i++)
    {
        generate(length);
    }

    return 0;
}