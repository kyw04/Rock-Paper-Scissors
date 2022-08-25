#include <iostream>
#include <cmath>
#include <windows.h>
#include <conio.h>
#include <vector>
#include <string>
#include <ctime>
#include <stdlib.h>
#define WIN_COLOR 10
#define LOSER_COLOR 4
#define DRAW_COLOR 14

using namespace std;

int computerHandIndex = -1;
int playerHandIndex = -1;
int winner = -1;
int playerScore = 0, computerScore = 0;

string hand[3][15] = {
		{
			"                             ",
			"                             ",
			"                             ",
			"       ﹥﹥  ﹥﹥  ﹥﹥      ",
			"     ﹥    ﹥    ﹥    ﹥    ",
			"     ﹥    ﹥    ﹥    ﹥﹥  ",
			"     ﹥    ﹥    ﹥    ﹥  ﹥",
			"   ﹥﹥                    ﹥",
			" ﹥  ﹥                    ﹥",
			" ﹥                        ﹥",
			"   ﹥                    ﹥  ",
			"   ﹥                    ﹥  ",
			"     ﹥                ﹥    ",
			"     ﹥                ﹥    ",
			"       ﹥﹥﹥﹥﹥﹥﹥﹥      ",
		}, 
		{
			"             ﹥﹥              ",
			"     ﹥﹥  ﹥    ﹥          ",
			"   ﹥    ﹥﹥    ﹥          ",
			"   ﹥      ﹥    ﹥﹥﹥      ",
			"   ﹥      ﹥    ﹥    ﹥    ",
			"     ﹥    ﹥    ﹥    ﹥﹥  ",
			"     ﹥    ﹥    ﹥    ﹥  ﹥",
			"   ﹥﹥                    ﹥",
			" ﹥  ﹥                    ﹥",
			" ﹥                        ﹥",
			"   ﹥                    ﹥  ",
			"   ﹥                    ﹥  ",
			"     ﹥                ﹥    ",
			"     ﹥                ﹥    ",
			"       ﹥﹥﹥﹥﹥﹥﹥﹥      ",	
		}, 
		{
			"             ﹥﹥            ",
			"           ﹥    ﹥﹥﹥      ",
			"       ﹥﹥﹥    ﹥    ﹥    ",
			"     ﹥    ﹥    ﹥    ﹥    ",
			"     ﹥    ﹥    ﹥    ﹥﹥  ",
			"     ﹥    ﹥    ﹥    ﹥  ﹥",
			"     ﹥    ﹥    ﹥    ﹥  ﹥",
			" ﹥﹥﹥                    ﹥",
			" ﹥  ﹥                    ﹥",
			" ﹥                        ﹥",
			"   ﹥                    ﹥  ",
			"   ﹥                    ﹥  ",
			"     ﹥                ﹥    ",
			"     ﹥                ﹥    ",
			"       ﹥﹥﹥﹥﹥﹥﹥﹥      ",
		}
	}; 
	

void SetConsoleView()
{
	system("mode con:cols=50 lines=20");
	system("title");
}

void GotoXY(int x, int y)
{
	COORD Pos;
	Pos.X = 2 * x;
	Pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);	
}

int GetKey()
{
	if (_kbhit() != 0)
		return _getch();
	
	return 0;
}

void DrawGame()
{
	if (winner == 0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WIN_COLOR);
	else if (winner == 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LOSER_COLOR);
	else if (winner == 2)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DRAW_COLOR);
	
	GotoXY(10 ,1);
	cout << "Player Score : " << playerScore;
	GotoXY(5, 2);
	cout << " 天天天天天天天天天天天天天天天";
	for (int i = 0; i < 15; i++)
	{
		GotoXY(5, i + 3);
		cout << "|                              |";
	}
	GotoXY(5, 18);
	cout << " 天天天天天天天天天天天天天天天";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);	
	if (winner == 0)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), LOSER_COLOR);
	else if (winner == 1)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), WIN_COLOR);
	else if (winner == 2)
		SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), DRAW_COLOR);
		
	GotoXY(40, 1);
	cout << "Computer Score : " << computerScore;
	GotoXY(35, 2);
	cout << " 天天天天天天天天天天天天天天天";
	for (int i = 0; i < 15; i++)
	{
		GotoXY(35, i + 3);
		cout << "|                              |";
	}
	GotoXY(35, 18);
	cout << " 天天天天天天天天天天天天天天天";

	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), 15);
}

void DrawHand(int index, int x, int y)
{
	for (int i = 0; i < 15; i++)
	{
		GotoXY(x, y + i);
		cout << hand[index][i];
	}
}

int WinnerCheck()
{
	int temp = computerHandIndex + 1;
	temp %= 3;
	
	if (computerHandIndex == playerHandIndex)
		return 2;
	if (temp == playerHandIndex)
	{
		computerScore++;
		return 1;
	}
	
	playerScore++;
	return 0;
}

int main()
{
	srand(time(NULL));
	int cnt = 0;
	bool isGameEnd = false;
	while (true)
	{
		cnt++;
		DrawGame();
		char key = GetKey();
		if (key == 'q' || key == 'Q')
		{
			playerHandIndex = 2;
		}
		else if (key == 'a' || key == 'A')
		{
			playerHandIndex = 0;
		}
		else if (key == 'w' || key == 'W')
		{
			playerHandIndex = 1;
		}
		else if (key == 32 && computerHandIndex != -1 && playerHandIndex != -1)
		{
			if (isGameEnd)
			{
				computerHandIndex = -1;
				playerHandIndex = -1;
				winner = -1;
				cnt = 0 + rand() % 5;
			}
			else
			{
				winner = WinnerCheck();
			}
			isGameEnd = !isGameEnd;
		}
		else if (key == 27)
			break;
		
		if (cnt == 10)
		{
			computerHandIndex = rand() % 3;
		}
		
		if (computerHandIndex != -1 && isGameEnd == false)
		{
			GotoXY(40, 10);
			cout << "I\'M READY";
		}
		else if (isGameEnd == true)
		{
			DrawHand(computerHandIndex, 36, 3);	
		}
		
		if (playerHandIndex != -1)
		{
			DrawHand(playerHandIndex, 6, 3);
		}
			
		Sleep(80);
		system("cls");
	}
	
	return 0;
}
