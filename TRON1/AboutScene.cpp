#pragma once
#include "Scene.cpp"

class AboutScene : public Scene
{
public:
	AboutScene(sf::RenderWindow *window)
	{
		gui = new tgui::Gui(*window);
		Load();
	}

	void Load()
	{
		texture.loadFromFile("about.jpg");
		backSprite.setTexture(texture);
		backSprite.setPosition(100, 120);

		auto BackBtn = tgui::Button::create();
		BackBtn->setRenderer(theme.getRenderer("Button"));
		BackBtn->setPosition(W / 2 - 50, 10);
		BackBtn->setText("Back");
		BackBtn->setTextSize(25);
		BackBtn->setSize(100, 50);
		BackBtn->connect("pressed", [=]() {
			GameMode = MENU;
		});
		gui->add(BackBtn);
	}

};