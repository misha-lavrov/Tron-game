#pragma once
#include "Scene.cpp"

class GameScene : public Scene
{
public:

	GameScene(sf::RenderWindow *window)
	{
		gui = new tgui::Gui(*window);
		Load();
	}

	void Load()
	{
		font.loadFromFile("DS_Comedy_Cyr_Bold.ttf");
		text.setFont(font);
		texture.loadFromFile("background.jpg");
		backSprite.setTexture(texture);
		renderTexture.create(W, H);
		renderTexture.setSmooth(true);
		renderTexture.clear();
		renderTexture.draw(backSprite);
		sprite.setTexture(renderTexture.getTexture());
	}

};