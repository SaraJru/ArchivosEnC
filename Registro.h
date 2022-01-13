#include <cstdio>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
#include <iostream>
#include <string> 
#include <vector>

using namespace std; 

class Registro
{
	private:
		struct Money{
			double monto;
		};
		
	public:
			vector<int> Num;
			vector<int> Pin;
			vector<double> Monto;
				
		Registro();
		void EditarRegistro();
		void CrearRegistroClientes(); 
		void Borrar();
		void MostrarArchivoClientes();
		void Guardar();
		struct Administrador
		{
			int NoCuenta;
			int Pin;
			char Nombre[50];
			char Apellido[50];
			char NoDPI[50];
			char TipoCuenta[50];				
		};

};


Registro::Registro()
{
}

void Registro::Borrar()
{
	FILE *cliente;
	FILE *CLIENTE;
	cliente = fopen("Monto.txt","w");
	CLIENTE = fopen("datosClientes.txt","w");
	fclose(CLIENTE);
	fclose(cliente);
	
}

void Registro::CrearRegistroClientes()
{
	system("cls");
	FILE *CLIENTE;
	FILE *cliente;
	Money M;
	Administrador A;
	
	cout<<"\n";
	cout<<"Ingrese el numero de cuenta----->"; cin>>A.NoCuenta;
	cout<<"Ingrese el pin de la cuenta----->"; cin>>A.Pin;
	cout<<"Ingrese el nombre del cliente----> ";  cin>>A.Nombre;
	cout<<"Ingrese el apellido del cliente----> ";  cin>>A.Apellido;
	cout<<"Ingrese el numero de DPI del cliente---->"; cin>>A.NoDPI;
	cout<<"Ingrese el tipo de cuenta que el cliente desea crear----> ";  cin>>A.TipoCuenta;
	cout<<"Ingrese el monto de apertura de la cuenta----> "; cin>>M.monto;
	
	CLIENTE = fopen("datosClientes.txt","a+");
	cliente = fopen("Monto.txt","a+");
	
	if(CLIENTE==NULL){
		cout<<"No es posible abrir el archivo"<<endl;
		exit(1);
	}
	
	fwrite(&A,sizeof(A),1,CLIENTE);
	fwrite(&M,sizeof(M),1,cliente);
	cout<<"Cliente registrado exitosamente!!"<<endl;
	fclose(CLIENTE);
	fclose(cliente);
	system("pause()");
}

void Registro::MostrarArchivoClientes()
{
	system("cls");
	Administrador A; 
	Money M;
	FILE *cliente;
	FILE *CLIENTE;
	cliente = fopen("datosClientes.txt","a+");
	CLIENTE = fopen("Monto.txt","a+");
	

	if (cliente == NULL)
	{
		cout<<"No se puede Abrir el Archivo"<<endl;
		exit(1);
	}
	
    cout<<"NoDeCuenta / Pin /Nombre / Apellido / NoDeDPI / TipoDeCuenta / Saldo\n\n\n";
    
    fread(&A,sizeof(A),1,cliente);
    fread(&M,sizeof(M),1,CLIENTE);

    while (!feof(cliente))
    {
    	// desplegando estructuras
    	cout<<A.NoCuenta<<" / "<<A.Pin<<" / "<<A.Nombre<<" / "<<A.Apellido<<" / "<<A.NoDPI<<" / "<<A.TipoCuenta<<" / Q"<<M.monto<<"\n"<<endl;
    	
		fread(&A,sizeof(A),1,cliente);
    	fread(&M,sizeof(M),1,CLIENTE);
    	
	};// termina el while;
	
	fclose(cliente);
	fclose(CLIENTE);
	cout<<"\n\n";
    system("Pause()");
}


void Registro::EditarRegistro()
{
	
	
	FILE *cliente;
	Money M;
	
	
	cliente = fopen("Monto.txt","w");
	cliente = fopen("Monto.txt","a+");
	
	for(int i=0;i<Monto.size();i++)
	{
		M.monto=Monto.at(i);
		fwrite(&M,sizeof(M),1,cliente);
	}
	
	
	
	
	fclose(cliente);
	
}


void Registro::Guardar(){
		Num.clear();
    	Pin.clear();
    	Monto.clear();
	
	Administrador A; 
	Money M;
	FILE *cliente;
	FILE *CLIENTE;
	cliente = fopen("datosClientes.txt","a+");
	CLIENTE = fopen("Monto.txt","a+");
	
    
    fread(&A,sizeof(A),1,cliente);
    fread(&M,sizeof(M),1,CLIENTE);

    while (!feof(cliente))
    {
    	
		Num.push_back(A.NoCuenta);
    	Pin.push_back(A.Pin);
    	Monto.push_back(M.monto);
    	
		fread(&A,sizeof(A),1,cliente);
    	fread(&M,sizeof(M),1,CLIENTE);
    	
	};// termina el while;
	
	fclose(cliente);
	fclose(CLIENTE);
	
	
		
}





