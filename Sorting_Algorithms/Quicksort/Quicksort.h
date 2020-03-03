 #ifndef QUICKSORT_H_
 #define QUICKSORT_H_
 #include <cstddef>
 #include <iostream>
 #include <algorithm>

template<typename Type>
int Punkt_podzialu(Type l, Type r){
return l + (r-l)/2; // zwraca indeks środka danej poddtablicy
}
template<typename Type>
void zamien ( Type * tab, int indeks1, int  indeks2  ){
    Type tmp;
    if(!(tab[indeks1]== tab[indeks2])){
        tab[indeks1]=tmp;
        tab[indeks1]=tab[indeks2];
        tab[indeks2]=tmp;
    }
}

template<typename Type>
int Separate(Type * tab, int l, int r){
    //std::cout<< l << r  <<std::endl;    
    int indeks=Punkt_podzialu(l,r);
    //std::cout << "Punt podzialu " << indeks <<std::endl;
    Type Val_sep= tab[indeks];
    //std::cout << "Punt podzialu wartosc " << tab[indeks] <<std::endl;
    std::swap(tab[r],tab[indeks]); //przeniesienie elementu (wyznacznika) na koniec żeby nie był sortowany 
    //zamien(tab,r, indeks);
    int pozycja= l;
    
     for(size_t i = l; i <= r-1; i++)
    {
        if(tab[i]<Val_sep){
         std::swap(tab[pozycja],tab[i]); 
         //zamien(tab,pozycja,i);
         pozycja++;
        }
    }
    //zamien(tab,pozycja,r);
    std::swap(tab[r],tab[pozycja]);
    return pozycja;

}

template<typename Type>
 void Quicksort(Type* tab, int l, int r ){
    
     if(l<r){
        int i=Separate(tab,l,r);
        Quicksort(tab,l,i-1);
        Quicksort(tab,i+1,r);

     }
 }




  #endif