#ifndef CROS_HPP_
#define CROSS_HPP_
#include <cmath>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
class Cross
{
private:
    int vect_leng;
    sf::RectangleShape C_front;
    sf::RectangleShape C_back;
   public:
    void set_pos(int x, int y)
    {
       //C_back.setPosition(0,0);
       //C_front.setPosition(300,300);    


     C_back.setPosition( x+this->vect_leng/(2*sqrt(2)), y );   
     C_front.setPosition( x-this->vect_leng/(2*sqrt(2)), y );
    } ;
    void display_cross(sf::RenderWindow & okno)
    {
     okno.draw(C_back);
     okno.draw(C_front);
    };
    Cross(/* args */);
    ~Cross(/* args */);
    Cross(int n, int vect_len);
};

Cross::Cross(int n, int vect_len)
{
    vect_leng=vect_len;
    C_back.setSize(sf::Vector2f(1,vect_len));	
    C_back.setOutlineColor(sf::Color::Yellow);
    C_back.setOutlineThickness(10);
    C_back.setFillColor(sf::Color::Yellow);
    C_back.rotate(45);
    C_front.setSize(sf::Vector2f(1,vect_len));	
    C_front.setOutlineColor(sf::Color::Green);
    C_front.setOutlineThickness(10);
    C_front.setFillColor(sf::Color::Green);
    C_front.rotate(-45);

}

Cross::~Cross()
{
}


#endif