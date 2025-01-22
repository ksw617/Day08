#include <stdio.h>
#include <Windows.h>


#define MAP_HEIGHT 30
#define MAP_WIDTH 30

#pragma region Color


#pragma endregion
#pragma region Map

int map[MAP_HEIGHT][MAP_WIDTH] =
{
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,3,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,1,1,1,1,1,1,1,1,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,1,0,0,0,1},
	{1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,1,1,1,1,1,1,1,1,1,1,1,1,1,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,2,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,1},
	{1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1},

};

#pragma endregion


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

enum DIR
{
	NONE,
	LEFT,
	RIGHT,
	UP,
	DOWN,
};
#pragma endregion
#pragma region WIN_API
void HideCursor();
void SetPosition(int x, int y);
void ChangeColor(Color color);
#pragma endregion

struct Obj
{
	DIR dir;
	int step;
	int maxStep;
	int x;
	int y;
	int hp;
	Color color;
	const char* shape;
};

Obj* player = nullptr;
Obj* enemy = nullptr;

void InitStage();
void UpdateStage();
void ReleaseStage();

void EnemyStepReset();
void MoveEnemy();
void CheckKeyInput();
bool IsBlocked(Obj* obj);
void CheckItem();
void ShowMap();

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
		player->hp = 1;
		player->color = Yellow;
		player->shape = "＠";
		player->dir = NONE;

	}

	if (enemy == nullptr)
	{
		enemy = (Obj*)malloc(sizeof(Obj));
		enemy->x = 14;
		enemy->y = 5;
		enemy->hp = 1;
		enemy->color = Magenta;
		enemy->shape = "♣";
		EnemyStepReset();
	}
}

void EnemyStepReset()
{
	enemy->step = 0;
	enemy->maxStep = rand() % 5 + 5;
	enemy->dir = (DIR)(rand() % 5);
}

void MoveEnemy()
{
	enemy->step++;
	if (enemy->step >= enemy->maxStep)
	{
		EnemyStepReset();
	}
	else
	{
		switch (enemy->dir)
		{
		case NONE:
			break;
		case LEFT:
			enemy->x--;
			break;
		case RIGHT:
			enemy->x++;
			break;
		case UP:
			enemy->y--;
			break;
		case DOWN:
			enemy->y++;
			break;
		default:
			break;
		}

		if (IsBlocked(enemy))
		{
			switch (enemy->dir)
			{
			case NONE:
				break;
			case LEFT:
				enemy->x++;
				break;
			case RIGHT:
				enemy->x--;
				break;
			case UP:
				enemy->y++;
				break;
			case DOWN:
				enemy->y--;
				break;
			default:
				break;
			}

			EnemyStepReset();
		}

	}




}

void CheckKeyInput()
{
	if (GetAsyncKeyState(VK_LEFT))
	{
		player->dir = LEFT;

		player->x--;
		if (IsBlocked(player))
			player->x++;
	}

	if (GetAsyncKeyState(VK_RIGHT))
	{

		player->dir = RIGHT;

		player->x++;
		if (IsBlocked(player))
			player->x--;
	}

	if (GetAsyncKeyState(VK_UP))
	{

		player->dir = UP;

		player->y--;
		if (IsBlocked(player))
			player->y++;
	}

	if (GetAsyncKeyState(VK_DOWN))
	{

		player->dir = DOWN;

		player->y++;
		if (IsBlocked(player))
			player->y--;
	}

}

void UpdateStage()
{
	MoveEnemy();
	CheckItem();
	CheckKeyInput();

	SetPosition(player->x, player->y);
	ChangeColor(player->color);
	printf(player->shape);

	SetPosition(enemy->x, enemy->y);
	ChangeColor(enemy->color);
	printf(enemy->shape);

	ShowMap();
}

bool IsBlocked(Obj* obj)
{
	return  map[obj->y][obj->x] == 1;
}

void CheckItem()
{
	switch (map[player->y][player->x])
	{
	case 2:
		break;
	case 3:
		player->hp++;
		map[player->y][player->x] = 0;
		break;
	default:
		break;
	}
}

void ShowMap()
{
	for (int y = 0; y < MAP_WIDTH; y++)
	{
		for (int x = 0; x < MAP_HEIGHT; x++)
		{
			switch (map[y][x])
			{
			case 1:
				SetPosition(x, y);
				ChangeColor(White);
				printf("■");
				break;
			case 2:
				SetPosition(x, y);
				ChangeColor(Yellow);
				printf("￦");
				break;
			case 3:
				SetPosition(x, y);
				ChangeColor(Red);
				printf("♥");
				break;
			default:
				break;
			}
		}
	}



	SetPosition(20, 0);
	ChangeColor(Red);
	printf("HP :");

	//1
	for (int i = 0; i < player->hp; i++)
	{
		SetPosition(22 + i, 0);
		ChangeColor(Red);
		printf("♥");
	}

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