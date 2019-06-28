#pragma once
#include <SFML/Graphics.hpp>
#include <TGUI/TGUI.hpp>
#include "Player.cpp"
#include "Mode.cpp"

class Scene 
{
public:
	int W = 600;
	int H = 480;
	tgui::Gui *gui;
	tgui::Theme theme{ "../themes/BabyBlue.txt" };
	sf::Font font;
	sf::Text text;
	sf::Texture texture;
	sf::Sprite sprite;
	sf::RenderTexture renderTexture;
	sf::Sprite backSprite;
	
	virtual void Load() = 0;
};