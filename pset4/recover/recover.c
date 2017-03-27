#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(stderr, "Usage: ./recover card.raw\n");
        return 1;
    }

    // remember filename
    char *infile = argv[1];

    // open input file
    FILE *inptr = fopen(infile, "r");
    if (inptr == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", infile);
        return 2;
    }

    int k = 0;
    uint8_t buffer[512];
    FILE *outptr = NULL;

    while (fread(&buffer, sizeof(buffer), 1, inptr) == 1)
    {

        if (buffer[0] == 0xff && buffer[1] == 0xd8 &&
            buffer[2] == 0xff && (buffer[3] & 0xf0) == 0xe0)
        {
            if (k >= 1)
            {
                // close previous file
                fclose(outptr);
            }
            // open output file for writing
            char filename[8];
            sprintf(filename, "%03d.jpg", k);
            outptr = fopen(filename, "w");
            k++;
        }
        if (k > 0)
        {
            // write block related to jpg to output file
            fwrite(&buffer, sizeof(buffer), 1, outptr);
        }
    }
    fclose(inptr);
    return 0;
}
