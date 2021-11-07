#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <thread>
#define RUNNING_CHECK 1
using namespace std;

struct Point
{
	int x, y;
};

void gotoXY(int x, int y)
{
	COORD coord;
	coord.X = x;
	coord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

void printOto(Point* oto, int size, Point p, int left, int right) {
	while (RUNNING_CHECK)
	{
		system("cls");
		gotoXY(p.x, p.y);
		cout << "Y";
		for (int i = 0; i < size; i++)
		{
			gotoXY(oto[i].x, oto[i].y);
			cout << "X";
			oto[i].x = (oto[i].x + 3) % right;
		}
	}
}

void solve(Point& p) {
	if (_kbhit) {
		char key = _getch();
		switch (key)
		{
		case 'A': case 'a': {
			p.x--;
			break;
		}
		case 'D': case 'd': {
			p.x++;
			break;
		}
		case 'W': case 'w': {
			p.y--;
			break;
		}
		case 'S': case 's': {
			p.y++;
			break;
		}
		}
	}
}

int main() {
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	int columns, rows;

	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);
	columns = csbi.srWindow.Right - csbi.srWindow.Left + 1;
	rows = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
	Point p;
	p.x = columns / 2;
	p.y = rows;
	Point oto[3];
	oto[0].x = 100;
	oto[0].y = rows - 5;
	oto[1].x = columns/2;
	oto[1].y = rows - 10;
	oto[2].x = 20;
	oto[2].y = rows - 4;
	while (1)
	{

	}

	return 0;
}