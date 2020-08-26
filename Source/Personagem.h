#pragma once
#include <SFML/Graphics.hpp>
#include "Animacao.h"
#include "Entidade.h"


class Personagem : public Entidade
{
public :

	Personagem(sf::Texture* textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo);
	~Personagem();

	void OnCollision(sf::Vector2f direcao);
	virtual void Update(float variacaoTempo) { }
	bool getViradoDireita() { return viradoDireita; }

protected:
	Animacao animacao;
	unsigned int linha;
	float velocidade;
	bool viradoDireita;
	bool podePular;

	sf::Vector2f vetorVelocidade;

	float alturaPulo;

};
