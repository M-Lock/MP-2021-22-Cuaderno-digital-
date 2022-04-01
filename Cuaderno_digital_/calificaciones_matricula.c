#include "calificaciones_matricula.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int comparar(char*,char*,int);
void copiar_cad(char[],char[],int);
void adelantar_Matriculas(Matriculas **,int);
void adelantar_Calificaciones(Calificaciones **,int);
int longitud_cadena(char*);

//Cabezera: void introducir_Matriculas(Matriculas **matri, int *n)
//Precondición: Las estructuras han de estar definidas
//Postcondición: Introduce los datos del ficheor de matriculas en una estructura de datos
void introducir_Matriculas(Matriculas **matri, int *n){
    FILE *Matricula;
    int len;
    char linea[14];
    char *token=NULL;
    (*n)=0;
    *matri=NULL;
    Matricula = fopen("Matriculas.txt","r");
    if(Matricula == NULL){
        printf("ERROR al abrir el fichero.\n");
        exit(1);
    }
    do{
        if(((fgets(linea,57,Matricula)) != (NULL))){
            *matri=realloc((Matriculas *)(*matri),((*n)+1)*sizeof(Matriculas));
            len=strlen(linea);
            linea[len-1]='\0';
            token=strtok(linea,"-");
            if(token==NULL){
                break;
            }
            if(token!=NULL){
                strcpy((*matri)[*n].Id_materia,token);
            }
            token=strtok(NULL,"-");
            if(token==NULL){
                break;
            }
            strcpy((*matri)[*n].Id_alum,token);
            (*n)++;
        }
    }while(!feof(Matricula));
    fclose(Matricula);
}


//Cabezera: void introducir_Calificaciones(Calificaciones **cali, int *n)
//Precondición: Las estructuras han de estar definidas
//Postcondición: Introduce los datos del fichero de matriculas en una estructura de datos
void introducir_Calificaciones(Calificaciones **cali,int *n){
	FILE *Calificacione;
	int len;
	char linea[57];
	char *token=NULL;
	*cali=NULL;
	*n=0;
	Calificacione = fopen("Calificaciones.txt","r");
	if(Calificacione == NULL){
		printf("No se ha podido abrir el fichero de calificaciones. \n");
		exit(1);
	}
	do{
		if(((fgets(linea,57,Calificacione)) != (NULL))){
			*cali = realloc((Calificaciones *)(*cali),((*n)+1) * sizeof(Calificaciones));
			len=strlen(linea);
			linea[len -1] = '\0';
			token = strtok(linea,"/");
			if(token == NULL) {
				break;
			}
			if(token != NULL){
				(*cali)[*n].Fecha_calif.dia = atoi(token);
			}
			token = strtok(linea,"/");
			if(token == NULL){
				break;
			}
			if(token != NULL){
				(*cali)[*n].Fecha_calif.mes = atoi(token);
			}
			token = strtok(linea,"/");
			if(token == NULL){
				break;
			}
			if(token != NULL){
				(*cali)[*n].Fecha_calif.anio = atoi(token);
			}
			token = strtok(linea,"-");
			if(token == NULL){
				break;
			}
			if(token != NULL){
				strcpy((*cali)[*n].Descrip_calif,token);
			}
			token = strtok(linea,"-");
			if(token == NULL){
				break;
			}
			if(token != NULL){
				strcpy((*cali)[*n].Id_materia,token);
			}
			token = strtok(linea,"-");
			if(token == NULL){
				break;
			}
			if(token != NULL){
				strcpy((*cali)[*n].Id_alum,token);
			}
			token = strtok(linea,"-");
			if(token == NULL){
				break;
			}
			if(token != NULL){
				(*cali)[*n].Valor_calif = atoi(token);
			}
			(*n)++;			
		}
	}while(!feof(Calificacione));
	fclose(Calificacione);
}

//Cabezera: void volcar_Matriculas(Matriculas *matri)
//Precondición: Tener las estructuras creados y con los datos almacenados
//Postcondición: Introduce los datos almacenados en las estructuras en el fichero de Matriculas
void volcar_Matriculas(Matriculas *matri){
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

//Cabezera: void volcar_Calificaciones(Calificaciones *cali)
//Precondición: Tener las estructuras creados y con los datos almacenados
//Postcondición: Introduce los datos almacenados en las estructuras en el fichero de Calificaciones
void volcar_Calificaciones(Calificaciones *cali){
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

//Cabezera: void materias_alum(Matriculas *matri, char* id_alum)//Falta imprimir el nombre de las asignaturas
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Devuelve las asignaturas en las que se encuentra matriculado un alumno
void materias_alum(Matriculas *matri,char* id_alum){
int i;
for(i=0;i<num_lin_Matriculas.lon;i++){
    if(comparar(id_alum,matri[i].Id_alum,6)==0){
        if(comparar(matri[i].Id_alum,id_alum,6)==0){
			//Función que según el id_materia devuleva el nombre de la materia
        }
    }
}
}

//Cabezera:void imprimir_nota(Calificaciones *cali, char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Imprime por pantalla las notas de una materia en concreto de un alumnos en concreto
void imprimir_nota(Calificaciones *cali, char* id_alum, char* id_materia){
	int i,cont;
	cont=0;
	for(i=0;i<num_lin_Calificaciones.lon;i++){
   		 if(comparar(cali[i].Id_alum,id_alum,6)==0){
        	if(comparar(cali[i].Id_materia,id_materia,4)==0){
        		printf("%s",cali[i].Valor_calif);
            	printf("La nota de la asignatura buscada es: %f \n",cali[i].Valor_calif);
            	cont=1;
        	}
    	}
	}
	if(i==num_lin_Calificaciones.lon && cont!=1){
   		printf("No se ha encontrado la calificación de la asignatura introducida. \n");
	}
}

//Cabezera: void modificar_nota(Calificaciones **cali, char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Modifica las notas de una asignatura de un alumno en concreto
void modificar_nota(Calificaciones **cali, char* id_alum, char* id_materia){
    int i,x;
    x=0;
    for(i=0;i<num_lin_Calificaciones.lon;i++){
        if(comparar((*cali)[i].Id_alum,id_alum,6)==0){
            if(comparar((*cali)[i].Id_materia,id_materia,4)==0){
                printf("Desea modificar la nota del examen denominado: %s", (*cali)[i].Descrip_calif);
                do{
                    printf("Si desea modificarla pulse '1' y si no desea eso pulse '0'.\n");
                    scanf("%i",&x);
                    if(x==0){
                        printf("introduce la nueva calificacion: ");
                        scanf("%f",&(*cali)[i].Valor_calif);
                    }
                }while(x!=0 || x!=1);
            }
        }
    }
}

//Cabezera: void eliminar_nota(Calificaciones **cali, char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Elimina una nota de una asignatura de un alumno en concreto
void eliminar_nota(Calificaciones **cali, char* id_alum, char* id_materia, int *n){
    int i,x;
    x=0;
    for(i=0;i<(*n);i++){
        if(comparar((*cali)[i].Id_alum,id_alum,6)==0){
            if(comparar((*cali)[i].Id_materia,id_materia,4)==0){
                printf("Desea eliminar la nota del examen denominado: %s", (*cali)[i].Descrip_calif);
                do{
                    printf("Si desea eliminarla pulse '1' y si no desea eso pulse '0'.\n");
                    scanf("%i",&x);
                    if(x==0){
                        adelantar_Calificaciones(cali,i);
                        *cali = realloc((Calificaciones *)(*cali),((*n)-1) * sizeof(Calificaciones));
                        (*n)--;
                    }
                }while(x!=0 || x!=1);
            }
        }
    }
}

//Cabezera: void anadir_nota(Calificaciones **cali, char* id_alum, char* id_materia) //terminar
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Añade una nueva nota de una asignatura a un alumno en concreto
void anadir_nota(Calificaciones **cali, char* id_alum, char* id_materia, int *n){ 
    int x,y;
    y=0;
    *cali = realloc((Calificaciones *)(*cali),((*n)+1) * sizeof(Calificaciones));
    do{
        printf("Introduce la descripcion del examen (Max 30 caracteres): ");
        fgets((*cali)[num_lin_Calificaciones.lon].Descrip_calif,32,stdin);
        printf("\n");
        x=longitud_cadena((*cali)[num_lin_Calificaciones.lon].Descrip_calif);
    }while(x>32);
    do{
        printf("Introduce el dia: ");
        scanf("%i",&(*cali)[(*n)].Fecha_calif.dia);
        printf("\n");
        printf("Introduce el mes: ");
        scanf("%i",&(*cali)[(*n)].Fecha_calif.mes);
        printf("\n");
        printf("Introduce el anio: ");
        scanf("%i",&(*cali)[(*n)].Fecha_calif.anio);
        printf("\n");
    }while(y==0);
    do{
        printf("Introduce una calificación:");
        scanf("%f",&(*cali)[(*n)].Valor_calif);
        printf("\n");
    }while(0<=((*cali)[(*n)].Valor_calif) && ((*cali)[(*n)].Valor_calif)<=10);
    (*n)++;
    printf("La nota se ha introducido correctamente. \n");
}

//Cabezera: void anadir_matricula(Matriculas **matri, char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Matricula a un alumno en una determinada asignatura
void anadir_matricula(Matriculas **matri,char* id_alum, char* id_materia, int *n){

    *matri = realloc((Matriculas *)(*matri),((*n)+1) * sizeof(Matriculas));
    strcpy((*matri)[(*n)].Id_alum,id_alum);
    strcpy((*matri)[(*n)].Id_materia,id_materia);
    (*n)++;
    printf("Se ha introducido la nueva matricula. \n");
}

//Cabezera: void borrar_matricula(Matriculas **matri, char* id_alum, char* id_materia)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Elimina la matricula de un alumno en una asignatura
void borrar_matricula(Matriculas **matri, char* id_alum, char* id_materia,int *n){
    int i;
    for(i=0;i<(*n);i++){
        if((comparar((*matri)[i].Id_alum,id_alum,6)==0) && (comparar((*matri)[i].Id_materia,id_materia,4)==0)){
            adelantar_Matriculas(matri,i);
            (*matri) = realloc((Matriculas *)(*matri),((*n)-1) * sizeof(Matriculas));
            (*n)--;
        }
    }
    printf("Se ha eliminado la matricula correctamente. \n");
}

//Cabezera: void modificar_matricula(Matricula **matri, char* id_alum, char* id_materia_vieja, char* id_materia_nueva)
//Precondición: Tener los valores pasados a la función con algún valor válido y no vacio
//Postcondición: Modifica la matricula de un alumno
void modificar_matricula(Matriculas **matri, char id_alum[8], char id_materia_vieja[6], char id_materia_nueva[6]){
    int i;
    for(i=0;i<num_lin_Matriculas.lon;i++){
        if((comparar((*matri)[i].Id_alum,id_alum,6)==0) && (comparar((*matri)[i].Id_materia,id_materia_vieja,4)==0)){
            strcpy((*matri)[i].Id_materia,id_materia_nueva);
        }
    }
    printf("Se ha cambiado la matricula exitosamente. \n");
}

//Cabezera: void eliminar_matricula_materia(Matriculas **matri, char* id_materia)
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Cuando se elimina una materia esta función borra todas las matriculas de dicha asignatura
void eliminar_matricula_materia(Matriculas **matri, char* id_materia, int *n){
    int i;
    for(i=0;i<(*n);i++){
        if(comparar((*matri)[i].Id_materia,id_materia,4)==0){
            adelantar_Matriculas(matri,i);
            (*matri) = realloc((Matriculas *)(*matri),((*n)-1) * sizeof(Matriculas));
            (*n)--;
        }
    }
    printf("Se han eliminado todas las matriculas correspondientes correctamente. \n");
}

//Cabezera: void eliminar_matriculas_alumno(Matriculas **matri, char* id_alum)
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Cuando se elimina a un alumno esta función elimina las matriculas que tenia realizadas
void eliminar_matriculas_alumno(Matriculas **matri, char* id_alum, int *n){
    int i;
    for(i=0;i<(*n);i++){
        if(comparar((*matri)[i].Id_alum,id_alum,6)==0){
            adelantar_Matriculas(matri,i);
            (*matri) = realloc((Matriculas *)(*matri),((*n)-1) * sizeof(Matriculas));
            (*n)--;
        }
    }
    printf("Se han eliminado todas las matriculas correpondientes correctamente. \n");
}

//Cabezera: void eliminar_calificaciones_materia(Calificaciones **cali, char* id_materia)
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Cuando se elimina una materia elimina todas la notas de dicha materia
void eliminar_calificaciones_materia(Calificaciones **cali, char* id_materia, int *n){
    int i;
    for(i=0;i<(*n);i++){
        if(comparar((*cali)[i].Id_materia,id_materia,4)==0){
            adelantar_Calificaciones(cali,i);
            (*cali) = realloc((Calificaciones *)(*cali),((*n)-1) * sizeof(Calificaciones));
            (*n)--;
        }
    }
    printf("Se han eliminado todas las matriculas correspondientes correctamente. \n");
}

//Cabezera: void eliminar_calificaciones_alumnos(Calificaciones **cali, char* id_alum)
//Precondición: Tener el valor pasado a la función con un valor válido y no vacio
//Postcondición: Cuando se elimina un alumno elimina todas las notas de dicho alumno
void eliminar_calificaciones_alumnos(Calificaciones **cali, char* id_alum, int *n){
    int i;
    for(i=0;i<(*n);i++){
        if(comparar((*cali)[i].Id_alum,id_alum,6)==0){
            adelantar_Calificaciones(cali,i);
            (*cali) = realloc((Calificaciones *)(*cali),((*n)+1) * sizeof(Calificaciones));
            (*n)--;
        }
    }
    printf("Se han eliminado todas las matriculas correpondientes correctamente. \n");
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

//Cabezera: void adelantar_Matriculas(Matriculas **matri, int n)
//Precondición: Tener la estructura de matriculas creada
//Postcondición:Adelanta una posición en la estructura a todos los elementos dentro de un rango para eliminar a uno de ellos de la estructura
void adelantar_Matriculas(Matriculas **matri, int n){
    int i;
    for(i=n;i<num_lin_Matriculas.lon-1;i++){
        strcpy((*matri)[i].Id_alum,(*matri)[i+1].Id_alum);
        strcpy((*matri)[i].Id_alum,(*matri)[i+1].Id_alum);
    }
}

//Cabezera: void adelantar_Calificaciones(Calificaciones **cali, int n)
//Precondición: Tener la estructura de Calificaciones creada
//Postcondición: Adelanta una posición en la estructura a todos los elementos dentro de un rango para eliminar a uno de ellos de la estructura
void adelantar_Calificaciones(Calificaciones **cali, int n){
    int i;
    for(i=n;i<num_lin_Calificaciones.lon;i++){
        (*cali)[i].Fecha_calif.dia=(*cali)[i+1].Fecha_calif.dia;
        (*cali)[i].Fecha_calif.mes=(*cali)[i+1].Fecha_calif.mes;
        (*cali)[i].Fecha_calif.anio=(*cali)[i].Fecha_calif.anio;
        strcpy((*cali)[i].Descrip_calif,(*cali)[i+1].Descrip_calif);
        strcpy((*cali)[i].Id_alum,(*cali)[i+1].Id_alum);
        strcpy((*cali)[i].Id_materia,(*cali)[i+1].Id_materia);
        (*cali)[i].Valor_calif=(*cali)[i+1].Valor_calif;
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

