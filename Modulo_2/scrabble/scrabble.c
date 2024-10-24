#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int POINTS[] = {1, 3, 3, 2, 1, 4, 2, 4, 1, 8, 5, 1, 3, 1, 1, 3, 10, 1, 1, 1, 1, 4, 4, 8, 4, 10};

int compute_score(string word);

int main(void)
{
    // Solicitar ao usuário duas palavras
    string word1 = get_string("Player 1: ");
    string word2 = get_string("Player 2: ");
    // Calcular os pontos de cada palavra
    int score1 = compute_score(word1);
    int score2 = compute_score(word2);
    // Imprimir o vencedor
    if (score1 > score2) {
        printf("Player 1 wins!");
    } else if(score1 < score2) {
        printf("Player 2 wins!");
    } else {
        printf("Tie!");
    }
}

int compute_score(string word)
{
    int score = 0;
    // Computa e devolve os pontos de cada palavra
    for (int i = 0, l = strlen(word); i < l; i++) {
        if(ispunct(word[i])) {
            score += 0;
        } else {
        int index = toupper(word[i]) - 65;
        score += POINTS[index];
        }

    }
    return score;
}
