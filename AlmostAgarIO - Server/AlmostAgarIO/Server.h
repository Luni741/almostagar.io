#pragma once
#include <SFML/Network.hpp>
#include <SFML\System.hpp>
#include <list>
#include <map>
#include <unordered_map>
#include "Player.h"
#include "FoodGenerator.h"

class Server
{
	sf::TcpListener listener;
	sf::UdpSocket udpSocket;
	std::unordered_map<int, Player> players;
	sf::SocketSelector selector;
	unsigned short port = 50000;
	unsigned int id;
	sf::Vector2f position;
	sf::Clock clock;
	FoodGenerator foodGenerator;
	std::vector<sf::Vector2f> food;
	std::unordered_map<int, sf::Vector2f> foodToUpdate;
	std::vector<Player*> ranking;
	sf::TcpListener testListener;

	bool running;
	bool rankingChanged;

	bool updatePlayerPosition(int id, sf::Vector2f pos);	//returns true if somebody died
	void updateFood(unsigned int id);
	void checkRanking();
	void deletePlayerFromRanking(int id);
	void playerDied(unsigned int id);
public:
	Server();
	~Server();

	void run();
};

