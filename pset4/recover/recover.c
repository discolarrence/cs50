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
    
    //make buffer
    BYTE bytes[512];
    
    //make place for image
    FILE *img = NULL;
    
    //counter to make filenames
    int jpg_count = 0;
    
    //set found first file to false
    int found_jpg = 0;
    
    //read through file, 512 bytes at a time, until no more
    while (fread(bytes, 512, 1, file) != 0)
    {
        if (bytes[0] == 0xff && bytes[1] == 0xd8 && bytes[2] == 0xff && (bytes[3] & 0xf0) == 0xe0)
        {
            //close last picture if not first picture
            if (found_jpg == 1)
            {
                fclose(img);
            }
            //set found first jpg to true
            else
            {
                found_jpg = 1;
            }
            //make filename for jpg, open with that name, and update jpg file count
            char name[8];
            sprintf(name, "%03i.jpg", jpg_count);
            img = fopen(name, "w");
            jpg_count++;
        }
        
        //write to img file if not before the first file is found
        if (found_jpg == 1)
        {
            fwrite(&bytes, 512, 1, img); 
        }
        
    }
    
    // Close file
    fclose(file);
    fclose(img);
}
