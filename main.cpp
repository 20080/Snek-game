#include <iostream>
#include<conio.h>
#include <ctime>//for linux
#include <windows.h>//for windows
#include<time.h>
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP = 0, UP, DOWN, LEFT, RIGHT };
eDirection dir;
int tailX[100], tailY[100];
int nTail = 0;

void Setup() {
	srand(time(0));
	gameOver = false;
	dir = STOP;
	x = width / 2;
	y = height / 2;
	fruitX = rand() % width;
	fruitY = rand() % height;
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

			else {
				bool print = false;
				for (int k = 0; k < nTail; ++k)
				{

					if (tailX[k] == j && tailY[k] == i)
					{	std::cout << "o";
						print = true;
					}

				}
				if (!print)
					std::cout << " ";

			}

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

	int prevX = tailX[0];
	int prevY =	tailY[0];
	int prev2X, prev2Y;
	tailX[0] = x;
	tailY[0] = y;
	for (int i = 1; i < nTail; ++i)
	{
		prev2X = tailX[i];
		prev2Y = tailY[i];
		tailX[i] = prevX;
		tailY[i] = prevY;
		prevX = prev2X;
		prevY = prev2Y;
	}
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

	// if (x > width || y > height || x < 0 || y < 0)
	// 	gameOver = true;

	if (x >= width) x = 0; else if (x < 0) x = width - 1;
	if (y >= height) y = 0; else if (y < 0) y = height - 1;

	for (int i = 0; i < nTail; ++i)
	{
		if (tailX[i] == x && tailY[i] == y)
			gameOver = true;
	}
	if (x == fruitX && y == fruitY)
	{
		score += 10;
		fruitX = rand() % width;
		fruitX = rand() % height;
		nTail++;
	}
}
int main() {

	Setup();
	while (!gameOver) {
		Draw();
		Input();
		Logic();
		Sleep(10);
		//sleep() to slow the game
	}
}
