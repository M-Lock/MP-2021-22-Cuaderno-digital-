//Implementación módulo Horarios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Horarios.h"

void cargarHorarios(tipo_Horario **vHorarios, int *n){
	
	FILE *fichero;
	int len;
    cha//Implementaci�n m�dulo Horarios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Horarios.h"

void cargarHorarios(tipo_Horario **vHorarios, int *n){
	
	FILE *fichero;
	int len;
    char linea[57];             // Guardar cada linea que leamos del fichero (57 como maximo)
    char *token=NULL;
    
    *vHorarios=NULL;		//Inicializamos a 0 el vector de tipo horario
    *n=0;					//Inicializamos a 0 el contador de horarios
    
    //Abrimos el fichero y comprobamos que lo haga correctamente.
	fichero = fopen ("Horarios.txt", "r");		
	if (fichero==NULL) {
		printf("ERROR al abrir el fichero...\n");
	 	exit(2);
	}	
	
	do{
			if ( (fgets(linea,44,fichero) ) != NULL) 
			{
                *vHorarios=realloc((tipo_Horario *)(*vHorarios),((*n)+1)*sizeof(tipo_Horario));		//Reservamos memoria dinamica por cada linea (horario) que lea

                token=strtok(linea,"-");
                if (token==NULL) break;
                

                strcpy((*vHorarios)[*n].id_prof,token);
                token=strtok(NULL,"-");
                if (token==NULL) break;
                
                (*vHorarios)[*n].dia_clase=atoi(token);
                token=strtok(NULL,"-");
                if (token==NULL) break;
                
               
                (*vHorarios)[*n].hora_clase=atoi(token);
                token=strtok(NULL,"-");
                if (token==NULL) break;
                
                
                strcpy((*vHorarios)[*n].id_materia,token);
                token=strtok(NULL,"-");
                if (token==NULL) break;
                
               
                strcpy((*vHorarios)[*n].grupo,token);
                

                (*n)++;

            }

        }while(!feof(fichero));
 
    fclose(fichero);

}

void volcarHorarios(tipo_Horario *vH, size_t tam) {
	FILE *f;
	int i;
	
	//Escribe en el fichero Horarios.txt toda la lista de Horarios
	f = fopen ("Horarios.txt", "w+");
	
	i = 0;
	
	if (f == NULL) puts ("\tNo se ha podido modificar el fichero");
	else {
		while (i < tam-1){
			
			fprintf(f, "%s-%d-%d-%s-%s\n", vH[i].id_prof, vH[i].dia_clase, vH[i].hora_clase, vH[i].id_materia, vH[i].grupo);
			i++;
		}
	}
	fprintf(f, "%s-%d-%d-%s-%s\n", vH[i].id_prof, vH[i].dia_clase, vH[i].hora_clase, vH[i].id_materia, vH[i].grupo);
	
	puts ("\tSe han guardado los horarios correctamente");
	
	system("pause");
}

//Mostrar por pantalla el vector
void listarHorarios (tipo_Horario *vHorarios, int n) {
	int i;

    if(n == 0)
        printf("\tNo tienes horarios registrados \n");
    else
        for(i=0;i<n;i++){
            printf("%d) %s-%d-%d-%s-%s", i+1, vHorarios[i].id_prof, vHorarios[i].dia_clase, vHorarios[i].hora_clase, vHorarios[i].id_materia, vHorarios[i].grupo);
        }
}

void annadirHoras(){
	printf("Estas en annadir horas.\n");
}
void eliminarHoras(){
	printf("Estas en eliminar horas.\n");
}
void modificarHoras(){
	printf("Estas en modificar horas.\n");
}

r linea[57];             // Guardar cada linea que leamos del fichero (57 como maximo)
    char *token=NULL;
    
    *vHorarios=NULL;		//Inicializamos a 0 el vector de tipo horario
    *n=0;					//Inicializamos a 0 el contador de horarios
    
    //Abrimos el fichero y comprobamos que lo haga correctamente.
	fichero = fopen ("Horarios.txt", "r");		
	if (fichero==NULL) {
		printf("ERROR al abrir el fichero...\n");
	 	exit(2);
	}	
	
	do{
			if ( (fgets(linea,44,fichero) ) != NULL) 
			{
                *vHorarios=realloc((tipo_Horario *)(*vHorarios),((*n)+1)*sizeof(tipo_Horario));		//Reservamos memoria dinamica por cada linea (horario) que lea

                token=strtok(linea,"-");
                if (token==NULL) break;
                

                strcpy((*vHorarios)[*n].id_prof,token);
                token=strtok(NULL,"-");
                if (token==NULL) break;
                
                (*vHorarios)[*n].dia_clase=atoi(token);
                token=strtok(NULL,"-");
                if (token==NULL) break;
                
               
                (*vHorarios)[*n].hora_clase=atoi(token);
                token=strtok(NULL,"-");
                if (token==NULL) break;
                
                
                strcpy((*vHorarios)[*n].id_materia,token);
                token=strtok(NULL,"-");
                if (token==NULL) break;
                
               
                strcpy((*vHorarios)[*n].grupo,token);
                

                (*n)++;

            }

        }while(!feof(fichero));
 
    fclose(fichero);

}


//Mostrar por pantalla el vector
void listarHorarios (tipo_Horario *vHorarios, int n) {
	int i;

    if(n == 0)
        printf("\tNo tienes horarios registrados \n");
    else
        for(i=0;i<n;i++){
            printf("%d) %s-%d-%d-%s-%s", i+1, vHorarios[i].id_prof, vHorarios[i].dia_clase, vHorarios[i].hora_clase, vHorarios[i].id_materia, vHorarios[i].grupo);
        }
}

void annadirHoras(){
	printf("Estas en annadir horas.\n");
}
void eliminarHoras(){
	printf("Estas en eliminar horas.\n");
}
void modificarHoras(){
	printf("Estas en modificar horas.\n");
}

