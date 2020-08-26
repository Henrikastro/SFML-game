#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;

#define MAX_NUMBER_OF_ITEMS 5

class Menu
{
public:
	Menu(float largura, float altura);
	~Menu();

	void draw(sf::RenderWindow &window);
	void moveCima();
	void moveBaixo();
	int carregaJogo(bool* dj, int* vidas, float* x, float* y);
	int getItemSelecionado() { return ItemSelecionado; }

private:
	int ItemSelecionado;
	sf::Font fonte;
	sf::Text menu[MAX_NUMBER_OF_ITEMS];
	string jogador;

};