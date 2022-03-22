//Implementaci�n m�dulo Usuarios

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Usuarios.h"


//Cabecera: void volcarUsuarios(tipo_Usuario **, int *);
//Precondicion: Se ponen de entrada el vector de usuarios y el numero de usuarios por referencia
//Postcondicion: Vuelca la informacion del fichero Usuarios.txt a estructuras del programa
void cargarUsuarios(tipo_Usuario **vUsuarios, int *n){
	
	FILE *fichero;
	int len;
    char linea[57];             // Guardar cada linea que leamos del fichero.
    char *token=NULL;
    
    *vUsuarios=NULL;			//Inicializa a 0 el vector de tipo_usuario
    *n=0;						//Inicializa a 0 el contador de usuarios
    
    
    //Abrimos el fichero y comprobamos que lo hace correctamente
	fichero = fopen ("Usuarios.txt", "r");
	if (fichero==NULL) {
		printf("ERROR al abrir el fichero...\n");
	 	exit(2);
	}	
	
	do{ 
            if ( ((fgets(linea,57,fichero) ) != (NULL) )){     
            
                *vUsuarios=realloc((tipo_Usuario *)(*vUsuarios),((*n)+1)*sizeof(tipo_Usuario));		//Reservamos memoria dinamica por cada linea (usuario) que lea
				
				len=strlen(linea);
                linea[len - 1] = '\0'; // Eliminamos el retorno de la cadena del fichero de texto
              
               
			    token=strtok(linea,"-");
			    if (token==NULL) break;
				
        
                if (token!= NULL ) {
                	strcpy((*vUsuarios)[*n].id,token);
				}
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
 				
                if (token!= NULL ) {
                	strcpy((*vUsuarios)[*n].nombre,token);
				}
				
				token=strtok(NULL,"-");
				if (token==NULL) break;
 
				if (token!= NULL) {
                	strcpy((*vUsuarios)[*n].perfil,token);
				}

				token=strtok(NULL,"-");
				if (token==NULL) break;
				
				if (token!= NULL ) {
                	strcpy((*vUsuarios)[*n].usuario,token);
				}

				token=strtok(NULL,"-");
				if (token==NULL) break;
			
				if (token!= NULL ) {
            	strcpy((*vUsuarios)[*n].contrasenna,token);
				}
		  
		    	(*n)++;
            
        	}
            

        }while(!feof(fichero));
 
    fclose(fichero);

}


//Cabecera: void volcarUsuarios(tipo_Usuario *vUsuarios, size_t tam);
//Precondicion: Recibe un vector de usuarios igual o modificado y el numero de usuarios
//Postcondicion: Vuelca en el fichero Usuarios.txt las nuevas modificaciones en los usuarios
void volcarUsuarios(tipo_Usuario *vU, size_t tam){
	FILE *f;
	int i;
	
	//Escribe en el fichero toda la lista de usuarios
	f = fopen ("Usuarios.txt", "w+");
	
	i = 0;
	
	if (f == NULL) puts ("\tNo se ha podido modificar el fichero");
	else{
		while (i < tam-1){
			fprintf(f, "%s-%s-%s-%s-%s\n", vU[i].id, vU[i].nombre, vU[i].perfil, vU[i].usuario, vU[i].contrasenna);
			
			i++;
		}
	}
	fprintf (f, "%s-%s-%s-%s-%s\n", vU[i].id, vU[i].nombre, vU[i].perfil, vU[i].usuario, vU[i].contrasenna);
	
	puts ("\tSe han volcado los usuarios correctamente.");
	
	fclose (f);
	
	system("pause");
}


//Cabecera: void mostrar_vUsuarios (tipo_Usuario *, int);
//Precondicion: vector de tipo_usuario declarado y entero con el numero de usuarios
//Postcondicion: muestra los usuarios por pantalla
void listarUsuarios (tipo_Usuario *vUsuarios, int n) {
	int i;

    if( n == 0)
        printf("\tNo tienes usuarios registrados \n");
    else
        for(i=0;i<n;i++){
            printf("%d) %s-%s-%s-%s-%s\n", i+1, vUsuarios[i].id, vUsuarios[i].nombre, vUsuarios[i].perfil, vUsuarios[i].usuario, vUsuarios[i].contrasenna);
            fflush(stdin);
        }
}


//Cabecera:void altaUsuario(tipo_Usuario **vUsuarios,int *nUsuarios)
//Precondicion: Recibe el vector de usuarios y el numero de estos.
//Postcondicion: Da de alta un usuario
void altaUsuario(tipo_Usuario **vUsuarios,int *nUsuarios){

    int n,i = 0;
    int u = -1;
    int repetido = 0;

    *vUsuarios=realloc((tipo_Usuario *)(*vUsuarios),((*nUsuarios)+1)*sizeof(tipo_Usuario));

	do {
		repetido=0;
		puts("\tIntroduzca el id del usuario (3 cifras maximo):");
    	fflush(stdin);
    	printf("\t");
   		scanf("%3s",(*vUsuarios)[*nUsuarios].id);

	for(i=0; i<*nUsuarios; i++){

            if(strcmp((*vUsuarios)[i].id,(*vUsuarios)[*nUsuarios].id )==0){

                u=i;
                if (i != *nUsuarios) { repetido = 1;}
				break;
            }
        }

    	if(repetido == 1){

            puts("\tERROR: El  id de usuario seleccionado ya esta registrado introduzca otro \n "); 
		   
		}
            
    } while ( repetido == 1) ;
    
    puts("\tIntroduzca el nombre completo del usuario (20 caracteres maximo):");
    fflush(stdin);
    printf("\t");
    fflush(stdin);
    fgets ((*vUsuarios)[*nUsuarios].nombre, 21, stdin);
    cambio_linea ((*vUsuarios)[*nUsuarios].nombre);

    while(n<1 || n>2){


        puts("\t\tSeleccione el perfil del usuario:");
        puts("\t\t\t1) Administrador");
        puts("\t\t\t2) Profesor");
        fflush(stdin);
        printf("\t");
        scanf("%d",&n);

        switch(n){

            case 1:
                strcpy((*vUsuarios)[*nUsuarios].perfil,"administrador");
                break;

            case 2:
                strcpy((*vUsuarios)[*nUsuarios].perfil,"profesor");
                break;

            default:
                puts("\tERROR: La opcion introducida no es valida");

        }

    }

    puts("\tIntroduzca el login del usuario (5 caracteres maximo):");
    fflush(stdin);
    printf("\t");
    scanf("%5s",(*vUsuarios)[*nUsuarios].usuario);

    puts("\tIntroduzca la contrasena del usuario (8 caracteres maximo):");
    fflush(stdin);
    printf("\t");
    scanf("%8s",(*vUsuarios)[*nUsuarios].contrasenna);

    (*nUsuarios)++;

}


//cabecera:void bajaUsuario(tipo_usuario **vUsuarios,int *nUsuarios);
//precondicion: recibe el vector usuarios (vUsuarios) y el numero total de usuarios (nUsuarios).
//postcondicion: elimina el usuario indicado.
void bajaUsuario(tipo_Usuario **vUsuarios,int *nUsuarios){

    int i;
    int u = 0;
    char resp=' ';
    char id[4];

    puts("______________________________________________________________\n");
    puts("\tDAR DE BAJA A USUARIO");
    puts("______________________________________________________________\n");

    printf("\tIntroduzca el id del usuario a eliminar: ");
    printf("\t");
    scanf("%3s",id);

    for(i=0;i<(*nUsuarios);i++){

        if(strcmp((*vUsuarios)[i].id, id)==0){

            u=i;

        }

    }

    while(resp!='s' && resp!='n'){

        printf("\tSe va a eliminar el siguiente usuario: %s-%s-%s-%s-%s\n", (*vUsuarios)[u].id, (*vUsuarios)[u].nombre, (*vUsuarios)[u].perfil, (*vUsuarios)[u].usuario, (*vUsuarios)[u].contrasenna);
        printf("\tEstas seguro de eliminar el usuario? (s/n)\n");
        fflush(stdin);
        printf("\t");
        scanf("%c",&resp);

    }

    if(resp=='s'){

        for(i=u;i+1<(*nUsuarios);i++){

            strcpy((*vUsuarios)[i].id,(*vUsuarios)[i+1].id);
            strcpy((*vUsuarios)[i].nombre,(*vUsuarios)[i+1].nombre);
            strcpy((*vUsuarios)[i].perfil,(*vUsuarios)[i+1].perfil);
            strcpy((*vUsuarios)[i].usuario,(*vUsuarios)[i+1].usuario);
            strcpy((*vUsuarios)[i].contrasenna,(*vUsuarios)[i+1].contrasenna);

        }

        (*nUsuarios)--;

        *vUsuarios=realloc((tipo_Usuario *)(*vUsuarios),(*nUsuarios)*sizeof(tipo_Usuario));

    }else{

        printf("\tSe ha cancelado la eliminacion del usuario\n");

    }

}



void modificarUsuarios(){
	printf ("Estas en modificar usuario.\n");
}

void cambio_linea (char * nombre){
	if ((strlen(nombre) > 0) && (nombre[strlen(nombre) - 1] == '\n'))
    {
        nombre[strlen(nombre) - 1] = '\0';
    }
}

