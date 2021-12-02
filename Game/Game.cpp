#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <cstdlib>
#include <ctime>

using namespace std;

HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE); //Color data type

bool gameOver;

enum eDirection { up, down, start, settings, back, quit };
eDirection way;
eDirection menu;

int y = 3;
int x = 2;

int obsX = 21; //Coordinates of obsticle
int obsY = 2;

int newObsY = 7; //Coordinates of more obsticles
int newObsX = 31;

int SleepTime = 0;
bool starting = 0;
bool graphics = 0;
char character = 219;
char player = 79;
bool level = 0;
bool newLevel = 0;
bool death = 0;

int record = 0;

void Draw()
{
	SleepTime = record / 5;
	if (record / 5 >= 100)
	{
		SleepTime = 100;
	}
	Sleep(100 - SleepTime);
	system("cls");
	if (starting == 1)
	{
		cout << "Record: " << record << endl;
		for (int i = 1; i <= 8; i++)
		{
			for (int j = 0; j <= 20; j++)
			{
				if (i != 1 && i != 8)
				{				
					if (i == x && j == y)
					{

					}
					else
					{
						if (j == obsX && i == obsY)
						{

						}
						else
						{
							if (j == newObsX && i == newObsY)
							{

							}
							else
							{
								if (j == newObsX && i - 1 == newObsY && newLevel == 0)
								{

								}
								else
								{
									if (j == newObsX && i + 1 == newObsY && newLevel == 0)
									{

									}
									else
									{
										SetConsoleTextAttribute(h, 11);
										cout << character;
										SetConsoleTextAttribute(h, 15);
									}
								}
							}
						}
					}
				}
				if (i == x && j == y)
				{
					SetConsoleTextAttribute(h, 176);
					cout << player;
					SetConsoleTextAttribute(h, 15);
				}
				if (i == 1)
				{
					SetConsoleTextAttribute(h, 6);
					cout << character;
					SetConsoleTextAttribute(h, 15);
				}
				if (i == 8)
				{
					SetConsoleTextAttribute(h, 6);
					cout << character;
					SetConsoleTextAttribute(h, 15);
				}
				if (j == obsX && i == obsY)
				{
					if (level == 0)
					{
						SetConsoleTextAttribute(h, 2);
						cout << character;
						SetConsoleTextAttribute(h, 15);
					}
					else
					{
						SetConsoleTextAttribute(h, 13);
						cout << character;
						SetConsoleTextAttribute(h, 15);
					}
				}
				if (level == 0)
				{
					if (x == obsY && y == obsX)
					{
						death = 1;
					}
				}
				if (level == 1)
				{
					if (x == obsY && y == obsX)
					{
						death = 0;
					}
					else
					{
						if (x != obsY && y == obsX)
						{
							death = 1;
						}
					}
				}
				if (death == 1)
				{
					system("cls");
					cout << "You lost";
					Sleep(5000);
					starting = 0;
					graphics = 0;
					record = 0;
					obsX = 21;
					SleepTime = 0;
					menu = back;
					death = 0;
					break;
					break;
					break;
				}
				if (newLevel == 0)
				{
					if (newObsY == 2)
					{
						if (j == newObsX && i - 1 == newObsY)
						{
							SetConsoleTextAttribute(h, 2);
							cout << character;
							SetConsoleTextAttribute(h, 15);
						}
					}
					else
					{
						if (j == newObsX && i + 1 == newObsY)
						{
							SetConsoleTextAttribute(h, 2);
							cout << character;
							SetConsoleTextAttribute(h, 15);
						}
					}
				}
				if (j == newObsX && i == newObsY)
				{
					if (newLevel == 0)
					{
						SetConsoleTextAttribute(h, 2);
						cout << character;
						SetConsoleTextAttribute(h, 15);
					}
					else
					{
						SetConsoleTextAttribute(h, 13);
						cout << character;
						SetConsoleTextAttribute(h, 15);
					}
				}
				if (newLevel == 0)
				{
					if (x == newObsY && y == newObsX)
					{
						death = 1;
					}
				}
				if (newLevel == 1)
				{
					if (x == newObsY && y == newObsX)
					{
						death = 0;
					}
					else
					{
						if (x != newObsY && y == newObsX)
						{
							death = 1;
						}
					}
				}

				if (level == 0)
				{
					if (x == obsY && y == obsX)
					{
						death = 1;
					}
				}
				if (level == 1)
				{
					if (x == obsY && y == obsX)
					{
						death = 0;
					}
					else
					{
						if (x != obsY && y == obsX)
						{
							death = 1;
						}
					}
				}
				if (death == 1)
				{
					system("cls");
					cout << "You lost";
					Sleep(5000);
					starting = 0;
					graphics = 0;
					record = 0;
					obsX = 21;
					newObsX = 36;
					SleepTime = 0;
					menu = back;
					death = 0;
					break;
					break;
					break;
				}
			}
			cout << endl;
		}
		record++;
		obsX--;
		newObsX--;
		if (newObsX == -2)
		{
			if (rand() % 2 == 1)
			{
				newObsY = 7;
			}
			else
			{
				newObsY = 2;
			}
			if (rand() % 2 == 1)
			{
				newLevel = 0;
			}
			else
			{
				newLevel = 1;
			}
			newObsX = 20;
		}
		if (obsX == -2)
		{
			if (rand() % 2 == 1)
			{
				obsY = 7;
			}
			else
			{
				obsY = 2;
			}
			if (rand() % 2 == 1)
			{
				level = 0;
			}
			else
			{
				level = 1;
			}
			obsX = 20;
		}
	}
	else if (graphics == 1)
	{
		cout << "Use W and S to change the gravity" << endl;
		cout << "press Space to go back or pause the game" << endl;
		cout << "Run from the green things and touch the dark blue one";
	}
	else
	{
	cout << "* *  *     ****  ****    ****      ****    ************    ****    ************       ************           *****           *****          *****     ************" << endl;
	cout << "*     *    *  *  *  *     *  *    *  *     *          *    *  *    *          *       *          *          *     *          *    *        *    *     *          *" << endl;
	cout << "*     *    *  *  *  *      *  *  *  *      *    *******    *  *    *    *******       *   ********         *   *   *         *     *      *     *     *   ********" << endl;
	cout << "*   *      *  ****  *       *  *   *       *    *          *  *    *    *             *   *               *   * *   *        *  *   *    *   *  *     *   ********" << endl;
	cout << "*  *       *  ****  *        *    *        *    *******    *  *    *    *             *   *   ****       *   *   *   *       *  * *  ****  * *  *     *          *" << endl;
	cout << "*  *       *  *  *  *         *  *         *          *    *  *    *    *             *   *   *  *      *   *     *   *      *  *  *      *  *  *     *   ********" << endl;
	cout << "*  *       *  *  *  *         *  *         ******     *    *  *    *    *******       *   *****  *     *   *********   *     *  *   ******   *  *     *   ********" << endl;
	cout << "*  *       *  *  *  *         *  *         *          *    *  *    *          *       *          *    *   ***********   *    *  *            *  *     *          *" << endl;
	cout << "****       ****  ****         ****         ************    ****    ************       ************   *****           *****   ****            ****     ************ " << endl;
		cout << "1. Play" << endl;
		cout << "2. How to play" << endl;
		cout << "3. Quit" << endl;
	}
}

void Setup()
{
	gameOver = false;
}

void Input()
{
	if (_kbhit())
	{
		switch (_getch())
		{
		case '1':
			menu = start;
			break;

		case '2':
			menu = settings;
			break;

		case '3':
			menu = quit;
			break;

		case ' ':
			menu = back;
			break;

			if (start == 1)
			{
		case 'w':
			way = up;
			break;
		case 's':
			way = down;
			break;
			}
		}
	}
}
void Logic()
{
	switch (menu)
	{
	case start:
		starting = 1;
		break;
	case settings:
		graphics = 1;
		break;
	case quit:
		gameOver = 1;
		break;
	case back:
		graphics = 0;
		starting = 0;
	}
	switch (way)
	{
	case up:
		y = 3;
		x = 2;
		break;

	case down:
		y = 3;
		x = 7;
		break;

	default:
		break;
	}
}

int main()
{
	srand(time(0));

	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
	}
}
