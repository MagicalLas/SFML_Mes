#include"../Include/Useful.h"
namespace Wonho_pp {
	
	void Screen_Move::setMiddle(sf::Text& text) {
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);

	};

};