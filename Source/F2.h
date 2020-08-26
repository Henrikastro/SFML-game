#pragma once
#include "Fase.h"

class F2 :
	public Fase
{
public:
	F2(sf::RenderWindow& window, bool* dj);
	~F2();

	void carregaEntidades();
};

