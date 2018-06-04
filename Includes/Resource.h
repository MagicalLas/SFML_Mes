/*************************************************************************
> File Name: Resource.cpp
> Project Name: 2048 in GSM
> Author: Wonho Ha aka Las
> Purpose: Resource Path Manager
> Created Time: 2018/05/26
> Copyright (c) 2018, Wonho Ha aka Las
*************************************************************************/
#pragma once
#include<string>
#include<SFML/Graphics.hpp>
#include<iostream>
namespace Wonho_pp {
	class Resource {
	public:
		Resource(std::string Root);
		std::string getPath(std::string filename);
		sf::Font font;
		[[noreturn]]
		void setFont(std::string path, sf::Text & text) {
			if (!font.loadFromFile(getPath(path)))
			{
				std::cout << "Font can't find\n";
			}
			text.setFont(font);
		};
	private:
		std::string ResourceRootPath;
	};
	class ColorControl {
	public:
		void setRecColor(sf::RectangleShape draw, int num) {
			draw.setFillColor(sf::Color::Color(2, 65, 23, 100));
		}
	};
};