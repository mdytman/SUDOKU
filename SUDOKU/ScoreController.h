#pragma once
#include <SFML/Graphics.hpp>
#include "ScoreView.h"

class ScoreController {
	bool finished = false;
	ScoreView & view;
public:
	explicit ScoreController(ScoreView & v);
	void handleEvent(sf::Event &event);
	void draw(sf::RenderWindow & win) { view.draw(win); }
	bool isFinished() const { return finished; }
};