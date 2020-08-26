#pragma once
#include "Inimigo.h"

class Ladrao :
	public Inimigo
{
public:
	Ladrao(sf::Texture * textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo);
	~Ladrao();
};

