#pragma once
#include "Inimigo.h"
class Chefao :
	public Inimigo
{
public:
	Chefao(sf::Texture * textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo);
	~Chefao();
};

