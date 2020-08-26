#include "Fase.h"

#define ALTURA 512
#define LARGURA 512

 
Fase::Fase(sf::RenderWindow& window, bool* dj)
{
	dj = &doisJogadores;
	pausado = false;
	morreu = false;
}


Fase::~Fase()
{
	LIs.clear();
	LJs.clear();
	LPs.clear();
	LOs.clear();
	Invisivel.clear();
}

void Fase::calculaColisoes(sf::View & view)
{

	for (int i = 0; i < tamPlataformas; i++)
		for (int j = 0; j<tamJogadores;j++)
			if (LPs[i]->getColisor().ChecaColisao(LJs[j]->getColisor(), direcao, 1.0f))
				LJs[j]->OnCollision(direcao);

	for (int i = 0; i < tamPlataformas; i++)
		for (int j = 0; j<tamInimigos;j++)
			if (LPs[i]->getColisor().ChecaColisao(LIs[j]->getColisor(), direcao, 1.0f))
				LIs[j]->OnCollision(direcao);

	for (int i = 0; i < tamObstaculos; i++)
		for (int j = 0; j<tamJogadores;j++)
			if (LOs[i]->getColisor().ChecaColisao(LJs[j]->getColisor(), direcao, 1.0f))
				LJs[j]->OnCollision(direcao);

	//Colisao Obstaculo - Inimigo

	/*for (int i = 0; i < tamObstaculos; i++)
		for (int j = 0; j<tamInimigos;j++)
			if (LOs[i]->getColisor().ChecaColisao(LIs[j]->getColisor(), direcao, 1.0f))
				LIs[j]->OnCollision(direcao);
				*/


	for (int i = 0; i < tamInimigos;i++) 
	{
		for (int j = 0; j < tamJogadores;j++)
		{
			if (LIs[i]->getColisor().ChecaColisao(LJs[j]->getColisor(), direcao, 1.0f)) 
			{
				LJs[j]->OnCollision(direcao);
				empurra(j);
				if (LJs[j]->Morto())
				{
					if (doisJogadoresVivos)
					{
						if (j == 0)
						{
							LJs[0] = LJs[1];
							LJs.pop_back();
							tamJogadores--;
							doisJogadoresVivos = false;
						}
						else
						{
							LJs.pop_back();
							tamJogadores--;
							doisJogadoresVivos = false;
						}
					}
					else
						morreu = true;
				}
				
			}
		}
	}

	for (int i = 0; i < tamInv; i++)
		for (int j = 0; j<tamJogadores;j++)
			if (Invisivel[i]->getColisor().ChecaColisao(LJs[j]->getColisor(), direcao, 1.0f))
				LJs[j]->OnCollision(direcao);

	Invisivel[1]->setPosicao(view.getCenter().x + (view.getSize().x / 2), 10.0f);
	Invisivel[2]->setPosicao(view.getCenter().x - (view.getSize().x / 2), 10.0f);
}

void Fase::empurra(int j)
{
	if (LJs[j]->getViradoDireita())
	{
		LJs[j]->setPosicao(LJs[j]->getPosicao().x - 120.0f, LJs[j]->getPosicao().y - 100.0f);
	}
	else
	{
		LJs[j]->setPosicao(LJs[j]->getPosicao().x + 120.0f, LJs[j]->getPosicao().y - 100.0f);
	}
}

void Fase::carregaEntidades()
{
}

void Fase::loop(sf::RenderWindow& window)
{
	sf::View view(sf::Vector2f(0.0f, 0.0f), sf::Vector2f(ALTURA, LARGURA));

	float deltaTempo = 0.0f;

	sf::Clock relogio;

	Menu m(ALTURA,LARGURA);
	MenuPausa p;
	MenuMorte morte;
	Ranking r("", 0);

	bool dj;
	int vidas;
	float x;
	float y;

	tamPlataformas = LPs.size();
	tamInimigos = LIs.size();
	tamJogadores = LJs.size();
	tamObstaculos = LOs.size();
	tamBackground = backgrounds.size();
	tamInv = Invisivel.size();
	string nome;


	while (window.isOpen())
	{
		deltaTempo = float(relogio.restart().asSeconds());
		if (deltaTempo > 1.0f / 20.0f)
			deltaTempo = 1.0 / 20.0f;

		sf::Event evnt;
		while (window.pollEvent(evnt))
		{
			switch (evnt.type)
			{
				
				case sf::Event::KeyReleased:
					switch (evnt.key.code)
					{
					case sf::Keyboard::Escape:
						if(!menuPrincipal)
							pausado = true;
					case sf::Keyboard::W:
						m.moveCima();
						p.moveCima();
						break;
					case sf::Keyboard::S:
						m.moveBaixo();
						p.moveBaixo();
						break;
					case sf::Keyboard::Return:
						switch (m.getItemSelecionado())
						{
						case 0:
							if (menuPrincipal) 
						{
							doisJogadores = false;
							doisJogadoresVivos = false;
							LJs.pop_back();
							tamJogadores = LJs.size();
							menuPrincipal = false;
							break;
						}
						case 1:
							if (menuPrincipal) 
							{
								doisJogadores = true;
								doisJogadoresVivos = true;
								menuPrincipal = false;
								break;
							}
						case 2:
							if (menuPrincipal)
							{
								LJs[0]->setPontuacao(m.carregaJogo(&dj,&vidas,&x,&y));
								cout << "Jogo carregado !" << endl;
								
								if (dj == 0) 
								{
									doisJogadores = false;
									LJs.pop_back();
									tamJogadores = LJs.size();
								}
								else
									doisJogadores = true;

								LJs[0]->setVidas(vidas);
								LJs[0]->setPosicao(x,y);
								menuPrincipal = false;
								break;
							}
						case 3:
							if (menuPrincipal) 
							{
								r.recuperaRanking();
								r.imprimeRank();
							}
							break;

						case 4:
							if(menuPrincipal)
							window.close();
							break;
						}
						switch (p.getItemSelecionado())
						{
						case 0:
							if (pausado)
							pausado = false;
							break;
						case 1:
							if (pausado) 
							{
								cout << "Insira seu nome :" << endl;
								cin >> nome;
								p.salvaJogo(doisJogadores, LJs[0]->getPosicao(), LJs[0]->getPontuacao(), LJs[0]->getVidas() ,nome);
								cout << "Jogo Salvo!" << endl;
								break;
							}
						case 2:
							if (pausado)
							{

							}
						case 3:
							if (pausado)
							window.close();
							break;
						}
					}
						break;
			case sf::Event::Closed:
				window.close();
				break;
			}
		}
		if (morreu)
		{
			morte.setView(view.getCenter().x, view.getCenter().y);
			window.clear();
			morte.draw(window);
			window.display();
			cout << "Insira seu nome :" << endl;
			cin >> nome;
			cout << "Pontuacao adicionada ao ranking." << endl;
			Ranking r(nome, LJs[0]->getPontuacao());
			r.salvaRanking();
			for (int i = 0; i<990000; i++)
			{
				LIs.size();
			}
			system("Pause");
			
			window.close();
		}
		else if (pausado)
		{
			p.setView(view.getCenter().x, view.getCenter().y);
			window.clear();
			p.draw(window);
			window.display();
		}
		else if (menuPrincipal)
		{

			window.clear(/*sf::Color(150, 150, 150)*/);
			m.draw(window);
			window.display();
		}
		else
		{

			for (int i = 0; i < tamInimigos;i++)
				LIs[i]->Update(deltaTempo);

			for (int i = 0; i < tamJogadores;i++)
				LJs[i]->Update(deltaTempo);


			calculaColisoes(view);

			LJs[0]->setPontuacao(LJs[0]->getPosicao().x + LJs[0]->getPosicao().y * LJs[0]->getVidas());

			for (int i = 0; i < tamJogadores;i++)
			{
				if (LJs[i]->getPosicao().y > 250.0f && f1)
				{
					if (doisJogadoresVivos)
					{
						if (i == 0)
						{
							LJs[0] = LJs[1];
							LJs.pop_back();
							tamJogadores--;
							doisJogadoresVivos = false;
						}
						else
						{
							LJs.pop_back();
							tamJogadores--;
							doisJogadoresVivos = false;
						}
					}
					else
					{
						
						morreu = true;
					}
				}
				else if (LJs[i]->getPosicao().y > 1250.0f && f1 != true)
				{
					if (doisJogadoresVivos)
					{
						if (i == 0)
						{
							LJs[0] = LJs[1];
							LJs.pop_back();
							tamJogadores--;
							doisJogadoresVivos = false;
						}
						else
						{
							LJs.pop_back();
							tamJogadores--;
							doisJogadoresVivos = false;
						}
					}
					else
					{
						
						morreu = true;
					}
				}

			}

			if (doisJogadoresVivos == true)
				view.setCenter((LJs[0]->getPosicao() + LJs[1]->getPosicao()) / 2.0f);
			else
				view.setCenter(LJs[0]->getPosicao());


			window.clear(sf::Color(150, 150, 150));
			window.setView(view);

	
			if (LJs[0]->getPosicao().x > 3370.0f && f1)
			{
				f1 = false;
				break;
			}
			if (LJs[0]->getPosicao().x > 3370.0f && f1 != true) 
			{
				morreu = true;
			}
			for (sf::Sprite& bk : backgrounds)
				window.draw(bk);

			for (int i = 0; i < tamJogadores;i++)
				LJs[i]->Draw(window);

			for (int i = 0; i < tamInimigos;i++)
				LIs[i]->Draw(window);

			for (int i = 0; i < tamPlataformas;i++)
				LPs[i]->Draw(window);

			for (int i = 0; i < tamObstaculos;i++)
				LOs[i]->Draw(window);

			window.display();
			//menuPrincipal = true;
		}
	}
}
