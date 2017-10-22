// AlmostAgarIO.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Button.h"
#include "Windows.h"

#include "iostream"

#include <SFML/Graphics.hpp>


int main()
{
	Windows window_first(sf::VideoMode(1000, 600), "almostagar.io");

	TextEditor *textinput1 = new TextEditor(300, 100, 400, 65, "", "Szerver IP");
	window_first.add(textinput1);

	TextEditor *textinput2 = new TextEditor(300, 200, 400, 65, "", "�rd be a neved!");
	window_first.add(textinput2);

	lambdaButton *g1 = new lambdaButton(100 + 300, 300, 200, 50, "J�t�k",
		[&]//mindent akarok haszn�lni
	()
	{
		if (!textinput2->isempty())
			std::cout << textinput2->getValue() << std::endl;
	}
	);
	window_first.add(g1);

	window_first.event_loop();
	return 0;
}