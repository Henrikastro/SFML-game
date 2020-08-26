#include "Obstaculo.h"


Obstaculo::Obstaculo(sf::Texture* textura, sf::Vector2f tamanho, sf::Vector2f posicao) : Entidade (textura)
{
	corpo.setPosition(posicao);
	corpo.setSize(tamanho);
	corpo.setOrigin(tamanho / 2.0f);
}

Obstaculo::~Obstaculo()
{
}
