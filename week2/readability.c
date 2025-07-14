// Libraries
#include <cs50.h>
#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

// Prototyping
void OutputGrade(string text);

int main(void)
{
    string text = get_string("Text: ");
    OutputGrade(text);
}

// prints the correct grade level
void OutputGrade(string text)
{
    int letters = 0;
    int sentences = 0;
    int spaces = 0;
    for (int i = 0, len = strlen(text); i < len; i++)
    {
        char thisChar = toupper(text[i]); // extracts each character from the text and capatilizes it

        if (thisChar >= 'A' && thisChar <= 'Z')
        {
            letters++;
        }
        else if (thisChar == '.' || thisChar == '!'|| thisChar == '?')
        {
            sentences++;
        }
        else if (thisChar == ' ') // prevents multiple spaces from being counted
        {
            spaces++;
        }
    }
    float words = spaces + 1; // formula to caculate words

    float letterAvg = (letters / words) * 100.0; //
    float sentenceAvg = (sentences / words) * 100.0;

    int index = round(0.0588 * letterAvg - 0.296 * sentenceAvg - 15.8); // coleman-liau index rounded to the nearest integer

    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}
