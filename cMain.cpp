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
}
void UpdateStage()
{
	SetPosition(10,10);
	ChangeColor(Yellow);
	printf("■");
}
void ReleaseStage()
{
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
