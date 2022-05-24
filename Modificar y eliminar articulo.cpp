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
         cout<< "  3. Buscar Articulo existente" <<endl; 
         cout<< "  4. Modificar Articulos existentes"<<endl;
		 cout<< "  5. Eliminar Articulo existente\n"<<endl;
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
	if(Lec.is_open()) //Se lee si el archivo o función ingresados existen.
	{
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
	}
	else 
	cout<<"Error al abrir el archivo"<<endl; //Se tira el mensaje de que si el archivo o funcion ingresados no existen, tirará un mensaje de error.
			
	system("pause");
}
//En este bloque se puede buscar los archivos existentes.
void buscarArt(ifstream &Lec)
{
    system ("cls");
    Lec.open("Articulos Libreria.txt", ios::in);
    bool encontrado = false;
    string Codigo,Articulo, Preciocompra, Precioventa, Cantidad, codaux;
    
    cout<<"Escriba el codigo del Articulo"<<endl;
    cin>>codaux;
    Lec>>Codigo;
    
    while (! Lec.eof() && !encontrado)
    {
    	 Lec>>Articulo;
    	 Lec>>Preciocompra;
    	 Lec>>Precioventa;
    	 Lec>>Cantidad;
    	 
		 if(Codigo == codaux)
		 {
		 	cout<<"Codigo----------: "<<Codigo<<endl;
			cout<<"Articulo----------: "<<Articulo<<endl;
			cout<<"Precio de Compra----------: "<<Preciocompra<<endl;
			cout<<"Precio de Venta----------: "<<Precioventa<<endl;
			cout<<"Cantidad Existente----------: "<<Cantidad<<endl;
			cout << "\n";
			
			encontrado = true; 	
		 }
    	 
		 Lec>>Codigo;
    }
    Lec.close();
    
    if (!encontrado)
    	cout<<"Articulo no encontrado"<<endl;
	
	system("pause"); 
}
// En este apartado se va a modificar los Datos del Articulo
void modificarArt(ifstream &Lec)
{
	system("cls");
	string Codigo;
	string Articulo;
	string Precioventa;
	string Preciocompra;
	string Cantidad;
	string codaux;
	string compraux;
	string ventaux;
	string cantaux;
	
	Lec.open("Articulos Libreria.txt", ios::in);
	ofstream aux("Auxiliar.txt", ios::out);
	
	if(Lec.is_open())
	{
		cout<<"Ingrese el codigo del articulo"<<endl;
		cin>>codaux;
		Lec>>Codigo;
		
		while(!Lec.eof())
		{
			Lec>>Preciocompra;
			Lec>>Precioventa;
			Lec>>Cantidad;
			
			if(codaux == Codigo)
			{
				cout<<"Escriba el nuevo precio de Compra"<<endl;
				cin>>compraux;
				cout<<"Escriba el nuevo precio de Venta"<<endl;
				cin>>ventaux;
				cout<<"Escriba la nueva Cantidad"<<endl;
				cin>>cantaux;
				aux<<Codigo<<" "<<Articulo<<" "<<compraux<<" "<<ventaux<<" "<<cantaux<<"\n";
			}
			else
			{
				aux<<Codigo<<" "<<Articulo<<" "<<Preciocompra<<" "<<Precioventa<<" "<<Cantidad<<"\n";
			}
			Lec>>Codigo;
		}
		Lec.close();
		aux.close();
		
	}
	else
		cout<<"Error"<<endl;
		
	remove("Articulos Libreria.txt");
	rename("Auxiliar.txt", "Articulos Libreria.txt");

}
//En está parte se podrá eliminar archivos previamente registrados. 	
void eliminar(ifstream &Lec)
{
		system("cls");
	string Codigo;
	string Articulo;
	string Precioventa;
	string Preciocompra;
	string Cantidad;
	string codaux;
	string compraux;
	
	Lec.open("Articulos Libreria.txt", ios::in);
	ofstream aux("Auxiliar.txt", ios::out);
	
	if(Lec.is_open())
	{
		cout<<"Ingrese el codigo del articulo"<<endl;
		cin>>codaux;
		Lec>>Codigo;
		
		while(!Lec.eof())
		{
			Lec>>Preciocompra;
			Lec>>Articulo;
			Lec>>Precioventa;
			Lec>>Cantidad;
			
			if(codaux == Codigo)
			{
				cout<<"Eliminado Perfectamente"<<endl;
				Sleep(1500);
			}
			else
			{
				aux<<Codigo<<" "<<Articulo<<" "<<Preciocompra<<" "<<Precioventa<<" "<<Cantidad<<"\n";
			}
			Lec>>Codigo;
		}
		Lec.close();
		aux.close();
		
	}
	else
		cout<<"Error"<<endl;
		
	remove("Articulos Libreria.txt");
	rename("Auxiliar.txt", "Articulos Libreria.txt");
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
						case 3:
					        buscarArt(Lec);
        					break;
        				case 4:
        					modificarArt(Lec);
        					break;
        				case 5:
							eliminar(Lec);
							break;	
					}
					
					
			   } 
			while (x != 6);   
			return 0;
		}	

