//
// Created by utec on 21/06/19.
//

#include "Tierra.h"
#include "Menu.h"
#include <iostream>
#include <string>
#include <cstdio>


using namespace std;
enum class Opciones {
    Agregar = 1, Remover , Mostrar, buscar, MejoresTotal, MejoresTipo};
 // se usa un tipo enumerado para indicar las opciones


/*
 ********************
 *
 * Funciones de Ayuda
 *
 ********************
 */

void limpiar() {
#ifndef WIN32
    cout << "\033[2J\033[0;0H";
#else
    system("cls");
#endif
}

void esperar() {
    TipoCaracter w;
    do {
        w = input<TipoCaracter>("Presione C y Enter para continuar...");
    } while (toupper(w) != 'C');
}

/*
 ******************************
 *
 * Metodos de clase Menu
 *
 ******************************
 */

Menu::Menu(int altura, int ancho): tierra(altura, ancho), opcion{} {}

void Menu::agregarObjeto() {
    auto i = 1;
    while (i==1){
        auto tipo = input<TipoCaracter>("Ingrese caracter de objeto (R=Restaurante, H=Hotel, M=Museo): ");
        if (tipo == 'R'){
                auto nombre = input<TipoString>("Ingrese Nombre de Restaurante: ");
                cout<<"Los Restaurantes son rojos"<<endl;
                auto x = input<TipoEntero>("Ingrese posicion X : ");
                while (x < 0 || x >= tierra.getAncho()) {
                    cout << "Posicion X Incorrecta, los limites son: 0, "
                    << tierra.getAncho() - 1 << "\n";
                    x = input<TipoEntero>("Ingrese posicion X : ");
                }
                auto y = input<TipoEntero>("Ingrese posicion Y : ");
                while (y < 0 || y >= tierra.getAncho()) {
                    cout  << "Posicion Y Incorrecta, los limites son: 0, "
                    << tierra.getAltura() - 1 << "\n";
                    y = input<TipoEntero>("Ingrese posicion Y : ");
                }
                auto direccion = input<TipoString>("Ingrese Direccion : ");
                auto calificacion = input<TipoEntero>("Ingrese Calificacion : ");
                auto TipodeComida = input<TipoString>("Ingrese Tipo de Comida : ");
                auto Especialidaddia = input<TipoString>("Ingrese Especialidad del dia : ");
                tierra.adicionarObjeto(new Restaurant(nombre,'R',x,y,tipo,direccion,calificacion,
                        TipodeComida,Especialidaddia));
                i--;
        } else if (tipo=='M'){
            auto nombre = input<TipoString>("Ingrese Nombre de Museo: ");
            cout<<"Los Museos son verdes"<<endl;
            auto x = input<TipoEntero>("Ingrese posicion X : ");
            while (x < 0 || x >= tierra.getAncho()) {
                cout << "Posicion X Incorrecta, los limites son: 0, "
                     << tierra.getAncho() - 1 << "\n";
                x = input<TipoEntero>("Ingrese posicion X : ");
            }
            auto y = input<TipoEntero>("Ingrese posicion Y : ");
            while (y < 0 || y >= tierra.getAncho()) {
                cout  << "Posicion Y Incorrecta, los limites son: 0, "
                      << tierra.getAltura() - 1 << "\n";
                y = input<TipoEntero>("Ingrese posicion Y : ");
            }
            auto direccion = input<TipoString>("Ingrese Direccion : ");
            auto calificacion = input<TipoEntero>("Ingrese Calificacion : ");
            auto Exposicion = input<TipoString >("Ingrese Exposicion : ");
            tierra.adicionarObjeto(new Museo(nombre,'G',x,y,tipo,direccion,calificacion, Exposicion));
            i--;
        } else if (tipo=='H'){
            auto nombre = input<TipoString>("Ingrese Nombre de Hotel: ");
            cout<<"Los Hoteles son azules"<<endl;
            auto x = input<TipoEntero>("Ingrese posicion X : ");
            while (x < 0 || x >= tierra.getAncho()) {
                cout << "Posicion X Incorrecta, los limites son: 0, "
                     << tierra.getAncho() - 1 << "\n";
                x = input<TipoEntero>("Ingrese posicion X : ");
            }
            auto y = input<TipoEntero>("Ingrese posicion Y : ");
            while (y < 0 || y >= tierra.getAncho()) {
                cout  << "Posicion Y Incorrecta, los limites son: 0, "
                      << tierra.getAltura() - 1 << "\n";
                y = input<TipoEntero>("Ingrese posicion Y : ");
            }
            auto direccion = input<TipoString>("Ingrese Direccion : ");
            auto calificacion = input<TipoEntero>("Ingrese Calificacion : ");
            auto Estrellas = input<TipoEntero>("Ingrese Estrellas : ");
            auto Disponibilidad = input<TipoString >("Ingrese Disponibilidad : ");
            tierra.adicionarObjeto(new Hotel(nombre,'B',x,y,tipo,direccion,calificacion,
                    Estrellas,Disponibilidad));
            i--;
        }
    }
}

void Menu::removerObjeto() {
    auto nombre = input<TipoString>("Ingrese Nombre: ");
    auto obj = tierra.removerObjeto(nombre);  //-- separa el objeto de la tierra
    if (obj == nullptr) {
        cout << "Objeto No existe\n";
    }
    else {
        delete obj;
        cout << "Objeto: " << nombre << " ha sido removido\n";
    }
    esperar();
}

void Menu::dibujarMapa() {
    limpiar();
    tierra.actualizarTierra();
    tierra.dibujarTierra();
    cout << '\n';
    tierra.imprimirObjetos();
    cout << '\n';
    esperar();
}



void Menu::mostrarMenu() {
    limpiar();
    cout << "Menu\n";
    cout << string(4, '-') << "\n\n";
    cout << "1. Agregar un nuevo objeto\n";
    cout << "2. Remover objeto\n";
    cout << "3. Dibujar Mapa\n";
    cout << "4. Buscar 3 objetos más cercanos\n";
    cout << "5. Mostrar top 3 Hoteles, Restaurantes o Museos\n";
    cout << "6. Mostrar top 3 de establecimientos\n\n";
    cout << "0. Para Salir\n\n";
}


void Menu::seleccionarOpcion() {
    limpiar();
    switch(Opciones(opcion)) {
        case Opciones::Agregar:  // Agregar Objeto
            agregarObjeto();
            break;
        case Opciones::Remover:  // Remover Objeto
            removerObjeto();
            break;
        case  Opciones::Mostrar: // Dibujando Tierra
            dibujarMapa();
            break;
        case Opciones::buscar: //buscar Objetos cercanos
            buscar();
            break;
        case Opciones ::MejoresTipo://buscar Mejores de cada Tipo
            MejoresTipo();
            break;
        case Opciones ::MejoresTotal://buscar los Maximo
            MejoresTotal();
            break;
    }
}

void Menu::ejecutar() {
    do {
        mostrarMenu();
        cin >> opcion;
        seleccionarOpcion();
    } while (opcion != 0);
    cout << "Fin del programa...\n";
}

void Menu::buscar(){
    cout<<"Ingrese coordenadas a buscar"<<endl;
    auto x = input<TipoEntero>("Posicion X a buscar: ");
    while (x < 0 || x >= tierra.getAncho()) {
        cout << "Posicion X Incorrecta, los limites son: 0, "
             << tierra.getAncho() - 1 << "\n";
        x = input<TipoEntero>("Ingrese posicion X : ");
    }
    auto y = input<TipoEntero>("Posicion Y a buscar: ");
    while (y < 0 || y >= tierra.getAncho()) {
        cout  << "Posicion Y Incorrecta, los limites son: 0, "
              << tierra.getAltura() - 1 << "\n";
        y = input<TipoEntero>("Ingrese posicion Y : ");
    }
    tierra.encontrar(x,y);
}

void Menu::MejoresTipo() {
    tierra.UbicarMejoresTipos();
}

void Menu::MejoresTotal() {
    tierra.Ubicar3max();
}