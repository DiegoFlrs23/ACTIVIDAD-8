#include <iostream>
using namespace std;
const char *nombre_archivo="archivo.dat";
struct Estudiante{
	int codigo;
	char nombres [50];
	char apellidos [50];
	int telefono;
};
void leer();
void crear();
main(){
	leer();
	crear();
	system("pause");
}
void leer(){
	system("cls");
	FILE* archivo = fopen(nombre_archivo,"rb");
	if (!archivo){
		archivo = fopen(nombre_archivo,"w+b");
	}
	Estudiante estudiante;
	int id=0; // indice o pocision del registro(fila) dentro del archivo
	fread(&estudiante,sizeof(Estudiante),1,archivo);
	cout<<"___________________________________________________"<<endl;
	cout<<"ID"<<"|"<<"Codigo"<<"|"<<"   Nombres  "<<"|"<<"   Apellidos   "<<"|"<<" Telefono"<<endl;
	do{
		cout<<id<<"|"<<estudiante.codigo<<"|"<<estudiante.nombres<<"|"<<estudiante.apellidos<<"|"<<estudiante.telefono<<endl;
		fread(&estudiante,sizeof(Estudiante),1,archivo);
		id+=1;
	}while(feof(archivo)==0);
	fclose(archivo);
}
void crear(){
	
	FILE*archivo=fopen(nombre_archivo,"a+b");
	char res;
	Estudiante estudiante;
	do{
		fflush(stdin);
		cout<<"Ingrese Codigo:";
		cin>>estudiante.codigo;
		cin.ignore();
		
		cout<<"Ingrrese Nombres:";
		cin.getline(estudiante.nombres,50);
		cout<<"Ingrrese Apellidos:";
		cin.getline(estudiante.apellidos,50);
		
		cout<<"Ingrese Telefono:";
		cin>>estudiante.telefono;
		
		fwrite(&estudiante,sizeof(Estudiante),1,archivo);
		cout<<"Desea ingresar otro estudiante (s/n):";
		cin>>res;
	}while(res=='s'||res=='S');
	fclose(archivo);
	leer();
}
