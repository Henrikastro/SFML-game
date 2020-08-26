#pragma once
#include <SFML/Graphics.hpp>

class Jogador;

class Animacao
{
public:
	Animacao(sf::Texture* textura, sf::Vector2u contImg, float tempMud);
	~Animacao();
	
	void Update(int linha, int maxColunas, float variacaoTempo, bool viradoDireita);

public:
	sf::IntRect retanguloImagem;
private:
	sf::Vector2u contaImagem;
	sf::Vector2u imagemAtual;
	Jogador* Jogador;

	float tempoTotal;
	float tempoMudanca;

};

