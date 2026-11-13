#include <stdio.h>
#include <string.h>
#include <windows.h>
typedef struct student
{
    char name[20];
    int age;
    float score;
} Student;

int main(){
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
    Student s1={"老李", 12 ,90.5};
    printf("Name: %s\n", s1.name);
    printf("Age: %d\n", s1.age);
    printf("Score: %.2f\n", s1.score);
    return 0;
}