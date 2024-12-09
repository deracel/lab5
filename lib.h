typedef struct car{
    char* model;
    char* owner;
    float mileage;
}tcar;

char choose();
void input_std(int, tcar*);
void output_std(int, tcar*);
void input_txt(int*, tcar*);
void output_txt(int, tcar*);

#define N 5000