#include <iostream>
#include <stdlib.h>
#include <string>
#include <tuple>
using namespace std;

typedef struct nodo{
    int id;
    string pregunta;
    struct nodo *izq, *der;

}*Node;

int numNodos = 0; // nummero de nodos del arbol Node

void jugar(Node nodo);

Node crearNodo(int id, string pregunta){
    Node nuevoNodo = new(struct nodo);

    nuevoNodo->pregunta = pregunta;
    nuevoNodo->id = id;
    nuevoNodo->izq = NULL;
    nuevoNodo->der = NULL;

    return nuevoNodo;
}

void insertar(Node &node, int id, string pregunta) {
    //Si raiz es nula
    if(node == NULL) {
        //Se crea nodo y se asigna a nuestra raiz
        node = crearNodo(id, pregunta);
        cout<<"\n\t  Insertado..! > " << pregunta;
    }
        //Si el id es menor al id de la raiz
    else if(id <= node->id)
        //Buscamos el proximo null a asignar recursivamente (Se agregará dependiendo de su valor)
        insertar(node->izq, id, pregunta);
        //Si el id es mayor al id de la raiz
    else if(id > node->id)
        //Buscamos el proximo null a asignar regursivamente (Se agregará dependiendo de su valor)
        insertar(node->der, id, pregunta);
}

void verArbol(Node raiz, int n) {
    if(raiz == NULL)
        return;
    verArbol(raiz->der, n + 1);

    for(int i=0; i<n; i++)
        cout<<"   ";

    numNodos++;
    cout << raiz->id << endl;

    verArbol(raiz->izq, n + 1);
}

void menu() {
    cout << "\n\t\t  ..[ ARBOL BINARIO ]..  \n\n";
    cout << "\t [1] Jugar                              \n";
    cout << "\t [2] SALIR                              \n";

    cout << "\n\t Ingrese opcion : ";
}

int main() {
    Node arbol = NULL;
    int id;
    int opcion;

    insertar(arbol,33," Eres Estudiante?");

    insertar(arbol,17," Eres Hombre?");

    insertar(arbol,9," Eres alto? ");
    insertar(arbol,5," Eres blanco? ");
    insertar(arbol,3," Eres delgado? ");
    insertar(arbol,2," R = Eres carita ");
    insertar(arbol,4," R = Eres abraham ");

    insertar(arbol,7," Eres tranquilo? ");
    insertar(arbol,6," R = Eres Beto ");
    insertar(arbol,8," R = Eres Oscar ");

    insertar(arbol,13," Eres moreno? ");
    insertar(arbol,11," Eres callado? ");
    insertar(arbol,10," R = Eres moreno ");
    insertar(arbol,12," R=Eres Ruso ");

    insertar(arbol,15," Eres gordito ? ");
    insertar(arbol,141," R = Eres gabo ");
    insertar(arbol,16," R = Eres José ");

    insertar(arbol,27," Eres bajito ? ");
    insertar(arbol,21," Eres blanco? ");
    insertar(arbol,19," Tienes cabello oscuro? ");
    insertar(arbol,18," R= Eres Tera ");
    insertar(arbol,20," R = Eres Javier ");

    insertar(arbol,29," Eres moreno? ");
    insertar(arbol,27," Hace deporte ");
    insertar(arbol,26," R = Eres Raul ");
    insertar(arbol,28," R= Eres Cristian ");

    insertar(arbol,31," Eres Risueño? ");
    insertar(arbol,30," R = Eres Edgar ");
    insertar(arbol,32," R = Eres Gared ");

    insertar(arbol,49," Eres mujer? ");

    insertar(arbol,41," Eres blanca? ");
    insertar(arbol,37," Le gustan las monas chinas?");
    insertar(arbol,35," Tiene cabello lacio? ");
    insertar(arbol,34," R= Eres Mich ");
    insertar(arbol,36," R = Eres la Wera ");

    insertar(arbol,39," Tiene bebé? ");
    insertar(arbol,38," R = Es Viry ");
    insertar(arbol,40," R = Es Delia ");

    insertar(arbol,43," Eres pequeña ?");
    insertar(arbol,43," Eres seria ?");
    insertar(arbol,42," R = Eres Jaqui ");
    insertar(arbol,44," R = Es Deni ");

    insertar(arbol,47," Vendes Dulces? ");
    insertar(arbol,46," R = Eres Toma ");
    insertar(arbol,48," R= Eres Eaeleen ");

    insertar(arbol,54," Eres morena? ");
    insertar(arbol,53," Eres alta? ");
    insertar(arbol,51," Eres gritona? ");
    insertar(arbol,50," R = Eres Esther ");
    insertar(arbol,52," R= Eres carmen ");

    insertar(arbol,55," Juegas basquet? ");
    insertar(arbol,54," R= Yuri ");
    insertar(arbol,56," R = Eres Katherine ");

    insertar(arbol,61," Eres bajita? ");
    insertar(arbol,59," Tienes cabello chino y eres delgada? ");
    insertar(arbol,58," R = Eres la china de 5to ");
    insertar(arbol,60," R= Eres Hilda ");

    insertar(arbol,63," Tienes cabello lacio? ");
    insertar(arbol,62," R= Eres Victoria ");
    insertar(arbol,64," R= Eres Jessica ");


    do{
        menu();
        cin >> opcion;
        cout << endl;

        switch (opcion) {
            /*case 2:
                verArbol(arbol, 0);
                break;

            case 1:
                verArbol(arbol, 0);
                cout << "\n\n El numero de nodos es : ";
                cout << numNodos;
                break;
                */
            case 1:
                jugar(arbol);
                break;

            case 2:

                cout << "Bye";
                exit(0);
        }

        cout << "\n\n\n";
    } while (opcion != 2);
}

void jugar(Node nodo) {
    int opcion;

    //Si el nodo es una hojapuesto que no tiene hijos
    if(nodo->der == NULL && nodo->izq == NULL){
        cout << nodo->pregunta;
        return;
    }
    try {
        //Se imprime la pregunta y las opciones
        cout << nodo->pregunta << " \n\t[1] Si \t[2] NO\n > ";
        cin >> opcion;
    }catch (...){
        cout << "Opcion no valida vuelve a intentarlo";
    }
    switch (opcion){
        case 1:
            jugar(nodo->izq);
            break;
        case 2:
            jugar(nodo->der);
            break;
        case 3:
            cout << "bye";
            break;
        default:
            cout << "Opcion no valida";
            jugar(nodo);
            break;
    }
}