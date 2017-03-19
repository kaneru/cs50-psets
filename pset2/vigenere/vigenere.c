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
    string k = argv[1];
    int k_length = strlen(k);
    for (int i = 0, n = strlen(k); i < n; i++)
    {
        if (!isalpha(k[i])) {
            printf("Bad key.\n");
            return 1;
            break;
        }
        k[i] = tolower(k[i]) - 97;
    }
    printf("plaintext: ");
    string p = get_string();
    if (p != NULL) {
        printf("ciphertext: ");
        for (int i = 0, j = 0, n = strlen(p); i < n; i++)
        {
            if (isalpha(p[i]))
            {
                if (islower(p[i])) {
                    printf("%c", 97 + (p[i] - 97 + k[j % k_length]) % 26);
                } else if (isupper(p[i])) {
                    printf("%c", 65 + (p[i] - 65 + k[j % k_length]) % 26);
                }
                j++;
            } else {
                printf("%c", p[i]);
            }
        }
        printf("\n");
        return 0;
    }
}