#pragma once
#include <SFML\Graphics.hpp>

class Colisor
{
public:
	Colisor(sf::RectangleShape& corpo);
	~Colisor();

	void Move(float dx, float dy) { corpo.move(dx, dy); }

	bool ChecaColisao(Colisor outro, sf::Vector2f& direcao, float empurra);
	sf::Vector2f getPosicao() { return corpo.getPosition(); }
	sf::Vector2f getMetadeTamanho() { return corpo.getSize() / 2.0f; }

private:
	sf::RectangleShape& corpo;


};

