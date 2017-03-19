#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{
    if (argc != 2) {
        printf("Bad input.\n");
        return 1;
    }
    int k = atoi(argv[1]);
    printf("plaintext: ");
    string p = get_string();
    if (p != NULL) {
        printf("ciphertext: ");
        for (int i = 0, n = strlen(p); i < n; i++)
        {   
            if (islower(p[i])) {
                printf("%c", 97 + (p[i] - 97 + k) % 26);
            } else if (isupper(p[i])) {
                printf("%c", 65 + (p[i] - 65 + k) % 26);
            } else {
                printf("%c", p[i]);
            }
        }
        printf("\n");
        return 0;
    }
}