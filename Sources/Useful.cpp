#include"../Includes/Useful.h"
namespace Wonho_pp {	
	Screen_Move::Screen_Move() {
		
	}
	
	void Screen_Move::setMiddle(sf::Text& text) {
		sf::FloatRect textRect = text.getLocalBounds();
		text.setOrigin(textRect.left + textRect.width / 2.0f,
			textRect.top + textRect.height / 2.0f);
	};
	sf::RectangleShape Screen_Move::setTile(int x, int y, sf::Color color) {

		sf::RectangleShape rectangle;
		rectangle.setSize(sf::Vector2f(tile_x - round, tile_y - round));
		rectangle.setOutlineColor(sf::Color::Yellow);
		rectangle.setFillColor(sf::Color::Color(2, 65, 23, 100));
		rectangle.setOutlineThickness(round);
		rectangle.setPosition(100 + x * (tile_x) , 200 + y * (tile_y ));

		return rectangle;
	};
	void Screen_Move::setTileSize(int x, int y, int r = 1) {
		this->tile_x = x;
		this->tile_y = y;
		this->round = r;
	};
	void Screen_Move::setMapSize(int x, int y, int bolder) {
		this->map_x = x;
		this->map_y = y;
		this->yBolder = bolder;
	};
};