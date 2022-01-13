#include <iostream>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <conio.h>
#include <iomanip>
#include <string>
#include "Registro.h"//se declara el header 

using namespace std;

//objeto rer de la clase registro
Registro rer;

//posicion del saldo del usuario
int posicion;
//declaracion de funciones y variables tipo bool 
		bool comparar(int,int);
		void Usuario();
		void Admin();
		void ConsultaDeSaldo();
		void Depositos();
		void Retiros();
		

	
int main(){
int usuario,password;
	int uAdmin=110011,pAdmin=101010;
	bool flag=false; //Se utiliza para verificar si los usuarios y los password son correctos o incorrectos
//Menu principal	
	system("cls");
cout<<"\t================================================================\n"<<endl;	
 cout<<"\t\t\t\t\tLOGIN"<<endl;
 cout<<"\t================================================================\n"<<endl;
 cout<<"\t\t\tUsuario:  ";
 cin>>usuario;
 cout<<"\t\t\tPassword: ";
 cin>>password;
 //se verfican los datos del administrador
 if(usuario==uAdmin && password==pAdmin)
 {
 	Admin();//de ser correctos dichos datos se entra al modo administrador
 	
 }else
 {
 	//se comparan los datos del usuario y el password 
 	flag=comparar(usuario,password);
 	if(flag==true){
 		Usuario();//de ser correctos los datatos introducidos, se entra al modo usuario
	 }else{
	 	main();//de no ser así se queda en el login 
	 }
 }
	return 0;
}

//Se utiliza para ver si el usuario y la contraseña ingresados previamente existen y coiciden 
bool comparar(int user, int pass)
{
	
	bool flag=false,resultado;
	int u,p;
	rer.Guardar();// llamando a la funcion de la clase registro
    
    	for(int i=0;i<rer.Num.size();i++){
    		u=rer.Num.at(i);
    		p=rer.Pin.at(i);
			
			if( user==u && pass==p)
	        {
	         flag=true;
	         posicion=i;
	        }
		}
    	
    	if(flag==true){
    		resultado=flag;
		}else{
			resultado=flag;
		}
		
return resultado;

}

//operaciones de la funcion administrador
void Admin(){
	//menu del administrador
	int op;
	char option= 'S';
	system("cls");
	cout<<"\n\t\t\tBIENVENIDO AL SISTEMA AMINISTRADOR!!"<<endl;
	while (option== 's'||option=='S'){
		
		cout<<"\n";
		cout<<"\t\t------------- BASE DE DATOS CLIENTES----------";
		cout<<"\n\n";
		cout<<"\t\t\t[1]Registro de clientes"<<endl;
		cout<<"\t\t\t[2]Mostrar clientes"<<endl;
		cout<<"\t\t\t[3]Borrar los registros"<<endl;
		cout<<"\t\t\t[4]Salir"<<endl;
		cout<<"\n";
		cout<<"\t\t\tElija una opcion: "; cin>>op;
		while(op<=0||op>4){
			cout<<"\t\tLa opcion seleccionada es invalida"<<endl;
			cout<<"\t\tIngrese una opcion valida: "; cin>>op;
		}
		
		switch(op){
			case 1:
				rer.CrearRegistroClientes();
				break;
			case 2:
				rer.MostrarArchivoClientes();
				break;
			case 3:
				cout<<"\n\nEsta seguro que desea borrar todos los registros? (S/N)  ";
				cin>>option;
				if(option== 's'||option=='S'){
					rer.Borrar();
					cout<<"\nRegistros eliminados con exito\n\n";
					system("PAUSE");
					Admin();
				}else{
					Admin();
				}
				
				break;
			case 4:
				 main();
				break;
		}
		
		cout<<"Desea regresar al menu anterior? (S/N) ---->"; cin>>option;
		system("cls");
	}
}

//operaciones de la funcion usuario, que es en si las operaciones que se pueden realizar en un cajero
void Usuario(){
   //menu de cajero
	int op;
	char opc;
	system("cls");
	cout<<"\t\t\tBIENVENIDO"<<endl;
	cout<<"1.- Consulta de saldo"<<endl;
	cout<<"2.- Depositar"<<endl;
	cout<<"3.- Retiros"<<endl;
	cout<<"4.- Salir"<<endl;
	cout<<"Elija una opcion"<<endl;
	cin>>op;						
	if(op >4 && op <= 0){					
	cout<<"\n \t\t\tOpcion invalida!!!"<<endl;
    cout<<"\n \t\t\tIngrese la Opcion Correcta: ";
    cin>>op;	
	}
	//LLamamos a nuestras funciones por medio de un switch
	switch(op){
		
	case 1:
		ConsultaDeSaldo();
		Usuario();
		break;
			
	case 2:
		Depositos();
		Usuario();
		break;
		
	case 3:
		Retiros();
		Usuario();
		break;
			
	case 4:
		cout<<"\n\n";
        cout<<"Esta seguro? (S/N)  "<<endl;
		cin>>opc;
		if(opc=='s' || opc=='S'){
			main();
		}else{
			Usuario();
		}
		break;
		
			
	
	
}
	
	system("pause");
	
}

//funcion para consulta de saldo
void ConsultaDeSaldo(){
	cout<<"\n\n Su saldo es de: Q"<<rer.Monto.at(posicion)<<endl;
	system("pause");
}

//funcion depositos
void Depositos(){
	
	float deposito;
	
	cout<<"\nIngrese la cantidad a depostitar: "<<endl;
	cin>>deposito;
	cout<<"\nSu depostito se ha realizado con exito!\n"<<endl;
	rer.Monto.at(posicion) +=deposito;//al saldo inicial o disponible se le suma el monto del deposito realizado
	rer.EditarRegistro();
	system("pause");
	
}

//funcion retiros
void Retiros(){
	
	int retiro;
	
	cout<<"Ingrese la cantidad que desea retirar: "<<endl;
	  cin>>retiro;
	  cout<<"Su retiro se ha retirado con exito!"<<endl;
	  if(retiro<rer.Monto.at(posicion)){
	  	rer.Monto.at(posicion) -=retiro;
	  	rer.EditarRegistro();
	  }else{ 
	  	cout<<"Su saldo es insuficiente para realizar su retiro"<<endl;
	  }
	
	system("pause");
	
}



