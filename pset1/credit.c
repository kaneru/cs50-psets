#include <stdio.h>
#include <cs50.h>

int main(void)
{
    long long number;
    printf("Number: ");
    number = get_long_long();
    long long digit_1 = number;
    long long digits_2 = number;

    while (digit_1 >= 10)
    {
        digit_1 /= 10;
    }

    while (digits_2 >= 100)
    {
        digits_2 /= 10;
    }

    long long i = 10;
    int k, sum = 0;

    while (i < number)
    {
        k = number / i % 10 * 2;
        if (k < 9) {
            sum += k;
        } else {
            sum += (k % 10);
            sum += (k / 10);
        }
        i *= 100;
    }

    i = 1;

    while (i < number)
    {
        sum += (number / i % 10);
        i *= 100;
    }

    if (sum % 10 == 0 && (digits_2 == 34 || digits_2 == 37)) {
        printf("AMEX\n");
    } else if (sum % 10 == 0 && (digits_2 == 51
                                 || digits_2 == 52 || digits_2 == 53
                                 || digits_2 == 54 || digits_2 == 55)) {
        printf("MASTERCARD\n");
    } else if (sum % 10 == 0 && digit_1 == 4) {
        printf("VISA\n");
    } else {
        printf("INVALID\n");
    }
    return 0;
}
