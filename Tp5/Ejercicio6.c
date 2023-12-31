#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int dia;
    int mes;
    int ano;
}Fecha;

typedef struct{
    char nombre[50];
    char apellido[50];
    Fecha fechaNacimiento;
    int edad;
}PersonaAntigua;
typedef struct{
    char nombre[50];
    char apellido[50];
    Fecha fechaNacimiento;
    int edad;
    int numOrden;
}Persona;

void agregarPersona(FILE *archivo, Persona *persona);
void agregarOrdenes(Persona *persona);
void listarOrdenes(FILE *archivo, Persona *persona);
int buscarOrden(FILE *archivo, Persona *persona);
void eliminarOrden(FILE *archivo, Persona *persona);
void modificarOrden(FILE *archivo, Persona *persona);


//----------------MAIN-------------
int main() {
    FILE *archivo;
    int opcion,ordenGral=1;
    Persona persona;

    //Abro el archivo en modo lectura/escritura (si es que ya existe cargo ordenes, sino se crea vacio y se cargan con agregarPersona)
    agregarOrdenes(&persona);

    //Con agregar ordenes siempre se crea el nuevo archivo
    archivo = fopen("datosImportadosConOrden.dat", "r+");
    
    do {
        printf("\n\t--- Menu de opciones: ----\n");
        printf("1. Agregar una nueva persona.\n");
        printf("2. Listar todos las Ordenes.\n");
        printf("3. Buscar una persona por su orden.\n");
        printf("4. Buscar una persona por su orden y eliminarla.\n");
        printf("5. Buscar una persona por su orden y moficarla.\n");
        printf("6. Limpiar consola.\n");
        printf("7. Salir.\n");

        printf("\nIngrese una opcion: ");
        scanf("%d", &opcion);
        printf("\n");

        switch (opcion) {
            case 1:
                agregarPersona(archivo,&persona);
                break;
            case 2:
                listarOrdenes(archivo,&persona);
                break;
            case 3:
                buscarOrden(archivo,&persona);
                break;
            case 4:
                eliminarOrden(archivo,&persona);
                break;
            case 5:
                modificarOrden(archivo,&persona);
                break;
            case 6:
                system("clear");
                break;
            case 7:
                break;
            default:
                printf("\nOpcion invalida.\n");
                break;
        }
    } while (opcion != 7);
    fclose(archivo);

    return 0;
}

//----------------AGREGAR Ordenes-------------
void agregarOrdenes(Persona *persona){
    FILE *archivoViejo, *archivo;
    PersonaAntigua personaAntigua;
    //Las ordenes que sean importadas van a arrancar desde 1000, y para agregar nuevas personas se permite elegir su numero de orden
    int orden = 1000;
    //Abro archivo viejo
    archivoViejo = fopen("datosImportados.dat","r");
    //Abro archivo nuevo con numeros de orden
    archivo = fopen("datosImportadosConOrden.dat", "w");
    
    //Veo si el archivo antiguo tiene algo
    if (!fread(&personaAntigua, sizeof(PersonaAntigua), 1, archivoViejo))
    {
        printf("\n\tEl archivo se encuentra vacio!\n");
    }else{
        //Reinicio el cursor
        rewind(archivoViejo);
        //Si tiene algo el archivo voy leyendo y guardando en el archivo nuevo
        while (fread(&personaAntigua, sizeof(PersonaAntigua), 1, archivoViejo)) {
            strcpy(persona->nombre, personaAntigua.nombre);
            strcpy(persona->apellido, personaAntigua.apellido);
            persona->fechaNacimiento.ano = personaAntigua.fechaNacimiento.ano;
            persona->fechaNacimiento.mes = personaAntigua.fechaNacimiento.mes;
            persona->fechaNacimiento.dia = personaAntigua.fechaNacimiento.dia;
            persona->edad = personaAntigua.edad;
            persona->numOrden = orden++;

            //Escribo en el nuevo archivo
            fwrite(persona, sizeof(Persona), 1, archivo);
        }
    }
    //Cierro ambos archivos
    fclose(archivo);
    fclose(archivoViejo);
}


//----------------AGREGAR Persona-------------
void agregarPersona(FILE *archivo, Persona *persona) {

    printf("Ingrese el nombre de la persona: ");
    scanf(" %[^\n]s", persona->nombre);

    printf("Ingrese el apellido de la persona: ");
    scanf(" %[^\n]s", persona->apellido);

    printf("Ingrese la fecha de nacimiento de la persona en formato dd/mm/aaaa:\n");
    scanf("%d/%d/%d", &persona->fechaNacimiento.dia, &persona->fechaNacimiento.mes, &persona->fechaNacimiento.ano);

    printf("Ingrese la edad de la persona: ");
    scanf("%d", &persona->edad); 

    printf("Ingrese el numero de orden de la persona: ");
    scanf("%d", &persona->numOrden);

    //Escribo en el archivo el registro que llene
    fwrite(persona, sizeof(Persona), 1, archivo);
}

//----------------LISTAR Personas-------------
void listarOrdenes(FILE *archivo, Persona *persona) {
    int i=1; //Contador para la lista de personas
    rewind(archivo);//Reinicio el cursor del archivo

    //Impresion cuando el archivo se encuentra vacio
    if (!fread(persona, sizeof(Persona), 1, archivo))
    {
        printf("\n\tEl archivo se encuentra vacio!\n");
    }else{
        //Impresion cuando el archivo tiene contenido
        rewind(archivo);//Reinicio el cursor del archivo (esto es por el condicional de arriba que deja el cursor en cualquier lado)
        while (fread(persona, sizeof(Persona), 1, archivo)) {
            printf("\t------- %d* Persona ------\n",i);
            printf("Numero de Orden: %d\n", persona->numOrden);
            printf("Nombre: %s\n", persona->nombre);
            printf("Apellido: %s\n", persona->apellido);
            printf("Fecha de Nacimiento: %d/%d/%d\n",persona->fechaNacimiento.dia,persona->fechaNacimiento.mes,persona->fechaNacimiento.ano);
            printf("Edad: %d\n",persona->edad);
            i++;
        }
    }
}

//----------------BUSCAR Orden-------------
int buscarOrden(FILE *archivo, Persona *persona) {
    int ord;
    int i=0; //Contador para la lista de estudiantes
    rewind(archivo);//Reinicio el cursor del archivo

    printf("Ingrese el numero de orden de la persona que desea buscar: ");
    scanf("%d", &ord);
    printf("\n");

    while (fread(persona, sizeof(Persona), 1, archivo)) {
        if (persona->numOrden == ord) {
            printf("\t------- %d* Orden ------\n",persona->numOrden);
            printf("Nombre: %s\n", persona->nombre);
            printf("Apellido: %s\n", persona->apellido);
            printf("Fecha de Nacimiento: %d/%d/%d\n",persona->fechaNacimiento.dia,persona->fechaNacimiento.mes,persona->fechaNacimiento.ano);
            printf("Edad: %d\n\n",persona->edad);
            fseek(archivo,sizeof(persona)*i,SEEK_SET); //Para posicionar el cursor una posicion antes
            return persona->numOrden;
        }
        i++;
    }

    printf("\tX No se encontro ningun persona con la matricula ingresada X\n");
    return -1;
}

//----------------ELIMINAR Orden-------------
void eliminarOrden(FILE *archivo, Persona *persona){
    FILE *archivoMOD;
    int ordSM = buscarOrden(archivo,persona);
    if (ordSM!=-1)//Esto significa que en la funcion de buscar si encontro el numero de orden
    {
        archivoMOD = fopen("temp.dat","w");
        rewind(archivo); //Reinicio el cursor del archivo original
        while (fread(persona, sizeof(Persona), 1, archivo))//Leo en el original
        {
            //Para que la orden a eliminar no se copie al archivo temporal
            if (persona->numOrden!=ordSM)//ESTO TIRA SEGMENTATION FAULT
            {    
                fwrite(persona, sizeof(Persona), 1, archivoMOD);//Copio en el temporal
            }
        }

        //Cierro y borro el archivo original
        fclose(archivo);
        remove("datosImportadosConOrden.dat");
        
        //Cierro el archivo temporal y lo renombro
        fclose(archivoMOD);
        if(rename("temp.dat", "datosImportadosConOrden.dat") != 0){
            printf("\tError al renombrar el archivo!");
        }
        //Abro denuevo el archivo original (temporal renombrado en realidad)
        archivo = fopen("datosImportadosConOrden.dat","r+");
        if (archivo == NULL)
        {
            printf("\tXX Error al abrir el archivo XX\n");
        }
        printf("\n\t--- ORDEN ELIMINADA ---\n\n");
    } 
}

//----------------MODIFICAR Orden-------------
void modificarOrden(FILE *archivo, Persona *persona){
    int ordSM = buscarOrden(archivo,persona);
    if (ordSM!=-1)
    {
        agregarPersona(archivo,persona);
    }
}
