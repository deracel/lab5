#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"



void input_std(int i, tcar* arr){
    int len = 0;
    printf("Enter the model of car %d  : ", i + 1);
    arr[i].model = malloc (N * sizeof(tcar));
    scanf("%s", arr[i].model);
    len = strlen(arr[i].model);
    arr[i].model = realloc(arr[i].model, len * sizeof(tcar));

    printf("Enter the owner of car %d  : ", i + 1);
    arr[i].owner = malloc (N * sizeof(tcar));
    scanf("%s", arr[i].owner);
    len = strlen(arr[i].model);
    arr[i].owner = realloc(arr[i].owner, len * sizeof(tcar));

    printf("Enter the mileage of car %d: ", i + 1);
    scanf("%f", &arr[i].mileage);
    printf("\n");
    }
