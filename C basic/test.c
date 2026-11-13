#include<stdio.h>
#define MAX_STU  50
#define NAME_LEN 32

typedef struct {
    char name[NAME_LEN];
    int  score;
} Student;
int main(){
    Student cls[MAX_STU];
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        scanf("%31s %d", cls[i].name, &cls[i].score);
    }
    for (int i = 0 ; i < n; i++) {
        printf("%31s %d\n", cls[i].name, cls[i].score);
    }
    return 0;
}