#pragma once
#include <SFML/Graphics.hpp>
#include "FoodGenerator.h"
#include "Network.h"
#include "Player.h"
#include<SFML/Network.hpp>

class Network;

//#include "C:\SFML\include\SFML\Graphics\RenderWindow.hpp"
class Game :
	public sf::RenderWindow
{
public:
	Game();
	//Game(sf::WindowHandle 	handle, const sf::ContextSettings & = sf::ContextSettings());
	~Game();
	void draw(sf::RenderWindow & window);
	void resize(sf::Event::SizeEvent event_size, sf::Vector2u window_size);
	void connect();
	void disconnect();
	sf::Vector2f getCirclePos();
	void setIpAndWindowSize(sf::IpAddress _serverIp, sf::Vector2u window_size);
	void counting(sf::RenderWindow & window);
	void func();
	void threadWait();
	void setFirst();
	void setFood(const std::vector<sf::Vector2f>& _food, float foodRadius);
	void updateFood(int index, sf::Vector2f newFood);

private:
	sf::Vector2f vec;
	sf::Vector2f movement;
	sf::Clock clock;
	bool first; //kamera n�zetet reseteli, ha first=true, mindig meg kell hivni a setfirst-t hogy ha �j j�t�kot kezd�nk
	sf::View view;

	std::vector<sf::CircleShape> food;
	//FoodGenerator gen;

	sf::CircleShape circle;
	sf::Sprite map, background;
	sf::Texture texture, texture2;
	Network* network;
	Player player;
	bool finished;
	sf::Thread thread;
};
//R�gi:
/*#include <SFML/Graphics.hpp>
#include "FoodGenerator.h"
#include "Network.h"
#include "Player.h"
#include<SFML/Network.hpp>
//#include "C:\SFML\include\SFML\Graphics\RenderWindow.hpp"
class Game :
	public sf::RenderWindow
{
public:
	Game(sf::VideoMode mode, const sf::String &title, sf::IpAddress _serverIp, sf::Uint32 style = sf::Style::Default, const sf::ContextSettings &settings = sf::ContextSettings());
	//Game(sf::WindowHandle 	handle, const sf::ContextSettings & = sf::ContextSettings());
	~Game();
	void event_loop();
	void add();
private:
	sf::View view;
	std::vector<sf::CircleShape> food;
	//FoodGenerator gen;
	sf::CircleShape circle;
	sf::Sprite map, background;
	sf::Texture texture, texture2;
	Network *network;
	Player player;
};*/