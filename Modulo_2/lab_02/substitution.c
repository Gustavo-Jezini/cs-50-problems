#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdlib.h>

// argc -> Argument count ||
int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./Substitution key\n");
        return 1;
    }

    string key = argv[1];

    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters. \n");
        return 1;
    }

    for (int i = 0, l = strlen(key); i < l; i++)
    {
        if (!isalpha(argv[1][i]))
        {
            printf("Usage: ./Substitution key\n");
            return 1;
        }
        for (int j = 0; j < l; j++)
        {
          if(toupper(key[i]) == toupper(key[j]) && i != j)
            {
              printf("Usage: ./Substitution key\n");
              return 1;
            }
         }
      }
    for (int i = 0, l = strlen(key); i < l; i++)
    {
      for (int j = i + 1; j < l; j++)
      {
        if(toupper(key[i]) == toupper(key[j]))
        {
          printf("Usage: ./Substitution key\n");
          return 1;
        }
      }
    }

    string plaintext = get_string("plaintext: ");

    for (int i = 0, l = strlen(key); i < l; i++)
    {
      if (islower(key[i]))
      {
        key[i] = key[i] - 32;
      }
    }

    printf("ciphertext: ");

    for (int i = 0, l = strlen(plaintext); i < l; i++)
    {
      if (isupper(plaintext[i]))
      {
        int letter = plaintext[i] - 65;
        printf("%c", key[letter]);
      }
      else if (islower(plaintext[i]))
      {
        int letter = plaintext[i] - 97;
        printf("%c", key[letter] + 32);
      }
      else printf("%c", plaintext[i]);
    }
    printf("\n");
}
