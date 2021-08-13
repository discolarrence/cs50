#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
 
typedef uint8_t BYTE;
 
int main(int argc, char *argv[])
{
    //accept one command line argument
    if (argc != 2)
    {
        printf("Usage: name of 1 image to recover\n");
        return 1;
    }
    
    //open files
    FILE *file = fopen(argv[1], "r");
    if (file == NULL)
    {
        fprintf(stderr, "Could not open %s.\n", argv[1]);
        return 1;
    }
    
    BYTE bytes[512];
    fread(bytes, sizeof(BYTE), 512, file);
    
    if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
    {
        printf("Maybe\n");
    }

    // Close file
    fclose(file);
}

// The files you generate should each be named ###.jpg, where ### is a three-digit decimal number, starting with 000 for the first image and counting up.
// Your program, if it uses malloc, must not leak any memory.