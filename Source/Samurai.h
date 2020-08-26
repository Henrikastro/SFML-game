#pragma once
#include "Inimigo.h"
class Samurai :
	public Inimigo
{
public:
	Samurai(sf::Texture * textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo);
	~Samurai();
};

