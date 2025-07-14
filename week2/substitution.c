// Libraries
#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Initialization
const int NUM_ALPHABETS = 26;
const int ASCII_A_UPPER = 65;
const int ASCII_A_LOWER = 97;

// Prototyping
bool ValidateKey(string key);
string Encrypt(string plaintext, string key);

int main(int argc, string argv[])
{
    // single command-line argument
    if (argc != 2)
    {
        printf("Incorrect number of arguments given! Only a single command-line argument is recquired.\n");
        return 1;
    }

    const string key = argv[1]; // storing the key as a constant
    if (!ValidateKey(key))
    {
        return 1;
    }

    string plaintext = get_string("plaintext: ");
    string ciphertext = Encrypt(plaintext, key);
    printf("ciphertext: %s\n", ciphertext);
}

bool ValidateKey(string key)
{
    // checking for 26 characters
    if (strlen(key) != 26)
    {
        printf("Enter exactly 26 characters! \n");
        return false;
    }

    int alphaCount[NUM_ALPHABETS] = {0};

    // only alphabet check
    for (int i = 0; i < NUM_ALPHABETS; i++)
    {
        char thisChar = key[i]; // extracting a character
        if (!isalpha(thisChar))
        {
            printf("Only enter Alphabets!\n");
            return false;
            break;
        }
        thisChar = toupper(thisChar);

        // counting the appearances of each character
        int pos = thisChar - ASCII_A_UPPER; // 0 to 25 instead of 65 to 90
        alphaCount[pos] += 1;
    }

    // checking if each alphabet is entered once
    for (int i = 0; i < NUM_ALPHABETS; i++)
    {
        if (alphaCount[i] != 1)
        {
            printf("Invalid Alpabet Count! Each alphabet must be entered once. \n");
            return false;
            break;
        }
    }
    return true;
}

// returns ciphertext
string Encrypt(string plaintext, string key)
{

    for (int i = 0, len = strlen(plaintext); i < len; i++)
    {
        char thisChar = plaintext[i]; // extracting a character
        if (isalpha(thisChar))
        {
            int pos = tolower(thisChar) - ASCII_A_LOWER;
            thisChar = (islower(thisChar)) ? tolower(key[pos]) : toupper(key[pos]);
        }
        plaintext[i] = thisChar;
    }
    string ciphertext = plaintext;
    return ciphertext;
}
