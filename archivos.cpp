#include <iostream>
#include <fstream>  
#include <string>
#include <limits>  

using namespace std;

// Función para validar la edad del estudiante, para que se un numero coherente
int validarEdad() {
    int edad;
    while (!(cin >> edad) || edad < 15 || edad > 90) {
        cout << "Error. Ingrese una edad valida (15-90): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return edad;
}

// Función para validar el promedio, debe ser en 0 y 10
float validarPromedio() {
    float promedio;
    while (!(cin >> promedio) || promedio < 0 || promedio > 10) {
        cout << "Error. Ingrese un promedio valido (0-10): ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
    return promedio;
}

void registrarEstudiante() {
    string nombre, carrera;
    int edad;
    float promedio;

    // Usamos el ofstream
    // Usamos de ios::app para poder guardar los datos anteriores que vamos registrando
    ofstream archivo;
    archivo.open("registros.txt", ios::app);

    if (archivo.fail()) {
        cout << "No se pudo abrir el archivo." << endl;
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 

    cout << "\n--- Registro de Estudiante ---" << endl;
    
    cout << "Nombre: ";
    getline(cin, nombre);

    cout << "Edad: ";
    edad = validarEdad();

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    
    cout << "Carrera: ";
    getline(cin, carrera);

    cout << "Promedio: ";
    promedio = validarPromedio();

    // Aqui guardamos los datos dentro del archivo.
    archivo << "Nombre: " << nombre << " | "
            << "Edad: " << edad << " | "
            << "Carrera: " << carrera << " | "
            << "Promedio: " << promedio << endl;
    archivo.close();

    cout << "\nLos Datos fueron guardados exitosamente en registros.txt" << endl;
}

int main() {
    int opcion;

    // Creamos un menu interactivo.
    do {
        cout << "\n-----------------------------" << endl;
        cout << "   SISTEMA DE REGISTRO UTA     " << endl;
        cout << "------------------------------" << endl;
        cout << "1. Registrar Estudiante" << endl;
        cout << "2. Salir" << endl;
        cout << "Seleccione una opcion: ";
        
        while (!(cin >> opcion)) { 
            cout << "Opcion no valida. Intente de nuevo: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }

        switch (opcion) {
            case 1:
                registrarEstudiante();
                break;
            case 2:
                cout << "Cerrando programa..." << endl;
                cout << "Gracias por usar este sistema de registro :)" << endl;
                break;
            default:
                cout << "Opcion fuera de rango." << endl;
        }
    } while (opcion != 2);

    return 0;
}
