#include "Jogador.h"



Jogador::Jogador(sf::Texture* textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo):
	Personagem(textura,contImg,tempMud,velocidade,alturaPulo)
{
	doisJogadores = false;
	corpo.setSize(sf::Vector2f(56.0f, 80.0f));
	corpo.setPosition(206.0f, 0.0f);
	vidas = 3;
	pontuacao = 0;
}


Jogador::~Jogador()
{
}

void Jogador::Update(float variacaoTempo)
{
	vetorVelocidade.x = 0.0f;

	if (doisJogadores == true)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			vetorVelocidade.x -= velocidade;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			vetorVelocidade.x += velocidade;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && podePular)
		{
			podePular = false;
			vetorVelocidade.y = -sqrtf(2.0f * 981.0f * alturaPulo);
		}
	}
	else
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			vetorVelocidade.x -= velocidade;
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			vetorVelocidade.x += velocidade;

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W) && podePular)
		{
			podePular = false;
			vetorVelocidade.y = -sqrtf(2.0f * 981.0f * alturaPulo);
		}
	}

	vetorVelocidade.y += 981.0f	* variacaoTempo;

	int maxColunas = 3;

	if (vetorVelocidade.x == 0.0f)
	{
		linha = 0;
	}
	else
	{
		linha = 1;
		if (vetorVelocidade.x > 0.0f)
			viradoDireita = true;
		else
			viradoDireita = false;

	}
	if (vetorVelocidade.y <= 0.0f)
	{
		linha = 2;
	}
	
	animacao.Update(linha, maxColunas, variacaoTempo, viradoDireita);
	corpo.setTextureRect(animacao.retanguloImagem);
	corpo.move(vetorVelocidade * variacaoTempo);
}

bool Jogador::Morto()
{
	if (vidas > 0)
	{
		vidas--;
		return false;
	}
	else 
	{
		return true;
	}

}
