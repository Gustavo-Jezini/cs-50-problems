#include <cs50.h>
#include <stdio.h>

bool check_card(long cardNumber);
int count(long cardNumber);

int main(void)
{
    long cardNumber = get_long("Digite o número do cartão\n");

    bool is_valid_number = check_card(cardNumber);

    if (!is_valid_number)
    {
        printf("INVALID\n");
        return 0;
    }

    int length = count(cardNumber);
    int single_digit = 0, two_digits = 0;
    while (cardNumber > 0)
    {
        if (cardNumber < 10)
        {
            single_digit = cardNumber;
        }
        if (cardNumber > 10 && cardNumber < 100)
        {
            two_digits = cardNumber;
        }
        cardNumber /= 10;
    }

    if (length == 15 && (two_digits == 34 || two_digits == 37))
    {
        printf("AMEX\n");
        return 0;
    }

    if (length == 16 && (two_digits == 51 || two_digits == 52 || two_digits == 53 ||
                         two_digits == 54 || two_digits == 55))
    {
        printf("MASTERCARD\n");
        return 0;
    }

    if ((length == 16 || length == 13) && single_digit == 4)
    {
        printf("VISA\n");
        return 0;
    }

    printf("INVALID\n");
    return 0;
}

int count(long cardNumber)
{
    int total = 0;
    while (cardNumber > 0)
    {
        total++;
        cardNumber /= 10;
    }
    return total;
}

bool check_card(long cardNumber)
{
    int total = 0, buffer = 0;
    bool multiple = false;
    while (cardNumber > 0)
    {
        if (multiple)
        {
            buffer = cardNumber % 10;
            buffer *= 2;
            if (buffer >= 10)
            {
                // Somar com numero de tras - unitário
                total += buffer % 10;
                // Somar com o da frente - dezena
                total += buffer / 10;
            }
            else
            {
                total += buffer;
            }
            // Remover o ultimo numero de card number
            cardNumber /= 10;

            multiple = false;
        }
        else
        {
            // Somar com o ultimo número de card number
            total += cardNumber % 10;
            // Remover o ultimo numero de card number
            cardNumber /= 10;

            multiple = true;
        }
    }
    if (total % 10 == 0)
        return true;
    return false;
}
