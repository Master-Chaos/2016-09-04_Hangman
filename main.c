#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LENGTH 100 //max wordlength

void init(char usedchar[LENGTH], char hitword[LENGTH], int len)
{
    for(int i = 0; i < len; i++)
    {
        usedchar[i] = ' ';
        hitword[i] = '_';
    }
}

void printchararray (char array[LENGTH], int len)
{
    for (int i = 0; i < len; i++)
    {
        printf("%c ",array[i]);
    }
    printf("\n\n");
}

int main()
{
    int trys = 6; // possible trys
    char word [LENGTH] = "Alibaba1der"; // word for hangman
    int len = strlen(word); // word length
    char hitword [len]; // found word
    char usedchar[len]; // array for already used letters

    init(usedchar, hitword, len); // init arrays

    printf("WILLKOMMEN BEI HANGMAN! \n\n");

    for(int j = 0; j < trys; j++)
    {
        printf("Bitte einen Buchstaben eingeben: [Moegliche Versuche %d]", (trys - j));
        usedchar[j] = getchar();
        printf("\nBereitsverwendete Buchstaben: \t");
        printchararray(usedchar, len);

        for(int i = 0; i < len; i++)
        {
            if(( word[i] == usedchar[j]) && (usedchar[j] != hitword[i]))
            {
                hitword [i] = usedchar[j];
                trys++;
            }
        }

        fflush(stdin); //CLEAR STANDARDIN
        printchararray(hitword, len);
        printf("#################################################################################################\n\n");

        if (((strcmp(word, hitword)) != 0) && (j > trys-2))
        {
            printf("\n\nDu hast das gesuchte Wort leider nicht gefunden und somit verloren gewonnen. Das Wort war %s.\n", word);
            break;
        }
        else if (((strcmp(word, hitword)) == 0) && (j <= trys))
        {
            printf("\nDu hast das gesuchte Wort gefunden und somit gewonnen!!! Das Wort war %s.\n", word);
            break;
        }
    }
    return 0;
}

