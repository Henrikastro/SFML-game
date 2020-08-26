#include "MenuPausa.h"



MenuPausa::MenuPausa()
{
	if (!fonte.loadFromFile("arial.ttf"))
	{
		cout << "Nao foi possivel carregar a fonte." << endl;
	}

	menu[0].setFont(fonte);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Resumir Jogo");
	menu[0].setOrigin(menu[0].getCharacterSize(), menu[0].getCharacterSize());
	
	menu[1].setFont(fonte);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Salvar Jogo");
	menu[1].setOrigin(menu[1].getCharacterSize(), menu[1].getCharacterSize());
	
	menu[2].setFont(fonte);
	menu[2].setFillColor(sf::Color::White);
	menu[2].setString("Sair");
	menu[2].setOrigin(menu[0].getCharacterSize(), menu[0].getCharacterSize());

	ItemSelecionado = 0;
}


MenuPausa::~MenuPausa()
{
}

void MenuPausa::draw(sf::RenderWindow &window)
{
	for (int i = 0; i < 3; i++)
	{
		window.draw(menu[i]);
	}
}

void MenuPausa::moveCima()
{
	if (ItemSelecionado - 1 >= 0)
	{
		menu[ItemSelecionado].setFillColor(sf::Color::White);
		ItemSelecionado--;
		menu[ItemSelecionado].setFillColor(sf::Color::Red);
	}
}

void MenuPausa::moveBaixo()
{
	if (ItemSelecionado + 1 < 3)
	{
		menu[ItemSelecionado].setFillColor(sf::Color::White);
		ItemSelecionado++;
		menu[ItemSelecionado].setFillColor(sf::Color::Red);
	}
}

void MenuPausa::setView(float x, float y)
{
	menu[0].setPosition(sf::Vector2f(x, y - 2 * menu[0].getCharacterSize()));
	menu[1].setPosition(sf::Vector2f(x, y));
	menu[2].setPosition(sf::Vector2f(x, y + 2 * menu[0].getCharacterSize()));
}

void MenuPausa::salvaJogo(bool doisJog, sf::Vector2f posicao, int score, int vidas, string nome)
{
		ofstream gravaJogo("save 1.dat", ios::out);
		gravaJogo << doisJog << ' '
			<< posicao.x << ' '
			<< posicao.y << ' '
			<< score << ' '
			<< vidas << ' '
			<< nome << endl;

		gravaJogo.close();

}
