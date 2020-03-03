#include "Board.hpp"
#include <stdint.h>
#include <iostream>
#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include "Cross.hpp"
#define G_WID 1000
/*

 	 	 x0   x1  x2
		 ___________		   tinycell (2bit)
		|   |   |   |		       ___
	y0	| - | O | X |		      v   v
		|___|___|___|		 ____________________________________________
		|   |   |   |		|   |   |   |   |   |   |   |   |   |   |   /
	y1	| - | - | O |		|   |   |   |   |   |   |   |   |   |   |   \ . . .
		|___|___|___|		|___|___|___|___|___|___|___|___|___|___|___/
		|   |   |   |
	y2	| - | O | - |		  ^___________________________^
		|___|___|___|					cell (byte)

		battle field					physical bf array
		  abstract
 */

int8_t Board::set_field(uint8_t x, uint8_t y, uint8_t mark)
{
	uint16_t field_idx = y * this->bf_size + x;		//Index of field in battle field abstract
	uint16_t cell_idx = field_idx/4;				//Index of cell (byte) in physical bf array
	uint8_t tinycell_idx = (field_idx%4)*2;			//Index of tinycell (2bit) in physical bf array

	if(mark == 0)
	{
	  this->pawns_amount--;
		this->bf[cell_idx] &= ~(0x03 << tinycell_idx);
	}
	//If there already is sign return error;
	if(this->bf[cell_idx] & (0x03 << tinycell_idx))
		return -1;

	//Set specified mark on given position
	if(mark == 1)
	{
		this->bf[cell_idx] |= (0x01 << tinycell_idx);
		this->pawns_amount++;
	}

	if(mark == 2)
	{
		this->bf[cell_idx] |= (0x02 << tinycell_idx);
		this->pawns_amount++;
	}

	//No error
	return 0;
}

uint8_t Board::get_field(uint8_t x, uint8_t y)
{
	uint16_t field_idx = y * this->bf_size + x;		//Index of field in battle field abstract
	uint16_t cell_idx = field_idx/4;
	uint8_t tinycell_idx = field_idx%4*2;
	return ((this->bf[cell_idx] & (0x03<<tinycell_idx)) >> tinycell_idx);
}


int8_t Board::set_field(uint16_t idx, uint8_t mark)
{
	uint16_t cell_idx = idx/4;				//Index of cell (byte) in physical bf array
	uint8_t tinycell_idx = (idx%4)*2;			//Index of tinycell (2bit) in physical bf array

	if(mark == 0)
	{
		this->bf[cell_idx] &= ~(0x03 << tinycell_idx);
		this->pawns_amount--;
	}
	//If there already is sign return error;
	if(this->bf[cell_idx] & (0x03 << tinycell_idx))
		return -1;

	//Set specified mark on given position
	if(mark == 1)
	{
		this->bf[cell_idx] |= (0x01 << tinycell_idx);
		this->pawns_amount++;
	}

	if(mark == 2)
	{
		this->bf[cell_idx] |= (0x02 << tinycell_idx);
		this->pawns_amount++;
	}

	//No error
	return 0;
}

uint8_t Board::get_field(uint16_t idx)
{
	uint16_t cell_idx = idx/4;
	uint16_t tinycell_idx = (idx%4)*2;
	return ((this->bf[cell_idx] & (0x03<<tinycell_idx)) >> tinycell_idx);
}
 
uint8_t * Board::get_bf(void)
{
   return this->bf;
}

Board::Board(uint8_t bf_size)
{  
    this->bf_size = bf_size;
    this->cell_number = (bf_size*bf_size%4) ? (bf_size*bf_size/4+1) : (bf_size*bf_size/4);
    this->pawns_amount = 0;

    this->bf = new uint8_t[this->cell_number];

    for(int i = 0; i < cell_number; i++)
    	this->bf[i] = 0;

}

Board::~Board()
{
}

void Board::reset(void)
{
	for(int i = 0; i < this->cell_number; i++)
		this->bf[i] = 0;

}

bool Board::valid_move(uint16_t move)
 {
	if(!get_field(move)&& (move>=0 && move<get_size()*get_size())){return true;}
	else{
		std::cout << "Incorrect field" << std::endl;
		return false;
	}
 }
void Board::display()
{

	uint16_t cell_idx;
	uint8_t tinycell_idx;
	uint8_t field_val;
	uint8_t col_cnt = 0;
	char mark[3] = {' ', 'O', 'X'};
	system("clear");


	for(uint16_t i = 0 ; i < this->bf_size*bf_size; i++)
	{
		cell_idx = i/4;
		tinycell_idx = i%4*2;
		field_val = ((this->bf[cell_idx] & (0x03<<tinycell_idx)) >> tinycell_idx);

		col_cnt++;
		std::cout << "|" << mark[field_val] ;
		if(col_cnt == this->bf_size)
		{
			std::cout << "|" << std::endl;
			col_cnt = 0;
		}
	}


}
  
uint8_t Board::get_size(void){return this-> bf_size;}

bool Board::is_board_full(void)
{
	if(this->pawns_amount == (this->bf_size * this->bf_size)) return true;
	return false;
}



void Board::desktop()
{
	
	  int	n=this->get_size();
  	int vect_len=((G_WID)/(n+1)) *(n) ;
		int D_circ=vect_len/(n*n);
		int Len_cross=(vect_len )/(n*n -n);
		int x;
		int y;
		Cross *tmp_cross;
		sf::CircleShape * tmp_circle;
		sf::RectangleShape krata[(n+1)];
  	sf::RectangleShape krata1[(n+1)];
	  
		
 	for (size_t i = 0; i < (n+1); i++)
 	{

			 krata[i].setSize(sf::Vector2f(1,vect_len));	
			 krata[i].setOutlineColor(sf::Color::White);
			 krata[i].setOutlineThickness(10);
			 krata[i].setPosition((G_WID/(n+1))*i +30,30);
			 krata[i].setFillColor(sf::Color::White);
	}

	for (size_t i = 0; i < n+1; i++)
	{
			 krata1[i].setSize(sf::Vector2f(vect_len,1));	
			 krata1[i].setOutlineColor(sf::Color::White);
			 krata1[i].setOutlineThickness(10);
			 krata1[i].setPosition(30,(G_WID/(n+1))*i +30 );
			 krata1[i].setFillColor(sf::Color::White);
	}

    sf::RenderWindow oknoAplikacji( sf::VideoMode( G_WID, G_WID, 32 ), "Thicc tac toe" );
		


while( oknoAplikacji.isOpen() )
    {
      sf::Event zdarzenie;
        
        while( oknoAplikacji.pollEvent( zdarzenie ) )
        {    
             
            if( zdarzenie.type == sf::Event::Closed )
                 oknoAplikacji.close();
            
            if( zdarzenie.type == sf::Event::KeyPressed && zdarzenie.key.code == sf::Keyboard::Escape )
                 oknoAplikacji.close();
            
        }
				
		for (size_t i = 0; i < (n+1); i++)
		{
			oknoAplikacji.draw(krata[i]);
		}
		for (size_t i = 0; i < (n+1); i++)
		{
			oknoAplikacji.draw(krata1[i]);
		}
		/*****************FIGURY ***************************/
		for (size_t y = 0; y < this->get_size(); y++)
		{
			for (size_t x = 0; x <this->get_size(); x++)
			{
						if (this->get_field(y,x)== 2)
						{ 
						 tmp_cross= new Cross(n,Len_cross);
						 tmp_cross->set_pos(y*vect_len/(n)+30 +vect_len/(2*n) -10 , x*vect_len/(n) +30 +vect_len/(2*n) -20 );
						 tmp_cross->display_cross(oknoAplikacji);
							
						}
						else if (this->get_field(y,x)== 1)
						{
							tmp_circle= new sf::CircleShape;
							tmp_circle->setRadius(D_circ);
    					tmp_circle->setPosition( y*vect_len/(n)+30 +45, x*vect_len/(n) +30 +45  );
	  					tmp_circle->setFillColor(sf::Color{9,100,100,0});
	  					tmp_circle->setOutlineColor(sf::Color{ 89, 200, 60, 255 });
	  					tmp_circle->setOutlineThickness(20.f);
						  oknoAplikacji.draw(*tmp_circle);
							
						}
			}
		}
		
		
	//	krzyz.set_pos(400, 400);
    //krzyz.display_cross(oknoAplikacji);
	//	oknoAplikacji.draw(circle);


		/******************FIGURY******************************/
		oknoAplikacji.display();
	
	}
}



