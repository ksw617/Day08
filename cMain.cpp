#include <stdio.h>
#include <Windows.h>
#pragma region Enum
enum Color
{
	Black,
	DarkBlue,
	DarkGreen,
	DarkCyan,
	DarkRed,
	DarkMagenta,
	DarkYellow,
	Gray,
	DarkGray,
	Blue,
	Green,
	Cyan,
	Red,
	Magenta,
	Yellow,
	White,
};
#pragma endregion

#pragma region WIN_API
void HideCursor();
void SetPosition(int x, int y);
void ChangeColor(Color color);
#pragma endregion

struct Obj
{
	int x;
	int y;
	Color color;
	const char* shape;
};

Obj* player = nullptr;

void CheckKeyInput();
void InitStage();
void UpdateStage();
void ReleaseStage();

int main()
{
	HideCursor();
	InitStage();

	while (true)
	{
		system("cls");

		UpdateStage();
		Sleep(50);

	}

	ReleaseStage();

	return 0;
}

#pragma region STAGE

void InitStage()
{
	if (player == nullptr)
	{
		player = (Obj*)malloc(sizeof(Obj));
		player->x = 10;
		player->y = 10;
		player->color = Yellow;
		player->shape = "■";

	}
}

void CheckKeyInput()
{
	if (GetAsyncKeyState(VK_LEFT)) 	player->x--;
	if (GetAsyncKeyState(VK_RIGHT))	player->x++;
	if (GetAsyncKeyState(VK_UP)) 	player->y--;
	if (GetAsyncKeyState(VK_DOWN))	player->y++;
}

void UpdateStage()
{
	CheckKeyInput();
	SetPosition(player->x, player->y);
	ChangeColor(player->color);
	printf(player->shape);
}
void ReleaseStage()
{
	if (player != nullptr)
	{
		free(player);
		player = nullptr;
	}
}

#pragma endregion


#pragma region WIN_API
//커서 이동
void SetPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

//커서 보이는거 방지
void HideCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

//색깔 바꾸기
void ChangeColor(Color color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}

#pragma endregion
