#pragma once
#include <SFML\Graphics.hpp>
#include "Plataforma.h"
#include "Personagem.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Personagem.h"
#include "Ladrao.h"
#include "Menu.h"
#include "Obstaculo.h"
#include "Caixa.h"
#include "Lixo.h"
#include "Exaustor.h"
#include "Samurai.h"
#include "Chefao.h"
#include "MenuPausa.h"
#include "MenuMorte.h"
#include "Ranking.h"
#include <iostream>
using namespace std;


class F2;
class Jogo;

class Fase
{
public:
	Fase(sf::RenderWindow& window, bool* dj);
	virtual ~Fase();

	sf::Vector2f getPosInicial() { return posInicial; }
	void setPosInicial(sf::Vector2f pos) { posInicial = pos; }
	void calculaColisoes(sf::View& view);
	void empurra(int j);
	virtual void carregaEntidades();

	void loop(sf::RenderWindow& window);

protected:
	int tamPlataformas, tamInimigos, tamJogadores, tamInv, tamObstaculos, tamBackground;

	bool morreu;
	bool pausado;
	bool menuPrincipal;
	bool doisJogadores;
	bool doisJogadoresVivos;
	bool f1;
	sf::Vector2f posInicial;
	sf::Vector2f direcao;

	sf::Texture texturaBackground;

	vector<sf::Sprite> backgrounds;
	vector<Inimigo*> LIs;
	vector<Jogador*> LJs;
	vector<Plataforma*> LPs;
	vector<Plataforma*> Invisivel;
	vector<Obstaculo*> LOs;
};

