#include "snake.h"  
#include "food.h"  
  
int main() {  
    srand(time(nullptr));  
  
    Snake snake;  
    FoodManage food;  
    food.initFood();  
  
    initscr();  
    keypad(stdscr, TRUE);  
    raw();  
    noecho();  
    curs_set(FALSE);  
  
    mvprintw(0, 0, "  Use arrows for control. Press 'q' for EXIT");  
    food.putFood();  
    timeout(0);  
  
    while (snake.changeDirection()) {  
  
        if (snake.isCrash()) break;  
  
        snake.move();  
        snake.moveTail();  
  
        if (haveEat(snake, food)) {  
            snake.addTail();  
            snake.printLevel();  
        }  
  
        food.refreshFood();  
        repairSeed(food, snake);  
  
        timeout(100);  
    }  
    snake.printExit();  
    timeout(SPEED);  
    getch();  
    endwin();  
  
    return 0;  
}
