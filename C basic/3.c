#include <stdio.h>

#define MAX_STU  50
#define NAME_LEN 32

typedef struct {
    char name[NAME_LEN];
    int  score;
} Student;

int main(void) {
    Student cls[MAX_STU];
    int cnt;

    printf("输入人数：");
    if (scanf("%d", &cnt) != 1 || cnt <= 0 || cnt > MAX_STU) {
        printf("人数无效\n");
        return 1;
    }

    for (int i = 0; i < cnt; i++) {
        scanf("%31s %d", cls[i].name, &cls[i].score);
    }

    /* 修复3：%-12s 是左对齐，原来的 %31s 会把名字推到很右边 */
    for (int i = 0; i < cnt; i++) {
        printf("%-12s %d\n", cls[i].name, cls[i].score);
    }

    /* 修复2：平均分要"所有分数求和 / 人数"，不能写死 cls[0]+cls[1]+cls[2] */
    double sum = 0;
    for (int i = 0; i < cnt; i++) {
        sum += cls[i].score;
    }
    printf("平均分: %.2f\n", sum / cnt);

    /* 修复4：最高分要同时记住分数和姓名（用下标记录） */
    int max_i = 0;
    for (int i = 1; i < cnt; i++) {
        if (cls[i].score > cls[max_i].score) {
            max_i = i;
        }
    }
    printf("最高分: %s %d\n", cls[max_i].name, cls[max_i].score);

    return 0;
}
