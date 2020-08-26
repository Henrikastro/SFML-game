#include "Menu.h"


Menu::Menu(float largura, float altura)
{
	if (!fonte.loadFromFile("arial.ttf"))
	{
		cout << "Nao foi possivel carregar a fonte." << endl;
	}

	menu[0].setFont(fonte);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Novo Jogo");
	menu[0].setOrigin(menu[0].getCharacterSize(), menu[0].getCharacterSize());
	menu[0].setPosition(sf::Vector2f(largura / 2 - menu[0].getCharacterSize() / 2, altura / (MAX_NUMBER_OF_ITEMS + 1) * 1));

	menu[1].setFont(fonte);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Co-op");
	menu[1].setOrigin(menu[1].getCharacterSize(), menu[1].getCharacterSize());
	menu[1].setPosition(sf::Vector2f(largura / 2 - menu[1].getCharacterSize() / 2, altura / (MAX_NUMBER_OF_ITEMS + 1) * 2));

	menu[2].setFont(fonte);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Carregar Jogo");
	menu[2].setOrigin(menu[2].getCharacterSize(), menu[2].getCharacterSize());
	menu[2].setPosition(sf::Vector2f(largura / 2 - menu[2].getCharacterSize() / 2, altura / (MAX_NUMBER_OF_ITEMS + 1) * 3));
	
	menu[3].setFont(fonte);
	menu[3].setFillColor(sf::Color::White);
	menu[3].setString("Ranking");
	menu[3].setOrigin(menu[3].getCharacterSize(), menu[3].getCharacterSize());
	menu[3].setPosition(sf::Vector2f(largura / 2 - menu[3].getCharacterSize() / 2, altura / (MAX_NUMBER_OF_ITEMS + 1) * 4));
	
	menu[4].setFont(fonte);
	menu[4].setFillColor(sf::Color::White);
	menu[4].setString("Sair");
	menu[4].setOrigin(menu[4].getCharacterSize(), menu[4].getCharacterSize());
	menu[4].setPosition(sf::Vector2f(largura / 2 - menu[4].getCharacterSize() / 2, altura / (MAX_NUMBER_OF_ITEMS + 1) * 5));

	ItemSelecionado = 0;
}


Menu::~Menu()
{
}

void Menu::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < MAX_NUMBER_OF_ITEMS; i++)
	{
		window.draw(menu[i]);
	}
}

void Menu::moveCima()
{
	if (ItemSelecionado - 1 >= 0)
	{
		menu[ItemSelecionado].setFillColor(sf::Color::White);
		ItemSelecionado--;
		menu[ItemSelecionado].setFillColor(sf::Color::Red);
	}
}

void Menu::moveBaixo()
{
	if (ItemSelecionado + 1 < MAX_NUMBER_OF_ITEMS)
	{
		menu[ItemSelecionado].setFillColor(sf::Color::White);
		ItemSelecionado++;
		menu[ItemSelecionado].setFillColor(sf::Color::Red);
	}
}

int Menu::carregaJogo(bool * dj, int * vidas, float * x, float * y)
{
	ifstream carregaSave("save 1.dat", ios::in);

	int pontuacao;

	carregaSave >> *dj >> *x >> *y >> *vidas >> pontuacao;

	cout << *dj << " " << *y;

	return pontuacao;
}
