#ifndef LISTALIGADA_HPP
#define LISTALIGADA_HPP
#include <iostream>
#include "No.hpp"

using namespace std;

template <typename E>
class Listaligada{
  private:
    No<E>*cabeca;
  public:
    Listaligada();
    ~Listaligada();
    bool vazia() const;
    const E& inicio()const;
    const E& fim()const;
    void insereInicio(E const& e);
    void insereFinal(E const& e);
    void removeInicio();
    void removeFim();
    void inverte();
    void operator+(Listaligada<E> * x);
    void show();
    No<E>* getCabeca();
    No<E>* getProx(No<E> * aux);
    };

template <typename E>
Listaligada<E>::Listaligada(){
  cabeca = NULL;
}

template <typename E>
Listaligada<E>::~Listaligada(){
  delete cabeca;
}

template <typename E>
bool Listaligada<E>::vazia() const{
  return cabeca == NULL;
}

template <typename E>
const E& Listaligada<E>::inicio()const{
  return cabeca -> elem;
}

template <typename E>
const E& Listaligada<E>::fim()const{
  No<E>* cursor = cabeca;
  while(cursor-> prox !=NULL){
      cursor = cursor->prox;
    }
  return cursor -> elem;
}

template <typename E>
void Listaligada<E>::insereInicio(E const& e){
  No<E>*aux;
  aux = new No<E>();
  aux -> elem = e;
  aux -> prox = cabeca;
  cabeca = aux;
}

template <typename E>
void Listaligada<E>::insereFinal(E const& e){
  if(!vazia()){
    No<E>* aux;
    aux = new No<E>();
    aux -> elem = e;
    aux -> prox = NULL;

    No<E>* cursor = cabeca;
    while(cursor -> prox !=NULL){
      cursor = cursor->prox;
      }
    cursor -> prox = aux;
    }
  else
    insereInicio(e);
    cout<<endl;
}

template <typename E>
void Listaligada<E>::removeInicio(){
  if(!vazia()){
    No<E>*aux = cabeca;
    cabeca = cabeca -> prox;
    delete aux;
  }
}

template <typename E>
void Listaligada<E>::removeFim(){
  if(!vazia()){
    No<E>* cursor = cabeca;
    if (cursor -> prox !=NULL){ 
      while((cursor->prox) -> prox != NULL){
        cursor = cursor->prox;
      }
      No<E>* next = cursor -> prox;
      cursor -> prox = NULL;
      delete next;
  
    }
    else
      removeInicio();
  }
}

template <typename E>
  void Listaligada<E>::inverte(){
  if(!vazia()){
    int count = 0;
    No<E>* cursor = cabeca->prox;
    while(cursor != NULL){
      insereInicio(cursor ->elem);
      cursor = cursor -> prox;
      count++;
    }
    for(int i = 0; i<count; i++){
      removeFim();
    }
  }


  }
   /*
    No<E>* cursor = cabeca->prox;
    int x = cabeca -> elem;
    while(cursor->prox!=NULL){
      E a = cursor->elem;
      insereInicio(a);
      cursor = cursor->prox;
    }
    removeFim();
    removeFim();
  }
    
     int elem = fim();
    removeFim();
    while (fim() != x){
      insereFinal(inicio());
      removeInicio();*/



  

template <typename E>
  void Listaligada<E>::operator+(Listaligada<E>*x){
  No<E>* aux = cabeca;
  while(aux ->prox != NULL){
    aux = aux ->prox;
  }
  aux -> prox = x->cabeca;
}


template<typename E>
void Listaligada<E>::show(){
  No<E>* cursor = cabeca;
  while (cursor!=NULL){
    cout<<cursor -> elem<<" ";
    cursor = cursor -> prox;
  }
}

template <typename E>
No<E>* Listaligada<E>::getCabeca(){
  return cabeca;
}

template <typename E>
No<E>* Listaligada<E>::getProx(No<E> * aux){
  return aux->prox;
}


#endif