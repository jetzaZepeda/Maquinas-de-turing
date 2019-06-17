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
	int t=0;
	while (t<1000){
	if(estado_act=="q4"){
		return check=cadena;
		break;
	}
	else if(estado_act=="q0" and cadena[posicion]=='Y'){
		
		cadena[posicion]='Y';
		posicion+=1;
		
		estado_act="q0";
	}
	else if(estado_act=="q0" and cadena[posicion]=='0'){
		
		cadena[posicion]='X';
		posicion+=1;
		
		estado_act="q1";
	}
	else if(estado_act=="q0" and cadena[posicion]==' '){
		
		cadena[posicion]=' ';
		posicion+=1;
		
		estado_act="q4";
	}
	else if(estado_act=="q1" and cadena[posicion]=='0'){
		
		cadena[posicion]='0';
		posicion+=1;
		
		estado_act="q1";
	}
	else if(estado_act=="q1" and cadena[posicion]=='Y'){
		
		cadena[posicion]='Y';
		posicion+=1;
		
		estado_act="q3";
	}
	else if(estado_act=="q1" and cadena[posicion]=='1'){
		
		cadena[posicion]='Y';
		posicion-=1;
		
		estado_act="q2";
	}
	else if(estado_act=="q3" and cadena[posicion]=='Y'){
		
		cadena[posicion]='Y';
		posicion+=1;
		
		estado_act="q3";
	}
	else if(estado_act=="q3" and cadena[posicion]=='1'){
		
		cadena[posicion]='Y';
		posicion-=1;
		
		estado_act="q2";
	}
	else if(estado_act=="q2" and cadena[posicion]=='Y'){
		
		cadena[posicion]='Y';
		posicion-=1;
		
		estado_act="q2";
	}
	else if(estado_act=="q2" and cadena[posicion]=='0'){
		
		cadena[posicion]='0';
		posicion-=1;
		
		estado_act="q2";
	}
	else if(estado_act=="q2" and cadena[posicion]=='X'){
		
		cadena[posicion]='X';
		posicion+=1;
		
		estado_act="q0";
	}
	t++;
	}
	if(estado_act!="q4"){
		return "No se acepta";
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
