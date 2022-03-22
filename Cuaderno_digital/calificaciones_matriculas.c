#include "calificaciones_matriculas.h"
#include <stdio.h>
#include <stdlib.h>

int cal_linias_Matriculas();
int cal_linias_Calificaiones();
int comparar(char*,char*,int);
void copiar_cad(char[],char[],int);
void adelantar_Matriculas(int);
void adelantar_Calificaciones(int);
int longitud_cadena(char*);
void vaciar_cadena(char*);

//Cabezera: void introducir_Matriculas()
//Precondición: Las estructuras han de estar definidas
//Postcondición: Introduce los datos del ficheor de matriculas en una estructura de datos
void introducir_Matriculas(){
    int i,j,cont;
    char aux;
    FILE *Matricula;
    i=0;
    j=0;
    cont=0;
    Matricula=fopen("Matriculas.txt","r");
    if(Matricula==NULL){
        printf("No se ha podido abrir el fichero de Matriculas. \n");
        exit(1);
    }
    else{
        num_lin_Matriculas.lon = cal_linias_Matriculas();
        matri = (Matriculas*)malloc(num_lin_Matriculas.lon * sizeof(Matriculas));
        while(aux!=EOF){
            aux=getc(Matricula);
            if(cont==0 && aux!='-'){
                matri[j].Id_materia[i]=aux;
                i++;
            }
            if(cont==1 && aux!='-'){
                matri[j].Id_alum[i]=aux;
                i++;
            }
            if(aux=='-'){
                i=0;
                cont++;
            }
            if(aux=='\n'){
                i=0;
                cont=0;
                j++;
            }
        }
    }
    printf("%s-%s\n",matri[0].Id_alum,matri[0].Id_materia);
    printf("%s-%s\n",matri[1].Id_alum,matri[1].Id_materia);
    fclose(Matricula);
}


//Cabezera: void introducir_Calificaciones()
//Precondición: Las estructuras han de estar definidas
//Postcondición: Introduce los datos del fichero de matriculas en una estructura de datos
void introducir_Calificaciones(){
    int i,j,cont,cont_h;
    char aux;
    char nota[4],d[4],m[4],a[6];
    FILE *Calificacione;
    i=0;
    j=0;
    cont=0;
    cont_h=0;
    Calificacione=fopen("Calificaciones.txt","r");
    if(Calificacione==NULL){
        printf("No se ha podido abrir el fichero de Calificaciones. \n");
        exit(1);
    }
    else{
        num_lin_Calificaciones.lon = cal_linias_Calificaiones();
        cali = (Calificaciones*)malloc(num_lin_Calificaciones.lon * sizeof(Calificaciones));
        while(aux!=EOF){
            aux=getc(Calificacione);
            if(cont==0 && aux!='-'){
                if(cont_h==0 && aux!='/'){
                    d[i]=aux;
                    i++;
                }
                if(cont_h==1 && aux!='/'){
                    m[i]=aux;
                    i++;
                }
                if(cont_h==2 && aux!='/'){
                    a[i]=aux;
                    i++;
                }
            }
            if(cont==1 && aux!='-'){
                cali[j].Descrip_calif[i]=aux;
                i++;
            }
            if(cont==2 && aux!='-'){
                cali[j].Id_materia[i]=aux;
                i++;
            }
            if(cont==3 && aux!='-'){
                cali[j].Id_alum[i]=aux;
                i++;
            }
            if(cont==4 && aux!='-'){
                nota[i]=aux;
                i++;
            }
            if(aux=='-'){
                cont++;
                i=0;
            }
            if(aux=='/'){
                cont_h++;
                i=0;
            }
            if(aux=='\n'){
                cali[j].Valor_calif=atoi(nota);
                cali[j].Fecha_calif.dia=atoi(d);
                cali[j].Fecha_calif.mes=atoi(m);
                cali[j].Fecha_calif.anio=atoi(a);
                i=0;
                cont=0;
                cont_h=0;
                j++;
            }
        }
    }
    fclose(Calificacione);
}

//Cabezera: void volcar_Matriculas()
//Precondición: Tener las estructuras creados y con los datos almacenados
//Postcondición: Introduce los datos almacenados en las estructuras en el fichero de Matriculas
void volcar_Matriculas(){
int i=0;
FILE* Matricula;
Matricula=fopen("Matriculas.txt","w");
if(Matricula==NULL){
    printf("No se ha podido abrir el fichero de Matriculas. \n");
    exit(1);
}
else{
    while(i<num_lin_Matriculas.lon){
        fprintf(Matricula,"%s-%s\n",matri[i].Id_materia,matri[i].Id_alum);
        i++;
    }
}
fclose(Matricula);
}

//Cabezera: void volcar_Calificaciones()
//Precondición: Tener las estructuras creados y con los datos almacenados
//Postcondición: Introduce los datos almacenados en las estructuras en el fichero de Calificaciones
void volcar_Calificaciones(){
int i=0;
FILE* Calificacione;
Calificacione=fopen("Calificaciones.txt","w");
if(Calificacione==NULL){
    printf("No se ha podido abrir el fichero de Calificaciones. \n");
    exit(1);
}
else{
    while(i<num_lin_Calificaciones.lon){
        fprintf(Calificacione,"%i/%i/%i-%s-%s-%s-%f\n",cali[i].Fecha_calif.dia,cali[i].Fecha_calif.mes,cali[i].Fecha_calif.anio,cali[i].Descrip_calif,cali[i].Id_materia,cali[i].Id_alum,cali[i].Valor_calif);
        i++;
    }
}
fclose(Calificacione);
}

//Cabezera: int cal_linias_calificaciones()
//Precondición: Tener el fichero creado
//Postcondición: Calcular el número de líneas que tiene el fichero
int cal_linias_Calificaiones(){
    char aux;
    num_lin_Calificaciones.lon=0;
    FILE *Calificaciones;
    Calificaciones=fopen("Calificaciones.txt","r");
    if(Calificaciones==NULL){
        printf("Mo se ha podido abrir el archivo de Calificaciones. \n");
        exit(1);
    }
    else{
        while(aux!=EOF){
            aux=fgetc(Calificaciones);
            if(aux=='\n'){
                num_lin_Calificaciones.lon++;
            }
        }
    }
    fclose(Calificaciones);
    return num_lin_Calificaciones.lon;
}

//Cabezera: int cal_linias_matriculas()
//Precondición: Tener el fichero creado
//Postcondición: Calcular el número de líneas que tiene el fichero
int cal_linias_Matriculas(){
    char aux;
    num_lin_Matriculas.lon=0;
    FILE *Matriculas;
    Matriculas=fopen("Matriculas.txt","r");
    if(Matriculas==NULL){
        printf("No se ha podido abrir el fichero de Matriculas. \n");
        exit(1);
    }
    else{
        while(aux!=EOF){
            aux=fgetc(Matriculas);
            if(aux=='\n'){
                num_lin_Matriculas.lon++;
            }
        }
    }
    fclose(Matriculas);
    return num_lin_Matriculas.lon;
}

//Cabezera: void materias_alum(char* id_alum)//Falta imprimir el nombre de las asignaturas
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Devuelve las asignaturas en las que se encuentra matriculado un alumno
void materias_alum(char* id_alum){
int i;
for(i=0;i<num_lin_Matriculas.lon;i++){
    if(comparar(id_alum,matri[i].Id_alum,6)==0){
        if(comparar(matri[i].Id_alum,id_alum,6)==0){

        }
    }
}
}

//Cabezera:void imprimir_nota(char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Imprime por pantalla las notas de una materia en concreto de un alumnos en concreto
void imprimir_nota(char* id_alum, char* id_materia){
int i,cont;
cont=0;
for(i=0;i<num_lin_Calificaciones.lon;i++){
    if(comparar(cali[i].Id_alum,id_alum,6)==0){
        if(comparar(cali[i].Id_materia,id_materia,4)==0){
            printf("La nota de la asignatura buscada es: %f \n",cali[i].Valor_calif);
            cont=1;
        }
    }
}
if(i==num_lin_Calificaciones.lon && cont==1){
    printf("No se ha encontrado la calificación de la asignatura introducida. \n");
}
}

//Cabezera: void modificar_nota(char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Modifica las notas de una asignatura de un alumno en concreto
void modificar_nota(char* id_alum, char* id_materia){
int i,x;
for(i=0;i<num_lin_Calificaciones.lon;i++){
    if(comparar(cali[i].Id_alum,id_alum,6)==0){
        if(comparar(cali[i].Id_materia,id_materia,4)==0){
            printf("Desea modificar la nota de: %s .\n",cali[i].Descrip_calif);
            printf("Si desea cambiarla introduca '1' y  si no intoduzca '2'.\n");
            scanf("%i",&x);
            while(x!=1 || x!=2){
                printf("Introduce un valor adecuado.\n");
                scanf("%i",&x);
            }
            if(x==1){
                printf("Introduce la nueva nota: ");
                scanf("%f",&cali[i].Valor_calif);
            }
        }
    }
}
}

//Cabezera: void eliminar_nota(char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Elimina una nota de una asignatura de un alumno en concreto
void eliminar_nota(char* id_alum, char* id_materia){

}

//Cabezera: void anadir_nota(char* id_alum, char* id_materia) //terminar
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Añade una nueva nota de una asignatura a un alumno en concreto
void anadir_nota(char* id_alum, char* id_materia){
num_lin_Calificaciones.lon++;
cali=(Calificaciones*)realloc(cali,num_lin_Calificaciones.lon * sizeof(Calificaciones));
if(cali==NULL){
    printf("No se ha podido reservar memoria. \n");
    exit(1);
}
}

//Cabezera: void anadir_matricula(char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Matricula a un alumno en una determinada asignatura
void anadir_matricula(char* id_alum, char* id_materia){
num_lin_Matriculas.lon++;
matri=(Matriculas*)realloc(matri,num_lin_Matriculas.lon * sizeof(Matriculas));
if(matri==NULL){
    printf("No se ha podido reservar memoria. \n");
    exit(1);
}
copiar_cad(matri[num_lin_Matriculas.lon-1].Id_materia,id_materia,4);
copiar_cad(matri[num_lin_Matriculas.lon-1].Id_alum,id_alum,6);
}

//Cabezera: void borrar_matricula(char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Elimina la matricula de un alumno en una asignatura
void borrar_matricula(char* id_alum, char* id_materia){
    int i;
    for(i=0;i<num_lin_Matriculas.lon;i++){
        if(comparar(matri[i].Id_alum,id_alum,6)==0){
            if(comparar(matri[i].Id_materia,id_materia,4)==0){
                adelantar_Matriculas(i);
            }
        }
    }
    num_lin_Matriculas.lon--;
    matri = (Matriculas*)realloc(matri,num_lin_Matriculas.lon * sizeof(Matriculas));
}

//Cabezera: void modificar_matricula(char* id_alum, char* id_materia_vieja, char* id_materia_nueva)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Modifica la matricula de un alumno
void modificar_matricula(char id_alum[8], char id_materia_vieja[6], char id_materia_nueva[6]){
int i;
for(i=0;i<num_lin_Matriculas.lon;i++){
    if(comparar(matri[i].Id_alum,id_alum,6)==0){
        if(comparar(matri[i].Id_materia,id_materia_vieja,4)==0){
            copiar_cad(matri[i].Id_materia,id_materia_nueva,6);
            printf("Se ha realizado el cambio de matrícula correctamente. \n");
            i=num_lin_Matriculas.lon;
        }
    }
}
}

//Cabezera: void eliminar_matricula_materia(char* id_materia)
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Cuando se elimina una materia esta función borra de las matriculas dicha asignatura
void eliminar_matricula_materia(char* id_materia){
    int i;
    for(i=0;i<num_lin_Matriculas.lon;i++){
        if(comparar(matri[i].Id_materia,id_materia,4)==0){
            adelantar_Matriculas(i);
            num_lin_Matriculas.lon--;
            matri = (Matriculas*)realloc(matri,num_lin_Matriculas.lon * sizeof(Matriculas));
        }
    }
}

//Cabezera: void eliminar_matriculas_alumno(char* id_alum)
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Cuando se elimina a un alumno esta función elimina las matriculas que tenia realizadas
void eliminar_matriculas_alumno(char* id_alum){
int i;
for(i=0;i<num_lin_Matriculas.lon;i++){
    if(comparar(matri[i].Id_alum,id_alum,6)){
        adelantar_Matriculas(i);
        num_lin_Matriculas.lon--;
        matri = (Matriculas*)realloc(matri,num_lin_Matriculas.lon * sizeof(Matriculas));
    }
}
}

//Cabezera: void eliminar_calificaciones_materia(char* id_materia)
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Cuando se elimina una materia elimina todas la notas de dicha materia
void eliminar_calificaciones_materia(char* id_materia){
int i;
for(i=0;i<num_lin_Calificaciones.lon;i++){
    if(comparar(cali[i].Id_materia,id_materia,4)){
        adelantar_Calificaciones(i);
        num_lin_Calificaciones.lon--;
        cali = (Calificaciones*)realloc(cali,num_lin_Calificaciones.lon * sizeof(Calificaciones));
    }
}
}

//Cabezera: void eliminar_calificaciones_alumnos(char* id_alum)
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Cuando se elimina un alumno elimina todas las notas de dicho alumno
void eliminar_calificaciones_alumnos(char* id_alum){
    int i;
    for(i=0;i<num_lin_Calificaciones.lon;i++){
        if(comparar(cali[i].Id_alum,id_alum,6)==0){
            adelantar_Calificaciones(i);
            num_lin_Calificaciones.lon--;
            cali = (Calificaciones*)realloc(cali,num_lin_Calificaciones.lon * sizeof(Calificaciones));
        }
    }
}

//Cabezera: int comparar(char* nom1,char* nom2,int n)
//Precondición: Tener los valores de las dos cadenas no vacios
//Postcondición: Comparar si las dos cadenas son iguales
int comparar(char* nom1,char* nom2,int n){
int i,j;
j=0;
for(i=0;i<n;i++){
    if(nom1[i]!=nom2[i]){
        j=1;
    }
}
return j;
}

//Cabezera: void copiar_cad(char cad1[] ,char cad2[])
//Precondición: Las dos cadenas tienen que tener la misma longitud
//Postcondición: Copiar el contenido de una cadena a otra
void copiar_cad(char cad1[] ,char cad2[], int n){
int i;
for(i=0;i<n;i++){
    cad1[i]=cad2[i];
}
}

//Cabezera: void adelantar_Matriculas(int n)
//Precondición: Tener la estructura de matriculas creada
//Postcondición:Adelanta una posición en la estructura a todos los elementos dentro de un rango para eliminar a uno de ellos de la estructura
void adelantar_Matriculas(int n){
    int i;
    for(i=n;i<num_lin_Matriculas.lon-1;i++){
        copiar_cad(matri[i].Id_alum,matri[i+1].Id_alum,6);
        copiar_cad(matri[i].Id_materia,matri[i+1].Id_materia,4);
    }
}

//Cabezera: void adelantar_Calificaciones(int n)
//Precondición: Tener la estructura de Calificaciones creada
//Postcondición: Adelanta una posición en la estructura a todos los elementos dentro de un rango para eliminar a uno de ellos de la estructura
void adelantar_Calificaciones(int n){ //Terminar
    int i;
    for(i=n;i<num_lin_Calificaciones.lon;i++){
        cali[i].Fecha_calif.dia=cali[i+1].Fecha_calif.dia;
        cali[i].Fecha_calif.mes=cali[i+1].Fecha_calif.mes;
        cali[i].Fecha_calif.anio=cali[i].Fecha_calif.anio;
        copiar_cad(cali[i].Descrip_calif,cali[i+1].Descrip_calif,30);
        copiar_cad(cali[i].Id_alum,cali[i+1].Id_alum,6);
        copiar_cad(cali[i].Id_materia,cali[i+1].Id_materia,4);
        cali[i].Valor_calif=cali[i+1].Valor_calif;
    }
}

//Cabezera: int longitud_cadena(char* cad)
//Precondición: Ninguna
//Postcondición: Devuelve el número de cacteres que tiene una cadena
int longitud_cadena(char* cad){
    int i=0;
    while(cad[i]!='\0'){
        i++;
    }
    return i;
}

//Cabezera: void vaciar_cadena(char* cad)
//Precondición: Ninguna
//Postcondición: Vacia una cadena
void vaciar_cadena(char* cad){

}
