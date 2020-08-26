#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>
#include <fstream>
using namespace std;
class Ranking
{
public:
	Ranking(string nome, int pontuacao);
	~Ranking();

	void salvaRanking();
	void recuperaRanking();
	int getPontuacao() { return pontuacao; }
	string getNome() { return nome; }
	void imprimeRank();

private:
	string nome;
	int pontuacao;
	vector<Ranking> rv;
	vector<Ranking> ordenado;
	bool mostrar;

};

