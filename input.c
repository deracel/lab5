#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


/*void input_std(int i, tcar* arr){
    int len = 0;
    printf("Enter the model of car %d  : ", i + 1);
    arr[i].model = malloc (N * sizeof(tcar));
    scanf("%s", arr[i].model);
    len = strlen(arr[i].model);
    while (len > 16){
        printf("Error: field model contains more than 16 elems\n");
        scanf("%s", arr[i].model);
        len = strlen(arr[i].model);
    }
    arr[i].model = realloc(arr[i].model, len * sizeof(tcar));

    printf("Enter the owner of car %d  : ", i + 1);
    arr[i].owner = malloc (N * sizeof(tcar));
    scanf("%s", arr[i].owner);
    len = strlen(arr[i].owner);
    arr[i].owner = realloc(arr[i].owner, len * sizeof(tcar));

    printf("Enter the mileage of car %d: ", i + 1);
    input_float(&arr[i].mileage);
    printf("\n");
}*/

void rando(int n_elem, int n_arr, tcar* arr){
    char buff[n_elem];
    for (int i = 0; i < n_arr; i++){
        arr[i].model = malloc((n_elem)* sizeof(tcar));
        for (int j = 0; j < n_elem; j++)
            buff[j] = 'a' + rand()%26;
        buff[n_elem] = '\0';
        arr[i].model = buff;

        arr[i].owner = malloc((n_elem) * sizeof(tcar));
        for (int j = 0; j < n_elem; j++)
            buff[j] = 'a' + rand()%26;
        buff[n_elem] = '\0';
        arr[i].owner = buff;
        
        arr[i].mileage = (rand() % 25) / 2 + 0.25;

        
    }
        for (int i = 0; i < n_arr; ++i){
            printf("%d----%s %s %0.2f\n", i+1, arr[i].model, arr[i].owner, arr[i].mileage);
        }
}