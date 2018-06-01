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
namespace Wonho_pp {
	class Resource {
	public:
		Resource(std::string Root);
		std::string getPath(std::string filename);
	private:
		std::string ResourceRootPath;
	};
};