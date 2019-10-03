/*
Un camionero conduce desde DF a Acapulco siguiendo una ruta dada
y llevando un camión que le permite, con el tanque de gasolina
lleno,recorrer n kilómetros sin parar. El camionero dispone de
un mapa de carreteras que le indica las distancias entre las
gasolineras que hay en su ruta. Como va con prisa, el camionero
desea detenerse a abastecer gasolina el menor número de veces posible.
Diseñe un algoritmo eficiente que determine en qué gasolineras
tiene que parar el camionero.
*/

#include <iostream>


using namespace std;

void calcularParadas(int n, int *mapa, int gasolineras){
    int kmRecorridos = 0;
    cout<<"Se tiene que parar en las gases: ";
    for (int i = 0; i < gasolineras-1; i++){
        if (n-kmRecorridos <= (mapa[i+1]+mapa[i]))
        {
            cout<<" "<<i+1;//Imprimiendo donde tiene que cargar gas
            kmRecorridos = 0;
        } else{
           /*Puede continuar*/
           kmRecorridos+=mapa[i];
        }
    }
}

int main(){
    int n = 10;
    int gasolineras = 6;
    int mapa[6] = {2,10,3,5,1,6};
    calcularParadas(n,mapa,gasolineras);
    return 0;
}