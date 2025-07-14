#include <cs50.h>
#include <stdio.h>

void create_gap(int n);
void create_hash(int n);

int main(void)
{
    int height;
    do
    {
        height = get_int("Enter the height: ");
    }
    while (height < 1 || height > 8);

    for (int hash = 1; hash < height + 1; hash++)
    {
        int gap = height - hash;
        // spaces
        create_gap(gap);
        // left hashes
        create_hash(hash);
        // gap of width 2
        printf("  ");
        // right hashes
        create_hash(hash);
        // new line
        printf("\n");
    }
}

// gap in a row
void create_gap(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" ");
    }
}
// hash in a row
void create_hash(int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("#");
    }
}
