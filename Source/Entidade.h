#pragma once
#include <SFML\Graphics.hpp>
#include "Colisor.h"

class Entidade
{
public:
	Entidade(sf::Texture* textura);
	~Entidade();

	void Draw(sf::RenderWindow& window) { window.draw(corpo); }
	void setPosicao(float x, float y) {	corpo.setPosition(x, y);}
	sf::Vector2f getPosicao() {	return corpo.getPosition();}
	Colisor getColisor() { return Colisor(corpo); }

protected:
	sf::RectangleShape corpo;
};

