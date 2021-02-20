#include <iostream>
#include<conio.h>
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, UP, DOWN, LEFT, RIGHT };
eDirection dir;

void Setup() {
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitX = rand() % height;
	score = 0;
}

void Draw() {
	system("cls"); //clear for linux
	for (int i = 0; i < width + 2; ++i) std::cout << '#';
	std::cout << std::endl;
	for (int i = 0; i < height; ++i) {
		for (int j = 0; j < width; ++j) {
			if (j == 0) std::cout << '#';

			if (i == y && j == x)std::cout << "O";

			else if (fruitY == i && fruitX == j)std::cout << "F";

			else std::cout << " ";

			if (j == width - 1) std::cout << "#";
		}

		std::cout << std::endl;
	}
	for (int i = 0; i < width + 2; ++i) std::cout << '#';
	std::cout << std::endl;

	std::cout << "Score: " << score;
}

void Input() {

	if (_kbhit()) {
		switch (_getch()) {
		case 'a':
			dir = LEFT;
			break;
		case 'w':
			dir = UP;
			break;
		case 's':
			dir = DOWN;
			break;
		case 'd':
			dir = RIGHT;
			break;
		case 'x':
			gameOver = true;
			break;
		}
	}


}
void Logic() {

	switch (dir) {
	case UP:
		y--;
		break;
	case LEFT:
		x--;
		break;
	case DOWN:
		y++;
		break;
	case RIGHT:
		x++;
		break;
	}

	if (x > width || y > height || x < 0 || y < 0)
		gameOver = true;
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitX = rand() % height;
	}
}
int main() {

	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		//sleep() to slow the game
	}
}
