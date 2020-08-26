#pragma once
#include "Personagem.h"
#include <iostream>
using namespace std;

class Inimigo :
	public Personagem
{
public:
	Inimigo(sf::Texture* textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo);
	~Inimigo();

	void Update(float variacaoTempo);
	void setPosicaoInicial(sf::Vector2f pos) { posInicial = pos; corpo.setPosition(pos); }
	void setInicial() { posInicial.x = corpo.getPosition().x; }

protected:
	bool fazRonda;
	bool rondaCompleta;
	float deslocamento;
	sf::Vector2f posInicial;
	float raio;
};

