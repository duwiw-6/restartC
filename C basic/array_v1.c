#include <stdio.h>
#include <string.h>
#include <windows.h>

#define MAX_STU  50
#define NAME_LEN 32

typedef struct {
    char name[NAME_LEN];
    int  score;
} Student;

/* ---------- 已实现：添加一个学生，返回新的 count ---------- */
int add(Student cls[], int count) {
    if (count >= MAX_STU) {
        printf("名单已满，最多 %d 人\n", MAX_STU);
        return count;
    }
    printf("姓名：");
    scanf("%31s", cls[count].name);
    printf("分数：");
    if (scanf("%d", &cls[count].score) != 1) {
        printf("分数无效，已取消\n");
        while (getchar() != '\n');
        return count;
    }
    printf("已添加 %s（%d 分）\n", cls[count].name, cls[count].score);
    return count + 1;
}

/* ---------- 已实现：显示全部 ---------- */
void print_all(Student cls[], int count) {
    if (count == 0) {
        printf("暂无学生记录\n");
        return;
    }
    printf("%-4s %-12s %s\n", "序号", "姓名", "分数");
    for (int i = 0; i < count; i++) {
        printf("%-4d %-12s %d\n", i + 1, cls[i].name, cls[i].score);
    }
}

/* ---------- TODO 3：按分数从高到低排序 ----------
 * 提示：冒泡排序，内层比较 cls[j].score < cls[j+1].score 就交换
 *      交换时必须整体交换：
 *          Student tmp = cls[j];
 *          cls[j] = cls[j+1];
 *          cls[j+1] = tmp;
 *      只交换 score 会让名字和分数错位
 */
void sort_by_score(Student cls[], int count) {
    /* TODO：在这里写 */
}

/* ---------- TODO 4：按姓名查找，返回下标，找不到返回 -1 ----------
 * 提示：strcmp(cls[i].name, name) == 0 表示字符串相等
 */
int find_by_name(Student cls[], int count, const char *name) {
    /* TODO：在这里写 */
    return -1;
}

/* ---------- TODO 5：按姓名删除，返回新的 count ----------
 * 提示：1. 先 pos = find_by_name(...)
 *      2. pos < 0 → 没找到，打印提示后 return count
 *      3. 找到 → 从 pos 开始整体前移：cls[i] = cls[i+1]
 *         循环条件 i < count - 1，最后 return count - 1
 */
int remove_by_name(Student cls[], int count, const char *name) {
    /* TODO：在这里写 */
    return count;
}

/* ---------- 菜单：已实现，不用改 ---------- */
int main(void) {
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);

    Student cls[MAX_STU];
    int count = 0;
    int choice;

    while (1) {
        printf("\n===== 学生管理（数组版）=====\n");
        printf("1. 添加学生\n");
        printf("2. 显示全部\n");
        printf("3. 按分数排序\n");
        printf("4. 按姓名查找\n");
        printf("5. 删除学生\n");
        printf("0. 退出\n");
        printf("请选择：");

        if (scanf("%d", &choice) != 1) {
            while (getchar() != '\n');
            continue;
        }

        char name[NAME_LEN];

        switch (choice) {
        case 0:
            printf("再见\n");
            return 0;

        case 1:
            count = add(cls, count);
            break;

        case 2:
            print_all(cls, count);
            break;

        case 3:
            sort_by_score(cls, count);
            print_all(cls, count);      /* 排完顺便显示结果 */
            break;

        case 4: {
            printf("要查找的姓名：");
            scanf("%31s", name);
            int pos = find_by_name(cls, count, name);
            if (pos < 0) {
                printf("没找到 %s\n", name);
            } else {
                printf("找到：第 %d 个，%s %d 分\n", pos + 1, cls[pos].name, cls[pos].score);
            }
            break;
        }

        case 5:
            printf("要删除的姓名：");
            scanf("%31s", name);
            count = remove_by_name(cls, count, name);
            break;

        default:
            printf("无效选项\n");
        }
    }
}
