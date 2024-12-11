typedef struct car{
    char* model;
    char* owner;
    float mileage;
}tcar;

void input_std(int, tcar*);
void output_std(int, tcar*);
void input_txt(int*, tcar*);
void output_txt(int, tcar*);
void output_bin(int, tcar*);
void input_bin(int* ncars, tcar* arr);
void selection_sort(tcar* arr, size_t size, char* tvalue, char* fvalue);

#define N 5000