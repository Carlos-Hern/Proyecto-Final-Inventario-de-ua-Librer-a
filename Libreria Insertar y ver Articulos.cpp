#include <iostream> 
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
using namespace std;

int menu() 
{
//Menu Principal de la Libreria.
	int opcion;
	system ("cls");
		 cout << "\n     ***************** Inventario de una libreria *****************\n\n"<<endl;
		 cout<<"\n  MENU PRINCIPAL\n"<<endl; 
		 cout<< "  1. Ingresar nuevo Articulo"<<endl; 
         cout<< "  2. Consultar Articulo existente"<<endl;
         cout<< "  3. Modificar Articulo existente" <<endl; 
		 cout<< "  4. Eliminar Articulo existente"<<endl;
	     cout<< "  5. Editar Articulos existentes\n"<<endl;
         cout<<"  Nota: Para guardar los registros es necesario al final seleccionar la opcion: "<<endl; 
		 cout<< "  6. Guardar registros y Salir del sistema" <<endl;
		 cin>>opcion;
		 
		 return opcion;
}
// En este bloque, se da la opcion de no registrar un articulo con el codigo igual, es decir, que no se tomarán en cuenta. 
bool verifica(string Codigo)
{
	ifstream leer("Articulos Libreria.txt", ios::in);
	string codigo;
	string articulo;
	string precioVenta;
	string precioCompra;
	string cantidad; 
	
	leer>>codigo;
	
	while (!leer.eof())
	{
		leer>>codigo;
		leer>>articulo;
		leer>>precioCompra;
		leer>>precioVenta;
		leer>>cantidad;
		
		if(Codigo == codigo)
		{
			leer.close();
			return false;
		}
	}
	leer.close();
		return true;
}
//En está parte saldrá la interfaz al seleccionar la opcion 1, que es la de Añadir archivos.
void agregar (ofstream &es) 

{
	system ("cls");	
	string codigo;
	string articulo;
	string precioVenta;
	string precioCompra;
	string cantidad; 
		
	 es.open("Articulos Libreria.txt", ios::out  |   ios::app);
	 cout<<"Codigo del Articulo"<<endl;
	 cin>>codigo;
	 cout<<"Nombre del Articulo"<<endl;
	 cin>>articulo;
	 cout<<"Precio de Compra"<<endl;
	 cin>>precioCompra;
	 cout<<"Precio de Venta"<<endl;
	 cin>>precioVenta;
	 cout<<"Cantidad  del Articulo existente Actualmente"<<endl;
	 cin>>cantidad;	

	 if (verifica(codigo)) //Se enlaza con la parte booleana para que no se repita el codigo de un articulo ya existente.
	 
	 es<<codigo<<" "<<articulo<<" "<<precioCompra<<" "<<precioVenta<<" "<<cantidad<<" "<<endl;
	 es.close ();
}

//Este bloque de código permitirá al usuario ver los registros de los articulos ya ingresados.
void verArticulos(ifstream & Lec)
{
	system("cls");
	string Codigo;
	string Articulo;
	string Precioventa;
	string Preciocompra;
	string Cantidad;
	
	Lec.open ("Articulos Libreria.txt", ios::in);
	cout<<"Articulos Registrados"<<endl;
	Lec>>Codigo;
	while(!Lec.eof())
	{
		
		Lec>>Articulo;
		Lec>>Preciocompra;
		Lec>>Precioventa;
		Lec>>Cantidad;		
		
		cout<<"Codigo----------: "<<Codigo<<endl;
		cout<<"Articulo----------: "<<Articulo<<endl;
		cout<<"Precio de Compra----------: "<<Preciocompra<<endl;
		cout<<"Precio de Venta----------: "<<Precioventa<<endl;
		cout<<"Cantidad Existente----------: "<<Cantidad<<endl;
		cout << "\n";
		Lec>>Codigo;
	}
	Lec.close();
	system("pause");
}


//Está parte del codigo es donde se regitra la opcion, por medio de un switch.
		int main()
		{
			ofstream Esc;
			ifstream Lec;
			int x;
			do {
					system ("cls");
					x = menu();	
					
					switch (x)
					{
						case 1:
							agregar(Esc);
							break;
						case 2: 
							verArticulos(Lec);
							break;
					}
					
					
			   } 
			while (x != 6);   
			return 0;
		}	
