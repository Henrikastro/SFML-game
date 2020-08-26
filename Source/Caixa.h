#pragma once
#include "Obstaculo.h"
class Caixa :
	public Obstaculo
{
public:
	Caixa(sf::Texture* textura, sf::Vector2f tamanho, sf::Vector2f posicao);
	~Caixa();
};

