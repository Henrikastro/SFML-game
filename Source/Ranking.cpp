#include "Ranking.h"



Ranking::Ranking(string nome, int pontuacao)
{
	this->nome = nome;
	this->pontuacao = pontuacao;
	mostrar = true;
}


Ranking::~Ranking()
{
}

void Ranking::salvaRanking()
{
	recuperaRanking();

	ofstream rankingSave("ranking.dat", ios::out);
	

	rv.push_back(Ranking(nome, pontuacao));

	//cout << nome << pontuacao << endl;

	int tam = rv.size();
	for (int i = 0; i < tam;i++) 
	{
		rankingSave << rv[i].getNome() << ' '
			<< rv[i].getPontuacao() << endl;
	}

	rankingSave.close();
}
void Ranking::recuperaRanking()
{
	ifstream rankingLoad("ranking.dat", ios::in);

	rv.clear();

	if (rankingLoad) 
	{
		while (!rankingLoad.eof())
		{
			string nAux = "";
			int pontAux = -1;
			rankingLoad >> nAux >> pontAux;
			if (nAux != "")
				rv.push_back(Ranking(nAux, pontAux));
		}

		rankingLoad.close();
	}

}

void Ranking::imprimeRank()
{

	int tam = rv.size();
	Ranking r("", 0);

	for (int i = 1; i < tam; i++)
	{
		for (int j = 0;j < tam - i;j++)
		{
			if (rv[j].getPontuacao() > rv[j + 1].getPontuacao())
			{
				r = rv[j];
				rv[j] = rv[j + 1];
				rv[j + 1] = r;
			}
		}
	}
	for (int i = tam-1; i >= 0; i--)
		cout << rv[i].getNome() << " - " << rv[i].getPontuacao() << endl;
}
