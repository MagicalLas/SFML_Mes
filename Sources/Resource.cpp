/*************************************************************************
> File Name: Resource.cpp
> Project Name: 2048 in GSM
> Author: Wonho Ha aka Las
> Purpose: Resource Path Manager
> Created Time: 2018/05/26
> Copyright (c) 2018, Wonho Ha aka Las
*************************************************************************/
#include"../Includes/Resource.h"
namespace Wonho_pp {
	Resource::Resource(std::string Root) {
		ResourceRootPath = Root;
	};
	std::string Resource::getPath(std::string filename) {
		return ResourceRootPath + "/" + filename;
	};
};