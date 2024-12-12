typedef struct car{
    char* model;
    char* owner;
    float mileage;
}tcar;

void rando(int n_elem, int n_arr, tcar* arr);

void out_time(float time, char* svalue, char* fvalue, char* tvalue, int n_elem, int n_arr);

void input_std(int, tcar*);
void input_txt(int*, tcar*);
void input_bin(int* ncars, tcar* arr);


void output_std(int, tcar*);
void output_txt(int, tcar*);
void output_bin(int, tcar*);


int comp_mod_up(const void* a, const void* b);
int comp_mod_down(const void* a, const void* b);

int comp_own_up(const void* a, const void* b);
int comp_own_down(const void* a, const void* b);

int comp_mil_up(const void* a, const void* b);
int comp_mil_down(const void* a, const void* b);


void selection_sort(tcar* arr, size_t size, char* tvalue, char* fvalue);
void quick_sort(tcar* arr, int ncars, char* fvalue, char* tvalue);
/*void my_quick_sort(tcar* arr, int low, int high, char* fvalue, char* tvalue);*/
void my_qsort(tcar* arr, int low, int high, char* fvalue, char* tvalue);
int partition (tcar arr, int low, int high, char* fvalue, char* tvalue);

#define N 5000