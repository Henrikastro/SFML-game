#pragma once
#include "Obstaculo.h"
class Exaustor :
	public Obstaculo
{
public:
	Exaustor(sf::Texture* textura, sf::Vector2f tamanho, sf::Vector2f posicao);
	~Exaustor();
};

