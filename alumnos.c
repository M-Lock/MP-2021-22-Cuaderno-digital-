#include "alumnos.h"

//Postcondición:Crea un conjunto de estructuras alumno a partir del fichero
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
//Postcondición: Añade al alumno con los valores recibidos de la entrada estandar
void dar_alta_alum(alumno* v_alumnos,int n_alumnos)
{
	
}
//Precondición: Recibe la Id del alumno a borrar (la id debe encontrarse en la tabla mostrada y ser mayor que 000000)
//Postcondición: Elimina los datos correspondientes a dicho alumno
void dar_baja_alum(alumno* v_alumnos,int n_alumnos,char id [])
{
	for (int i = 0; i < n_alumnos;i++)
	{
		if (strcmp(id,v_alumnos[i].id_alum) == 0)
		{
			
			strcpy(v_alumnos[i].id_alum,"000000");
			i = n_alumnos;			
		}
	}
}
//Precondición: Recibe la Id del alumno a modificar (la id debe encontrarse en la tabla mostrada y ser mayor que 000000)
//Postcondición: Modifica los datos seleccionados correspondientes a dicho alumno
void modif_alum(alumno* v_alumnos,int n_alumnos, char id [])
{
	int mod;
	for (int i = 0; i < n_alumnos;i++)
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
						else strcpy(v_alumnos[i].local_alum,nombre_nuevo);
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
						else strcpy(v_alumnos[i].grupo,nombre_nuevo);
					} while (strlen(grupo_nuevo) > 10);
			}	
		}
	}
}
//Postcondicion: Muestra los nombres completos de los alumnos dados de alta;
void listar_alum(alumno* v_alumnos,int n_alumnos)
{
	 if (n_alumnos > 0)
	 {
	 	for(int i = 0; i < n_alumnos;i++)
		 {
		 	printf("%s %s %s %s %s %s",v_alumnos[i].id_alum,v_alumnos[i].nombre_alum,v_alumnos[i].direc_alum,v_alumnos[i].local_alum,v_alumnos[i].curso,v_alumnos[i].grupo);
		 }
	 }
}
//Postcondición: Sobreescribe el fichero con los datos correspondientes a las estruccturas del programa
void volcado_fichero_alum(alumno* v_alumnos)
{
	
}
