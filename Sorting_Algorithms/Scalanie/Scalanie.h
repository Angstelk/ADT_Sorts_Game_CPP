 #ifndef SCALANIE_H_
 #define SCALANIE_H_
 #include <cstddef>
 #include <iostream>
 // 2 funkcje merge i merge sort
 template<class Typ>
 /* Scalanie 2 poortowanych podtablic by wyszla posortowana tablica ale lepiej   */
 Typ * merge(Typ *TMP, int l,int i, int p){
    int indeks1=0, indeks2=0; // tymi indeksami wędrujemy po tablicach
    int n1 = i - l +1 ; // ilosc elementów w lewej 
    int n2 =  p - i ;  // ilosc elementow w prawej
    int f = 0; // wskaźnik do wędrowania po tablicy 
    Typ L[n1], R[n2]; // alokuje sobie 2 tablice
    for(size_t z = 0; z < n1; z++) // pętle przypisujaca tablicom l i p wartosci  
    { 
      L[z]=TMP[l+z];
    }

    for(size_t k = 0; k < n2; k++)
    {
      R[k]=TMP[k+1+i];
    }

    for(f = l; indeks1<n1 && indeks2<n2 ; f++)
    { 
     if (L[indeks1]>=R[indeks2] ) {
     TMP[f]=R[indeks2];
     if(indeks2<n2)indeks2++;   
     }
      else
      {
        TMP[f]=L[indeks1];
        if(indeks1<n1)indeks1++;
      }
    }
    while (indeks1 < n1) 
    { 
        TMP[f] = L[indeks1]; 
        f++; 
        indeks1++; 
    }  //merge(tab,l,i,p);
    while (indeks2 < n2) 
    { 
        TMP[f] = R[indeks2]; 
        f++; 
        indeks2++; 
    } 
      return TMP;
 }

 template<typename Type>
Type* Merge_Sort(Type *tab, int l, int p){
int i;
if(l<p){
   i=(l+p)/2;
  Merge_Sort(tab,l,i);
  Merge_Sort(tab,i+1 ,p);
  merge(tab,l,i,p);
  
}
return tab;
}
 #endif
