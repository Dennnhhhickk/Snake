#include <iostream>
#include <queue>
#include <unistd.h>
#include <thread>
#include <chrono>
#include <conio.h>

#define x first
#define y second
#define mp make_pair

using namespace std;

inline void Setup();
inline void Draw();
inline void Logic();
inline void Input();
inline void FruitGenerate();

typedef long long ll;

enum eDirection{Stop = 0, Right, Left, Up, Down};

ll width, height, score;
bool gameOver;
eDirection dir;
pair<ll, ll> fruit, head;
int a[1000][1000];
queue<pair<ll, ll>> q;

int main()
{
	cin >> width >> height;
	Setup();
	while (!gameOver)
	{
		Draw();
		Input();
		Logic();
		this_thread::sleep_for (std::chrono::milliseconds(1000));
	}
	return 0;
}

inline void Setup()
{
	gameOver = 0;
	dir = Stop;
	head.x = width / 2;
	head.y = height / 2;
	a[head.x][head.y] = 1;
	q.push(head);
	score = 0;
	FruitGenerate();
}

inline void FruitGenerate()
{
	fruit.x = rand() % width;
	fruit.y = rand() % height;
}

inline void Draw()
{
	system("clear");
	for(int i = 0; i < width; i++)
		cout << '#';
	cout << "                 SCORE - " << score << endl;

	for (int i = 0; i < height; i++, cout << endl)
		for (int j = 0; j < width; j++)
			if (j == 0 || j == width - 1)
				cout << '#';
			else
				if (a[i][j])
				{
					if (head.x == i && head.y == j)
						cout << 'H';
					else
						cout << 'S';
				}
				else
					if (fruit.x == i && fruit.y == j)
						cout << 'F';
					else
						cout << ' ';

	for(int i = 0; i < width; i++)
		cout << '#';
	cout << endl;
}

inline void Logic()
{
	if (dir == Stop)
		return;
	if (dir == Up)
		head.x--;
	if (dir == Down)
		head.x++;
	if (dir == Right)
		head.x++;
	if (dir == Left)
		head.x--;

	q.push(head);
	a[head.x][head.y] = 1;
	if (head != fruit)
	{
		pair<ll, ll> tmp = q.front();
		a[tmp.x][tmp.y] = 0;
		q.pop();
	}
}

inline void Input()
{
	
}