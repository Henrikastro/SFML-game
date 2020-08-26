#pragma once
#include <SFML\Graphics.hpp>
#include "Entidade.h"


class Obstaculo :
	public Entidade
{
public:
	Obstaculo(sf::Texture* textura, sf::Vector2f tamanho, sf::Vector2f posicao);
	~Obstaculo();
};

