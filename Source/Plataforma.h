#pragma once
#include <SFML\Graphics.hpp>
#include "Entidade.h"

class Plataforma : public Entidade
{
public:
	Plataforma(sf::Texture* textura, sf::Vector2f tamanho, sf::Vector2f posicao);
	~Plataforma();
};

