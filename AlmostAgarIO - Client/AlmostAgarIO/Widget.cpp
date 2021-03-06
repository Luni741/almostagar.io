#include "stdafx.h"
#include "Widget.h"


Widget::Widget(float x,float y, float size_x,float size_y,std::string value)
{
	_x = x;
	_y = y;
	_size_x = size_x;
	_size_y = size_y;
	_value = value;
	_mouseover = false;
	_mousedown = false;
}


Widget::~Widget()
{
}

void Widget::draw(sf::RenderWindow & window)
{
}

void Widget::handle(sf::Event event)
{
}

std::string Widget::getValue()
{
	return _value;
}

void Widget::resize(float r)
{
	_x = r*_x;
	_y = r*_y;
	_size_x = r*_size_x;
	_size_y = r*_size_y;
}
