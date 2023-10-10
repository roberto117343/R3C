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
#include <vector>
#include <chrono>

using namespace std;

bool esEntero(long double numero) {
		
    return numero == static_cast<long long int>(numero);
    
}

long double calcularMCD(long double a, long double b) {
	
    if (b == 0) {
		
        return a;
        
    }
    
    return calcularMCD(b, fmod(a, b));
    
}

long double formulaNumPolinomial(long double p, long double n){
	
	long double resultado = 2.0 * pow(n, 2.0) + p;
	
	return resultado;
	
}

long double phi1(long double p, long double n, long double Tphi){
	
	long double resultado = sqrt(-32.0 * p * pow(Tphi, 2.0) + 16.0 * (abs(n) - 2.0 * p) * Tphi + 8.0 * (abs(n) - p) + 1.0);
	
	return resultado;
	
}

long double phi2(long double p, long double n, long double Tphi){
	
	long double resultado = sqrt(-32.0 * p * pow(Tphi, 2.0) + 16.0 * (abs(n) - 4.0 * p) * Tphi + 16.0 * (abs(n) - 2.0 * p) + 1.0);
	
	return resultado;
	
}

long double t_pos(long double phi){

	return -1.0 + phi;
	
}

long double t_neg(long double phi){
	
	return -1.0 - phi;
	
}

long double b(long double Tphi){
	
	return 4.0 * (2.0 * Tphi + 1.0);
	
}

long double b_2(long double Tphi){
	
	return 8 * (Tphi + 1.0);
	
}

long double formulaFactores(long double p, long double t, long double b) {
	
    long double resultado = 2.0 * pow(t, 2.0) + p * pow(b, 2.0);
    
    if (fmod(resultado, 2.0) == 0.0) {
		
        return resultado / 2.0;
        
    } else {
		
        return resultado;
        
    }
}

int main(){
	
	long double p;
	long double n;
	long double phi_;
	long double Tphi;
	long double t_pos_;
	long double t_neg_;
	long double b_pos;
	long double b_neg;
	long double mcd;
	long double valor1;
	long double valor2;
	long double contarParesOrdenados;
	bool salida;
	long double contadorEnteros;
	long double factores;
	long double numeroDividido;
	long double numeroTemporal;
	bool escribir;
	long double numeroPolinomial;
	
	cout << fixed << setprecision(0);
	
	while(true){
		
		vector<long double> array1;
		vector<long double> array2;
		vector<long double> array3;
		vector<long double> array4;
		
		cout << "------------------------" << endl;
		
		cout << endl << "Introduce valor p: ";
		cin >> p;
	
		cout << "Introduce valor n: ";
		cin >> n;
		
		auto start = chrono::high_resolution_clock::now();
		
		contarParesOrdenados = 0;
		
		numeroPolinomial = formulaNumPolinomial(p, n);
		
		cout << endl << "Número Polinomial: " << numeroPolinomial << endl << endl;
				
		Tphi = 0;
		
		while(true){
					
			phi_ = phi1(p, n, Tphi);
				
			if (isnan(phi_)) {
					
				break;
			
			}
						
			if(esEntero(phi_)){
					
				contarParesOrdenados++;
														
				t_pos_ = t_pos(phi_); 
				b_pos = b(Tphi);
				
				mcd = calcularMCD(t_pos_, b_pos);
				
				t_pos_ /= mcd;
				b_pos /= mcd;
				
				valor1 = formulaFactores(p, t_pos_, b_pos);
								
				t_neg_ = t_neg(phi_); 
				b_neg = b(Tphi);
				
				mcd = calcularMCD(t_neg_, b_neg);
				
				t_neg_ /= mcd;
				b_neg /= mcd;
				
				valor2 = formulaFactores(p, t_neg_, b_neg);
				
				array1.push_back(valor1);
				array2.push_back(valor2);
								
			}
								
			Tphi++;
						
		}
		
		if(contarParesOrdenados == 0){
						
			Tphi = 0;
		
			while(true){
				
				phi_ = phi2(p, n, Tphi);
				
				if (isnan(phi_)) {
					
					break;
			
				}
						
				if(esEntero(phi_)){
											
					contarParesOrdenados++;
													
					t_pos_ = t_pos(phi_); 
					b_pos = b_2(Tphi);
				
					mcd = calcularMCD(t_pos_, b_pos);
				
					t_pos_ /= mcd;
					b_pos /= mcd;
				
					valor1 = formulaFactores(p, t_pos_, b_pos);
								
					t_neg_ = t_neg(phi_); 
					b_neg = b_2(Tphi);
				
					mcd = calcularMCD(t_neg_, b_neg);
				
					t_neg_ /= mcd;
					b_neg /= mcd;
				
					valor2 = formulaFactores(p, t_neg_, b_neg);
				
					array1.push_back(valor1);
					array2.push_back(valor2);
									
				}
							
				Tphi++;
						
			}
		}
		
		if(contarParesOrdenados == 0){
	
			cout << "Es primo" << endl;
		
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
