#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <time.h>
#include "lib.h"


int main (int argc, char **argv)
{

    int n;
    char *svalue = NULL;
    char *fvalue = NULL;
    char *tvalue = NULL;
   
    int index;
    int c;
    opterr = 0;
    int ncars = 0;

    while ((c = getopt (argc, argv, "s:f:t:")) != -1)
        switch (c){
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
                if (isprint (optopt))
                    fprintf (stderr, "Unknown option `-%c'.\n", optopt);
        return 1;
        default:
        abort ();
    }
    if (svalue == NULL || fvalue == NULL || tvalue == NULL)
        {fprintf (stderr, "Incorrect input, not all options or option characters are entered\n"); return 0;}
    printf ("svalue = %s, fvalue = %s, tvalue = %s", svalue, fvalue, tvalue);
    if ((strcmp(svalue, "quick") != 0&&strcmp(svalue, "sel") != 0&&strcmp(svalue, "myquick") != 0)||
        (strcmp(fvalue, "mod") != 0&&strcmp(fvalue, "own") != 0&&strcmp(fvalue, "mil") != 0)||
        (strcmp(tvalue, "up") != 0&&strcmp(tvalue, "down") != 0))
            {printf("\nIncorrect option for value\n");
            printf("\nOptions for values:\nsvalue: sel, quick, myquick\nfvalue: mod, own, mil\ntwalue: up, down\n\n");
            return 0;}

    int n_elem;
    int n_arr;
    printf("\nEnter number of elements in arrays: ");
    scanf("%d", &n_elem);
    printf("Enter number of arrays: ");
    scanf("%d", &n_arr);
    tcar* arr = malloc(n_arr * sizeof(tcar));


    
    char buff[n_elem];
    for (int i = 0; i < n_arr; i++){
        arr[i].model = malloc((n_elem)* sizeof(tcar));
        for (int j = 0; j < n_elem; j++)
            buff[j] = 'a' + rand()%26;
        buff[n_elem] = '\0';
        strcpy(arr[i].model, buff);

        arr[i].owner = malloc((n_elem) * sizeof(tcar));
        for (int j = 0; j < n_elem; j++)
            buff[j] = 'a' + rand()%26;
        buff[n_elem] = '\0';
        strcpy(arr[i].owner, buff);
        
        arr[i].mileage = (rand() % 25) / 2 + 0.25;

        
    }
    



    time_t start;
    time_t end;
    if (strcmp(svalue, "sel") == 0){
        start = clock();
        selection_sort(arr, n_arr, tvalue, fvalue);
        end = clock();
    }
    if (strcmp(svalue, "quick") == 0){
        start = clock();
        quick_sort(arr, n_arr, fvalue, tvalue);
        end = clock();
    }
    if (strcmp(svalue, "mquick") == 0){
        int low = 0;
        int high = n_arr - 1;
        start = clock();
        my_qsort(arr, low, high, fvalue, tvalue);
        end = clock();
    }
    

    float time = (float)(end - start) / CLOCKS_PER_SEC;

    out_time(time, svalue, fvalue, tvalue, n_elem, n_arr);
    printf("time   - %6.f μs\n", time * 1000000);
    printf("\n\n");
  
    
    output_txt(n_arr, arr);




    for (index = optind; index < argc; index++)
        printf ("Non-option argument %s\n", argv[index]);
    return 0;
}

