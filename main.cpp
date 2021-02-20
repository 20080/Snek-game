#include <iostream>
bool gameOver;
const int width =20;
const int height =20;
int x,y,fruitX,fruitY,score;
enum eDirection{STOP=0, UP, DOWN,LEFT,RIGHT };
eDirection dir;
void Setup(){
gameOver=false;
dir=STOP;
x=width/2;
y=height/2;
fruitX = rand()%width-1;
fruitX = rand()%height-1;
score=0;
}

void Draw(){
    system("clear");
    for (int i = 0; i < width; ++i) std::cout<<'#';
    std::cout<<std::endl;
    for (int i = 0; i < height; ++i) {
        for (int j = 0; j < width; ++j) {
            if (j==0)
        }
    }
    for (int i = 0; i < width; ++i) std::cout<<'#';
    std::cout<<std::endl;
}

void Input(){

}
void Logic(){

}
int main() {

    Setup();
    while (!gameOver){
        Draw();
        Input();
        Logic();
        //sleep() to slow the game
    }
}
