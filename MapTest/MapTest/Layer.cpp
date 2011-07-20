
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <SFML\Graphics.hpp>
#include "Dynamic2DArray.h"
#include "Layer.h"


Layer::Layer(std::ifstream &mapFile, std::string tile[], int heightt, int lengthh, int i)
{
	animation = 0;
	std::string set;

	height = heightt;
	length = lengthh;

	aniClock = new sf::Clock;
	rendImage = new sf::RenderImage;
	
	tileName = tile[i];
	if (!tileImage.LoadFromFile(tile[i]))
	{
		std::cout << "Huh";
	}
	tileImage.CreateMaskFromColor(sf::Color(255,174,201));
	tiles.SetImage(tileImage);
	tiles.SetOrigin(0,0);

	map = new Dynamic2DArray(height, length);
	
	std::string name = "L";
	char numstr[2];
	char numst[2];
	sprintf_s(numstr, "%d", i+1);
	sprintf_s(numst, "%d", i);
	std::string result = name + numstr;
	std::string current = name + numst;
	
	int intt;
	
	while (mapFile.good() && set!= result)
	{
		for ( int x = 0; x < length; x++)
		{
			for (int y = 0; y < height; y++)
			{
				mapFile >> set;
				if ( set == current)
				{
					std::cout << "Current";
					mapFile >> set;
				}
				if (set == result)
				{
					std::cout << "Next";
					break;
				}
				
				std::stringstream convert(set);
				convert >> intt;
				
				map->setAtPoint(y,x,intt);
			}

			if (set == result)
			{
				break;
			}
		}
	}

	rendImage->Create((32*height), (32*length));
}

Layer::~Layer()
{
	delete aniClock;
	delete rendImage;
}

void Layer::drawTheMap()
{
	int tester;
	
	for (int i = 0; i < length; i++)
	{
		for (int j = 0; j < height; j++)
		{
			tester = map->getAtPoint(j,i);
			this->setTheSubRect(tester);
			tiles.SetPosition((j * 32), (i * 32));
			rendImage->Draw(tiles);
		}
	}
	this->animationCheck();
	rendImage->Display();
	
	sf::Sprite temp(rendImage->GetImage());

	mapD = temp;
	mapD.SetOrigin((16*height), (16*length));
	mapD.SetPosition(320, 240);

}

int Layer::getHeight()
{
	return height;
}

int Layer::getLength()
{
	return length;
}

void Layer::setTheSubRect(int &tester)
{
	if (tester == 0)
	{
		tiles.SetSubRect(sf::IntRect(0, 0, 32, 32));
	}
	else if (tester == 1)
	{
		tiles.SetSubRect(sf::IntRect(32, 0, 32, 32));
	}
	else if (tester == 2)
	{
		if (animation == 0)
		{
			tiles.SetSubRect(sf::IntRect(64, 0, 32, 32));
		}
		else if (animation == 1)
		{
			tiles.SetSubRect(sf::IntRect(96, 0, 32, 32));   
		}
	}
	else if (tester == 3)
	{
		tiles.SetSubRect(sf::IntRect(160 , 0, 32, 32));
	}
	else
	{
		tiles.SetSubRect(sf::IntRect(128, 0, 32, 32));
	}
}

void Layer::animationCheck()
{
	if (animation == 0 && (aniClock->GetElapsedTime() > 1))
	{
		animation = 1;
		aniClock->Reset();
	}
	else if (animation == 1 && (aniClock->GetElapsedTime() > 1))
	{
		animation = 0;
		aniClock->Reset();
	}
}

sf::Sprite Layer::getMapImage()
{
	return mapD;
}

std::string Layer::getName()
{
	return tileName;
}