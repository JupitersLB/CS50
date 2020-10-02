#include <cs50.h>
#include <stdio.h>

// prototypes for main to work
bool check_valid(long credit_num);
int find_length(long n);
bool checksum(long cc_num);
void print_cc_brand(long cc_num);

int main(void)
{
    // make sure user gives cc number
    long credit_num;
    do
    {
        credit_num = get_long("Number: ");
    }
    while (credit_num < 0);

    // check validity
    if (check_valid(credit_num))
    {
        print_cc_brand(credit_num);
    }
    else
    {
        printf("INVALID\n");
    }
}

// checks validity by checking length and using the algo to check the sum
bool check_valid(long credit_num)
{
    int len = find_length(credit_num);
    return (len == 13 || len == 15 || len == 16) && checksum(credit_num);
}

// finds the length by / 10 from each
int find_length(long n)
{
    int len;
    for (len = 0; n != 0; n /= 10, len++);
    return len;
}

// adds even digits to the sum, multiplies odd by 2, then adds each digit together if over 10 to add to sum.
bool checksum(long cc_num)
{
    int sum = 0;
    for (int i = 0; cc_num != 0; i++, cc_num /= 10)
    {
        if (i % 2 == 0)
        {
            sum += cc_num % 10;
        }
        else
        {
            int digi = 2 * (cc_num % 10);
            sum += digi / 10 + digi % 10;
        }
    }
    return (sum % 10) == 0;
}

// checks the first numbers in the range it is allowed to print the brand
void print_cc_brand(long cc_num)
{
    //AMEX cards start with 34 or 37
    if ((cc_num >= 34e13 && cc_num < 35e13) || (cc_num >= 37e13 && cc_num < 38e13))
    {
        printf("AMEX\n");
    }
    // mc cards start with range of 51 to 55
    else if (cc_num >= 51e14 && cc_num < 56e14)
    {
        printf("MASTERCARD\n");
    }
    // visa cards start with 4
    else if ((cc_num >= 4e12 && cc_num < 5e12) || (cc_num >= 4e15 && cc_num < 5e15))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
