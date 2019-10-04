/*
Dada una secuencia X={x1 x2 ... xm}, se dice que Z={z1 z2 ... zk} 
es una scm de X (siendo k ≤ m) si existe una secuencia
creciente {i1 i2 ... ik} de índices de X tales que para todo
j = 1, 2, ..., k tenemos xij = zj.
Dadas dos secuencias X e Y, se dice que Z es una scm
común de X e Y si es scm de X y scm de Y. 
Diseñe un algoritmo que permita determinar la scm
de longitud máxima común a dos secuencias.
*/

#include <iostream>
#include <string>

using namespace std;

string scm(string input1, int n , string input2, int m);
int check(string input1, int i, string input2, int j);
string max(string input1, int i, string input2, int j);

int check(string input1, int i, string input2, int j)
{
  int maximo = 0;
  while(input1[i] == input2[j]){
    ++i;
    ++j;
    maximo++;
  }
  return maximo;
}
string scm(string input1, int n , string input2, int m){
  int j;
  string maximo;
  for(int i = 0; i < n; i++){
    for(int j = 0; j < n; j++){
      if(input1[i] == input2[j]){
        if(check(input1, i, input2, j) >= maximo.length()){
          maximo = max(input1, i, input2, j);
        }
      }
    }
  }
  if (maximo == ""){
    return "NO EXISTE";
  } else {
    return maximo;
  }
}
string max(string input1, int i, string input2, int j){
  string maximo = " ";
  while(input1[i] == input2[j]){
    maximo += input1[i];
    ++i;
    ++j;
  }
  return maximo;
}

int main(){
    
    string X = "Este es un enunciado que sirve de ejemplo";
    string Z = "Se toma y sirve de ejemplo";
    cout<<scm(X, X.length(), Z, Z.length())<<endl;

  return 0;
}