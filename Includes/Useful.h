#pragma once
#include"SFML\Graphics.hpp"
#include<string>
namespace Wonho_pp {
	struct Screen_Move
	{
		void setMiddle(sf::Text& draw);
	};
	struct String_Helper
	{
		std::wstring Korean(std::string str);
	};
};