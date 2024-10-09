#include <cs50.h>
#include <stdio.h>

int main(void)
{

        int start_pop = 0;
        do
        {
            start_pop = get_int("Start population: ");
        }
        while (start_pop < 9);

        int end_pop = 0;
        do
        {
            end_pop = get_int("End population: ");
        }
        while (end_pop < start_pop);

        if(start_pop == end_pop) {
            printf("Years: 0");
            return 0;
        }

        int years = 0;
        while (start_pop < end_pop) {
            years++;
            start_pop += (start_pop / 3) - (start_pop / 4);
        }

        printf("Years: %i\n", years);
}
