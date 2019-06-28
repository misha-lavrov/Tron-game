#pragma once
#include <SFML/Graphics.hpp>

class Player
{
public:
	int x, y, dir;
	sf::Color color;

	Player(sf::Color c, int W, int H)
	{
		color = c;
		SetUp(W, H);
	}

	void SetUp(int W, int H) {
		x = rand() % W;
		y = rand() % H;
		dir = rand() % 4;
	}

	void tick(int W, int H)
	{
		if (dir == 0) y += 1;
		if (dir == 1) x -= 1;
		if (dir == 2) x += 1;
		if (dir == 3) y -= 1;

		if (x >= W) x = 0;  if (x < 0) x = W - 1;
		if (y >= H) y = 0;  if (y < 0) y = H - 1;
	}
};