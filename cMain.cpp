#include <iostream>
#include <Windows.h>
#include <math.h>

#include <list>
#include <set>

using namespace std;

#define MapHeight 30
#define MapWidth 30

#pragma region Color

enum Color
{
	BLACK,
	BLUE,
	GREEN,
	CYAN,
	RED,
	MAGENTA,
	BROWN,
	LIGHTGRAY,
	DARKGRAY,
	LIGHTBLUE,
	LIGHTGREEN,
	LIGHTCYAN,
	LIGHTRED,
	LIGHTMAGENTA,
	YELLOW,
	WHITE,
};

#pragma endregion
#pragma region Map

int map[MapHeight][MapWidth] =
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


struct Node* startNode = nullptr;
struct Node* targetNode = nullptr;
bool found = false;

#pragma region Node

struct Node
{
	Node* parentNode = nullptr;

	int x;
	int y;
	bool wall = false;

	Color color = BLACK;

	int gCost = 0;
	int hCost = 0;

	int Fcost() const { return gCost + hCost; }
	Node(int _x, int _y, int mapIndex) : x(_x), y(_y)
	{
		switch (mapIndex)
		{
		case 1:
			wall = true;
			color = WHITE;
			break;

		case 2:
			startNode = this;
			color = YELLOW;
			break;
		case 3:
			targetNode = this;
			color = BLUE;
			break;
		default:
			break;
		}
	}

};

#pragma endregion

Node* grid[MapHeight][MapWidth] = {};

void Init();
void DrawMap();

void FindPath(Node* startNode, Node* targetNode);
list<Node*> GetNeighbours(Node* centerNode);
int GetDistance(Node* nodeA, Node* nodeB);


#pragma region WinAPI
int main();
void MoveCursorPosition(int x, int y);
void RemoveCursor();
void ChangeColor(int color);
#pragma endregion



int main()
{
	Init();
	RemoveCursor();

	while (true)
	{
		system("cls");

		if (GetAsyncKeyState(VK_RETURN))
		{
			if (!found)
			{
				found = true;
				FindPath(startNode, targetNode);

				Node* temp = targetNode;

				while (temp != startNode)
				{

					temp = temp->parentNode;
					if (temp != targetNode && temp != startNode)
					{
						temp->color = LIGHTMAGENTA;
					}

				}
			}
		}

		DrawMap();

		Sleep(1000);
	}

	return 0;
}


void Init()
{
	for (int y = 0; y < MapHeight; y++)
	{
		for (int x = 0; x < MapWidth; x++)
		{
			if (grid[y][x] == nullptr)
			{
				grid[y][x] = new Node(x, y, map[y][x]);

			}

		}
	}

}

void DrawMap()
{
	for (int y = 0; y < MapHeight; y++)
	{
		for (int x = 0; x < MapWidth; x++)
		{
			Node* node = grid[y][x];

			if (node != nullptr)
			{
				switch (node->color)
				{
				case WHITE:
					ChangeColor(node->color);
					MoveCursorPosition(node->x, node->y);
					cout << "■";
					break;
				case RED:
					ChangeColor(node->color);
					MoveCursorPosition(node->x, node->y);
					cout << "■";
					break;
				case GREEN:
					ChangeColor(node->color);
					MoveCursorPosition(node->x, node->y);
					cout << "■";
					break;
				case BLUE:
					ChangeColor(node->color);
					MoveCursorPosition(node->x, node->y);
					cout << "■";
					break;

				case YELLOW:
					ChangeColor(node->color);
					MoveCursorPosition(node->x, node->y);
					cout << "■";
					break;

				case LIGHTMAGENTA:
					ChangeColor(node->color);
					MoveCursorPosition(node->x, node->y);
					cout << "■";
					break;
				default:
					break;
				}
			}


		}
	}

}

void FindPath(Node* startNode, Node* targetNode)
{
	list<Node*> openset;
	set<Node*> closeSet;

	openset.push_back(startNode);

	while (!openset.empty())
	{

		Node* itBest = openset.front();

		for (auto it : openset)
		{
			if (it->Fcost() < itBest->Fcost() || (it->Fcost() == itBest->Fcost() && it->hCost < itBest->hCost))
			{
				itBest = it;
			}
		}

		openset.remove(itBest);
		closeSet.insert(itBest);

		if (itBest != startNode && itBest != targetNode)
		{
			itBest->color = RED;
		}



		if (itBest == targetNode)
		{
			//exit(true);
			break;
		}


		for (Node* neighbourNode : GetNeighbours(itBest))
		{
			auto result = closeSet.find(neighbourNode);
			if (result != closeSet.end())
			{
				continue;
			}

			int newGcost = itBest->gCost + GetDistance(itBest, neighbourNode);

			if (neighbourNode->Fcost() != 0)
			{
				if (newGcost < neighbourNode->gCost)
				{
					neighbourNode->gCost = newGcost;

					//이웃 노드의 부모는 현재 노드
					neighbourNode->parentNode = itBest;
				}

				//여기는 해당 되지 않음
			}
			else
			{
				int newHcost = GetDistance(neighbourNode, targetNode);
				neighbourNode->gCost = newGcost;
				neighbourNode->hCost = newHcost;

				openset.push_back(neighbourNode);
				neighbourNode->color = GREEN;

				//이웃 노드의 부모는 현재 노드
				neighbourNode->parentNode = itBest;

			}


		}

		DrawMap();
		Sleep(50);

	}
}

//이웃 노드 탐색
list<Node*> GetNeighbours(Node* centerNode)
{
	list<Node*> neighbours;

	for (int y = -1; y <= 1; y++)
	{
		for (int x = -1; x <= 1; x++)
		{
			if (x == 0 && y == 0)
				continue;

			int checkX = centerNode->x + x;
			int checkY = centerNode->y + y;

			if ((0 <= checkX && checkX < MapWidth) && (0 <= checkY && checkY < MapHeight))
			{
				Node* checkNode = grid[checkY][checkX];
				if (!checkNode->wall)
				{
					neighbours.push_back(checkNode);
				}
			}

		}
	}


	return neighbours;
}

int GetDistance(Node* nodeA, Node* nodeB)
{
	int distX = abs(nodeA->x - nodeB->x);
	int distY = abs(nodeA->y - nodeB->y);

	if (distX > distY)
	{
		return 14 * distY + 10 * (distX - distY);
	}
	else
	{
		return 14 * distY + 10 * (distY - distX);
	}
}


#pragma region WinAPI
void MoveCursorPosition(int x, int y)
{
	COORD pos;
	pos.X = x * 2;
	pos.Y = y;

	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void RemoveCursor()
{
	CONSOLE_CURSOR_INFO info;
	info.bVisible = false;
	info.dwSize = 1;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &info);
}

void ChangeColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
#pragma endregion
