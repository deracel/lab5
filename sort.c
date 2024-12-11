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


