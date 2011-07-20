#include "Map.h"
#include <fstream>
#include <sstream>


Map::Map(std::string maps)
{
	std::ifstream mapfile;
	mapfile.open(maps);
	
	mapfile >> test;
	if (test == "HEIGHT")
	{
		mapfile >> test;
		int resukt;
		std::stringstream convert(test);
		convert >> resukt;

		height = resukt;

	}
	else
	{
		std::cout << "ERROR: formatting in line HEIGHT";
	}
	
	mapfile >> test;
	if (test == "LENGTH")
	{
		mapfile >> test;
		int resukt;
		std::stringstream convert(test);
		convert >> resukt;

		length = resukt;
	}
	else
	{
		std::cout << "ERROR: formatting in line LENGTH";
	}
	
	mapfile >> test;
	if (test == "LAYERS")
	{
		mapfile >> test;
		int resukt;
		std::stringstream convert(test);
		convert >> resukt;

		numberOfLayers = resukt;
	}
	else
	{
		std::cout << "ERROR: formatting in line LAYERS";
	}
	
	for (int i = 1; i <= numberOfLayers; i++)
	{
		std::string name = "LAYERTILE";
		char numstr[2];
		sprintf_s(numstr, "%d", i);
		std::string result = name + numstr;
				
		mapfile >> test;
		if (test == result)
		{
			mapfile >> test;
			tiles[i] = test;
		}
		else
		{
			std::cout << "ERROR: formatting in line " << result;
		}
	}
	
	for (int i = 1; i <= numberOfLayers; i++)
	{
		layers[i] = new Layer(mapfile, tiles, height, length, i);
	}
	
	for (int i = 1; i <= numberOfLayers; i++)
	{
		std::cout << i << " " << layers[i]->getName();
	}
}


Map::~Map()
{
}

int Map::returnHeight()
{
	return height;
}

int Map::returnLength()
{
	return length;
}

int Map::returnNumberOfLayers()
{
	return numberOfLayers;
}

void Map::drawMap()
{
	for (int i = 1; i <= numberOfLayers; i++)
	{
		layers[i]->drawTheMap();
	}
}

void Map::displayMap(sf::RenderWindow &App)
{
	for (int i = 1; i <= numberOfLayers; i++)
	{
		App.Draw(layers[i]->getMapImage());
	}
}