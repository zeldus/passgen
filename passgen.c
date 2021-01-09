#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>

int length = 12;

void generate(int len)
{
    int i;

    for (i = 0; i < len; i++)
    {
        printf("%c", 33 + rand() % 94); /* ASCII 33 - 126 */
    }

    printf("\n");
}

int main(int argc, char **argv)
{
    srand(getpid());

    if (argc == 3)
    {
        /* Password Length & Amount to Generate Provided */
        int i;
        int amt = atoi(argv[2]);

        for (i = 0; i < amt; i++)
        {
            /* Password Length Provided */
            generate(atoi(argv[1]));
        }
    }
    else if (argc == 2)
    {
        /* Password Length Provided */
        generate(atoi(argv[1]));
    }
    else if (argc == 1)
    {
        /* Default; generates a single 12 character password */
        generate(length);
    }
    else
    {
        /* Incorrect Argument Count */
        printf("Usage: passgen {Optional: LENGTH} {Optional: AMOUNT}\n");
    }
    return 0;
}