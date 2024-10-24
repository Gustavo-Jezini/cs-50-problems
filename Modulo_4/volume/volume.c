// Modifies the volume of an audio file

#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

// Number of bytes in .wav header
const int HEADER_SIZE = 44;

int main(int argc, char *argv[])
{
    // Check command-line arguments
    if (argc != 4)
    {
        printf("Usage: ./volume input.wav output.wav factor\n");
        return 1;
    }

    // Open files and determine scaling factor
    FILE *input = fopen(argv[1], "r");
    if (input == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    FILE *output = fopen(argv[2], "w");
    if (output == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    float factor = atof(argv[3]);

    uint8_t header[HEADER_SIZE];

    // - Copy the 44 first bytes
    // First argument => Is a pointer to where the data will by inserted
    // Second arg => Is the size/ quantity of bytes will be inserted
    // Third arg => Is the amount of bytes that will be read at once
    // Fourth arg => Is the file
    fread(&header, HEADER_SIZE, 1, input);
    // So, first we read and save the data, now with fwrite
    // First arg => where data came from
    // Fourth arg => where data will be inserted
    fwrite(&header, HEADER_SIZE, 1, output);

    // Here the buffer is size 16bites (2bytes)
    int16_t buffer;

    // Reading the input put one byte at once but sending sizeof(int16_t)
    // to buffer (2 bytes per loop)
    // Thats why is not needed to explicit the size of the buffer
    while (fread(&buffer, sizeof(int16_t), 1, input))
    {
        buffer *= factor;
        fwrite(&buffer, sizeof(int16_t), 1, output);
    }
    // - Multiply every sample of 2 bytes by the factor
    // - Write the samples multiplied to a new file

    // Close files
    fclose(input);
    fclose(output);
}
