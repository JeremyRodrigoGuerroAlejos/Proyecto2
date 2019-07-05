//
// Created by rodri on 4/7/2019.
//

#include "Restaurant.h"

Restaurant::Restaurant(): TipodeComida{}, Especialidaddia{}{}

Restaurant::Restaurant(const TipoString& nombre, TipoCaracter color,
                       TipoEntero posX, TipoEntero posY, TipoCaracter tipo,
                       TipoString& direccion, TipoEntero& calificacion, TipoString TipodeComida,
                       TipoString Especialidaddia): Objeto(nombre,color,posX,posY,tipo,direccion,calificacion){
    this->Especialidaddia=Especialidaddia;
    this->TipodeComida=TipodeComida;
}


void Restaurant::setEspecialidad(TipoString Especialidad) { this->Especialidaddia=Especialidaddia;}

void Restaurant:: setTipode(TipoString TipodeComida) { this->TipodeComida=TipodeComida;}


TipoString Restaurant::getEspe() { return(Especialidaddia);}

TipoString Restaurant::getTipode(){return(TipodeComida);}