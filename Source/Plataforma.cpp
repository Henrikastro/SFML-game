#include "Plataforma.h"



Plataforma::Plataforma(sf::Texture* textura, sf::Vector2f tamanho, sf::Vector2f posicao) : Entidade(textura)
{
	corpo.setSize(tamanho);
	corpo.setPosition(posicao);
	corpo.setOrigin(tamanho / 2.0f);
}


Plataforma::~Plataforma()
{

}
