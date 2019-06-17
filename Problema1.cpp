#include "bits/stdc++.h"
using namespace std;

bool Validar(string cadena, bool x = false){
	int i;
	for(i = 0;i < cadena.length(); i++){
		if (cadena[i] == '1' || cadena[i] == '0'){ x = true; }
		else{
			x = false;
			break;
		}
	}
	return x;
}

string AFD(string cadena, string estado_act,int posicion){
	string check;
	
	while (true){
	if(estado_act=="q1"){
		return check=cadena;
		break;}
	else if(estado_act=="q0" and cadena[posicion]=='0'){
		
		cadena[posicion]='1';
		posicion+=1;
		
		estado_act="q0";
	}
	else if(estado_act=="q0" and cadena[posicion]=='1'){
		
		cadena[posicion]='0';
		posicion+=1;
		
		estado_act="q0";
	}
	else if(estado_act=="q0" and cadena[posicion]==' '){
		
		cadena[posicion]=' ';
		posicion+=1;
		
		estado_act="q1";
	}
	}
}

int main(){
	
	string cad, Estado_ini="q0";
	
	cout << "Ingresar la cadena: ";
	cin >> cad;
	
	if(Validar(cad) == 1){
		cout<<"La cadena '" + cad + "' es: "<<AFD(" "+cad+" ",Estado_ini,1);
		
	}
	
	else{ cout << "Por favor ingresa cadenas que contengan '1' o '0'"; }
	
}
