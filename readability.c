#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    // Get text from the user
    string s = get_string("Text: ");

    // Count number of letters, words and sentences
    float letter = 0;
    float word = 1;
    float sentence = 0;
    for (int i = 0, n = strlen(s); i < n; i++)
    {
        // Count number of letters
        if ((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z'))
        {
            letter++;
        }
        // Count number of words
        else if (s[i] == ' ')
        {
            word++;
        }
        // Count number of sentences
        else if (s[i] == '.' || s[i] == '!' || s[i] == '?')
        {
            sentence++;
        }
    }

    // Define grade using Coleman-Liau index
    float grade = 0.0588 * (letter / word * 100) - 0.296 * (sentence / word * 100) - 15.8;

    // Output Grade
    if (grade < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (grade >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %.0f\n", grade);
    }
}
