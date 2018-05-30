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