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

void input_txt(int* ncars, tcar* arr){
    char* filename = "input.txt";
    FILE *f = fopen(filename, "r");
    if (f == NULL){
        printf("Error with open=ing file\n");
    }
    char symbol;
    int kol = 0;
    while ((symbol = fgetc(f)) != EOF){
        if (symbol == ';')
            kol++;
    }
    *ncars = kol;
    rewind(f);
    printf("%d\n\n", *ncars);
    for (int i = 0; i < *ncars; ++i){    
        arr[i].model = malloc(N * sizeof(tcar));
        fscanf(f, "%s ", arr[i].model);

        arr[i].owner = malloc(N * sizeof(tcar));
        fscanf(f, "%s ", arr[i].owner);

        fscanf(f, "%f;", &arr[i].mileage);
    }

    fclose(f);
}

void input_bin(int* ncars, tcar* arr){
    char* filename = "outputbin.txt";
    FILE *f = fopen(filename, "rb");
    if (f == NULL){
        printf("Error with opening file\n");
    }
    for (int i = 0; i < 5; ++i){
        arr[i].model = malloc(N * sizeof(tcar));
        
        fread(arr[i].model, 17, sizeof(char), f);

        arr[i].owner = malloc(N * sizeof(tcar));
        fread(arr[i].owner, 10, sizeof(char), f);

        fread(&arr[i].mileage, 4, sizeof(char), f);
    }
    fclose(f);

    for (int i = 0; i < 5; ++i){
        printf("next---%s%s%f\n\n", arr[i].model, arr[i].owner, arr[i].mileage);
    }


}