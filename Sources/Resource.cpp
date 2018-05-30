#include"../Include/Resource.h"
namespace Wonho_pp {
	Resource::Resource(std::string Root) {
		ResourceRootPath = Root;
	};
	std::string Resource::getPath(std::string filename) {
		return ResourceRootPath + "/" + filename;
	};
};