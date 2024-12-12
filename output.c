#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lib.h"


void output_txt(int ncars, tcar* arr){
    char* filename = "out.txt";
    FILE *f = fopen(filename, "w");
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

void out_time(float time, char* svalue, char* fvalue, char* tvalue, int n_elem, int n_arr){
    char* filename = "time.txt";
    FILE *f = fopen(filename, "a");
    fprintf(f, "%s\t", svalue);
    fprintf(f, "arrays = %d\t", n_arr);
    fprintf(f, "%0.6f μs\n", time);
    fclose(f);
}