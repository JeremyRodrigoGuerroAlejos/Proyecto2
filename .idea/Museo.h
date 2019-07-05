//
// Created by rodri on 4/7/2019.
//

#ifndef PROYECTOFINALPOO_MUSEO_H
#define PROYECTOFINALPOO_MUSEO_H

#include "Objeto.h"
#include "Tipos.h"

class Museo : public Objeto{
private:
    TipoString Exposicion;
public:
    Museo();
    Museo(const TipoString& nombre, TipoCaracter color,
          TipoEntero posX, TipoEntero posY, TipoCaracter tipo,
          TipoString& direccion, TipoEntero& calificacion,TipoString Exposicion);
    void setExposicion(TipoString Exposicion);
    TipoString getExposicion();
    virtual ~Museo(){};
};
#endif //PROYECTOFINALPOO_MUSEO_H

