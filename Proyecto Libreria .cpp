#include <iostream> 
#include <fstream>
#include <windows.h>
#include <stdlib.h>
#include <cstdlib>
#include <conio.h>
#include <string>

using namespace std;
void gotoxy (int x, int y)
{ 
	HANDLE hcon= GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y =y;
	SetConsoleCursorPosition(hcon, dwPos);
}
int menu() 
{
//Menu Principal de la Libreria.
	int opcion;
	system ("cls");
	
		 cout <<"\n     ***************** Inventario de una libreria *****************\n\n"<<endl;
		 cout <<" **************************************************************************"<<endl;
		 cout<< " *                             MENU PRINCIPAL                             *"<<endl; 
		 cout<< " * 1. Ingresar nuevo Articulo                                             *"<<endl; 
         cout<< " * 2. Consultar Articulo existente                                        *"<<endl;
         cout<< " * 3. Buscar Articulo existente                                           *"<<endl; 
         cout<< " * 4. Modificar Articulos existentes                                      *"<<endl;
		 cout<< " * 5. Vender articulo                                                     *"<<endl;
		 cout<< " * 6. Eliminar articulo                                                   *"<<endl; 
		 cout<< " * 7. Guardar registros y Salir del sistema                               *"<<endl;
		 cout<< " **************************************************************************"<<endl;
		 cout<< " *Elija una opcion                                       *                *"<<endl;
		 cout<< " **************************************************************************"<<endl;
		 
		gotoxy(65,14); cin>>opcion;
		 
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
		leer>>articulo;
		leer>>precioCompra;
		leer>>precioVenta;
		leer>>cantidad;
		
		if(Codigo == codigo)
		{
			leer.close();
			return false;
		}
		leer>>codigo;
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
	        cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *  Codigo  -  Nombre Producto  -  Precio Compra  -  Precio Venta - Cantidad * "<<endl;
			cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *          -                   -                 -               -          * "<<endl;
			cout<<"   ***************************************************************************** "<<endl;
			
			gotoxy(6,3);cin>>codigo;
			gotoxy(17,3);cin>>articulo;
			gotoxy(37,3);cin>>precioCompra;
			gotoxy(55,3);cin>>precioVenta;	
			gotoxy(71,3);cin>>cantidad;

	 if (verifica(codigo)) //Se enlaza con la parte booleana para que no se repita el codigo de un articulo ya existente.
	 
	 es<<codigo<<" "<<articulo<<" "<<precioCompra<<" "<<precioVenta<<" "<<cantidad<<" "<<endl;
	 es.close ();
}

//Este bloque de código permitirá al usuario ver los registros de los articulos ya ingresados.
void verArticulos(ifstream & Lec)
{
	
	system("cls");
	int o=0;
	string Codigo;
	string Articulo;
	string Precioventa;
	string Preciocompra;
	string Cantidad;
	
	Lec.open ("Articulos Libreria.txt", ios::in);
	if(Lec.is_open()) //Se lee si el archivo o función ingresados existen.
	{
		    cout<<"   *                           Articulos Registrados                           *"<<endl;
			cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *  Codigo  *  Nombre Producto  *  Precio Compra  *  Precio Venta * Cantidad * "<<endl;
			cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *          *                   *                 *               *          * "<<endl;
		Lec>>Codigo;
		while(!Lec.eof())
		{	
			o++;
				cout<<o;
				Lec>>Articulo;
				Lec>>Preciocompra;
				Lec>>Precioventa;
				Lec>>Cantidad;
				gotoxy(0,3+o);cout<<"   *          *                   *                 *               *          * "<<endl;
				gotoxy(6,3+o);cout<<Codigo;
				gotoxy(17,3+o);cout<<Articulo;
				gotoxy(37,3+o);cout<<Preciocompra;
				gotoxy(55,3+o);cout<<Precioventa;	
				gotoxy(71,3+o);cout<<Cantidad;
			Lec>>Codigo;
		}
		cout<<endl;
			cout<<"   ***************************************************************************** ";
	Lec.close();
	o=0;
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
    
            cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *  Codigo  *  Nombre Producto  *  Precio Compra  *  Precio Venta * Cantidad * "<<endl;
			cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *          *                   *                 *               *          * "<<endl;
		 	cout<<"   ***************************************************************************** "<<endl;
   		    gotoxy(6,3);cin>>codaux;
            Lec>>Codigo; 
    
    while (! Lec.eof() && !encontrado)
    {
    	 Lec>>Articulo;
    	 Lec>>Preciocompra;
    	 Lec>>Precioventa;
    	 Lec>>Cantidad;
		 if(Codigo == codaux)
		 {	
				gotoxy(17,3);cout<<Articulo;
				gotoxy(37,3);cout<<Preciocompra;
				gotoxy(55,3);cout<<Precioventa;	
				gotoxy(71,3);cout<<Cantidad;
			
			encontrado = true; 	
		 }
    	 
		 Lec>>Codigo;
    }
    getch();
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
	        cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *  Codigo  *  Nombre Producto  *  Precio Compra  *  Precio Venta * Cantidad * "<<endl;
			cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *          *                   *                 *               *          * "<<endl;
		 	cout<<"   ***************************************************************************** "<<endl;
   		    gotoxy(6,3);cin>>codaux;
            Lec>>Codigo; 
	
	if(Lec.is_open())
	{
		
		while(!Lec.eof())
		{
			Lec>>Articulo;
			Lec>>Preciocompra;
			Lec>>Precioventa;
			Lec>>Cantidad;
			
			if(codaux == Codigo)
			{
			gotoxy(17,3);cout<<Articulo;
			gotoxy(37,3);cin>>compraux;
			gotoxy(55,3);cin>>ventaux;	
			gotoxy(71,3);cin>>cantaux;
			
		     aux<<codaux<<" "<<Articulo<<" "<<compraux<<" "<<ventaux<<" "<<cantaux<<" "<<endl;
			 
				
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
 	
void vender(ifstream &Lec)
{
	system("cls");
	string Codigo;
	string Articulo;
	char Precioventa[100];
	string Preciocompra;
	char Cantidad[100];
	string codaux;
	string compraux;
	string ventaux;
	char cantaux[100];
	int cantidadfin;
	
	Lec.open("Articulos Libreria.txt", ios::in);
	ofstream aux("Auxiliar.txt", ios::out);
	        cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *  Codigo  *  Nombre Producto  *  Precio Ventaa  *  Cantidad     * TOTAL    * "<<endl;
			cout<<"   ***************************************************************************** "<<endl;
			cout<<"   *          *                   *                 *               *          * "<<endl;
		 	cout<<"   ***************************************************************************** "<<endl;
   		    gotoxy(6,3);cin>>codaux;
            Lec>>Codigo; 
	
	if(Lec.is_open())
	{
		
		while(!Lec.eof())
		{
			Lec>>Articulo;
			Lec>>Preciocompra;
			Lec>>Precioventa;
			Lec>>Cantidad;
			
			if(codaux == Codigo)
			{
			gotoxy(17,3);cout<<Articulo;
			gotoxy(0,0);cout<<Preciocompra;
			gotoxy(37,3);cout<<Precioventa;
			gotoxy(60,3);cin>>cantaux;
			
			
			int num1=0,num2=0,num3=0;
			 num1=atoi(Cantidad);
			 num2=atoi(cantaux);
			 num3=atoi(Precioventa);
			cantidadfin=num1-num2;
			int total = num2+num3;
				gotoxy(71,3);cout<<total;
		     aux<<codaux<<" "<<Articulo<<" "<<Preciocompra<<" "<<Precioventa<<" "<<cantidadfin<<" "<<endl;
			 
				
			}
			else
			{
				aux<<Codigo<<" "<<Articulo<<" "<<Preciocompra<<" "<<Precioventa<<" "<<Cantidad<<"\n";
			}
			Lec>>Codigo;
		}
		getch();
		Lec.close();
		aux.close();
		
	}
	else
		cout<<"Error"<<endl;
		
	remove("Articulos Libreria.txt");
	rename("Auxiliar.txt", "Articulos Libreria.txt");
}

void eliminar(ifstream &Lec)
{
	system("cls");
	string Codigo;
	string Articulo;
	string Precioventa;
	string Preciocompra;
	string Cantidad;
	string codaux;
	
	Lec.open("Articulos Libreria.txt", ios::in);
	ofstream aux("Auxiliar.txt", ios::out);
	        cout<<"   ************************************************************************************************* "<<endl;
			cout<<"   *  Codigo  *  Nombre Producto  *  Precio Compra  *  Precio Venta * Compras  * Ventas  * Cantidad *"<<endl;
			cout<<"   **************************************************************************************************"<<endl;
			cout<<"   *          *                   *                 *               *          *         *          *"<<endl;
		 	cout<<"   ************************************************************************************************* "<<endl;
   		    gotoxy(6,3);cin>>codaux;
            Lec>>Codigo; 
	
	if(Lec.is_open())
	{
		
		while(!Lec.eof())
		{
			Lec>>Articulo;
			Lec>>Preciocompra;
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
							vender(Lec);
							
							break;	
						case 6:
							eliminar(Lec);
							break;	
					}
					
					
			   } 
			while (x != 7);   
			return 0;
		}	


