#include "Inimigo.h"



Inimigo::Inimigo(sf::Texture* textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo) :
	Personagem(textura, contImg, tempMud, velocidade, alturaPulo)
{
	this->rondaCompleta = false;
	//corpo.setPosition(600.0f, 100.0f);
	fazRonda = true;
	podePular = true;
}


Inimigo::~Inimigo()
{
}

void Inimigo::Update(float variacaoTempo)
{
	vetorVelocidade.x = 0;

	int maxColunas = 2;

	//posInicial = corpo.getPosition();
		

	if (fazRonda) {
		if (rondaCompleta == false)
		{
			vetorVelocidade.x += velocidade;
		}
		else
		{
			vetorVelocidade.x -= velocidade;
		}

		deslocamento = abs(posInicial.x - corpo.getPosition().x);

		if (deslocamento > raio)
		{
			rondaCompleta = true;
			//posInicial.x = corpo.getPosition().x;
		}
		if (deslocamento < 3.0f)
		{
			rondaCompleta = false;
			//posInicial.x = corpo.getPosition().x;
		}
	}
	else
	{
		vetorVelocidade.x += velocidade;
	}

	if (vetorVelocidade.y >= 5.0f && podePular) 
	{
		podePular = false;
		vetorVelocidade.y = -sqrtf(2.0f * 981.0f * alturaPulo);
	}

	vetorVelocidade.y += 981.0f * variacaoTempo;


	if (vetorVelocidade.x == 0.0f)
	{
		linha = 0;
	}
	else
	{
		linha = 0;
		if (vetorVelocidade.x > 0.0f)
			viradoDireita = true;
		else
			viradoDireita = false;
	}
	
	animacao.Update(linha, maxColunas, variacaoTempo, viradoDireita);
	corpo.setTextureRect(animacao.retanguloImagem);
	corpo.move(vetorVelocidade * variacaoTempo);
}
