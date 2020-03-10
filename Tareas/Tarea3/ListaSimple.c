#include <stdio.h>
#include <stdlib.h> //sugerencia del compilador
#include <string.h>

typedef struct _agenda {

    int id;
    float height;
    char dir[50];
    char nombre[20];
    char telefono[12];
    struct _agenda *siguiente;

}_agenda; //definicion del tipo de dato _agenda

struct _agenda *primero, *ultimo;


void mostrar_menu() {

    printf("\n\nMenú:\n=====\n\n");
    printf("1.- Añadir elementos\n");
    printf("2.- Mostrar lista\n");
    printf("3.- Consultar Registro\n");
    printf("4.- Consultar Nombre\n");
    printf("5.- Eliminar Registro\n");
    printf("6.- Salir\n\n");
    printf("Escoge una opción: ");

    fflush(stdout);
}

/* Con esta función añadimos un elemento al final de la lista */
void anadir_elemento() {

    struct _agenda *nuevo;

    /* reservamos memoria para el nuevo elemento */
    nuevo = ( _agenda *) malloc (sizeof( _agenda));

    if (nuevo==NULL){
        printf( "No hay memoria disponible!\n");
        return; // se le agrega return a la validacion porque sino se cae el programa en caso de no haber memoria
    }

    printf("\nNuevo elemento:\n");

    printf("Altura: ");
    scanf("%f", &nuevo->height);
    while ((getchar()) != '\n');

    printf("Direccion: ");
    fgets(nuevo->dir,50,stdin);
    for (int i = 0; i < 50; i++){
        if(nuevo->dir[i] == '\n'){
            nuevo->dir[i] = '\000';
        }
    }


    printf("Nombre: ");
    fflush(stdout);
    scanf("%s", nuevo->nombre); // cambio de gets() a fgets() por sugerencia del compilador
    while ((getchar()) != '\n');

    printf("Teléfono: ");
    fflush(stdout);
    scanf("%s", nuevo->telefono); // cambio de gets() a fgets() por sugerencia del compilador
    while ((getchar()) != '\n');

    /* el campo siguiente va a ser NULL por ser el último
    elemento de la lista */
    nuevo->siguiente = NULL;

    /* ahora metemos el nuevo elemento en la lista. lo situamos
    al final de la lista, se comprueba si la lista está vacía.
    si primero==NULL es que no hay ningún elemento en la lista.
    también vale ultimo==NULL */
    if (primero==NULL) {

    printf( "Primer elemento\n");
    nuevo->id = 0;
    primero = nuevo;
    ultimo = nuevo;

    }
    else {

    /* el hasta ahora último apuntará al nuevo */
    nuevo->id = ultimo->id+1;
    ultimo->siguiente = nuevo;

    /* hacemos que el nuevo sea ahora el último */
    ultimo = nuevo;

    }

}
void organizarRegistros(){

    _agenda *aux = primero;
    int registro = 0;

    while(aux!= NULL) {
        aux->id = registro;
        registro++;
        aux = aux->siguiente;
    }
}

void EliminarElemento(){

    int registro;
    printf("Ingrese el nummero de registro a eliminar: ");
    scanf("%d", &registro);
    while((getchar()) != '\n');

    _agenda *aux1 = primero;


    while(aux1 != NULL){
        if(registro == primero->id && registro == ultimo->id){

            free(primero);
            free(ultimo);
            primero = NULL;
            ultimo = NULL;

        }

        else if (registro == ultimo->id){
            free(ultimo);
            aux1->siguiente = NULL;
            ultimo = aux1;
            break;
        }
        else if(aux1->siguiente->id == registro){
            _agenda *borrar = aux1->siguiente;
            aux1->siguiente = borrar->siguiente;
            free(borrar);
            organizarRegistros();
            break;
        }
        else if(registro == primero->id){
            _agenda *borrar = primero;
            primero = aux1->siguiente;
            free(borrar);
            organizarRegistros();
            break;
        }

        aux1 = aux1->siguiente;

    };

}

void mostrar_lista() {

    struct _agenda *auxiliar; /* para recorrer la lista */

    int i; i=0;
    auxiliar = primero;

    printf("\nMostrando la lista completa:\n");

    while (auxiliar!=NULL) {
        printf("------------------------\n");
        printf( "Nombre: %s\nTelefono: %s\nAltura: %f\nDireccion: %s\nID: %d\n",
        auxiliar->nombre, auxiliar->telefono, auxiliar->height, auxiliar->dir, auxiliar->id);
        printf("------------------------\n");
        auxiliar = auxiliar->siguiente;

        i++;

    }

    if (i==0){
        printf( "\nLa lista está vacía!!\n" );
    }

}

void ConsultarRegistro(){
    int registro;
    printf("Ingrese numero de registro a consultar: ");
    scanf("%d", &registro);
    while ((getchar()) != '\n');

    _agenda *aux;
    aux = primero;

    while (aux != NULL){
        if(registro == aux->id){
            printf( "Nombre: %s\nTelefono: %s\nAltura: %f\nDireccion: %s\nID: %d\n",
                    aux->nombre, aux->telefono, aux->height, aux->dir, aux->id);
            break;
        }
        else{
            aux = aux->siguiente;
        }
    }


}

void ConsultarNombre(){
    char nombre[20] = {};
    printf("Ingrese nombre a consultar: ");
    scanf("%s", nombre);
    while((getchar()) != '\n');

    _agenda *aux;
    aux = primero;



    while (aux != NULL){
        int comp = strcmp(nombre, aux->nombre);
        if(comp == 0){
            printf("\n");
            printf( "Nombre: %s\nTelefono: %s\nAltura: %f\nDireccion: %s\nID: %d\n",
                    aux->nombre, aux->telefono, aux->height, aux->dir, aux->id);
            break;
        }
        else{
            aux = aux->siguiente;
        }
    }

    if(aux == NULL){
        printf("No existe el elemento buscado\n");
    }
}

int main() {

    char opcion;

    primero = (_agenda *) NULL;
    ultimo = (_agenda *) NULL;

    do {

        mostrar_menu();
        scanf("%c", &opcion);// cambio de getch() a scanf() para poder limpiar el buffer de entrada y eliminar el \n
        while ((getchar()) != '\n');// elimina el \n en el buffer de entrada

        switch ( opcion ) {

            case '1':
                anadir_elemento(); break;

            case '2':
                mostrar_lista(primero); break;

            case '3':
                ConsultarRegistro(); break;

            case '4':
                ConsultarNombre(); break;

            case '5':
                EliminarElemento(); break;

            case '6':
                exit( 1);

            default:

            printf( "Opción no válida\n" );

            break;

        }

    } while (opcion!='6');

    return 0;
}