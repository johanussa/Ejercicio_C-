#include <iostream>
#include <stdlib.h>	// Podremos salir del programa cuando ocurra un error 
#include <fstream>	// Lectura y escritura de archivos
#include <windows.h>

using namespace std;

int auxClave = 0;
bool find = false;
char mensaje[] = {'P','R','O','G','R','A','M','A','C','I','O','N', ' ','D','E',' ', 'S','O','F','T','W','A','R','E'};

struct infoAp {
	int clave = 0;
	int semestre = 0;
	int edad = 0;
	string nombre = "";
	string grupo = "";	
};
struct infoAp aprendiz;

void menu();
void salir();
//void buscar();
void guardar();
//void eliminar();
void consultas();
//void modificar();

int main() {
	
	menu();	
	system("PAUSE");
	return 0;
}
void menu() {
	
	
	int opcion = 0;
    do {
		system("CLS");    	
        cout << "\n\n\n\n\n \t\t\t Manejo de Archivos en C++\n\n";
        cout << " \t\t\t\t 1. Guardar" << endl;
        cout << " \t\t\t\t 2. Eliminar" << endl;
        cout << " \t\t\t\t 3. Consultar Registros" << endl;
        cout << " \t\t\t\t 4. Buscar Registro" << endl;
        cout << " \t\t\t\t 5. Modificar" << endl;
        cout << " \t\t\t\t 6. Salir" << endl << endl;
        cout << " \t\t\t Que deseas hacer.... ? ";
        cin >> opcion;
        system("CLS");
        
        switch (opcion) {   
			case 1: guardar(); break;
            case 2: /*eliminar();*/ break;
            case 3: consultas(); break;
            case 4: /*buscar();*/ break;
            case 5: /*modificar();*/ break;  
            case 6: salir(); break;
            default: 
				cout << "\n\n\n\t\t\t* La Opcion ingresada es Incorrecta! *\n\n\t";
				system("PAUSE");
				system("CLS");
        }
    } while (opcion != 6);
	return;
}
void guardar() {
	
	int cont = 0;
	string frase;
	bool repeat = false;
	
	ofstream escribir;					// Crear tipo de dato ofstream de archivos - o = output
	escribir.open("Aprendices.txt", ios::out | ios::app);	// Intentamos abrir el archivo - ios::out = abrir y reemplazar	
	// Parametro 1: Nombre de archivo - Parametro 2: Modo de apertura - app = agregar datos
	// Si el archivo No existe, lo va a crear
	ifstream consultar;		// Crear tipo de dato ifstream de archivos - i = input
	consultar.open("Aprendices.txt", ios::in);	// ios::in = lectura de datos
	
	if (escribir.is_open() && consultar.is_open()) {
		
		cout << "\n\n\t> Cuantos datos va a ingresar? "; cin >> cont; cout << endl;
		system("CLS");
		
		for (int i = 0; i < cont; i++) {
			
			cout << "\n\t\t*** Datos aprendiz " << i + 1 << " ***\n\n";			
			cout << "\t> Ingresa la Clave del Aprendiz: ";
	        cin >> auxClave;
	        consultar >> aprendiz.clave;
	        
	        while (!consultar.eof()) {   
				consultar >> aprendiz.nombre >> aprendiz.semestre >> aprendiz.grupo >> aprendiz.edad;
	            if(aprendiz.clave == auxClave) { 
					system("CLS");  
					cout << "\n\n\t\t* Ya Existe un Registro con esta Clave :( *" << endl;
					cout << "\t\t\t* Vuelve a intentarlo *\n" << endl;
	                repeat = true;
	                break;
	            }
	            consultar >> aprendiz.clave;
	        }
			if (!repeat) {
				
				aprendiz.clave = auxClave;
				fflush(stdin); 
				cout << "\t* Ingresa el Nombre del Aprendiz: "; getline(cin, aprendiz.nombre); 
	            cout << "\t* Ingresa el Semestre del Aprendiz: "; cin >> aprendiz.semestre; fflush(stdin);
	            cout << "\t* Ingresa el Grupo del Aprendiz: "; getline(cin, aprendiz.grupo);
	            cout << "\t* Ingresa la Edad del Aprendiz: "; cin >> aprendiz.edad;
	            escribir << aprendiz.clave << " " << aprendiz.nombre << " " << aprendiz.semestre
					<< " " << aprendiz.grupo << " " << aprendiz.edad << "\n"; 
			}			
		}
		cout << "\n\t\t*** Registro Agregado Corectamente !!! ***\n\n\n\n\t";
        system("PAUSE");
		escribir.close(); consultar.close();
		system("CLS");
				
	} else {
		cout << "\n\n\t** El archivo NO pudo ser creado o abierto **\n\n";
		exit(1);	// Salimos del programa ya que no se pudo crear el archivo
	}	
	return;
}
void consultas() {
	
	ifstream read;
	read.open("Aprendices.txt", ios::out | ios::in);
	
	if (read.is_open()) {
		
		cout << "\n\n\t\t\t\t    * Registros del archivo Aprendices.txt *" << endl;
        cout << "\t\t\t\t\t________________________________" << endl;
        read >> aprendiz.clave;
        
        while (!read.eof()) {   
			read >> aprendiz.nombre >> aprendiz.semestre >> aprendiz.grupo >> aprendiz.edad;
            cout << "\n\t\t\t\t\t * Clave: " << aprendiz.clave << endl;
            cout << "\t\t\t\t\t * Nombre: " << aprendiz.nombre << endl;
            cout << "\t\t\t\t\t * Semestre: " << aprendiz.semestre << endl;
            cout << "\t\t\t\t\t * Grupo: " << aprendiz.grupo << endl;
            cout << "\t\t\t\t\t * Edad: " << aprendiz.edad << endl;
            read >> aprendiz.clave;
            cout << "\t\t\t\t\t________________________________" << endl;
        }
        cout << "\n\n\n\t";
        system("PAUSE");
	} else {
		cout << "\n\n\t** El archivo NO pudo ser creado o abierto **\n\n";
		exit(1);	// Salimos del programa ya que no se pudo crear el archivo
	}
	read.close();
	return;
}
void salir() {   
    cout << "\n\n\n\t\t\t *** ";
    for(int i = 0; i < strlen(mensaje); i++) {   
		cout << mensaje[i];
        Sleep(80);
    }
    cout << " ***\n\n\t\t\t   *** Programa Finalizado ***\n\n\n\n\n\n\n\t";
}
