#include <cs50.h>
#include <math.h>
#include <stdio.h>

int main(void)
{
    int money_rounded, quarter = 0, dimme = 0, penny = 0, cent = 0, total_coins = 0;

    do
    {
        money_rounded = get_float("Quanto deseja trocar? ");
    }
    while (money_rounded < 0);


    if (money_rounded == 0)
    {
        return printf("%i\n", total_coins);
    }

    while (money_rounded >= 25)
    {
        quarter += 1;
        money_rounded -= 25;
    }

    while (money_rounded >= 10)
    {
        dimme += 1;
        money_rounded -= 10;
    }

    while (money_rounded >= 5)
    {
        penny += 1;
        money_rounded -= 5;
    }

    while (money_rounded >= 1)
    {
        cent += 1;
        money_rounded -= 1;
    }

    total_coins = cent + dimme + penny + quarter;
    printf("%i\n", total_coins);
}
