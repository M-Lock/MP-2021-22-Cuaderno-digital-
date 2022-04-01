#include "menus.h"
#include <stdio.h>
#include "calificaciones_matricula.h"

int main(){
    //inicio_cuaderno();
    introducir_Calificaciones(&cali,&num_lin_Calificaciones.lon);
    imprimir_nota(cali,"342312","0001");
 	volcar_Calificaciones(cali);
    return 0;
}

