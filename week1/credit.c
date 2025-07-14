#include <cs50.h>
#include <stdio.h>

// protoypes of functions
int Integer_Length(long n);
int Add_Individual_Digits(int n);
bool Checksum(long cardnum);
void Identify_Card(long cardnum);

// main loop
int main(void)
{
    long cardnum = get_long("Enter the card number: ");

    // if valid number then identify the card type
    if (Checksum(cardnum) == true)
    {
        // check for card type. can also be invalid
        Identify_Card(cardnum);
    }
    else
    {
        printf("INVALID\n");
    }
}

// returns the number of characters in a integer number
int Integer_Length(long n)
{
    int i = 0;
    while (n != 0)
    {
        n /= 10;
        i += 1;
    }
    return i;
}

// add individual digits of a number
int Add_Individual_Digits(int n)
{
    int sum = 0;
    int length = Integer_Length(n);
    for (int i = 0; i < length; i++)
    {
        sum += n % 10;
        n = n / 10;
    }
    return sum;
}

// Returns true for valid number
bool Checksum(long cardnum)
{
    int sum = 0;
    int length = Integer_Length(cardnum);

    for (int i = 0; i < length; i++)
    {
        long currentNum = cardnum % 10; // extracts the current digit
        if (i % 2 == 1)                 // checks for alternate values
        {
            currentNum = currentNum * 2;
            sum += Add_Individual_Digits(currentNum);
        }
        else
        {
            sum += currentNum;
        }
        cardnum = cardnum / 10; // removes the digit from the cardnumber
    }
    if (sum % 10 == 0) // checking if the sum has last digit 0
    {
        return true;
    }
    else
    {
        return false;
    }
}

// prints the type of card number
void Identify_Card(long cardnum)
{
    int length = Integer_Length(cardnum);

    // removees all digits except starting two digits
    long typeNum = cardnum;
    while (Integer_Length(typeNum) > 2)
    {
        typeNum = typeNum / 10; // removes a single digit
    }

    // checks for all cases of types
    if ((typeNum == 34 || typeNum == 37) && length == 15)
    {
        printf("AMEX\n");
    }
    else if ((typeNum == 51 || typeNum == 52 || typeNum == 53 || typeNum == 54 || typeNum == 55) &&
             length == 16)
    {
        printf("MASTERCARD\n");
    }
    else if ((typeNum / 10) == 4 && (length == 13 || length == 16))
    {
        printf("VISA\n");
    }
    else
    {
        printf("INVALID\n");
    }
}
