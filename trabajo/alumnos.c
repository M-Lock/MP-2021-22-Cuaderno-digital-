#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "alumnos.h"
#include "calificaciones_matricula.h"


void volcado_entrada_alum(alumno **v_alumnos, int *n_alumnos)
{
	FILE *fichero;
	int len;
    char linea[131]; //guardamos una linea del fichero antes de tratarla (130 es el tamaño maximo que puede alcanzar una linea)
    char *token=NULL; //Nos permitirá dividir la cadena en segmentos

    *v_alumnos=NULL;
    *n_alumnos=0;
    
   fichero = fopen("Alumnos.txt", "r");
     if (fichero == NULL)
	 {
		printf("Error al abrir el fichero:se encuentra vacio o no existe");
		exit(2);
	 }	

	 	do{
	 		if ( (fgets(linea,131,fichero) ) != NULL)
			 {     
            
                *v_alumnos=realloc((alumno *)(*v_alumnos),((*n_alumnos)+1)*sizeof(alumno));
                
              
               //partimos la cadena en segmentos para poder almacenarla
			    token=strtok(linea,"-");
			   	if(token == NULL) break;
                strcpy((*v_alumnos)[*n_alumnos].id_alum,token);
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
                strcpy((*v_alumnos)[*n_alumnos].nombre_alum,token);
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
                strcpy((*v_alumnos)[*n_alumnos].direc_alum,token);
					
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
            	strcpy((*v_alumnos)[*n_alumnos].local_alum,token);

				token=strtok(NULL,"-");
				if (token==NULL) break;
            	strcpy((*v_alumnos)[*n_alumnos].curso,token);
					
				token=strtok(NULL,"-");
				if (token==NULL) break;
            	 strcpy((*v_alumnos)[*n_alumnos].curso,token);
		  
		    (*n_alumnos)++;
            
        }
		 }while (!feof(fichero)); //Realizamos la conversion mientras nos queden lineas en el fichero
		 fclose (fichero);
}

void dar_alta_alum(alumno* v_alumnos,int * n_alumnos)
{
	bool flag = false;
	int i;
	for (i = 0; i < *n_alumnos;i++)
	{
		if(strcmp(v_alumnos[i].id_alum,"000000") == 0) //Si ha ocurrido un borrado, machacamos sus campos para añadir al nuevo alumno
		{
			if(i == 0) //Si el alumno previo era el primero, es un caso especial
			{
			strcpy(v_alumnos[i].id_alum,"000001");	
			}
			
			else  //Si no es el primero, realizamos el tratamiendo general a la id
			{
				int id = atoi(v_alumnos[i-1].id_alum);
				id++;
				sprintf(v_alumnos[i].id_alum,"%d",id);
			}
			
			char nombre_nuevo [21];
					do
					{	
						printf("Introduzca el nuevo nombre, maximo 20 caracteres (pulse intro para finalizar):");
						scanf("%s",nombre_nuevo);
						if (strlen(nombre_nuevo) > 20) printf("El nombre no es valido");
						else strcpy(v_alumnos[i].nombre_alum,nombre_nuevo);
					} while (strlen(nombre_nuevo) > 20);
					
			char direc_nuevo [31];
					do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",direc_nuevo);
						if (strlen(direc_nuevo) > 30) printf("La direccion no es valida");
						else strcpy(v_alumnos[i].direc_alum,direc_nuevo);
					} while (strlen(direc_nuevo) > 30);
					
			char local_nuevo [31];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",local_nuevo);
						if (strlen(local_nuevo) > 30) printf("El nombre no es valido");
						else strcpy(v_alumnos[i].local_alum,local_nuevo);
					} while (strlen(local_nuevo) > 30);	
					
			char curso_nuevo [31];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",curso_nuevo);
						if (strlen(curso_nuevo) > 30) printf("El nombre no es valido");
						else strcpy(v_alumnos[i].curso,curso_nuevo);
					} while (strlen(curso_nuevo) > 30);
					
			char grupo_nuevo [11];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 10 caracteres (pulse intro para finalizar):");
						scanf("%s",grupo_nuevo);
						if (strlen(grupo_nuevo) > 10) printf("El nombre no es valido");
						else strcpy(v_alumnos[i].grupo,grupo_nuevo);
					} while (strlen(grupo_nuevo) > 10);
					i = *n_alumnos; //Si hemos insertado en una posicion borrada (intermedia) no necesitamos recorrer el bucle
					flag = true;
		}
	}
	if( flag == false) //Si no hemos insertado en una posicion ya existente, debemos añadir una nueva posicion
	{
		v_alumnos=realloc((alumno *)(v_alumnos),((*n_alumnos)+1)*sizeof(alumno));
		int i = *n_alumnos;
		*n_alumnos+=1;
		int id = atoi(v_alumnos[i].id_alum);
		id++;
		sprintf(v_alumnos[i+1].id_alum,"%d",id);
		//Pasamos a añadir los valores restantes del nuevo alumno
			char nombre_nuevo [21];
					do
					{	
						printf("Introduzca el nuevo nombre, maximo 20 caracteres (pulse intro para finalizar):");
						scanf("%s",nombre_nuevo);
						if (strlen(nombre_nuevo) > 20) printf("El nombre no es valido");
						else strcpy(v_alumnos[i+1].nombre_alum,nombre_nuevo);
					} while (strlen(nombre_nuevo) > 20);
					
			char direc_nuevo [31];
					do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",direc_nuevo);
						if (strlen(direc_nuevo) > 30) printf("La direccion no es valida");
						else strcpy(v_alumnos[i+1].direc_alum,direc_nuevo);
					} while (strlen(direc_nuevo) > 30);
					
			char local_nuevo [31];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",local_nuevo);
						if (strlen(local_nuevo) > 30) printf("El nombre no es valido");
						else strcpy(v_alumnos[i+1].local_alum,local_nuevo);
					} while (strlen(local_nuevo) > 30);	
					
			char curso_nuevo [31];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",curso_nuevo);
						if (strlen(curso_nuevo) > 30) printf("El nombre no es valido");
						else strcpy(v_alumnos[i+1].curso,curso_nuevo);
					} while (strlen(curso_nuevo) > 30);
					
			char grupo_nuevo [11];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 10 caracteres (pulse intro para finalizar):");
						scanf("%s",grupo_nuevo);
						if (strlen(grupo_nuevo) > 10) printf("El nombre no es valido");
						else strcpy(v_alumnos[i+1].grupo,grupo_nuevo);
					} while (strlen(grupo_nuevo) > 10);
	}
	
}

void dar_baja_alum(alumno* v_alumnos,int n_alumnos,char id [])
{
	bool flag_borrado = false;
	int i;
	for (i = 0; i < n_alumnos;i++)
	{
		if (strcmp(id,v_alumnos[i].id_alum) == 0)
		{
			
			strcpy(v_alumnos[i].id_alum,"000000");
			i = n_alumnos;		
			flag_borrado = true;	
		}
	}
	if(flag_borrado == true)
	{
		eliminar_matriculas_alumno(&matri,id,&num_lin_Matriculas.lon);
		eliminar_calificaciones_alumnos(&cali,id,&num_lin_Calificaciones.lon);
	}
}

void modif_alum(alumno* v_alumnos,int n_alumnos, char id [])
{
	int mod,i;
	for (i = 0; i < n_alumnos;i++)
	{
		if (strcmp(id,v_alumnos[i].id_alum) == 0)
		{
			printf("¿Que desea modificar?\n 1.Nombre alumno\n 2.direccion\n 3.localidad\n4.curso\n 5.grupo ");
			scanf("%d", &mod);
			switch(mod)
			{
				case (1): ;//se pedira por pantalla y se modificará si es valido.
				char nombre_nuevo [21];
					do
					{	
						printf("Introduzca el nuevo nombre, maximo 20 caracteres (pulse intro para finalizar):");
						scanf("%s",nombre_nuevo);
						if (strlen(nombre_nuevo) > 20) printf("El nombre no es valido");
						else strcpy(v_alumnos[i].nombre_alum,nombre_nuevo);
					} while (strlen(nombre_nuevo) > 20);
					
				case(2): ;
				char direc_nuevo [31];
					do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",direc_nuevo);
						if (strlen(direc_nuevo) > 30) printf("La direccion no es valida");
						else strcpy(v_alumnos[i].direc_alum,direc_nuevo);
					} while (strlen(direc_nuevo) > 30);
				
				case(3): ;
				char local_nuevo [31];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",local_nuevo);
						if (strlen(local_nuevo) > 30) printf("El nombre no es valido");
						else strcpy(v_alumnos[i].local_alum,local_nuevo);
					} while (strlen(local_nuevo) > 30);	
					
				case(4): ;	
				char curso_nuevo [31];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 30 caracteres (pulse intro para finalizar):");
						scanf("%s",curso_nuevo);
						if (strlen(curso_nuevo) > 30) printf("El nombre no es valido");
						else strcpy(v_alumnos[i].curso,curso_nuevo);
					} while (strlen(curso_nuevo) > 30);
					
				case(5): ;
				char grupo_nuevo [11];
				do
					{
						printf("Introduzca el nuevo nombre, maximo 10 caracteres (pulse intro para finalizar):");
						scanf("%s",grupo_nuevo);
						if (strlen(grupo_nuevo) > 10) printf("El nombre no es valido");
						else strcpy(v_alumnos[i].grupo,grupo_nuevo);
					} while (strlen(grupo_nuevo) > 10);
			}	
		}
	}
}

void listar_alum(alumno* v_alumnos,int n_alumnos)
{
	int i;
	 if (n_alumnos > 0)
	 {
	 	for(i = 0; i < n_alumnos;i++)
		 {
		 	printf("%s %s %s %s %s %s",v_alumnos[i].id_alum,v_alumnos[i].nombre_alum,v_alumnos[i].direc_alum,v_alumnos[i].local_alum,v_alumnos[i].curso,v_alumnos[i].grupo);
			fflush(stdin); 
		 }
	 }
}

void volcado_fichero_alum(alumno* v_alumnos,size_t tam)
{
	FILE *f;
	int i;
	
	//Escribe en el fichero toda la lista de usuarios
	f = fopen ("Alumnos.txt", "w+");
	
	i = 0;
	
	if (f == NULL) puts ("\tNo se ha podido modificar el fichero");
	else{
		while (i < tam-1){
			fprintf(f, "%s-%s-%s-%s-%s-%s\n", v_alumnos[i].id_alum, v_alumnos[i].nombre_alum, v_alumnos[i].direc_alum, v_alumnos[i].local_alum, v_alumnos[i].curso,v_alumnos[i].grupo);
			
			i++;
		}
	}
	fprintf (f, "%s-%s-%s-%s-%s-%s\n", v_alumnos[i].id_alum, v_alumnos[i].nombre_alum, v_alumnos[i].direc_alum, v_alumnos[i].local_alum, v_alumnos[i].curso,v_alumnos[i].grupo);
	
	puts ("\tSe han volcado los usuarios correctamente.");
	
	fclose (f);
	
	system("pause");
}

