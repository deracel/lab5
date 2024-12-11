#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"

void output_std(int ncars, tcar* arr){
    for (int i = 0; i < ncars; ++i){
        printf("%d car model  : %s\n", i + 1, arr[i].model);
        printf("%d car owner  : %s\n", i + 1, arr[i].owner);
        printf("%d car mileage: %.2f\n", i + 1, arr[i].mileage);
        printf("\n");
    }
    for (int i = 0; i < ncars; i++){
        free(arr[i].model);
        free(arr[i].owner);
    }
    free(arr);
}

void output_txt(int ncars, tcar* arr){
    char* filename = "output.txt";
    FILE *f = fopen(filename, "a");
    for (int i = 0; i < ncars; ++i){
        fprintf(f, "%s ", arr[i].model);
        fprintf(f, "%s ", arr[i].owner);
        fprintf(f, "%.2f;\n", arr[i].mileage);
    }
    /*printf(f, "\n");*/
    for (int i = 0; i < ncars; i++){
        free(arr[i].model);
        free(arr[i].owner);
    }
    free(arr);
    fclose(f);
}
char space[] = {" "};
char delim[] = {";\n"};

int lenmodel;
int lenowner;
void output_bin(int ncars, tcar* arr){
    char* filename = "outputbin.txt";
    FILE *f = fopen(filename, "ab");
    for (int i = 0; i < ncars; ++i){
        lenmodel = strlen(arr[i].model);
        fwrite(arr[i].model, lenmodel, sizeof(char), f);
        fwrite(space, 1, sizeof(char), f);
        lenowner = strlen(arr[i].owner);
        fwrite(arr[i].owner, lenowner, sizeof(char), f);
        fwrite(space, 1, sizeof(char), f);
        fwrite(&arr[i].mileage, 2, sizeof(float), f);
        fwrite(delim, 2, sizeof(char), f);
        
    }
    for (int i = 0; i < ncars; i++){
        free(arr[i].model);
        free(arr[i].owner);
    }
    free(arr);
    fclose(f);
}