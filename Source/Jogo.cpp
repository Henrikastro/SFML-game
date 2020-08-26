#include "Jogo.h"


Jogo::Jogo()
{
	sf::RenderWindow window(sf::VideoMode(ALTURA, LARGURA), "The Legend of the Ninja", sf::Style::Close | sf::Style::Titlebar | sf::Style::Resize);
	F1 *f1 = new F1(window, &dj);
	F2 *f2 = new F2(window, &dj);
}
Jogo::~Jogo()
{
}