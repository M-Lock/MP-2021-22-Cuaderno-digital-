#include "materias.h"

//Postcondición:Crea un conjunto de estructuras alumno a partir del fichero
void volcado_entrada_mat(materia ** v_materias, int * n_materias)
{
	FILE *fichero;
	int len;
    char linea[60]; //guardamos una linea del fichero antes de tratarla (130 es el tamaño maximo que puede alcanzar una linea)
    char *token=NULL; //Nos permitirá dividir la cadena en segmentos

    *v_materias=NULL;
    *n_materias=0;
    
    fichero = fopen("Materias.txt","r");
     
     if (fichero == NULL)
	 {
	 	puts("Error al abrir el fichero:se encuentra vacio o no existe");
	 }
	 else
	 {
	 	do{
	 		if ( ((fgets(linea,60,fichero) ) != (NULL) ))
			 {     
            
                *v_materias=realloc((materia *)(*v_materias),((*n_materias)+1)*sizeof(materia));

				len=strlen(linea);
                linea[len - 1] = '\0'; // Eliminamos el retorno de la cadena del fichero de texto
              
               //partimos la cadena en segmentos para poder almacenarla
			    token=strtok(linea,"-");
			    if(token == NULL) break;
                strcpy((*v_materias)[*n_materias].id_materia,token);
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
                strcpy((*v_materias)[*n_materias].nombre_materia,token);
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
            	strcpy((*v_materias)[*n_materias].abrev_materia,token);
		    (*n_materias)++;
            
        }
		 }while (!(feof(fichero))); //Realizamos la conversion mientras nos queden lineas en el fichero
		 fclose (fichero);
	 }
}
//Postcondición: Añade la materia con los valores recibidos de la entrada estandar
void dar_alta_mat(materia* v_materias,int n_materias,char  id[])
{
	
}
//Precondición: Recibe la Id de la materia a borrar
//Postcondición: Elimina los datos correspondientes a dicha materia
void dar_baja_mat(materia* v_materias,int n_materias,char id [])
{
	for (int i = 0; i < n_materias;i++)
	{
		if (strcmp(id,v_materias[i].id_materia) == 0)
		{
			
			strcpy(v_materias[i].id_materia,"000000");
			i = n_materias;	//si hemos encontrado la materia, salimos del bucle		
		}
	}
}
//Precondición: Recibe la Id de la materia a modificar
//Postcondición: Modifica los datos correspondientes a dicha materia
void modif_mat(materia* v_materias,int n_materias,char id [])
{
		int mod;
	for (int i = 0; i < n_materias;i++)
	{
		if (strcmp(id,v_materias[i].id_materia) == 0)
		{
			printf("¿Que desea modificar?\n 1.Nombre alumno\n 2.direccion\n 3.localidad\n4.curso\n 5.grupo ");
			scanf("%d", &mod);
			switch(mod)
			{
				case (1): ;//se pedira por pantalla y se modificará si es valido.
				char nombre_nuevo [51];
					do
					{	
						printf("Introduzca el nuevo nombre, maximo 50 caracteres (pulse intro para finalizar):");
						scanf("%s",nombre_nuevo);
						if (strlen(nombre_nuevo) > 50) printf("El nombre no es valido");
						else strcpy(v_materias[i].nombre_materia,nombre_nuevo);
					} while (strlen(nombre_nuevo) > 50);
					
				case(2): ;
				char abrev_nuevo [4];
					do
					{
						printf("Introduzca la abreviatura, maximo 3 caracteres (pulse intro para finalizar):");
						scanf("%s",abrev_nuevo);
						if (strlen(abrev_nuevo) > 4) printf("La abreviatura no es valida");
						else strcpy(v_materias[i].abrev_materia,abrev_nuevo);
					} while (strlen(abrev_nuevo) > 4);
			}	
		}
	}
}
//Postcondicion: Muestra los nombres completos de los alumnos dados de alta
void listar_mat(materia* v_materias,int n_materias)
{
	if (n_materias > 0)
	{
		for (int i = 0; i < n_materias;i++)
		{
			printf("%s %s %s \n",v_materias[i].id_materia,v_materias[i].nombre_materia,v_materias[i].abrev_materia);
		}
	}
}
//Postcondición: Sobreescribe el fichero con los datos correspondientes al as estruccturas del programa
void volcar_fichero_mat(materia* v_materias)
{
	
}
