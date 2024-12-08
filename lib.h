typedef struct car{
    char* model;
    char* owner;
    float mileage;
}tcar;

char choose();
void input_std(int, tcar*);
void output_std(int, tcar*);

#define N 50