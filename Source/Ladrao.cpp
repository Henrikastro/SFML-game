#include "Ladrao.h"



Ladrao::Ladrao(sf::Texture* textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo) : 
	Inimigo(textura, contImg, tempMud, velocidade, alturaPulo)
{
	raio = 200.0f;
}


Ladrao::~Ladrao()
{
}
