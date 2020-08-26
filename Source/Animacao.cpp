#include "Animacao.h"



Animacao::Animacao(sf::Texture* textura, sf::Vector2u contImg, float tempMud)
{
	this->contaImagem = contImg;
	this->tempoMudanca = tempMud;
	tempoTotal = 0.0f;
	imagemAtual.x = 0;

	retanguloImagem.width = int(textura->getSize().x / float(contaImagem.x));
	retanguloImagem.height = int(textura->getSize().y / float(contaImagem.y));
}


Animacao::~Animacao()
{
}

void Animacao::Update(int linha, int maxColunas, float variacaoTempo, bool viradoDireita)
{
	imagemAtual.y = linha;
	tempoTotal += variacaoTempo;

	if (tempoTotal >= tempoMudanca)
	{
		tempoTotal -= tempoMudanca;
		imagemAtual.x++;
		if (imagemAtual.x >= maxColunas)
		{
			imagemAtual.x = 0;
		}
	}

	retanguloImagem.top = imagemAtual.y * retanguloImagem.height;
	if (viradoDireita)
	{
		retanguloImagem.left = imagemAtual.x * retanguloImagem.width;
		retanguloImagem.width = abs(retanguloImagem.width);
	}
	else
	{
		retanguloImagem.left = (imagemAtual.x + 1) * abs(retanguloImagem.width);
		retanguloImagem.width = -abs(retanguloImagem.width);
	}

}
