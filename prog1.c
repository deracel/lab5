#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "lib.h"

int main (int argc, char **argv)
{
    tcar* arr = malloc(N * sizeof(tcar));
    int n;
    char *rvalue = NULL;
    char *wvalue = NULL;
    char *svalue = NULL;
    char *fvalue = NULL;
    char *tvalue = NULL;    
    int index;
    int c;
    opterr = 0;
    int ncars;

    while ((c = getopt (argc, argv, "r:w:s:f:t:")) != -1)
        switch (c){
            case 'r':
                rvalue = optarg;
                break;
            case 'w':
                wvalue = optarg;
                break;
            case 's':
                svalue = optarg;
                break;
            case 'f':
                fvalue = optarg;
                break;
            case 't':
                tvalue = optarg;
                break;
            
            case '?':
                if (rvalue == NULL || wvalue == NULL || svalue == NULL || fvalue == NULL || tvalue == NULL)
                    {fprintf (stderr, "Incorrect input, not all options or option characters are entered\n"); break;}
                else if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        return 1;
        default:
        abort ();
    }
    if (rvalue == NULL || wvalue == NULL || svalue == NULL || fvalue == NULL || tvalue == NULL)
        {fprintf (stderr, "Incorrect input, not all options or option characters are entered\n"); return 0;}
    printf ("rvalue = %s, wvalue = %s, svalue = %s, fvalue = %s, tvalue = %s \n", 
        rvalue, wvalue, svalue, fvalue, tvalue);

    if (strcmp(rvalue, "std") == 0){
        printf("Enter the number of cars: ");
        scanf("%d", &n);
        printf("\n");
        arr = realloc(arr, n * sizeof(tcar));
        for (int i = 0; i < n; ++i)
            input_std(i, arr);
    }
    else if (strcmp(rvalue, "txt") == 0)
        /*input_txt();*/;
    else if (strcmp(rvalue, "bin") == 0)
        /*input_bin();*/;
    else
        printf("Incorrect option for rvalue\n");

    if (strcmp(wvalue, "std") == 0)
        output_std(n, arr);
    else if (strcmp(wvalue, "txt") == 0)
        /*output_txt();*/;
    else if (strcmp(wvalue, "bin") == 0)
        /*output_bin();*/;
    else
        printf("Incorrect option for wvalue\n");
    
    if (strcmp(svalue, "qui") != 0 && strcmp(svalue, "sel") != 0)
        printf ("Unknown option for sort\n");
    if (strcmp(fvalue, "mod") != 0 && strcmp(fvalue, "own") != 0 && strcmp(fvalue, "mil") != 0)
        printf ("Unknown option for field\n");
    if (strcmp(tvalue, "up") != 0 && strcmp(tvalue, "down") != 0)
        printf ("Unknown option for type\n");


    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
    return 0;
}
//quick/selection_brand/owner/mileage_up/down