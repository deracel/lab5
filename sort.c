#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lib.h"


void selection_sort(tcar* arr, size_t size, char* tvalue, char* fvalue) {

    if (strcmp(fvalue, "mod") == 0){//for filed "model"
        tcar* buff = malloc(1 * sizeof(tcar));
        for (size_t i = 0; i < size - 1; i++) {
            size_t minValueIndex = i;
            for (size_t j = i + 1; j < size; j++) {
                if (strcmp(tvalue, "up") == 0){
                    /*if (arr[j].mileage < arr[minValueIndex].mileage)*/
                    if (strcmp(arr[j].model, arr[minValueIndex].model) < 0)
                        minValueIndex = j;
                }
                if (strcmp(tvalue, "down") == 0){
                    /*if (arr[j].mileage > arr[minValueIndex].mileage)*/
                    if (strcmp(arr[j].model, arr[minValueIndex].model) > 0)
                        minValueIndex = j;
                }
            }
        
 
            buff[0].model = arr[i].model;
        

            arr[i].model = arr[minValueIndex].model;
            arr[minValueIndex].model = buff[0].model;
    
    
      


        
            buff[0].owner = arr[i].owner;
            arr[i].owner = arr[minValueIndex].owner;
            arr[minValueIndex].owner = buff[0].owner;
    
      

    
            buff[0].mileage = arr[i].mileage;
            arr[i].mileage = arr[minValueIndex].mileage;
            arr[minValueIndex].mileage = buff[0].mileage;
        }
    free(buff);
    }




    if (strcmp(fvalue, "own") == 0){//for field "owner"
        tcar* buff = malloc(1 * sizeof(tcar));
        for (size_t i = 0; i < size - 1; i++) {
            size_t minValueIndex = i;
            for (size_t j = i + 1; j < size; j++) {
                if (strcmp(tvalue, "up") == 0){
                    /*if (arr[j].mileage < arr[minValueIndex].mileage)*/
                    if (strcmp(arr[j].owner, arr[minValueIndex].owner) < 0)
                        minValueIndex = j;
                }
                if (strcmp(tvalue, "down") == 0){
                    /*if (arr[j].mileage > arr[minValueIndex].mileage)*/
                    if (strcmp(arr[j].owner, arr[minValueIndex].owner) > 0)
                        minValueIndex = j;
                }
            }
        
 
            buff[0].model = arr[i].model;
        

            arr[i].model = arr[minValueIndex].model;
            arr[minValueIndex].model = buff[0].model;
    
    
      


        
            buff[0].owner = arr[i].owner;
            arr[i].owner = arr[minValueIndex].owner;
            arr[minValueIndex].owner = buff[0].owner;
    
      

    
            buff[0].mileage = arr[i].mileage;
            arr[i].mileage = arr[minValueIndex].mileage;
            arr[minValueIndex].mileage = buff[0].mileage;
        }
    free(buff);
    }



    if (strcmp(fvalue, "mil") == 0){//for fielf "mileage"
        tcar* buff = malloc(1 * sizeof(tcar));
        for (size_t i = 0; i < size - 1; i++) {
            size_t minValueIndex = i;
            for (size_t j = i + 1; j < size; j++) {
                if (strcmp(tvalue, "up") == 0){
                    if (arr[j].mileage < arr[minValueIndex].mileage)
                        minValueIndex = j;
                }
                if (strcmp(tvalue, "down") == 0){
                    if (arr[j].mileage > arr[minValueIndex].mileage)
                        minValueIndex = j;
                }
            }
        
 
            buff[0].model = arr[i].model;
        

            arr[i].model = arr[minValueIndex].model;
            arr[minValueIndex].model = buff[0].model;
    
    
      


        
            buff[0].owner = arr[i].owner;
            arr[i].owner = arr[minValueIndex].owner;
            arr[minValueIndex].owner = buff[0].owner;
    
      

    
            buff[0].mileage = arr[i].mileage;
            arr[i].mileage = arr[minValueIndex].mileage;
            arr[minValueIndex].mileage = buff[0].mileage;
        }
    free(buff);
    }
    
}

int comp_mod_up(const void* a, const void* b){
    return strcmp(((tcar*)a)->model, ((tcar*)b)->model);
}
int comp_mod_down(const void* a, const void* b){
    return -1 * strcmp(((tcar*)a)->model, ((tcar*)b)->model);
}


int comp_own_up(const void* a, const void* b){
    return strcmp(((tcar*)a)->owner, ((tcar*)b)->owner);
}
int comp_own_down(const void* a, const void* b){
    return -1 * strcmp(((tcar*)a)->owner, ((tcar*)b)->owner);
}

int comp_mil_up(const void* a, const void* b){
    return (((tcar*)a)->mileage - ((tcar*)b)->mileage);
}

int comp_mil_down(const void* a, const void* b){
    return -1 * (((tcar*)a)->mileage - ((tcar*)b)->mileage);
}


void quick_sort(tcar* arr, int ncars, char* fvalue, char* tvalue){
    if (strcmp(fvalue, "mod") == 0){
        if (strcmp(tvalue, "up") == 0)
            qsort(arr, ncars, sizeof(tcar), comp_mod_up);
        if (strcmp(tvalue, "down") == 0)
            qsort(arr, ncars, sizeof(tcar), comp_mod_down);
    }
    if (strcmp(fvalue, "own") == 0){
        if (strcmp(tvalue, "up") == 0)
            qsort(arr, ncars, sizeof(tcar), comp_own_up);
        if (strcmp(tvalue, "down") == 0)
            qsort(arr, ncars, sizeof(tcar), comp_own_down);
    }
    if (strcmp(fvalue, "mil") == 0){
        if (strcmp(tvalue, "up") == 0)
            qsort(arr, ncars, sizeof(tcar), comp_mil_up);
        if (strcmp(tvalue, "down") == 0)
            qsort(arr, ncars, sizeof(tcar), comp_mil_down);
    }

}


int partit(tcar* arr, int low, int high, char* fvalue, char* tvalue){
    /*tcar* buff = malloc(1 * sizeof(tcar));*/
    if (strcmp(fvalue, "mod") == 0){

    tcar* buff = malloc(1 * sizeof(tcar));
    char* pivo = arr[high].model;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++){
        if (strcmp(tvalue, "up") == 0){
            if (strcmp(arr[j].model, pivo) < 0){
                i++;

                buff[0].model = arr[i].model;
                arr[i].model = arr[j].model;
                arr[j].model = buff[0].model;

                buff[0].owner = arr[i].owner;
                arr[i].owner = arr[j].owner;
                arr[j].owner = buff[0].owner;

                buff[0].mileage = arr[i].mileage;
                arr[i].mileage = arr[j].mileage;
                arr[j].mileage = buff[0].mileage;
            }
        }
        else if (strcmp(tvalue, "down") == 0){
            if (strcmp(arr[j].model, pivo) > 0){
                i++;

                buff[0].model = arr[i].model;
                arr[i].model = arr[j].model;
                arr[j].model = buff[0].model;

                buff[0].owner = arr[i].owner;
                arr[i].owner = arr[j].owner;
                arr[j].owner = buff[0].owner;

                buff[0].mileage = arr[i].mileage;
                arr[i].mileage = arr[j].mileage;
                arr[j].mileage = buff[0].mileage;
            }
        }
    }


    buff[0].model = arr[i + 1].model;
    arr[i + 1].model = arr[high].model;
    arr[high].model = buff[0].model;

    buff[0].owner = arr[i + 1].owner;
    arr[i + 1].owner = arr[high].owner;
    arr[high].owner = buff[0].owner;

    buff[0].mileage = arr[i + 1].mileage;
    arr[i + 1].mileage = arr[high].mileage;
    arr[high].mileage = buff[0].mileage;

    free(buff);

    return i + 1;


    }



    if (strcmp(fvalue, "own") == 0){

    tcar* buff = malloc(1 * sizeof(tcar));
    char* pivo = arr[high].owner;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++){
        if (strcmp(tvalue, "up") == 0){
            if (strcmp(arr[j].owner, pivo) < 0){
                i++;

                buff[0].model = arr[i].model;
                arr[i].model = arr[j].model;
                arr[j].model = buff[0].model;

                buff[0].owner = arr[i].owner;
                arr[i].owner = arr[j].owner;
                arr[j].owner = buff[0].owner;

                buff[0].mileage = arr[i].mileage;
                arr[i].mileage = arr[j].mileage;
                arr[j].mileage = buff[0].mileage;
            }
        }
        else if (strcmp(tvalue, "down") == 0){
            if (strcmp(arr[j].owner, pivo) > 0){
                i++;

                buff[0].model = arr[i].model;
                arr[i].model = arr[j].model;
                arr[j].model = buff[0].model;

                buff[0].owner = arr[i].owner;
                arr[i].owner = arr[j].owner;
                arr[j].owner = buff[0].owner;

                buff[0].mileage = arr[i].mileage;
                arr[i].mileage = arr[j].mileage;
                arr[j].mileage = buff[0].mileage;
            }
        }
    }


    buff[0].model = arr[i + 1].model;
    arr[i + 1].model = arr[high].model;
    arr[high].model = buff[0].model;

    buff[0].owner = arr[i + 1].owner;
    arr[i + 1].owner = arr[high].owner;
    arr[high].owner = buff[0].owner;

    buff[0].mileage = arr[i + 1].mileage;
    arr[i + 1].mileage = arr[high].mileage;
    arr[high].mileage = buff[0].mileage;

    free(buff);

    return i + 1;


    }




    if (strcmp(fvalue, "mil") == 0){

    tcar* buff = malloc(1 * sizeof(tcar));
    float pivo = arr[high].mileage;
    int i = low - 1;
    for (int j = low; j <= high - 1; j++){
        if (strcmp(tvalue, "up") == 0){
            if (arr[j].mileage < pivo){
                i++;

                buff[0].model = arr[i].model;
                arr[i].model = arr[j].model;
                arr[j].model = buff[0].model;

                buff[0].owner = arr[i].owner;
                arr[i].owner = arr[j].owner;
                arr[j].owner = buff[0].owner;

                buff[0].mileage = arr[i].mileage;
                arr[i].mileage = arr[j].mileage;
                arr[j].mileage = buff[0].mileage;
            }
        }
        else if (strcmp(tvalue, "down") == 0){
            if (arr[j].mileage > pivo){
                i++;

                buff[0].model = arr[i].model;
                arr[i].model = arr[j].model;
                arr[j].model = buff[0].model;

                buff[0].owner = arr[i].owner;
                arr[i].owner = arr[j].owner;
                arr[j].owner = buff[0].owner;

                buff[0].mileage = arr[i].mileage;
                arr[i].mileage = arr[j].mileage;
                arr[j].mileage = buff[0].mileage;
            }
        }
    }


    buff[0].model = arr[i + 1].model;
    arr[i + 1].model = arr[high].model;
    arr[high].model = buff[0].model;

    buff[0].owner = arr[i + 1].owner;
    arr[i + 1].owner = arr[high].owner;
    arr[high].owner = buff[0].owner;

    buff[0].mileage = arr[i + 1].mileage;
    arr[i + 1].mileage = arr[high].mileage;
    arr[high].mileage = buff[0].mileage;

    free(buff);

    return i + 1;


    }
    return 0;

}


void my_qsort(tcar* arr, int low, int high, char* fvalue, char* tvalue){
    if (low < high){
        int parted = partit(arr, low, high, fvalue, tvalue);
        my_qsort(arr, low, parted - 1, fvalue, tvalue);
        my_qsort(arr, parted + 1, high, fvalue, tvalue);
    }
}

