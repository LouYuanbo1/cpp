#include "food.h"  
#include "snake.h"  

FoodManage::FoodManage() {  
    food.resize(MAX_FOOD_SIZE);  
}  
  
void FoodManage::initFood() {  
    int max_y = 0, max_x = 0;  
    getmaxyx(stdscr, max_y, max_x);  
    for (auto& f : food) {  
        f = {0, 0, 0, '$', false};  
    }  
}  
  
void putFoodSeed(Food& fp) {
    int max_x = 0, max_y = 0;
    getmaxyx(stdscr, max_y, max_x);
    mvprintw(fp.y, fp.x, " ");
    fp.x = rand() % (max_x - 1);
    fp.y = rand() % (max_y - 2) + 1;
    fp.put_time = time(nullptr);
    fp.enable = true;
    mvprintw(fp.y, fp.x, "%c", fp.point);
}

void FoodManage::putFood() {
    for (auto& f : food) {
        putFoodSeed(f);
    }
}

void FoodManage::refreshFood() {
    for (auto& f : food) {
        if (f.put_time && (!f.enable || (time(nullptr) - f.put_time) > FOOD_EXPIRE_SECONDS)) {
            putFoodSeed(f);
        }
    }
}

bool haveEat(Snake& snake, FoodManage& foodManage) {
    for (auto& f : foodManage.food) {
        if (f.enable && snake.getX() == f.x && snake.getY() == f.y) {
            f.enable = false;
            return true;
        }
    }
    return false;
}

void repairSeed(FoodManage& foodManage, Snake& snake) {
    for (size_t i = 0; i < snake.getTsize(); i++) {
        for (auto& f : foodManage.food) {
            if (f.x == snake.getTail()[i].x && f.y == snake.getTail()[i].y && f.enable) {
                putFoodSeed(f);
            }
        }
    }
}

