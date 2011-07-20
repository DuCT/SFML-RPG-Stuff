#pragma once
#include <iostream>
#include <SFML\Graphics.hpp>
#include "Layer.h"

class Map
{
public:
	Map(std::string maps);
	~Map();

	void drawMap();
	void displayMap(sf::RenderWindow &app);
	int returnHeight();
	int returnLength();
	int returnNumberOfLayers();

private:
	int numberOfLayers;
	int height;
	int length;
	std::string test;
	std::string tiles[4];
	Layer *layers[4];
};

