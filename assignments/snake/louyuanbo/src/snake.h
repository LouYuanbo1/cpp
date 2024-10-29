#pragma once  
  
#include <iostream>  
#include <vector>  
#include <ncurses.h>  
  
enum {LEFT=1, UP, RIGHT, DOWN, STOP_GAME='q'};  
enum {MAX_TAIL_SIZE=1000, START_TAIL_SIZE=3, SPEED=20000};  
  
class FoodManage;  
  
class Snake {  
private:  
    struct Tail {  
        int x, y;  
    };  
    int x, y, direction;  
    size_t tsize;  
    std::vector<Tail> tail;  
  
public:  
    Snake();  
    void move();  
    void moveTail();  
    void addTail();  
    bool isCrash();  
    bool changeDirection();  
    void printLevel();  
    void printExit();  
    size_t getTsize() const { return tsize; }  
    int getX() const { return x; }  
    int getY() const { return y; }  
    std::vector<Tail>& getTail() { return tail; }  
};  
  
