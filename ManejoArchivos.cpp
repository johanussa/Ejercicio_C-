#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;

void menu();
void salir();
void clear();
void buscar();
void guardar();
void eliminar();
void consultas();
void modificar();

// Variables Globales

bool encontrado=false;	// Saber cuando fue encontrado el registro
int semestre = 0, edad = 0, clave = 0, auxClave = 0;
char nombre[30], grupo[15], res[1], auxGrupo[10];
char mensaje[]={'P','R','O','G','R','A','M','A','C','I','O','N', ' ','D','E',' ', 'S','O','F','T','W','A','R','E'};

int main() {   
 
	menu(); 
	system("PAUSE");
	return 0;
}
void clear() {
	
	//system("CLS");
	cout << "\n\n\n\t* Error, el Archivo No se Pudo Abrir o No ha sido Creado *\n\n\n\t"; 
	//system("PAUSE");
	//system("CLS");
	
	//return;
}
void menu() {   
	system("CLS");
	int opcion = 0;
    do {    	
        cout << "\n\n\n\n\n \t\t\t Manejo de Archivos en C++\n\n";
        cout << " \t\t\t\t 1. Guardar"<<endl;
        cout << " \t\t\t\t 2. Eliminar"<<endl;
        cout << " \t\t\t\t 3. Consultar Registros"<<endl;
        cout << " \t\t\t\t 4. Buscar Registro"<<endl;
        cout << " \t\t\t\t 5. Modificar"<<endl;
        cout << " \t\t\t\t 6. Salir"<<endl<<endl;
        cout << " \t\t\t Que deseas hacer.... ? ";
        cin >> opcion;
        system("CLS");
        
        switch (opcion) {   
			case 1: guardar(); break;
            case 2: eliminar(); break;
            case 3: consultas(); break;
            case 4: buscar(); break;
            case 5: modificar(); break;  
            case 6: salir(); break;
            default: 
				cout << "\n\n\n\t\t\t* La Opcion ingresada es Incorrecta! *\n\n\t";
				system("PAUSE");
				system("CLS");
        }
    } while (opcion != 6);
}
void guardar() {   

	ofstream escritura;  ifstream consulta;   
    escritura.open("aprendiz.txt", ios::out | ios::app); 
	consulta.open("aprendiz.txt", ios::in);
	bool repetido = false;
	
    if (escritura.is_open() && consulta.is_open()) {   
    
		cout << "\n\n\n\t> Ingresa la Clave del Aprendiz: ";
        cin >> auxClave;
        consulta >> clave;
        
        while (!consulta.eof()) {   
			consulta >> nombre >> semestre >> grupo >> edad;
            if(clave == auxClave) {   
				cout << "Ya Existe un Registro con esta Clave" << endl;
                repetido = true;
                break;
            }
            consulta >> clave;
        }
        if (repetido == false) {  
        
			fflush(stdin); // cin.getline(Estu1.Nombre,50,'\n');
			cout << "\t* Ingresa el nombre del Aprendiz: "; cin.getline(nombre, 30, '\n'); // gets(nombre);
            cout << "\t* Ingresa el Semestre del Aprendiz: "; cin >> semestre; fflush(stdin);
            cout << "\t* Ingresa el Grupo del Aprendiz: "; cin.getline(grupo, 15, '\n');
            cout << "\t* Ingresa la Edad del Aprendiz: "; cin >> edad;
            escritura << auxClave << " " << nombre << " " << semestre << " " << grupo << " \n\n"; // auxClave la tomo de la que solicite arriba
            cout << "\n\t\t*** Registro Agregado Corectamente !!! ***\n\n\n\n\t";
            system("PAUSE");
        }		
    } else { void clear(); }
    escritura.close(); consulta.close();
}
void consultas() { 
  
    ifstream leer;
	leer.open("aprendiz.txt", ios::out | ios::in);
    
	if (leer.is_open()) {   
		cout << "\t\t\t\t\tRegistros del Archivo aprendiz.txt" << endl;
        cout << "\t\t\t\t\t________________________________" << endl;
        leer >> clave;
        while (!leer.eof()) {   
			leer >> nombre >> semestre >> grupo >> edad;
            cout << "\t\t\t\t\t* Clave: " << clave << endl;
            cout << "\t\t\t\t\t* Nombre: " << nombre << endl;
            cout << "\t\t\t\t\t* Semestre: " << semestre << endl;
            cout << "\t\t\t\t\t* Grupo: " << grupo << endl;
            cout << "\t\t\t\t\t* Edad: " << edad << endl;
            leer >> clave;
            cout << "\t\t\t\t\t________________________________" << endl;
        }
    } else { cout << "Entra"; system("pause"); void clear(); }
    
    leer.close();
}
void eliminar() {   

	ofstream aux; 	// para escribir en un archivo auxiliar que nos va a servir para ir vaciando los registros que tiene el original
    ifstream leer;	// para solo leer, al final aux  va a tener todo lo de el original mas la modificacion,
					// para finalmente eliminar el original y luego renombrar el aux con el nombre del originaal
    encontrado = false;
    int auxClave = 0;
    
    aux.open("auxiliar.txt", ios::out); 
	leer.open("aprendiz.txt", ios::in);
    
    if (aux.is_open() && leer.is_open()) {   
    
		cout << "Ingresa la clave del Aprendiz que desea Eliminar" << endl;
        cin >> auxClave;
        leer >> clave;
        
        while (!leer.eof()) {   
			leer >> nombre >> semestre >> grupo >> edad;
            if (auxClave == clave)	{	// Comparar cada registro para ver si es encontrado
				encontrado = true;      
                cout << "Registro Eliminado " << endl;
            } else {   
				aux << clave << " " << nombre << " " << semestre << " " << grupo << " \n\n";
            }
            leer >> clave;//leer adelantada
        }
    } else { void clear(); }
    
    if (encontrado == false) {
        cout << "No se encontro ningun registro con clave : " << auxClave << endl;	
    }
	aux.close(); 
    leer.close(); 
    remove("aprendiz.txt");
    rename("auxiliar.txt","aprendiz.txt");
}
void buscar() {    

    ifstream leer;	// Creamos la variable de tipo leer
    leer.open("aprendiz.txt", ios::out | ios::in);	// Abrimos el archivo
    encontrado = false;	// validando la apertura del archivo
    
    if (leer.is_open()) { 
	  
		cout << "Ingresa la Clave del Aprendiz que deseas Buscar: ";
        cin >> auxClave;
        leer >> clave;	// leer adelantada
			
        while(!leer.eof()) {   
			leer >> nombre >> semestre >> grupo >> edad;//leyendo los campos del registro
            if (auxClave == clave)	{   // Comparar cada registro para ver si es encontrado
				cout << "\t\t\t______________________________" << endl;
                cout << "\t\t\t\t* Clave: " << clave << endl;
                cout << "\t\t\t\t* Nombre: " << nombre << endl;
                cout << "\t\t\t\t* Semestre: " << semestre << endl;
                cout << "\t\t\t\t* Grupo: " << grupo << endl;
                cout << "\t\t\t\t* Edad: " << edad << endl;
                cout << "\t\t\t______________________________" << endl;
                encontrado = true;
            }
            leer >> clave; // leer adelantada
        }
        if (!encontrado) {   cout << "No hay registros con la Clave " << auxClave << endl; }
    } else { void clear(); }
    
    leer.close();	// Cerrando el archivo	    
}
void modificar() {   

	ofstream aux;	// para escribir en un archivo auxiliar que nos va a servir para ir vaciando los registros que tiene el original
    ifstream leer;	// para solo leer, al final aux  va a tener todo lo de el original mas la modificacion,
	encontrado = false;	// para finalmente eliminar el original y luego renombrar el aux con el nombre del original  
	  
    int auxClave = 0;
    char auxNombre[20];
    aux.open("auxiliar.txt",ios::out);	leer.open("aprendiz.txt",ios::in);
    
    if(aux.is_open() && leer.is_open()) {   
    
		cout << "Ingresa la clave del Aprendiz que desea modificar" << endl;
        cin >> auxClave;
        leer >> clave;
        
        while(!leer.eof()) {	// Mientras no llegue al final del archivo  
		 
			leer >> nombre >> semestre >> grupo >> edad;
            if (auxClave == clave) {	// Comparar cada registro para ver si es encontrado   
				encontrado = true;
				cout << "\t\t\t______________________________" << endl;
                cout << "\t\t\t\t* Clave: " << clave << endl;
                cout << "\t\t\t\t* Nombre: " << nombre << endl;
                cout << "\t\t\t\t* Semestre: " << semestre << endl;
                cout << "\t\t\t\t* Grupo: " << grupo << endl;
                cout << "\t\t\t\t* Edad: " << edad << endl;
                cout << "\t\t\t______________________________" << endl;
                cout << "Ingrese el nuevo nombre del aprendiz con clave : " << clave << endl;
                cin >> auxNombre;
                aux << clave << " " << auxNombre << " " << semestre << " " << grupo << " " << edad << endl;
                cout << "Registro Modificado " << endl;
            } else {   
				aux << clave << " " << nombre << " " << semestre << " " << grupo << " \n\n";
            }
            leer >> clave;	// leer adelantada
        }
    } else { void clear(); }
    
    if(encontrado == false) { cout << "No se encontro ningun registro con clave : " << auxClave << endl; }
    
    leer.close();
    aux.close();
    remove("aprendiz.txt");
    rename("auxiliar.txt","aprendiz.txt");	
}
void salir() {   
    cout << "\n\n\t\t\t   ";
    for(int i = 0; i < 29; i++) {   
		cout<<mensaje[i];
        Sleep(80);
    }
    cout << "\n\n\t\t\t      Programa Finalizado\n\n\n\n\n\n\n\n\n\n";
}
