#include <stdio.h>
#include <stdlib.h>

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
    //int numOrden;
}Persona;

void agregarPersona(FILE *archivo, Persona *persona, int *ordenGral);
void agregarOrdenes(FILE *archivo, Persona *persona, int *ordenGral);
void listarOrdenes(FILE *archivo, Persona *persona);
int buscarOrden(FILE *archivo, Persona *persona);
void eliminarOrden(FILE *archivo, Persona *persona, int *ordenGral);
void modificarOrden(FILE *archivo, Persona *persona);


//----------------MAIN-------------
int main() {
    FILE *archivo;
    int opcion,ordenGral=1;
    Persona persona;

    //Abro el archivo en modo lectura/escritura (si es que ya existe cargo ordenes, sino se crea vacio y se cargan con agregarPersona)
    archivo = fopen("datosImportados.dat", "r+");
    
    //Errores al abrir el archivo
    if (archivo == NULL) {
        archivo = fopen("datosImportados.dat", "w");
        fclose(archivo);
        archivo = fopen("datosImportados.dat", "r+");
    }else{
        //agregarOrdenes(archivo,&persona,&ordenGral);
        printf("agregarOrdenes tiene el error");
    }

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
                agregarPersona(archivo,&persona,&ordenGral);
                break;
            case 2:
                listarOrdenes(archivo,&persona);
                break;
            case 3:
                buscarOrden(archivo,&persona);
                break;
            case 4:
                eliminarOrden(archivo,&persona,&ordenGral);
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
void agregarOrdenes(FILE *archivo, Persona *persona, int *ordenGral){
    //persona->numOrden = (int)ordenGral;
    rewind(archivo);
        while (fread(&persona, sizeof(Persona), 1, archivo)){ {
            //persona->numOrden = (int)++ordenGral;
            fwrite(&persona, sizeof(Persona), 1, archivo);
        }
    }
}


//----------------AGREGAR Persona-------------
void agregarPersona(FILE *archivo, Persona *persona, int *ordenGral) {

    printf("Ingrese el nombre de la persona: ");
    scanf(" %[^\n]s", persona->nombre);

    printf("Ingrese el apellido de la persona: ");
    scanf(" %[^\n]s", persona->apellido);

    printf("Ingrese la fecha de nacimiento de la persona en formato dd/mm/aaaa:\n");
    scanf("%d/%d/%d", persona->fechaNacimiento.dia, persona->fechaNacimiento.mes, persona->fechaNacimiento.ano);

    printf("Ingrese la edad de la persona: ");
    scanf("%d", persona->edad);

    //persona->numOrden = (int)ordenGral++;

    //Escribo en el archivo el registro que llene
    fwrite(&persona, sizeof(Persona), 1, archivo);
}

//----------------LISTAR Personas-------------
void listarOrdenes(FILE *archivo, Persona *persona) {
    int i=1; //Contador para la lista de estudiantes
    rewind(archivo);//Reinicio el cursor del archivo

    //Impresion cuando el archivo se encuentra vacio
    if (!fread(&persona, sizeof(Persona), 1, archivo))
    {
        printf("\n\tEl archivo se encuentra vacio!\n");
    }else{
        //Impresion cuando el archivo tiene contenido
        rewind(archivo);//Reinicio el cursor del archivo (esto es por el condicional de arriba que deja el cursor en cualquier lado)
        while (fread(&persona, sizeof(Persona), 1, archivo)) {
            printf("\t------- %d* Persona ------\n",i);
            //printf("Numero de Orden: %s\n", persona->numOrden);
            printf("Nombre: %s\n", persona->nombre);
            printf("Apellido: %s\n", persona->apellido);
            printf("Fecha de Nacimiento: %d/%d/%d\n",persona->fechaNacimiento.dia,persona->fechaNacimiento.mes,persona->fechaNacimiento.ano);
            printf("Edad: %s\n",persona->edad);
            i++;
        }
    }
    
}

//----------------BUSCAR Orden-------------
int buscarOrden(FILE *archivo, Persona *persona) {
    int ord;
    int i=0; //Contador para la lista de estudiantes
    rewind(archivo);//Reinicio el cursor del archivo

    printf("Ingrese la matricula del persona que desea buscar: ");
    scanf("%d", &ord);
    printf("\n");

    while (fread(&persona, sizeof(Persona), 1, archivo)) {
        //if (persona->numOrden == ord) {
            //printf("\t------- %d* Orden ------\n",persona->numOrden);
            printf("Nombre: %s\n", persona->nombre);
            printf("Apellido: %s\n", persona->apellido);
            printf("Fecha de Nacimiento: %d/%d/%d\n",persona->fechaNacimiento.dia,persona->fechaNacimiento.mes,persona->fechaNacimiento.ano);
            printf("Edad: %s\n",persona->edad);
            fseek(archivo,sizeof(persona)*i,SEEK_SET); //Para posicionar el cursor una posicion antes
            //return persona->numOrden;
        //}
        i++;
    }

    printf("\tX No se encontro ningun persona con la matricula ingresada X\n");
    return -1;
}

//----------------ELIMINAR Orden-------------
void eliminarOrden(FILE *archivo, Persona *persona, int *ordenGral){
    FILE *archivoMOD;
    int ordSM = buscarOrden(archivo,persona);
    archivoMOD = fopen("temp.dat","w");
    if (ordSM!=-1)
    {
        rewind(archivo); //Reinicio el cursor del archivo original
        while (fread(&persona, sizeof(Persona), 1, archivo))//Leo en el original
        {
            //Para que la orden a eliminar no se copie al archivo temporal
            //if (persona->numOrden!=ordSM)
            //{
                fwrite(&persona, sizeof(Persona), 1, archivoMOD);//Copio en el temporal
            //}
        }
        //Cierro y borro el archivo original
        fclose(archivo);
        remove("datosImportados.dat");
        
        //Cierro el archivo temporal y lo renombro
        fclose(archivoMOD);
        if(rename("temp.dat", "datosImportados.dat") == 0){
            printf("Archivo renombrado exitosamente.");
        }else{
            printf("Error al renombrar el archivo.");
        }
        //Abro denuevo el archivo original (temporal renombrado en realidad)
        archivo = fopen("datosImportados.dat","r+");
        if (archivo == NULL)
        {
            printf("\tXX Error al abrir el archivo XX\n");
        }
    }    
}

//----------------MODIFICAR Orden-------------
void modificarOrden(FILE *archivo, Persona *persona){
    int ordSM = buscarOrden(archivo,persona);
    if (ordSM!=-1)
    {
        agregarPersona(archivo,persona,&ordSM);
    }
}
