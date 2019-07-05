//
// Created by utec on 21/06/19.
//

#include <string>
#include <iomanip>
#include <map>
#include <algorithm>
#include <cmath>
#include "Objeto.h"
#include "Tierra.h"


map<char, sf::Color> listaColores = {
        {'R', sf::Color::Red},
        {'G', sf::Color::Green},
        {'B', sf::Color::Blue}};


using namespace std;

Tierra::Tierra() : altura{}, ancho{} {
    plano = nullptr;
}

Tierra::Tierra(TipoEntero altura, TipoEntero ancho) : altura{altura}, ancho{ancho} {
    plano = new sf::RenderWindow();
}

Tierra::~Tierra() {
    delete plano;
}

void Tierra::adicionarObjeto(Objeto *objeto) {
    objetos.emplace_back(objeto);
}

Objeto *Tierra::removerObjeto(string &nombre) {
// Si vector esta vacio
    if (objetos.size() == 0)
        return nullptr;
// Buscando objeto
    auto iter = find_if(begin(objetos), end(objetos),
                        [&nombre](Objeto *obj) { return obj->getNombre() == nombre; });
    if (iter != end(objetos)) {
// Eliminando la referencia al puntero objeto dentro del vector objetos
        objetos.erase(iter);
//-- si encuentra al objeto lo separa del vector,
//-- (no libera de memoria el objeto encontrado), esto se hará en el menú,
//-- donde fue asignado, debido a que el objeto no es parte sino el objeto es un visitante.
        return *iter;
    }
// Si vector esta vacio
    return nullptr;
}


//Objeto* Tierra::buscarObjeto(string& nombre){
//    if (objetos.size()<4){
//        cout << "Deben de haber 4 o mas objetos\n\n";
//        return nullptr;
//    }
//    if (objetos.size() == 0){
//        return nullptr;
//    }
//    return *iter;
//}
//
//double Tierra::cantidadObjetosClase(){
//    for (auto& item: objetos){auto i = 0;}
//
//}
//
//Objeto* Tierra::buscarTipo(){
//    if (objetos.size() <4){
//        return nullptr;
//    }
//    else{
//        return nullptr;
//    }
////    return *iter;
//}



void Tierra::imprimirObjetos() {
    int i = 0;
    for (auto &item: objetos) {
        cout << "* * * * * * [" << i << "] ";
        cout << " Nombre = " << item->getNombre() << " "
             << item->mostrarPosicion()
             << " Color = " << item->getColor() << '\n';
        i++;
    }
}

void Tierra::actualizarTierra() {
    plano->clear();
    for (auto obj: objetos) {
        sf::CircleShape shape(10);
        shape.setPosition(static_cast<float>(obj->getPosX()), static_cast<float>(obj->getPosY()));
        shape.setFillColor(listaColores[obj->getColor()]);
        plano->draw(shape);
    }
    plano->display();
}

void Tierra::dibujarTierra() {

    // Verifica si plano ha sido creado anteriormente
    if (!plano->isOpen())
        plano->create(sf::VideoMode(ancho, altura), "Proyecto Final - Presione [ESC] para salir... ");
    else
        plano->display();

    // Bucle principal
    while (plano->isOpen()) {
        capturarEventos();
        actualizarTierra();
    }
}

void Tierra::encontrar(TipoEntero x, TipoEntero y) {
    map<Raices , TipoString> elMapa;
    TipoEntero i=0, top=0;
    TipoString nombre;
    Raices raiz;
    for (auto& item: objetos){
        nombre = item->getNombre();
        auto a = x - item->getPosX();
        auto b = y - item->getPosY();
        raiz = sqrt((a*a) + (b*b));
        cout<< "xd" << " ";
        cout<< nombre << " " << raiz <<endl;
        auto raiz = upper_bound(begin(elMapa), end(elMapa), nombre);
        elMapa.insert(raiz, nombre);
    }

}


//void Tierra::ubicarObjetos(Objeto* nombre){
//
//    int i=0;
//    for (auto& item: objetos){
//        auto lx = xBuscado - item->getPosX();
//        auto ly = yBuscado - item->getPosY();
//        auto l = sqrt((lx*lx) + (ly*ly));
//        if (l == 0 || item->getNombre()==nombre->getNombre()){
//            l = 0;
//        } else if (a==0){
//            a = l;
//            primerObjeto = item->getNombre();
//        } else if (b==0){
//            b = l;
//            segundoObjeto = item->getNombre();
//        } else if (c==0){
//            c = l;
//            tercerObjeto = item->getNombre();
//        } else if (l<a || l<b || l<c){
//            if (a-l>b-l && a-l>c-l){
//                a = l;
//                primerObjeto = item->getNombre();
//            } else if (b-l>a-l && b-l>c-l){
//                b = l;
//                segundoObjeto = item->getNombre();
//            } else if (c-l>b-l && c-l>a-l){
//                c = l;
//                tercerObjeto = item->getNombre();
//            }
//        }
//        i++;
//    }
//
//}


//void Tierra::get3mejoresTipo(TipoCaracter tipoBuscar) {
//
//    for (auto &item: objetos) {
//        if (item->getTipo() == tipoBuscar) {
//            auto evaluar = item->getCalificacion();
//            if (valorC1 == 0) {
//                valorC1 = evaluar;
//                objeto1 = item;
//            } else if (valorC2 == 0) {
//                valorC2 = evaluar;
//                objeto2 = item;
//            } else if (valorC3 == 0) {
//                valorC3 = evaluar;
//                objeto3 = item;
//            } else if (evaluar > valorC1 || evaluar > valorC2 || evaluar > valorC3) {
//                if (valorC3 < valorC2 && valorC3 < valorC1) {
//                    valorC3 = evaluar;
//                    objeto3 = item;
//                } else if (valorC2 < valorC3 && valorC2 < valorC1) {
//                    valorC2 = evaluar;
//                    objeto2 = item;
//                } else if (valorC1 < valorC2 && valorC1 < valorC3) {
//                    valorC1 = evaluar;
//                    objeto1 = item;
//                }
//            }
//        }
//    }
//}
//

//void Tierra::get3mejoresTotal(){
//
//        auto evaluar = item->getCalificacion();
//        if (valorC1 == 0){
//            valorC1 = evaluar;
//            objeto1 = item;
//        } else if (valorC2==0){
//            valorC2 = evaluar;
//            objeto2 = item;
//        } else if (valorC3==0){
//            valorC3 = evaluar;
//            objeto3 = item;
//        } else if (evaluar>valorC1 || evaluar>valorC2 || evaluar>valorC3){
//            if (valorC3<valorC2 && valorC3<valorC1){
//                valorC3 = evaluar;
//                objeto3 = item;
//            } else if (valorC2<valorC3 && valorC2<valorC1){
//                valorC2 = evaluar;
//                objeto2 = item;
//            } else if (valorC1<valorC2 && valorC1<valorC3){
//                valorC1 = evaluar;
//                objeto1 = item;
//            }
//        }
//}


TipoEntero Tierra::getAltura() {
    return (altura);
}

TipoEntero Tierra::getAncho() {
    return (ancho);
}

TipoEntero Tierra::getCantidadObjectos() {
    return (objetos.size());
}

void Tierra::capturarEventos() {
    sf::Event event{};

    while (plano->pollEvent(event)) {

        switch (event.type) {
            case sf::Event::Closed:
                plano->close();
                break;
            case sf::Event::KeyPressed:
                if (event.key.code == sf::Keyboard::Escape)
                    plano->close();
                break;
        }
    }
}
