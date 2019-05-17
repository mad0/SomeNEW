#pragma once
#include <string>
#include <map>
#include <memory>
#include <SFML/Graphics.hpp>
#include <iostream>
#include <typeinfo>

template <typename Resource>
class CResourceManager {
public:
	void addResource(int, const std::string&);
	Resource& getResource(int);
private:
	std::map<int, std::unique_ptr<Resource>> mResources;
};

template <typename Resource>
inline void CResourceManager<Resource>::addResource(int _id, const std::string& _file) {
	auto _temp = std::make_unique<Resource>();
	if (!_temp->loadFromFile(_file)) {
		std::cout<<"ERROR\n";
	}
	mResources.insert(std::make_pair(_id, std::move(_temp)));
};

template<typename Resource>
Resource & CResourceManager<Resource>::getResource(int _id)  {
	auto find = mResources.find(_id);
	//std::cout << typeid(find->second).name();
	std::cout << "1 address: " << &(*find->second) << "\n";
	return *find->second;
};
