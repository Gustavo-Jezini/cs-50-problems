#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int main(void)
{
    string text = get_string("Texto: ");
    int letters = 0;
    int words = 1;
    int sentences = 0;

    for (int i = 0, l = strlen(text); i < l; i++) {
        if(isalpha(text[i])) {
            letters++;
        } else if(isspace(text[i])) {
            words++;
        } else if(text[i] == '.' || text[i] == '?' || text[i] == '!') {
            sentences++;
        }
    }
    float L = (float) letters / (float) words * 100;
    float S = (float) sentences / (float) words * 100;
    int INDICE = round(0.0588 * L - 0.296 * S - 15.8);
    printf("%i \n", INDICE);
    if (INDICE > 16) {
        printf("Grade 16+\n");
    } else if(INDICE < 1) {
        printf("Before Grade 1\n");
    } else {
        printf("Grade %i\n", INDICE);
    }
}
