//
// Created by utec on 21/06/19.
//

#ifndef GAME_TIERRA_H
#define GAME_TIERRA_H

#include <iostream>
#include <vector>
#include "Tipos.h"
#include "Objeto.h"
#include <SFML/Graphics.hpp>

using namespace std;

// Valores constantes
const TipoEntero ALTURA = 21;
const TipoEntero ANCHO  = 21;
const TipoCaracter COLOR ='.';

class Tierra {
private:
    int altura;
    int ancho;
    sf::RenderWindow* plano;
    vector<Objeto*> objetos;
    void capturarEventos();
public:
    void actualizarTierra();
    Tierra();
    Tierra(TipoEntero altura, TipoEntero ancho);
    virtual ~Tierra();
    void adicionarObjeto(Objeto* objeto);
    Objeto* removerObjeto(string& nombre);
    void imprimirObjetos();
    TipoEntero getAltura();
    TipoEntero getAncho();
    TipoEntero getCantidadObjectos();
    void dibujarTierra();
    void encontrar(TipoEntero x, TipoEntero y);
    void Ubicar3max();
    void UbicarMejoresTipos();
    void imprimir();
};


#endif

