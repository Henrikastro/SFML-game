#include "Chefao.h"



Chefao::Chefao(sf::Texture * textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo) :
	Inimigo(textura, contImg, tempMud, velocidade, alturaPulo)
{
	corpo.setSize(sf::Vector2f(180.0, 110.0));
	corpo.setOrigin(corpo.getSize() / 2.0f);
	fazRonda = false;
}


Chefao::~Chefao()
{
}
