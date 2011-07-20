#include <SFML\Graphics.hpp>
#include <fstream>
#include <iostream>
#include "Layer.h"
#include "Map.h"




using namespace std;

int main()
{
	Map test("newMap.txt");

	sf::RenderWindow App(sf::VideoMode(640, 480, 32), "HAHAHAHAHAHAHA");

	while (App.IsOpened())
	{
		sf::Event Event;
		while (App.GetEvent(Event))
		{
			if (Event.Type == sf::Event::Closed)
			{
				App.Close();
			}
		}
		App.Clear(sf::Color::Black);
		
		test.drawMap();
		test.displayMap(App);

		App.Display();
	}
	return 0;
}
