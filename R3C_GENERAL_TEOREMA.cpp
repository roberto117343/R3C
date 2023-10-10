/*
 * «Copyright 2023 Roberto Reinosa Fernández, Ronald Cordero Méndez»
 * 
 * This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.
    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
 * */

#include <iostream>
#include <cmath>
#include <iomanip>
#include <chrono>
#include <thread>
#include <vector>
#include <algorithm>


using namespace std;


long double calcularMCD(long double a, long double b) {
	
    if (b == 0) {
		
        return a;
        
    }
    
    return calcularMCD(b, fmod(a, b));
    
}

bool esEntero(long double numero) {
		
    return numero == static_cast<long long int>(numero);
    
}

long double formulaNumPolinomial(long double r, long double p, long double n){
	
	long double resultado = pow(n, 2.0) + n * (r - 2.0) + pow(r, 2.0) * p - r + 1.0;
		
	return resultado;
	
}

long double phi(long double Tphi, long double r, long double p, long double n){
	
	long double resultado = sqrt((1.0-(4.0*p)) * pow(Tphi, 2.0) + (2.0*(r+2.0*n-2.0)) * Tphi + (pow(r, 2.0)));
	
	return resultado;
	
}

long double t_positiva(long double r, long double Tphi, long double phi){
		
	long double resultado = -r + Tphi + phi; 
	
	return resultado;
	
}

long double t_negativa(long double r, long double Tphi, long double phi){
		
	long double resultado = -r + Tphi - phi; 
	
	return resultado;
	
}

long double b(long double r, long double Tphi){
	
	long double resultado = 2.0 * Tphi;
	
	return resultado;
	
}

long double formula_tb(long double t, long double b, long double p){
		
	long double resultado = pow(t, 2.0) - t*b + p*pow(b,2.0);
	return resultado;
	
}

long double calculo_n(long double s, long double r, long double x, long double p, long double T){
	
	
	long double tramo1 = (s * ((r - 1.0)* s + r)*pow(x, 2.0) + ((r - 1)*pow(s, 2.0)-(r - 2.0)* s - r) * x + s *(( r - 1.0) * s + r) * p - ( r - 1.0) * s);
	long double tramo2 = (pow(s, 2.0) * pow(x, 2.0) + s * (s-2.0)* x + p * pow(s, 2.0) -s +1.0)* r * T;
	
	return tramo1 + tramo2;
	
}

int main(){
		
	long double mcd;
	
	long double valor1;
	long double valor2;
	
	long double tn;
	long double bn;
	
	long double Tphi;
	
	bool salida;
	bool escribir;
	
	long double contadorEnteros;
	long double factores;
	long double numeroTemporal;
	
	long double contarParesOrdenados;	
	long double numeroPolinomial;
	long double numeroDividido;
				
	cout << fixed << setprecision(0);
		
	long double r;
	long double p;
	long double n;
	long double s;
	long double T;
	long double x;
	long double n2;
	
	long double phiValor;
	
	bool salidaPrograma = true;
	
	while(salidaPrograma){
	
		vector<long double> array1;
		vector<long double> array2;
		vector<long double> array3;
		vector<long double> array4;
	
		cout << "------------------------" << endl;
	
		cout << endl << "Introduce valor r: ";
		cin >> r;
		
		if(r == 0){
			
			cout << "El valor de r no puede ser 0" << endl;
			
			continue;
			
		}
		
		cout << "Introduce valor p: ";
		cin >> p;
	
		cout << "Introduce valor s: ";
		cin >> s;
	
		cout << "Introduce valor x: ";
		cin >> x;
		
		cout << "Introduce valor T: ";
		cin >> T;
		
		auto start = chrono::high_resolution_clock::now();
		
		n = calculo_n(s, r, x, p, T);
		n2 = -(n + 1.0 - (2.0/r));
		
		cout << fixed << setprecision(10);
		
		if(esEntero(n) == false && esEntero(n2) == true){
			
			n = n2;
			
		}else if((esEntero(n) == true && esEntero(n2) == true) || (esEntero(n) == false && esEntero(n2) == false)){
			
			if(abs(n) > abs(n2)){
					
				n = n2;
				
			}
			
		}
				
		cout << fixed << setprecision(0);
				
		contarParesOrdenados = 0;
		
		numeroPolinomial = formulaNumPolinomial(r, p, n);
		
		cout << endl << "Número Polinomial: " << numeroPolinomial << endl << endl;
	
		Tphi = 1;
		
		while(true){
								
			phiValor = phi(Tphi, r, p, n);
				
			if (isnan(phiValor)) {
					
				break;
			
			}
		
			if(esEntero(phiValor)){
									
				contarParesOrdenados++;	
																		
				tn = t_positiva(r, Tphi, phiValor);
				bn =  b(r, Tphi);		
														
				mcd = calcularMCD(tn, bn);
			
				tn = tn/mcd;
				bn = bn/mcd;
			
				valor1 =  formula_tb(tn, bn, p);
									
				tn = t_negativa(r, Tphi, phiValor);
				bn =  b(r, Tphi);				
											
				mcd = calcularMCD(tn, bn);
			
				tn = tn/mcd;
				bn = bn/mcd;
			
				valor2 = formula_tb(tn, bn, p);
									
				array1.push_back(valor1);
				array2.push_back(valor2);
															
			}
		
			Tphi++;
		
		}
		
		Tphi = -1;
		
		while(true){
				
			phiValor = phi(Tphi, r, p, n);
				
			if (isnan(phiValor)) {
					
				break;
			
			}
		
			if(esEntero(phiValor)){
									
				contarParesOrdenados++;	
																		
				tn = t_positiva(r, Tphi, phiValor);
				bn = b(r, Tphi);	
														
				mcd = calcularMCD(tn, bn);
			
				tn = tn/mcd;
				bn = bn/mcd;
			
				valor1 =  formula_tb(tn, bn, p);
									
				tn = t_negativa(r, Tphi, phiValor);
				bn =  b(r, Tphi);	
											
				mcd = calcularMCD(tn, bn);
			
				tn = tn/mcd;
				bn = bn/mcd;
			
				valor2 = formula_tb(tn, bn, p);
									
				array1.push_back(valor1);
				array2.push_back(valor2);
															
			}
		
			Tphi--;
		
		}
		
		if(contarParesOrdenados == 0){
	
			cout << endl << "Es primo" << endl << endl;
		
		}else if(contarParesOrdenados == 1){

			cout << "Es biprimo" << endl << endl;

			cout << "Factor 1: " << array1[0] << endl;
			cout << "Factor 2: " << array2[0] << endl;
		
		}else{
		
			for(long double i = 0; i < array1.size(); i++){
		
				array3.push_back(array1[i]);
				
				array3.push_back(array2[i]);
			
			}
			
			salida = true;
			contadorEnteros = 0;
		
			while(salida){
		
				for(long double i = 0; i < array3.size(); i++){
			
					contadorEnteros = 0;
				
					for(long double x = 0; x < array3.size(); x++){
				
						if(array3[i] > array3[x]){
				
							factores = array3[i]/array3[x];
				
						}else{
				
							factores = array3[x]/array3[i];
					
						}
				
						if(esEntero(factores) && factores != 1){
					
							contadorEnteros++;
					
							if(array3[i] > array3[x]){
						
								array3[i] = factores;
						
							}else{
						
								array3[x] = factores;
						
							}
					
						}
				
					}
			
					if(contadorEnteros == 0){
				
						salida = false;
				
					}
			
				}
		
			}
	
			array4.push_back(array3[0]);
	
			for(long double i = 0; i < array3.size(); i++){
	
				escribir = true;
	
				for(long double x = 0; x < array4.size(); x++){
				
					if(array3[i] == array4[x]){
								
						escribir = false;
				
						break;
				
					}
	
				}
			
				if(escribir == true){
				
					array4.push_back(array3[i]);
				
				}
			
			}
	
			numeroTemporal = 1.0;
	
			for(long double x = 0; x < array4.size(); x++){
		
				numeroTemporal *= array4[x];
		
			}
	
			if(numeroTemporal == numeroPolinomial){
			
				for(long double x = 0; x < array4.size(); x++){
		
					cout << "Factor " << (x+1) << ": " << array4[x] << endl;
		
				}
			
			}else{
															
				for(long double i = 0; i < array4.size(); i++){
					
					numeroDividido = numeroPolinomial / array4[i];
					
					while(true){
						
						if(esEntero(numeroDividido) && numeroDividido != 1){
						
							cout << "Factor " << ": " << array4[i] << endl;
							numeroDividido = numeroDividido/array4[i];
							
						}else{
							
							break;
							
						}
					
					}
					
				}
				
			}
			
		}
		
		auto end = chrono::high_resolution_clock::now();
	
		chrono::duration<double> elapsed = end - start;
	
		cout << fixed << setprecision(8);
	
		cout << endl << "Tiempo transcurrido: " << elapsed.count() << " segundos" << endl;
		
		cout << fixed << setprecision(0);
						
	}
	
	return 0;
	
}
