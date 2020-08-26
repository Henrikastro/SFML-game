#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include "Personagem.h"
#include "Plataforma.h"
#include "Fase.h"
#include "Jogador.h"
#include "Inimigo.h"
#include "Ladrao.h"
#include "Menu.h"
#include "F1.h"
#include "F2.h"
using namespace std;

#define ALTURA 512
#define LARGURA 512


class Jogo
{
public:

	Jogo();
	~Jogo();	
	//void loop();
	//void inicia();

private: 
	bool dj;

};
