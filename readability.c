#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

void readinglevel(string txt);

int main(void) 
{
    string text = get_string("Text: ");
    readinglevel(text);
}

void readinglevel(string txt)
{
    int sentencecount = 0;
    int wordcount = 0;
    int lettercount = 0;
    int totalwords = 0;
    int totalletters = 0;
    float index = 0;
    
    for (int i = 0; i < strlen(txt); ++i)
    {
        if (txt[i] == '?' || txt[i] == '.' || txt[i] == '!')
        {
            sentencecount = sentencecount + 1;
        }
    }
    int wordper[sentencecount];
    for (int i = 0, n = 0 ; i < strlen(txt); ++i)
    {
        if (txt[i] == ' ')
        {
            wordcount = wordcount + 1;
        }
        else if (txt[i] == '?' || txt[i] == '.' || txt[i] == '!')
        {
            wordper[n] = wordcount;
            ++n;
            wordcount = 0;
            
        }
        else if (i == 0)
        {
            wordcount = wordcount + 1;
        }
    }
    for (int i = 0; i < sentencecount; ++i)
    {
        totalwords =  totalwords + wordper[i];
    }
    int letterper[totalwords];
    for (int i = 0, n = 0; i <= strlen(txt); ++i)
    {
        if (txt[i] == ' ')
        {
            letterper[n] = lettercount;
            ++n;
            lettercount = 0;
        }
        else if (txt[i] == '\'' || txt[i] == ',' || txt[i] == '?' || txt[i] == '.' || txt[i] == '!' || txt[i] == ':' 
        || txt[i] == ';'  || txt[i] == '\"' || txt[i] == '\"')
        {
            continue;
        }
        else if (i == strlen(txt))
        {
            letterper[n] = lettercount;
            ++n;
            lettercount = 0;
        }
        else 
        {
            ++lettercount;
        }
    }
    for (int i = 0; i < totalwords; ++i)
    {
        totalletters =  totalletters + letterper[i];
    }

    index = 0.0588 * (((float)totalletters / (float)totalwords) * 100) - 0.296 * (((float)sentencecount / (float)totalwords)
    * 100) - 15.8;
    if (round(index) < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (round(index) >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %1g\n", round(index)); 
    }
    
    
    
}