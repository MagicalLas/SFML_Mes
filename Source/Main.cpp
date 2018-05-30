//STD
#include<iostream>
//Other
#include "../Library/Imgui/imgui-SFML.h"
#include "../Library/Imgui/imgui.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include <SFML/System/Clock.hpp>
#include <SFML/Window/Event.hpp>
#include <SFML/Graphics/CircleShape.hpp>
//Wonho
#include"../Include/Resource.h"
#include"../Include/Useful.h"

int main(){
	
	
	std::cout <<"Biuld Success" << std::endl;
	std::cout << "Program Start!" << std::endl;

	//WON API
	Wonho_pp::Resource res("../../Resource");
	Wonho_pp::String_Helper StringHelper;
	Wonho_pp::Screen_Move ScreenHelper;

	sf::RenderWindow window(sf::VideoMode(640, 480), "ImGui + SFML = <3");
	window.setFramerateLimit(60);
	sf::CircleShape shape(100.f);
	shape.setFillColor(sf::Color::Green);

	sf::Clock deltaClock;
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			
			if (event.type == sf::Event::Closed)
			{
				window.close();
			}
		}

		window.clear();
		window.draw(shape);
		window.display();
	}

	
	std::cout << "Program End - Las\n";
	return 0;
}