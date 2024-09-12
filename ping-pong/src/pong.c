// I WANT TO PLAY WITH YOU
//        YOUR FRIEND, AI

#include <stdio.h>
#include <ncurses.h>
#include <unistd.h>
#include <time.h>

#define SIZE_X 80
#define SIZE_Y 25
#define GAME_END_SCORE 3
#define RIGHT_RACKET 76
#define LEFT_RACKET 3

char ZERO[15] = {'#', '#', '#', '#', ' ', '#', '#', ' ', '#', '#', ' ', '#', '#', '#', '#'};
char ONE[15] = {'#', '#', '#', ' ', '#', ' ', ' ', '#', ' ', ' ', '#', ' ', '#', '#', ' '};
char TWO[15] = {'#', '#', '#', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#'};
char THREE[15] = {'#', '#', '#', ' ', ' ', '#', '#', '#', '#', ' ', ' ', '#', '#', '#', '#'};
char FOUR[15] = {' ', ' ', '#', ' ', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', ' ', '#'};
char FIVE[15] = {'#', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', ' ', ' ', '#', '#', '#'};
char SIX[15] = {'#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', ' ', '#', '#', '#'};

char SEVEN[15] = {'#', ' ', ' ', '#', ' ', ' ', ' ', '#', ' ', ' ', ' ', '#', '#', '#', '#'};
char EIGHT[15] = {'#', '#', '#', '#', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#'};

char NINE[15] = {'#', '#', '#', ' ', ' ', '#', '#', '#', '#', '#', ' ', '#', '#', '#', '#'};

enum RACKET_DIRECTION {
    UP,
    DOWN,
};

enum START_PLAYER {
    LEFT,
    RIGHT,
};


typedef struct {
    int x;
    int y;
    int angle;
    int direction;
} ball;

typedef struct {
    int y;
    int score;
} player;

void initialize(player *player_left, player *player_right, ball *ball, enum START_PLAYER start);
void update_racket(player *player, enum RACKET_DIRECTION dir);
void update_ball(player *player_left, player *player_right, ball *ball);
int is_collision_wall(ball *ball);
int is_collision_racket(ball *ball, player *player);
int is_goll(ball *ball);
int game_end(player *player_left, player *player_right);
int is_collision_racket_with_walls(player *player, enum RACKET_DIRECTION direction);
void draw(player player_left, player player_right, ball ball);
void print_goal();
void print_player_one();
void print_player_two();
int draw_number(char array[15], int del_x, int y);
int is_score(player player_left, player player_right, int x, int y);

int main() {
    player left_player;
    player right_player;
    left_player.score = 0;
    right_player.score = 0;
    ball ball;
    initialize(&left_player, &right_player, &ball, LEFT);
    initscr();
    nodelay(stdscr, TRUE);
    noecho();
    char sym;

    draw(left_player, right_player, ball);
        
    refresh();
    scanf("%c", &sym);
    char symbol = ' ';
    while (1) {
        symbol = getch();
        switch (symbol) {
            case 'a':
                update_racket(&left_player, UP);
                break;
            case 'z':
                update_racket(&left_player, DOWN);
                break;
            case 'k':
                update_racket(&right_player, UP);
                break;
            case 'm':
                update_racket(&right_player, DOWN);
                break;
            default:
                break;
        }
        update_ball(&left_player, &right_player, &ball);

        if (is_goll(&ball) && !game_end(&left_player, &right_player)) {
            clear();
            print_goal();
            refresh();
            sleep(1);
            if (ball.direction == 1) {
                left_player.score++;
                initialize(&left_player, &right_player, &ball, RIGHT);
            } else {
                right_player.score++;
                initialize(&left_player, &right_player, &ball, LEFT);
            }
            clear();
            draw(left_player, right_player, ball);
            refresh();
            scanf("%c", &sym);
        }

        if (game_end(&left_player, &right_player)) {
            clear();
            if (left_player.score > right_player.score) {
                print_player_one();
            } else {
                print_player_two();
            }
            refresh();
            sleep(5);
            break;
        }
        clear();
        draw(left_player, right_player, ball);
        
        refresh();
        usleep(100000);
    }
    sleep(5);
    endwin();
}

int game_end(player *player_left, player *player_right) {
    if ((player_left->score == GAME_END_SCORE) || (player_right->score == GAME_END_SCORE)) {
        return 1;
    }
    return 0;
}

void initialize(player *player_left, player *player_right, ball *ball, enum START_PLAYER start) {
    player_left->y = SIZE_Y / 2;
    player_right->y = SIZE_Y / 2;
    ball->y = SIZE_Y / 2;
    ball->angle = 1;

    if (start == LEFT) {
        ball->x = LEFT_RACKET + 1;
        ball->direction = 1;

    } else {
        ball->x = RIGHT_RACKET - 1;
        ball->direction = -1;
    }
}

void update_ball(player *player_left, player *player_right, ball *ball) {
    if (is_collision_wall(ball) == 1) {
        ball->angle *= -1;
    }
    if (is_collision_racket(ball, player_left) == 1) {
        ball->direction *= -1;
    }
    if (is_collision_racket(ball, player_right) == 1) {
        ball->direction *= -1;
    }

    if (ball->angle == 1) {
        if (ball->direction == 1) {
            ball->x++;
            ball->y++;
        } else {
            ball->x--;
            ball->y++;
        }
    } else {
        if (ball->direction == 1) {
            ball->x++;
            ball->y--;
        } else {
            ball->x--;
            ball->y--;
        }
    }
}

void update_racket(player *player, enum RACKET_DIRECTION dir) {
    if (!is_collision_racket_with_walls(player, dir)) {
        if (dir == UP) {
            player->y++;
        } else {
            player->y--;
        }
    }
}

int is_collision_wall(ball *ball) {
    if ((ball->y == 2) || (ball->y == (SIZE_Y - 1))) {
        return 1;
    }
    return 0;
}

int is_collision_racket(ball *ball, player *player) {
    if (ball->direction == 1) {
        if (ball->x == RIGHT_RACKET - 1) {
            if ((ball->y <= player->y + 1) && (ball->y >= player->y - 1)) {
                return 1;
            }
            if ((ball->angle == 1) && (ball->y == player->y - 2)) {
                return 1;
            }
            if ((ball->angle == -1) && (ball->y == player->y + 2)) {
                return 1;
            }
        }
    }

    if (ball->direction == -1) {
        if (ball->x == LEFT_RACKET + 1) {
            if ((ball->y <= player->y + 1) && (ball->y >= player->y - 1)) {
                return 1;
            }
        }
    }
    return 0;
}

int is_goll(ball *ball) {
    if (ball->direction == 1) {
        if (ball->x == SIZE_X + 1) {
            return 1;
        }
    }
    if (ball->direction == - 1) {
        if (ball->x == 1) {
            return 1;
        }
    }
    return 0;
}

int is_collision_racket_with_walls(player *player, enum RACKET_DIRECTION direction) {
    if (direction == UP) {
        if (player->y == (SIZE_Y - 2)) {
            return 1;
        }
    }
    if (direction == DOWN) {
        if (player->y == 3) {
            return 1;
        }
    }
    return 0;
}

void draw(player player_left, player player_right, ball ball) {
    for (int i = SIZE_Y; i > 0; i--) {
        for (int j = 0; j < SIZE_X; j++) {
            if ((i == SIZE_Y) || (i == 1)) {
                printw("-");
                continue;
            }
            if (((j == 0) || (j == SIZE_X / 2) || (j == SIZE_X - 1)) && ((ball.x != j)
            || (ball.y != i))) {
                printw("|");
                continue;
            }
            if ((j == LEFT_RACKET) && ((player_left.y == i - 1) || (player_left.y == i)
            || (player_left.y == i + 1))) {
                printw("H");
                continue;
            }

            if ((j == RIGHT_RACKET) && ((player_right.y == i - 1) || (player_right.y == i)
            || (player_right.y == i + 1))) {
                printw("H");
                continue;
            }

            if (ball.x == j && ball.y == i) {
                printw("o");
                continue;
            }

            if (is_score(player_left, player_right, j, i)) {
                printw("#");
                continue;
            }

                printw(" ");
        }
            printw("\n");
    }
}

void print_goal() {
    printw("HHHHH  HHHHH   HHH   H      HH\n");
    printw("H      H   H  H   H  H      HH\n");
    printw("H  HH  H   H  H   H  H      HH\n");
    printw("H   H  H   H  HHHHH  H\n");
    printw("HHHHH  HHHHH  H   H  HHHHH  HH\n\n\n");
}

void print_player_one() {
    printw("HHHHH  H       HHH     H   H  HHHHH  HHHHH    H\n");
    printw("H   H  H      H    H   H   H  H      H   H  HHH\n");
    printw("HHHHH  H      H    H    HHH   HHHHH  HHHHH    H\n");
    printw("H      H   H  HHHHHH     H    H      H H      H\n");
    printw("H      HHHHH  H    H     H    HHHHH  H  H   HHHHH\n\n\n");
    printw("H          H   HH    H       H   HH\n");
    printw("H     H    H         H H     H   HH\n");
    printw(" H    H   H    HH    H   H   H   HH\n");
    printw("   H  H  H     HH    H     H H     \n");
    printw("     HHH       HH    H       H   HH\n");
}

void print_player_two() {
    printw("HHHHH  H       HHH     H   H  HHHHH  HHHHH  HHHHH\n");
    printw("H   H  H      H    H   H   H  H      H   H  H   H\n");
    printw("HHHHH  H      H    H    HHH   HHHHH  HHHHH     H\n");
    printw("H      H   H  HHHHHH     H    H      H H     H\n");
    printw("H      HHHHH  H    H     H    HHHHH  H  H   HHHHH\n\n\n");
    printw("H          H   HH    H       H   HH\n");
    printw("H     H    H         H H     H   HH\n");
    printw(" H    H    H   HH    H   H   H   HH\n");
    printw("  HH  H  HH    HH    H     H H     \n");
    printw("    HHHHH      HH    H       H   HH\n");
}

int draw_number(char array[15], int del_x, int y) {
    if (del_x == 0) {
        switch (y) {
        case 23:
            return (array[12] == '#') ? 1 : 0;
            break;
        case 22:
            return (array[9] == '#') ? 1 : 0;
            break;
        case 21:
            return (array[6] == '#') ? 1 : 0;
            break;
        case 20:
            return (array[3] == '#') ? 1 : 0;
            break;
        case 19:
            return (array[0] == '#') ? 1 : 0;
            break;
        default:
            break;
        }
    }

    if (del_x == 1) {
        switch (y) {
        case 23:
            return (array[13] == '#') ? 1 : 0;
            break;
        case 22:
            return (array[10] == '#') ? 1 : 0;
            break;
        case 21:
            return (array[7] == '#') ? 1 : 0;
            break;
        case 20:
            return (array[4] == '#') ? 1 : 0;
            break;
        case 19:
            return (array[1] == '#') ? 1 : 0;
            break;
        default:
            break;
        }
    }
     if (del_x == 2) {
        switch (y) {
        case 23:
            return (array[14] == '#') ? 1 : 0;
            break;
        case 22:
            return (array[11] == '#') ? 1 : 0;
            break;
        case 21:
            return (array[8] == '#') ? 1 : 0;
            break;
        case 20:
            return (array[5] == '#') ? 1 : 0;
            break;
        case 19:
            return (array[2] == '#') ? 1 : 0;
            break;
        default:
            break;
        }
    }
    return 0;
}

int is_score(player player_left, player player_right, int x, int y) {
    int score = -1;
    int start_x;
    if ((x >= 35) && (x <= 37) && (y >= 19) && (y <= 23)) {
        score = player_left.score % 10;
        start_x = 35;
    }

    if ((x >= 47) && (x <=49) && (y >= 19) && (y <= 23)) {
        score = player_right.score % 10;
        start_x = 47;
    }

    if ((x >= 31) && (x <= 33) && (y >= 19) && (y <= 23)) {
        score = player_left.score / 10;
        start_x = 31;
    }

    if ((x >= 43) && (x <=45) && (y >= 19) && (y <= 23)) {
        score = player_right.score / 10;
        start_x = 43;
    }

    if (score == -1) {
        return 0;
    }

    switch (score) {
            case 0:
                return draw_number(ZERO, x - start_x, y);
            case 1:
                return draw_number(ONE, x - start_x, y);
            case 2:
                return draw_number(TWO, x - start_x, y);
            case 3:
                return draw_number(THREE, x - start_x, y);
            case 4:
                return draw_number(FOUR, x - start_x, y);
            case 5:
                return draw_number(FIVE, x - start_x, y);
            case 6:
                return draw_number(SIX, x - start_x, y);
            case 7:
                return draw_number(SEVEN, x - start_x, y);
            case 8:
                return draw_number(EIGHT, x - start_x, y);
            case 9:
                return draw_number(NINE, x - start_x, y);
        }
    return 0;
}


