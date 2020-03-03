// Projekt2.cpp : Defines the entry point for the console application.
//


#include <chrono>
#include <iostream>
#include <vector>
#include <algorithm>
#include "inputs.h"
#include "Quicksort.h"
#include "intro.h"
#include "Scalanie.h"
template<typename T>
bool checkIfCorrect(std::vector<T> table, const std::vector<T>& result)
{
	std::sort(table.begin(), table.end());
	return (table == result);
}

template<typename T, size_t N>
bool checkIfCorrect(const T (&table)[N], const  T (&result)[N])
{
	T sorted[N];
	std::copy(table, table + N, sorted);
	std::sort(std::begin(sorted), std::end(sorted));

	return std::equal(std::begin(sorted), std::end(sorted),
		std::begin(result), std::end(result));
}

int main()
{
	//srand(time(NULL));

	std::vector<int> nVector{10000, 50000, 100000,500000, 1000000};
	const int nbOfExperiments = 10;
    float t[8];
    t[0]=0;
    t[1]=0.25;
    t[2]=0.50;
    t[3]=0.75;
    t[4]=0.95;
    t[5]=0.997;
    t[6]=1;
    float suma=0;
	float suma_min=0;
	float suma_max=0;

	/*Badanie dla ka�dego rozmiaru tablicy n
	int rozmiar3=30;
	int tab3[rozmiar3];
	input_min_max(tab3,rozmiar3-1,0.3);
	print_tab(tab3,rozmiar3-1);
	Quicksort(tab3,0,rozmiar3-1);
	print_tab(tab3,rozmiar3-1);
     */

	for(size_t i = 0; i < 5; i++)
	{ int *tab=new int[nVector[i]];
	std::cout<< "N : "<<nVector[i]<<std::endl;
		for(size_t z = 0; z < 7; z++)
		{  
			for(size_t k = 0; k < nbOfExperiments; k++)
		    {
		    	  auto start = std::chrono::system_clock::now();
				  //quicksort(tab,0,nVector[i]-1);
				  Merge_Sort(tab,0,nVector[i]-1);
		    	  //IntroSort_Q(tab,0,nVector[i]-1,2*log2(nVector[i])-50);
				  auto end = std::chrono::system_clock::now();
                   if_sorted(tab,nVector[i]);
			std::chrono::duration<double> diff = end - start; // w sekundach https://en.cppreference.com/w/cpp/chrono/duration
			double durationTime = diff.count(); // zmierzony czas zapisa� do pliku lub zagregowa�, zapisa� liczb� badanych element�w
			if (suma_max< durationTime ) {
				suma_max=durationTime;
			}
			if(k==0)suma_min=durationTime;
			if (suma_min> durationTime ) {
				suma_min=durationTime;
			}			
			
			suma+=durationTime;
			}
             
		  	std::cout<< t[z]<< " "<< suma/100 << std::endl;
		}
		delete tab;
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	}
			

			/*
			Przygotowanie tablic o rozmiarze n:
			�wszystkie elementy tablicy losowe,
			� 25%, 50%, 75%, 95%, 99%, 99,7% pocz�tkowych element�w tablicy jest ju� posortowanych,
			� wszystkie elementy tablicy ju� posortowane ale w odwrotnej kolejno�ci.
			*/

		
				

			/* Mierzenie czasu trwania jednego eksperymentu
			Poni�szy fragment wykonywany jest wielokrotnie 
			osobno dla ka�dej kombinacji algorytmu i tablicy wej�ciowej*/
			
			//pojedyncze wykonanie jednego algorytmu sortowania dla jednej tablicy
			//sortowanie na kopii tablic wej�ciowych
			
		
	
	return 0;
}

