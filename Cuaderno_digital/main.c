#include "menus.h"
#include <stdio.h>
#include "calificaciones_matriculas.h"

int main(){
    //inicio_cuaderno();
    int *n;
    introducir_Matriculas(&matri,n);

    volcar_Calificaciones(&matri);
    return 0;
}
