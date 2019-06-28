#pragma once
#include "Scene.cpp"

class MenuScene : public Scene
{
public:
	MenuScene(sf::RenderWindow *window)
	{
		gui = new tgui::Gui(*window);
		Load();
	}

	void Load() 
	{
		texture.loadFromFile("tronmenu.jpg");
		sprite.setTexture(texture);
		sprite.setPosition(W / 2 - 200, 0);

		auto PlayBtn = tgui::Button::create();
		PlayBtn->setRenderer(theme.getRenderer("Button"));
		PlayBtn->setPosition(W / 2 - 50, 150);
		PlayBtn->setText("Play");
		PlayBtn->setTextSize(25);
		PlayBtn->setSize(100, 50);
		PlayBtn->connect("pressed", [=]() {
			GameMode = GAME;
		});
		gui->add(PlayBtn);

		auto InfoBtn = tgui::Button::create();
		InfoBtn->setRenderer(theme.getRenderer("Button"));
		InfoBtn->setPosition(W / 2 - 50, 220);
		InfoBtn->setText("Info");
		InfoBtn->setTextSize(25);
		InfoBtn->setSize(100, 50);
		InfoBtn->connect("pressed", [=]() {
			GameMode = INFO;
		});
		gui->add(InfoBtn);

		auto AboutBtn = tgui::Button::create();
		AboutBtn->setRenderer(theme.getRenderer("Button"));
		AboutBtn->setPosition(W / 2 - 50, 290);
		AboutBtn->setText("About");
		AboutBtn->setTextSize(25);
		AboutBtn->setSize(100, 50);
		AboutBtn->connect("pressed", [=]() {
			GameMode = ABOUT;
		});
		gui->add(AboutBtn);

		auto ExitBtn = tgui::Button::create();
		ExitBtn->setRenderer(theme.getRenderer("Button"));
		ExitBtn->setPosition(W / 2 - 50, 360);
		ExitBtn->setText("Exit");
		ExitBtn->setTextSize(25);
		ExitBtn->setSize(100, 50);
		ExitBtn->connect("pressed", [=]() {
			exit(0);
		});
		gui->add(ExitBtn);
	}

};