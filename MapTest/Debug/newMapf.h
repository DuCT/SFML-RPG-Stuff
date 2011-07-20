Map::Map(std::string maps)
{
	std::ifstream mapFile;
	mapFile.open(maps);
	
	mapfile >> test;
	if (test == "HEIGHT")
	{
		mapfile >> test;
		height = test;
	}
	else
	{
		std::cout << "ERROR: formatting in line HEIGHT";
	}
	
	mapfile >> test;
	if (test == "LENGTH")
	{
		mapfile >> test;
		length = test;
	}
	else
	{
		std::cout << "ERROR: formatting in line LENGTH";
	}
	
	mapfile >> test;
	if (test == "LAYERS")
	{
		mapfile >> test;
		numberOfLayers = test;
	}
	else
	{
		std::cout << "ERROR: formatting in line LAYERS";
	}
	
	for (int i = 1; i <= numberOfLayers; i++)
	{
		std::string name = "LAYERTILE";
		char numstr[2];
		sprintf(numstr, "%d", i);
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
		mapfile >> test;
		layers[i] = new Layer(std::ifstream &mapFile, std::string &tiles[i], int height, int length, int i);
	}
	//layers[0] = new Layer(std::ifstream &mapFile, std::string &tile);
	//layers[1] = new Layer(std::ifstream &mapFile);
}