#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "Player.cpp"
#include "MenuScene.cpp"
#include "GameScene.cpp"
#include "InfoScene.cpp"
#include "AboutScene.cpp"

using namespace sf;

class MainWindow
{
private:
	static const int W = 600;
	static const int H = 480;
	double speed = 2;
	bool field[W][H] = { false };
	bool Game;
	Player *p1;
	Player *p2;
	RenderWindow *window;
	MenuScene *menu;
	GameScene *game;
	InfoScene *info;
	AboutScene *about;
public:
	MainWindow() {
		window = new RenderWindow(VideoMode(W, H), "The Tron Game!");
		window->setFramerateLimit(60);
		p1 = new Player(Color::Red, W, H);
		p2 = new Player(Color::Green, W, H);
		menu = new MenuScene(window);
		game = new GameScene(window);
		info = new InfoScene(window);
		about = new AboutScene(window);
		Game = true;
	}

	void update(Event event)
	{
		if (Keyboard::isKeyPressed(Keyboard::Left)) if (p1->dir != 2) p1->dir = 1;
		if (Keyboard::isKeyPressed(Keyboard::Right)) if (p1->dir != 1)  p1->dir = 2;
		if (Keyboard::isKeyPressed(Keyboard::Up)) if (p1->dir != 0) p1->dir = 3;
		if (Keyboard::isKeyPressed(Keyboard::Down)) if (p1->dir != 3) p1->dir = 0;

		if (Keyboard::isKeyPressed(Keyboard::A)) if (p2->dir != 2) p2->dir = 1;
		if (Keyboard::isKeyPressed(Keyboard::D)) if (p2->dir != 1)  p2->dir = 2;
		if (Keyboard::isKeyPressed(Keyboard::W)) if (p2->dir != 0) p2->dir = 3;
		if (Keyboard::isKeyPressed(Keyboard::S)) if (p2->dir != 3) p2->dir = 0;

		if (Keyboard::isKeyPressed(Keyboard::Escape))
		{
			Game = false;
			GameMode = MENU;
		}

		if ((Keyboard::isKeyPressed(Keyboard::Space) && !Game))
		{
			srand(time(0));
			for (int i = 0; i < W; i++)
			{
				for (int e = 0; e < H; e++)
				{
					field[i][e] = false;
				}
			}
			game->renderTexture.clear();
			game->renderTexture.draw(game->backSprite);
			Game = true;
			p1->SetUp(W, H);
			p2->SetUp(W, H);

		}

		if (Game) 
		{
			for (int i = 0; i < speed; i++)
			{
				p1->tick(W, H);
				p2->tick(W, H);
				if (field[p1->x][p1->y] == 1)
				{
					game->text.setPosition(W / 2 - 150, H / 2 - 100);
					game->text.setCharacterSize(50);
					game->text.setFillColor(p2->color);
					game->text.setString("Green Win");
					game->renderTexture.draw(game->text);
					Game = 0;
				}
				else if (field[p2->x][p2->y] == 1)
				{
					game->text.setPosition(W / 2 - 150, H / 2 - 100);
					game->text.setCharacterSize(50);
					game->text.setFillColor(p1->color);
					game->text.setString(" Red Win");
					game->renderTexture.draw(game->text);
					Game = 0;
				}
				field[p1->x][p1->y] = 1;
				field[p2->x][p2->y] = 1;

				CircleShape c(3);
				c.setPosition(p1->x, p1->y);
				c.setFillColor(p1->color);
				game->renderTexture.draw(c);
				c.setPosition(p2->x, p2->y);
				c.setFillColor(p2->color);
				game->renderTexture.draw(c);
				game->renderTexture.display();
			}
		}
		else
		{
			game->text.setPosition(W / 2 - 125, H / 2);
			game->text.setFillColor(Color::Blue);
			game->text.setCharacterSize(15);
			game->text.setString("   Press ECS to exit \nPress SPACE to restart");
			game->renderTexture.draw(game->text);
			game->renderTexture.display();
		}
	}

	void EventNow(Event event)
	{
		switch (GameMode) {
		case MENU:
			menu->gui->handleEvent(event);
			break;
		case GAME:
			game->gui->handleEvent(event);
			break;
		case INFO:
			info->gui->handleEvent(event);
			break;
		case ABOUT:
			about->gui->handleEvent(event);
			break;
		}
	}

	void DrawModeNow(Event event)
	{
		switch (GameMode)
		{
		case MENU:
			window->draw(menu->sprite);
			menu->gui->draw();
			break;
		case GAME:
			update(event);
			window->draw(game->sprite);
			break;
		case INFO:
			info->gui->draw();
			window->draw(info->backSprite);
			break;
		case ABOUT:
			about->gui->draw();
			window->draw(about->backSprite);
			break;
		}
	}

	void Run()
	{
		while (window->isOpen())
		{
			Event e;
			while (window->pollEvent(e))
			{
				if (e.type == Event::Closed)
					window->close();
				EventNow(e);
			}
			window->clear();
			DrawModeNow(e);
			window->display();
		}
	}
};