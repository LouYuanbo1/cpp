#include "snake.h"  
#include "food.h"  
  
Snake::Snake() : x(0), y(2), direction(RIGHT), tsize(START_TAIL_SIZE + 1) {  
    tail.resize(MAX_TAIL_SIZE);  
}  
  
void Snake::move() {  
    int max_x = 0, max_y = 0;  
    char ch = '@';  
    getmaxyx(stdscr, max_y, max_x);  
    mvprintw(y, x, " ");  
  
    switch (direction) {  
        case LEFT:  
            if (x <= 0) x = max_x - 1;  
            mvprintw(y, --x, "%c", ch);  
            break;  
        case RIGHT:  
            if (x >= max_x - 1) x = 0;  
            mvprintw(y, ++x, "%c", ch);  
            break;  
        case UP:  
            if (y <= 0) y = max_y - 1;  
            mvprintw(--y, x, "%c", ch);  
            break;  
        case DOWN:  
            if (y >= max_y - 1) y = 0;  
            mvprintw(++y, x, "%c", ch);  
            break;  
    }  
    refresh();  
}  
  
void Snake::moveTail() {  
    char ch = '*';  
    mvprintw(tail[tsize - 1].y, tail[tsize - 1].x, " ");  
    for (size_t i = tsize - 1; i > 0; i--) {  
        tail[i] = tail[i - 1];  
        if (tail[i].y || tail[i].x) {  
            mvprintw(tail[i].y, tail[i].x, "%c", ch);  
        }  
    }  
    tail[0].x = x;  
    tail[0].y = y;  
}  
  
void Snake::addTail() {  
    if (tsize < MAX_TAIL_SIZE) {  
        tsize++;  
    } else {  
        mvprintw(0, 0, "Can't add tail");  
    }  
}  
  
bool Snake::isCrash() {  
    for (size_t i = 1; i < tsize; ++i) {  
        if (x == tail[i].x && y == tail[i].y) return true;  
    }  
    return false;  
}  
  
bool Snake::changeDirection() {  
    int key = getch();  
    if (key == STOP_GAME)  
        return false;  
    switch (key) {  
        case KEY_DOWN: direction = DOWN; break;  
        case KEY_UP: direction = UP; break;  
        case KEY_LEFT: direction = LEFT; break;  
        case KEY_RIGHT: direction = RIGHT; break;  
    }  
    return true;  
}  
  
void Snake::printLevel() {  
    int max_x = 0, max_y = 0;  
    getmaxyx(stdscr, max_y, max_x);  
    mvprintw(0, max_x - 10, "LEVEL: %zu", tsize);  
}  
  
void Snake::printExit() {  
    int max_x = 0, max_y = 0;  
    getmaxyx(stdscr, max_y, max_x);  
    mvprintw(max_y / 2, max_x / 2 - 5, "Your LEVEL is %zu", tsize);  
}
  

