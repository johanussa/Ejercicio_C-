#include <iostream>
#include <stdlib.h>
using namespace std;

int main() {
	
	int aux = 0, cant = 0;
	
	cout << "\t\t\n > Cuantos numeros va a ingresar: "; cin >> cant;
	system("cls");
	
	int num[cant] = { 0 };
	
	for (int i = 0; i < cant; i++) {
		//cout << "\n\n\t> Ingrese el numero " << i + 1  ": ";
		//cin >> num[i];
		num[i] = 1 + rand() % 100;		
	}
	
	cout << "\n\t ** Array Inicial **\n\n";
	cout << " Array: {";
	for (int i = 0; i < cant; i++) {
		cout << " " << num[i];
	}
	cout << " }\n\n";
	
	// Ordenamiento en burbuja
	
	cout << "\n\t ** Array Ordenado de menor a mayor **\n\n";
	
	for (int i = 0; i < cant; i ++) {
		for (int j = 0; j < cant - 1; j++) {
			if (num[j] > num[j+1]) {
				aux = num[j+1];
				num[j+1] = num[j];
				num[j] = aux;				
			}
		}
	}
	cout << " Array: {";
	for (int i = 0; i < cant; i++) {
		cout << " " << num[i];
	}
	cout << " }\n\n";
	
	cout << "\n\t ** Array Ordenado de mayor a menor **\n\n";
	
	cout << " Array: {";
	for (int i = cant - 1; i >= 0; i --) {
		cout << " " << num[i];
	}
	cout << " }\n\n";
	
	return 0;
}


