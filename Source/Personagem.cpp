#include "Personagem.h"



Personagem::Personagem(sf::Texture* textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo = 0) :
	animacao(textura,contImg,tempMud), Entidade (textura)
{
	this->velocidade = velocidade;
	this->alturaPulo = alturaPulo;
	linha = 0;
	viradoDireita = true;
	podePular = true;

	corpo.setSize(sf::Vector2f(56.0f, 80.0f));
	corpo.setOrigin(corpo.getSize() / 2.0f);

}

Personagem::~Personagem()
{
}

void Personagem::OnCollision(sf::Vector2f direcao)
{
	if (direcao.x < 0.0f)
	{
		//colisao direita
		vetorVelocidade.x = 0.0f;
	}
	else if (direcao.x > 0.0f)
	{
		//colisao esquerda
		vetorVelocidade.x = 0.0f;
	}
	else if (direcao.y < 0.0f)
	{
		//colisao abaixo
		podePular = true;
		vetorVelocidade.y = 0.0f;
	}
	else if (direcao.y > 0.0f)
	{
		//colisao acima
		vetorVelocidade.y = 0.0f;
	}
}
