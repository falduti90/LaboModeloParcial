#include <iostream>
using namespace std;
#include "funciones.h"
#include "rlutil.h"
#include "Becas2022.h"

void mostrarMensaje(string mensaje, int color, int colorFondo, int x, int y){
    rlutil::locate(x, y);
    rlutil::setColor(color);
    rlutil::setBackgroundColor(colorFondo);
    cout << mensaje;
    rlutil::resetColor();
}

void ListadoBecas2020(){

    Becas2022 reg;
    int pos=0;

    while(reg.LeerDeDisco(pos++)){
        cout<<"Nombre: "<< reg.getNombre()<< "-"<< "Apellido: "<< reg.getApellido()<< "-"<< "Promedio: "<< reg.getPromedio()<<endl;

    }


}
