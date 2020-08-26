#include "F1.h"



F1::F1(sf::RenderWindow& window, bool* dj) : Fase(window, dj)
{
	f1 = true;
	menuPrincipal = true;
	//doisJogadores = true;
	//doisJogadores = true;
	carregaEntidades();
	loop(window);
	*dj = doisJogadores;
}


F1::~F1()
{
}

void F1::carregaEntidades()
{
	//Carrega texturas
	sf::Texture *texturaJogador1, *texturaJogador2, *texturaPlataforma, *texturaLixo, *texturaCaixa, *texturaExaustor, *texturaLadrao,
		*texturaSamurai, *texturaChefao;

	texturaJogador1 = new sf::Texture();
	texturaJogador2 = new sf::Texture();
	texturaPlataforma = new sf::Texture();
	texturaCaixa = new sf::Texture();
	texturaLixo = new sf::Texture();
	texturaExaustor = new sf::Texture();
	texturaLadrao = new sf::Texture();
	texturaSamurai = new sf::Texture();
	texturaChefao = new sf::Texture();
	//cria backgrounds

	backgrounds.push_back(sf::Sprite());
	backgrounds.push_back(sf::Sprite());
	backgrounds.push_back(sf::Sprite());
	backgrounds.push_back(sf::Sprite());


	if (!texturaBackground.loadFromFile("background.png"))
		cout << "Nao foi possivel carregar o background" << endl;
	else
	{
		for (sf::Sprite& bk : backgrounds)
			bk.setTexture(texturaBackground);
	}

	if (!texturaJogador1->loadFromFile("Jogador1.png"))
		cout << "Nao foi possivel carregar a texura do Jogador 1." << endl;

	if (!texturaJogador2->loadFromFile("Jogador2.png"))
		cout << "Nao foi possivel carregar a textura Jogador 2." << endl;
	
	if (!texturaLadrao->loadFromFile("Ladrao.png"))
		cout << "Nao foi possivel carregar a textura Jogador 2." << endl;

	if (!texturaSamurai->loadFromFile("Samurai.png"))
		cout << "Nao foi possivel carregar a textura Jogador 2." << endl;
	
	if (!texturaChefao->loadFromFile("Chefao.png"))
		cout << "Nao foi possivel carregar a textura Jogador 2." << endl;

	if (!texturaPlataforma->loadFromFile("Plataforma.png"))
		cout << "Nao foi possivel carregar a textura Plataforma.png" << endl;
	
	if (!texturaCaixa->loadFromFile("Caixa.png"))
		cout << "Nao foi possivel carregar a textura Jogador 2." << endl;
	
	if (!texturaExaustor->loadFromFile("exaustor.png"))
		cout << "Nao foi possivel carregar a textura Jogador 2." << endl;
	
	if (!texturaLixo->loadFromFile("Lixo.png"))
		cout << "Nao foi possivel carregar a textura Jogador 2." << endl;

		LJs.push_back(new Jogador(texturaJogador1, sf::Vector2u(3, 3), 0.3f, 300.0f, 200.0f));
		LJs.push_back(new Jogador(texturaJogador2, sf::Vector2u(3, 3), 0.3f, 300.0f, 200.0f));
		LJs[1]->setTwoPlayers();
		LJs[1]->setPosicao(LJs[0]->getPosicao().x + 2.0 * LJs[1]->getColisor().getMetadeTamanho().x, LJs[0]->getPosicao().y);

	LIs.push_back(new Ladrao(texturaLadrao, sf::Vector2u(2, 1), 0.3f, 150.0f, 100.0f));
	LIs.push_back(new Ladrao(texturaLadrao, sf::Vector2u(2, 1), 0.3f, 150.0f, 100.0f));
	LIs.push_back(new Ladrao(texturaLadrao, sf::Vector2u(2, 1), 0.3f, 150.0f, 100.0f));
	LIs[0]->setPosicao(800.0f, 100.0f);
	LIs[0]->setInicial();
	LIs[1]->setPosicao(1400.0f, 100.0f);
	LIs[1]->setInicial();
	LIs[2]->setPosicao(2000.0f, 100.0f);
	LIs[2]->setInicial();
	//LIs.push_back(new Samurai(texturaSamurai, sf::Vector2u(2, 1), 0.3f, 200.0f, 0.0f));
	//LIs.push_back(new Chefao(texturaChefao, sf::Vector2u(2, 1), 0.3f, 150.0f, 0.0f));

	//Carrega as Plataformas
	LPs.push_back(new Plataforma(texturaPlataforma, sf::Vector2f(1000.0f, 1000.0f), sf::Vector2f(1700.0f, 600.0f)));
	LPs.push_back(new Plataforma(texturaPlataforma, sf::Vector2f(1000.0f, 1000.0f), sf::Vector2f(500.0f, 600.0f)));
	LPs.push_back(new Plataforma(texturaPlataforma, sf::Vector2f(1000.0f, 1000.0f), sf::Vector2f(3000.0f, 600.0f)));

	//Carrega as paredes inivisiveis
	Invisivel.push_back(new Plataforma(nullptr, sf::Vector2f(10.0f, 1000.0f), sf::Vector2f(0.0f, 100.0f)));
	Invisivel.push_back(new Plataforma(nullptr, sf::Vector2f(10.0f, 1000.0f), sf::Vector2f(0.0f, 100.0f)));
	Invisivel.push_back(new Plataforma(nullptr, sf::Vector2f(10.0f, 1000.0f), sf::Vector2f(0.0f, 100.0f)));

	//Carrega Obstaculos
	LOs.push_back(new Caixa(texturaCaixa, sf::Vector2f(60.0f, 60.0f), sf::Vector2f(500.0f, 70.0f)));
	LOs.push_back(new Lixo(texturaLixo, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(1800.0f, 51.0f)));
	LOs.push_back(new Lixo(texturaLixo, sf::Vector2f(150.0f, 100.0f), sf::Vector2f(600.0f, 51.0f)));
	LOs.push_back(new Exaustor(texturaExaustor, sf::Vector2f(50.0f, 50.0f), sf::Vector2f(1300.0f, 73.0f)));



	//Posiciona Background

	float tamBackground = -1000.0f;
	int tamVector = backgrounds.size();
	for (sf::Sprite& bk : backgrounds)
	{
		bk.setScale(2, 6);
		bk.setPosition(tamBackground, -1000);
		tamBackground += 1500;
	}
}
