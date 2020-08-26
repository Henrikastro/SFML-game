#pragma once
#include "Fase.h"
class F1 :
	public Fase
{
public:
	F1(sf::RenderWindow& window, bool *dj);
	virtual ~F1();

	void carregaEntidades();

private:
};

