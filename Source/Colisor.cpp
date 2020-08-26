#include "Colisor.h"


Colisor::Colisor(sf::RectangleShape& corpo) :
	corpo(corpo)
{
}

Colisor::~Colisor()
{
}

bool Colisor::ChecaColisao(Colisor outro, sf::Vector2f& direcao, float empurra)
{
	sf::Vector2f outroPosicao = outro.getPosicao();
	sf::Vector2f outroMetadeTamanho = outro.getMetadeTamanho();
	sf::Vector2f thisPosicao = getPosicao();
	sf::Vector2f thisMetadeTamanho = getMetadeTamanho();

	float deltaX = outroPosicao.x - thisPosicao.x;
	float deltaY = outroPosicao.y - thisPosicao.y;
	float interseccaoX = abs(deltaX) - (outroMetadeTamanho.x + thisMetadeTamanho.x);
	float interseccaoY = abs(deltaY) - (outroMetadeTamanho.y + thisMetadeTamanho.y);

	if (interseccaoX < 0.0f && interseccaoY < 0.0f)
	{
		empurra = std::min(std::max(empurra, 0.0f), 1.0f);

		if (interseccaoX > interseccaoY)
		{
			if (deltaX > 0.0f)
			{
				Move(interseccaoX * (1.0f - empurra), 0.0f);
				outro.Move(-interseccaoX * empurra, 0.0f);

				direcao.x = 1.0f;
				direcao.y = 0.0f;
			}
			else
			{
				Move(-interseccaoX * (1.0f - empurra), 0.0f);
				outro.Move(interseccaoX * empurra, 0.0f);
				
				direcao.x = -1.0f;
				direcao.y = 0.0f;
			}
		}
		else
		{
			if (deltaY > 0.0f)
			{
				Move(0.0f, interseccaoY * (1.0f - empurra));
				outro.Move(0.0f, -interseccaoY * empurra);

				direcao.x = 0.0f;
				direcao.y = 1.0f;
			}
			else
			{
				Move(0.0f, -interseccaoY * (1.0f - empurra));
				outro.Move(0.0f, interseccaoY * empurra);

				direcao.x = 0.0f;
				direcao.y = -1.0f;
			}
		}

		return true;
	}

	return false;
}
