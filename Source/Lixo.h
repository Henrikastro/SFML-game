#pragma once
#include "Obstaculo.h"
class Lixo :
	public Obstaculo
{
public:
	Lixo(sf::Texture* textura, sf::Vector2f tamanho, sf::Vector2f posicao);
	~Lixo();
};

