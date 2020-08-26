#include "MenuMorte.h"



MenuMorte::MenuMorte()
{
	if (!fonte.loadFromFile("arial.ttf"))
	{
		cout << "Nao foi possivel carregar a fonte." << endl;
	}

	menu[0].setFont(fonte);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Game Over");
	menu[0].setOrigin(menu[0].getCharacterSize(), menu[0].getCharacterSize());
}


MenuMorte::~MenuMorte()
{
}

void MenuMorte::draw(sf::RenderWindow & window)
{
	window.draw(menu[0]);
}

void MenuMorte::setView(float x, float y)
{
	menu[0].setPosition(sf::Vector2f(x - x/25, y ));

}
