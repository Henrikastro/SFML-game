#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;

class MenuPausa
{
public:
	MenuPausa();
	~MenuPausa();

	void draw(sf::RenderWindow &window);
	void moveCima();
	void moveBaixo();
	void setView(float x, float y);
	void salvaJogo(bool doisJog, sf::Vector2f posicao, int score, int vidas, string nome);
	int getItemSelecionado() { return ItemSelecionado; }

private:
	int ItemSelecionado;
	sf::Font fonte;
	sf::Text menu[3];

};

