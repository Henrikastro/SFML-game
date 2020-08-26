#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
using namespace std;

class MenuMorte
{
public:
	MenuMorte();
	~MenuMorte();

	void draw(sf::RenderWindow &window);
	void setView(float x, float y);

private:
	sf::Font fonte;
	sf::Text menu[2];

};

