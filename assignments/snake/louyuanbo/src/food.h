#pragma once
#include"snake.h" 
#include <vector>  
#include <ctime>  
#include <ncurses.h>  
  
enum {MAX_FOOD_SIZE=20, FOOD_EXPIRE_SECONDS=10};  
  
struct Food {  
    int x, y;  
    time_t put_time;  
    char point;  
    bool enable;  
};  
  
class FoodManage {  
private:  
    std::vector<Food> food;  
    friend bool haveEat(Snake& snake, FoodManage& foodManage);  
    friend void repairSeed(FoodManage& foodManage, Snake& snake);  
  
public:  
    FoodManage();  
    void initFood();  
    void putFood();  
    void refreshFood();  
    std::vector<Food>& getFood() { return food; }  
};  
  

