/*
Supongamos que tenemos n hombres y n mujeres y dos matrices M y H
que contienen las preferencias de los unos por los otros. Más concretamente,
la fila M[i,·] es una ordenación (de mayor a menor) de las mujeres según las
preferencias del i-ésimo hombre y, análogamente, la fila H[i,·] es una
ordenación (de mayor a menor) de los hombres según las preferencias de la i-ésima mujer.
Diseñe un algoritmo que encuentre, si es que existe, un emparejamiento de hombres
y mujeres tal que todas las parejas formadas sean estables. Una pareja (h,m)
es estable si no se da ninguna de estas dos circunstancias:

- Existe una mujer m’ (que forma la pareja (h’,m’)) tal que el hombre h
la prefiere sobre la mujer m y además la mujer m’ también prefiere a h sobre h’. 
- Existe un hombre h” (que forma la pareja (h”,m”)) tal que la mujer m
lo prefiere sobre el hombre h y además el hombre h” también prefiere a m sobre la mujer m”.

Complejidad O(n^2)
*/

#include <iostream> 
#include <string.h> 
#include <stdio.h> 
using namespace std; 
  

#define N  4 //Numero de hombres y mujeres
  
bool wPrefersM1OverM(int prefer[2*N][N], int w, int m, int m1) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        if (prefer[w][i] == m1) 
            return true; 
        if (prefer[w][i] == m) 
           return false; 
    } 
} 

void parejasEstables(int prefer[2*N][N]) 
{ 
    int wPartner[N]; 
    bool mFree[N]; 
    memset(wPartner, -1, sizeof(wPartner)); 
    memset(mFree, false, sizeof(mFree)); 
    int freeCount = N; 
  
    // While there are free men 
    while (freeCount > 0) 
    { 
        int m; 
        for (m = 0; m < N; m++) 
            if (mFree[m] == false) 
                break; 

        for (int i = 0; i < N && mFree[m] == false; i++) 
        { 
            int w = prefer[m][i]; 
            if (wPartner[w-N] == -1) 
            { 
                wPartner[w-N] = m; 
                mFree[m] = true; 
                freeCount--; 
            } 
  
            else   
            { 
                int m1 = wPartner[w-N]; 
                if (wPrefersM1OverM(prefer, w, m, m1) == false) 
                { 
                    wPartner[w-N] = m; 
                    mFree[m] = true; 
                    mFree[m1] = false; 
                } 
            } 
        }  
    } 
    //Solucion
    cout << "Parejas" << endl; 
    cout << "Mujer con Hombre" << endl; 
    for (int i = 0; i < N; i++) 
       cout << " " << i+N << "\t" << wPartner[i] << endl; 
} 
  
int main() 
{ 
    int prefer[2*N][N] = { 
        {7, 5, 6, 4}, 
        {5, 4, 6, 7}, 
        {4, 5, 6, 7}, 
        {4, 5, 6, 7}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
        {0, 1, 2, 3}, 
    }; 
    parejasEstables(prefer); 
  
    return 0; 
} 