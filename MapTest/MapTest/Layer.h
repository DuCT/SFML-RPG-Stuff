#ifndef LAYER_H
#define LAYER_H

#include "Dynamic2DArray.h"

class Layer{
public:
	//Layer(std::string mapFile, std::string tileFile);
	Layer(std::ifstream &mapFile, std::string tiles[], int height, int length, int i);
	~Layer();

	void drawTheMap();
	int getHeight();
	int getLength();
	std::string getName();
	void setTheSubRect(int&);
	void animationCheck();

	sf::Sprite getMapImage();

private:
	int height;
	int length;
	int animation;
	Dynamic2DArray *map;
	sf::Clock *aniClock;
	std::string tileName;

	sf::RenderImage *rendImage;
	sf::Image tileImage;
	sf::Sprite tiles;
	sf::Sprite mapD;
};

#endif