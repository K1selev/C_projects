#include <stdio.h>
#include <stdlib.h>
#include <curses.h>
#include <unistd.h>
#define YMAX 25
#define XMAX 80

void alloc(int ***a, int n, int m);
int screen(int **a);
int lifecheck(int ** a, int i, int j);
void swap(int **a, int **b);
void input(int **a);

int main() {
    int **matrix = NULL, **matr = NULL;
    int flag = 0, resting_time = 500000;
    alloc(&matrix, YMAX, XMAX);
    alloc(&matr, YMAX, XMAX);
    input(matrix);
    printf("\e[8;$33;$83;t");
    initscr();
    noecho();
    nodelay(stdscr, TRUE);
    while (!flag) {
        char c;
        clear();
        screen(matrix);
        c = getch();
        if (c == '1') {
            resting_time = 500000;
        } else if (c == '2') {
            resting_time = 250000;
        } else if (c == '3') {
            resting_time = 125000;
        } else if (c == 'q' || c == 'Q') {
            flag = 1;
        }
        for (int i = 0; i < YMAX; i++) {
            for (int j = 0; j < XMAX; j++) {
              matr[i][j] = lifecheck(matrix, i, j);
            }
        }
        swap(matrix, matr);
        refresh();
        usleep(resting_time);
    }
    clear();
    endwin();
    free(matr);
    free(matrix);
    return 1;
}

int lifecheck(int** a, int i, int j) {
    int life_sum = 0, condition = 0, left = j - 1, right = j + 1, down = i + 1, up = i - 1;
    if (i == 0) up = YMAX - 1;
    if (i == YMAX - 1) down = 0;
    if (j == 0) left = XMAX - 1;
    if (j == XMAX -1) right = 0;
    life_sum+=a[up][left];
    life_sum+=a[i][left];
    life_sum+=a[down][left];
    life_sum+=a[up][j];
    life_sum+=a[down][j];
    life_sum+=a[up][right];
    life_sum+=a[i][right];
    life_sum+=a[down][right];
    if (a[i][j] == 1 && (life_sum == 2 || life_sum == 3))
        condition = 1;
    if (a[i][j] == 1 && (life_sum < 2 || life_sum > 3))
        condition = 0;
    if (a[i][j] == 0 && life_sum == 3)
        condition = 1;
    return condition;
}

void alloc(int ***a, int n, int m) {
    int** arr = malloc(n * m * sizeof(int) + m * sizeof(int*));
    int* ptr = (int*) (arr + n);
    for (int i = 0; i < n; i++)
        arr[i] =  ptr + m * i;
    *a = arr;
}

int screen(int **a) {
    for (int i = 0; i < YMAX + 2; i++) {
        for (int j = 0; j < XMAX + 2; j++) {
            if (i == 0 || i == YMAX + 1) {
                printw("_");
            } else if (j == 0 || j == XMAX + 1) {
                printw("|");
            } else if (a[i - 1][j - 1] == 1) {
                printw("#");
            } else {
                printw(" ");
            }
            }
        printw("\n");
    }
    printw("\n1 - minimum game speed\n2 - medium game speed\n3 - maximum game speed\nq/Q - exit");
    return 0;
}

void swap(int **a, int **b) {
    for (int i = 0; i < YMAX; i++) {
         for (int j = 0; j < XMAX; j++) {
            a[i][j] = b[i][j];
         }
     }
}

void input(int **a) {
    for (int i = 0; i < YMAX; i++) {
        for (int j = 0; j < XMAX; j++) {
            scanf("%d", &a[i][j]);
        }
    }
}
