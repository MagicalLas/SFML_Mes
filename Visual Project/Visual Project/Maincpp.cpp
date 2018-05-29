#include<iostream>


#include <SFML/Graphics.hpp>


int main()
{
	std::cout << "Program Start - Las\n";
	sf::RenderWindow window(sf::VideoMode(800, 800), "PLAY - LAS");


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
		}

		window.clear();

		window.display();
	}

	std::cout << "Program End - Las\n";
	return 0;
}