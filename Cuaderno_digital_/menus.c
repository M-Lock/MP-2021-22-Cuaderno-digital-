#include <stdio.h>


void inicio_sesion();  //Necesito funciones de los demás
void obtener_datos(char*,char*);  //Funciona
int comparar_cad(char*,char*,int);  //Funciona
void menu_profesores(char*);  //Funciona
void menu_administrador();  //Funciona
void menu_usuaruios();  //Funciona
void menu_alumnos();  //Funciona
void menu_alumno_individual();  //Funciona
void menu_materias();  //Funciona
void menu_horarios();  //Funciona


//Cabezera: void inicio_cuaderno()
//Precondición: Ninguna
//Postcondición: Se encarga de iniciar el programa y de llamar a las funione necesarias para cargar los datos de los ficheros en las estructuras
void inicio_cuaderno(){
    int x,y;
    //LLama a funciones para almacenar datos de los ficheros en las estructuras
    printf("Hola, este es el cuaderno del profesor. \n");
    do{
        while(y<1 || y>2){
            printf("Pulse 1 para iniciar sesion en el pograma. \n");
            printf("Pulse 2 para salir del pograma. \n");
            scanf("%i",&y);
        }
        switch(y){
            case 1: inicio_sesion();break;
            case 2: x=1;
                    //Funcion que almacene los datos de las estructura en los ficheros
                    printf("Adios, gracias por usar el programa. \n");break;
        }
    }while(x==0);
}

//Cabezera void inicio_secion()
//Precondición: Tener ya almacenados los datos de los ficheros dentro de las estructuras
//Precondición: Iniciar sesión dentro de un perfil de Usuario
void inicio_sesion(){
    int i,j;
    i=0;
    j=0;
    char nom_usuario[7],contra[10];
    obtener_datos(nom_usuario,contra);
    do{
        //if(comparar_nom(nom_usuario,)==0 && comparar_con(contra,)){
            //menu_profesores();
        //}
        //i++;
        //if(i==(Lo largo de la estructurasde usuarios)){i=1;printf("El ususario introducido no existe");printf("Intentalo de nuevo");
    }while(i==0);
}

//Cabezera:void obtener_datos(char* nom,char* con)
//Precondición: Tener creadas las dos variables que se le pasan como parámetros a la funcición
//Postcondición: Permite introducir por teclado el nombre de usuario y la contraseña
void obtener_datos(char* nom,char* con){
    printf("Introduce el nombre de usuario.\n");
    printf("Ten en cuenta que el nombre de usuario son 5 caracteres.\n");
    fgets(nom,7,stdin);
    printf("Introduce la constraseña.\n");
    printf("Ten en cuenta que la contraseña son 8 caracteres.\n");
    fgets(con,10,stdin);
}

//Cabezera: int comparar_nom(char* nom1,char* nom2,int n)
//Precondición: Tener los valores de las dos cadenas no vacios
//Postcondición: Comparar si las dos cadenas son iguales
int comparar_cad(char* nom1,char* nom2,int n){
int i,j;
j=0;
for(i=0;i<n;i++){
    if(nom1[i]!=nom2[i]){
        j=1;
    }
}
return j;
}

//Cabezera: void menu_profesores()
//Precondición: Tener los datos necesarios almacenados en las estructuras y tener un id de profesor
//Postcondición: Te deja elegir las funciones que puede realizar un usuario profesor
void menu_profesores(char* prof){
    int x,y;
    printf("Hola, estas dentro del perfil del profesor.\n");
    printf("Seleccione un grupo de la lisa .\n");
    //Función para seleccionar el grupo de la lista dependiendo del profesor
    do{

    }while(x==0);
}

//Cabezera: void menu_administrador()
//Precondición: Tener los datos necesarios almacenados en las estructuras y tener un id de administrador
//Postcondición: Te deja elegir las funciones que puede realizar un usuario administrador
void menu_administrador(){
    int x,y;
    x=0;
    printf("Hola, estas dentro del perfil del administrador.\n");
    do{
        while(y<1 || y>5){
            printf("Introduce el numero de la opcion para entrar en dicha opcion.\n");
            printf("1- Usuarios.\n");
            printf("2- Alumnos.\n");
            printf("3- Materias.\n");
            printf("4- Horarios.\n");
            printf("5- Salir.\n");
            scanf("%i",&y);
        }
        switch(y){
            case 1: ;break;
            case 2: ;break;
            case 3: ;break;
            case 4: ;break;
            case 5: x=1;break;
        }
    }while(x==0);
}

//Cabezera: void menu_usuaruios()
//Precondición: Ninguna
//Postcondición: Entras en el menu de usuario para gestionar los datos de los usuarios
void menu_usuaruios(){
    int x,y;
    x=0;
    printf("Hola, estas dentro del menu de gestion de usuarios.\n");
    do{
        while(y<1 || y>5){
            printf("Introduce el numero de la opcion para entrar en dicha opcion.\n");
            printf("1- Dar de alta a un usuario.\n");
            printf("2- Dar de baja a un usuario.\n");
            printf("3- Modificar lista de usuarios.\n");
            printf("4- Listar usuarios.\n");
            printf("5- Salir.\n");
            scanf("%i",&y);
        }
        switch(y){
            case 1: ;break;
            case 2: ;break;
            case 3: ;break;
            case 4: ;break;
            case 5: x=1;break;
        }
    }while(x==0);
}

//Cabezera: void menu_alumnos()
//Precondición: Ninguna
//Postcondición: Entras en el menu de alumnos para gestionar los datos de los alumnos
void menu_alumnos(){
    int x,y;
    x=0;
    printf("Hola, estas dentro del menu de gestion de usuarios.\n");
    do{
        while(y<1 || y>6){
            printf("Introduce el numero de la opcion para entrar en dicha opcion.\n");
            printf("1- Dar de alta a un alumno.\n");
            printf("2- Dar de baja a un alumno.\n");
            printf("3- Modificar lista de alumnos.\n");
            printf("4- Listar alumnos.\n");
            printf("5- Seleccionar alumno");
            printf("6- Salir.\n");
            scanf("%i",&y);
        }
        switch(y){
            case 1: ;break;
            case 2: ;break;
            case 3: ;break;
            case 4: ;break;
            case 5: menu_alumno_individual();break;
            case 6: x=1;break;
        }
    }while(x==0);
}

//Cabezera: void menu_alumno_individual()
//Precondición: Ninguna
//Postcondición: Entras dentro de un menu donde te dan opciones para gestionar los datos de un alumno
void menu_alumno_individual(){
    int x,y,z;
    char* nom_alum;
    x=0;
    z=0;
    do{
        printf("Introduce el nombre de un alumno:");
        fgets(nom_alum,21,stdin);
        //función que compruebe que el alumnos existe y que devuelva 1 si existe
    }while(z==0);
    do{
            printf("Seleccione una de las siguientes opciones: \n");
        while(y<1 || y>6){
            printf("1- Lista de materias. \n");
            printf("2- Cambio de matricula. \n");
            printf("3- Eliminar matricula. \n");
            printf("4- Matricular de una asignatura");
            printf("5- Salir");
            scanf("%i",&y);
        }
         switch(y){
            case 1: ;break;
            case 2: ;break;
            case 3: ;break;
            case 4: ;break;
            case 5: x=1;break;
        }
    }while(x==0);
}

//Cabezera: void menu_materias()
//Precondición: Ninguna
//Postcondición: Entras en el menu de materias para gestionar los datos de las materias
void menu_materias(){
    int x,y;
    x=0;
    printf("Hola, estas dentro del menu de gestion de materias.\n");
    do{
        while(y<1 || y>5){
            printf("Introduce el numero de la opcion para entrar en dicha opcion.\n");
            printf("1- Dar de alta a una materia.\n");
            printf("2- Dar de baja a una materia.\n");
            printf("3- Modificar lista de materias.\n");
            printf("4- Eliminar una materia.\n");
            printf("5- Salir.\n");
            scanf("%i",&y);
        }
        switch(y){
            case 1: ;break;
            case 2: ;break;
            case 3: ;break;
            case 4: ;break;
            case 5: x=1;break;
        }
    }while(x==0);
}

//Cabezera : void menu_horarios()
//Precondición: Ninguna
//Postcondición: Entras en el menu de horarios para gestionar los datos de los horarios
void menu_horarios(){
    int x,y;
    x=0;
    printf("Hola, estas dentro del menu de gestion de horarios.\n");
    do{
        while(y<1 || y>5){
            printf("Introduce el numero de la opcion para entrar en dicha opcion.\n");
            printf("1- Anadir horas de clase.\n");
            printf("2- Eliminar horar de clase.\n");
            printf("3- Modificar horarios de clase.\n");
            printf("4- Listar horarios.\n");
            printf("5- Salir.\n");
            scanf("%i",&y);
        }
        switch(y){
            case 1: ;break;
            case 2: ;break;
            case 3: ;break;
            case 4: ;break;
            case 5: x=1;break;
        }
    }while(x==0);
}

