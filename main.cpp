#include <iostream>
#include "listaligada.hpp"
using namespace std;

int main() {
  Listaligada<int> lista1;
  lista1.insereInicio(1);
  lista1.insereFinal(2);
  lista1.insereFinal(3);
  lista1.insereFinal(4);
  lista1.insereFinal(5);


  lista1.show();
  
  cout<<endl;
  lista1.inverte();
  lista1.show();



}