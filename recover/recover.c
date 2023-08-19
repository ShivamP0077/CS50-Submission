#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

typedef uint8_t BYTE;

int main(int argc, char *argv[])
{
    // Check if the command-line argument is provided
    if (argc != 2)
    {
        printf("Usage: ./recover image\n");
        return 1;
    }

    // Open the input file
    FILE *input_file = fopen(argv[1], "r");
    if (input_file == NULL)
    {
        printf("Could not open file.\n");
        return 1;
    }

    // Define variables for file reading and image recovery
    BYTE buffer[512];
    int file_count = 0;
    FILE *output_file = NULL;
    char filename[8];

    // Iterate over each block of 512 bytes in the input file
    while (fread(buffer, sizeof(BYTE), 512, input_file) == 512)
    {
        // Check if the block starts with a JPEG signature
        if (buffer[0] == 0xff && buffer[1] == 0xd8 && buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            // Close the previous output file if it's open
            if (output_file != NULL)
            {
                fclose(output_file);
            }

            // Generate a new output filename
            sprintf(filename, "%03i.jpg", file_count);

            // Open the output file for writing
            output_file = fopen(filename, "w");
            if (output_file == NULL)
            {
                printf("Could not create file.\n");
                fclose(input_file);
                return 1;
            }

            // Increment the file counter
            file_count++;
        }

        // Write the block to the output file
        if (output_file != NULL)
        {
            fwrite(buffer, sizeof(BYTE), 512, output_file);
        }
    }

    // Close the input and output files
    fclose(input_file);
    if (output_file != NULL)
    {
        fclose(output_file);
    }

    return 0;
}
