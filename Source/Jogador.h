#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include "Personagem.h"
using namespace std;

class Jogador : public Personagem
{
public:
	Jogador(sf::Texture* textura, sf::Vector2u contImg, float tempMud, float velocidade, float alturaPulo);
	~Jogador();

	void Update(float variacaoTempo);
	void setTwoPlayers() { doisJogadores = true; }
	bool Morto();
	void setPontuacao(int p) { pontuacao = p; }
	void setVidas(int v) { vidas = v; }
	int getPontuacao() { return pontuacao; }
	int getVidas() { return vidas; }


private:
	int vidas;
	int pontuacao;
	bool doisJogadores;
	//bool morto;

};

