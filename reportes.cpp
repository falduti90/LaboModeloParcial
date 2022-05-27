#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
#include "rlutil.h"
using namespace rlutil;
#include "reportes.h"
#include "estudiante.h"
#include "examen.h"
#include "fecha.h"
#include "funciones.h"
#include "Becas2022.h"

void menu_reportes()
{
    int opcion;
    while(true)
    {
        rlutil::setColor(rlutil::WHITE);
        rlutil::setBackgroundColor(rlutil::DARKGREY);
        rlutil::cls();
        cout << "Menú Reportes" << endl;
        cout << "--------------------------" << endl;
        cout << "1 - Reporte 1" << endl;
        cout << "2 - Reporte 2" << endl;
        cout << "3 - Reporte 3" << endl;
        cout << "--------------------------" << endl;
        cout << "0 - Salir del programa" << endl << endl;

        cout << "Opción: ";
        cin >> opcion;

        rlutil::cls();
        switch(opcion)
        {
        case 1:
            reporte_1();
            break;
        case 2:
            reporte_2();
            break;
        case 3:
            reporte_3();
            //ListadoBecas2020();
            break;
        case 0:
            return;
            break;
        }
        cin.ignore();
        rlutil::anykey();
    }
}


int ExamenesAprobado(int legajo, int anio)
{
    Examen reg;
    int pos = 0;
    int ContadorAprobados = 0;
    while (reg.LeerDeDisco(pos++))
    {
        if (reg.getLegajo() == legajo && reg.getFecha().getAnio() == anio && reg.getNota() > 6)
        {
            ContadorAprobados++;
        }
    }
    return ContadorAprobados;
}

void reporte_1()
{

    Estudiante reg;
    Fecha Anioactual;
    int pos = 0;
    while (reg.LeerDeDisco(pos++))
    {
        int examenes = 0;
        examenes = ExamenesAprobado(reg.getLegajo(), Anioactual.getAnio());
        if (examenes < 2)
        {
            cout << "Legajo :" << reg.getLegajo() << " ";
            cout << "Nombre : " << reg.getNombres() << "Apellido: " << reg.getApellidos()<<endl;
        }
    }


}

/**Listar legajo, apellidos y nombres de los estudiantes que hayan
rendido al menos un examen en todos los años (desde 2015 a la fecha)*/

bool ExamenesConsecutivos(int legajo, int desde, int actual)
{

    int memoria = actual - desde + 1;


    //pido memoria
    bool* vec = new bool[memoria];

    //pregunto si consiguio la misma
    if (vec == nullptr) return false;

    //pongo el vector en false
    for (int i = 0; i < memoria; i++)
    {
        vec[i] = false;
    }

    //recorremos el archivo de examenes
    Examen reg;
    int pos = 0;
    bool ok = true;
    while (reg.LeerDeDisco(pos++))
    {

        // declaro un int para guardar el año
        int anio = reg.getFecha().getAnio();
        int leg= reg.getLegajo();

        //pregunto si el legajo coincide y si el reg de examen se encuentra entre el año 2015
        // y el año actual.
        if (leg == legajo && anio >= desde && anio <= actual)
        {
            //si todo es verdadero , asigno true a la posicio del año del examen menos el anio
            //de donde empezamos a verificar(2015)
            vec[anio - desde] = true;
        }
    }

    //verificamos si tenemos alguna posicion en false, si es asi cambio el valor a la var ok.
    for (int i = 0; i < memoria; i++)
    {
        if (vec[i] == false)ok = false;
    }
    //eliminamos la memoria dinamica.
    delete vec;
    //retornamos el valor de ok.
    return ok;
}

void reporte_2()
{
    Estudiante reg;
    Fecha Anioactual;
    const int anioInicio = 2015;
    int pos = 0;
    while (reg.LeerDeDisco(pos++))
    {
        if (ExamenesConsecutivos(reg.getLegajo(), anioInicio, Anioactual.getAnio()))
        {
            cout << "Legajo :" << reg.getLegajo() << " ";
            cout << "Nombre : " << reg.getNombres() << "Apellido: " << reg.getApellidos()<<endl;
        }
    }
}
/**Generar un archivo llamado Becas2022.dat con los apellidos,
nombres y promedio general de aquellos estudiantes que hayan logrado un
promedio de 7.5 o más en el año 2022 y que no hayan desaprobado ningún
examen con nota menor a 3 en dicho año*/

float BuscarPromedio(int legajo);

void reporte_3()
{

    Estudiante reg;
    int pos=0;
    float MinPromedio=7.5;
    float promedio=0;
    Becas2022 aux;
    bool ok;

    while(reg.LeerDeDisco(pos++))
    {

        promedio=BuscarPromedio(reg.getLegajo());
        if(promedio>= MinPromedio){
            aux.setNombre(reg.getNombres());
            aux.setApellido(reg.getApellidos());
            aux.setPromedio(promedio);
            ok=aux.GuardarEnDisco();

        }


    }

}

float BuscarPromedio(int legajo)
{

    Examen reg;
    int pos=0;
    float promedio,AcumuladorDeNotas;
    promedio=AcumuladorDeNotas=0;
    int ContadorExamenes=0;
    bool bandera=true;

    // leemos registro a registro el archivo de examenes
    while(reg.LeerDeDisco(pos++))
    {

        if(reg.getLegajo()==legajo)
        {

            if(reg.getNota>=3 && reg.getFecha().getAnio()==2022 )
            {
                AcumuladorDeNotas+= reg.getNota();
                ContadorExamenes++;
            }
        }
        else{
            bandera=false;
            AcumuladorDeNotas=0;

        }

    }

    //calculamos el promedio y lo retornamos.
    if(bandera){ promedio= (float)AcumuladorDeNotas/(float)ContadorExamenes;}
    return promedio;



}
