//Nitis Jadipang 66070501020

// Grading

#include <stdio.h>
#include <math.h>

typedef struct { 
    char name[50];
    float score;
} Student;

void findmean(Student data[],int num,float *mean){
    float sum = 0;
    for(int i=0; i<num; ++i){
        sum += data[i].score;
    }
    *mean = sum/num;
}

float findsd(Student data[], int num, float mean) {
    float sum_squared_diff = 0.0;

    for (int i = 0; i < num; ++i) {
        float diff = data[i].score - mean;
        sum_squared_diff += diff * diff;
    }

    return sqrt(sum_squared_diff / num);
}

int main(){
    int number;
    scanf("%d", &number);
    
    Student students[number];

    for (int i = 0; i < number; ++i) {
        scanf("%s %f", students[i].name, &students[i].score);
    }

    //find max min score
    float max, min;
    max = min = students[0].score;

    int posMAX = 0, posMIN = 0;
    
    for(int i = 0; i< number; i++){
        if(max < students[i].score){
            max = students[i].score;
            posMAX = i;
        }
        if(min > students[i].score){
            min = students[i].score;
            posMIN = i;
        }
    }
    float meanValue = 0.0;
    findmean(students, number, &meanValue);
    float sdValue = findsd(students, number, meanValue);

    printf("%.2f %.2f %s %s", meanValue, sdValue, students[posMAX].name,students[posMIN].name);
}