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
#include <random>
#include <boost/multiprecision/cpp_int.hpp>


using namespace std;
using boost::multiprecision::cpp_int;

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
	
	long double resultado = pow(r, 2.0) * (pow(n,2.0) + n + p) - (2.0 * n + 1.0) * r + 1.0;
	
	return resultado;
	
}

long double phi(long double Tphi, long double r, long double p, long double n){
	
	long double resultado = sqrt((1.0 - (4.0 * p)) * pow(Tphi, 2.0) + (2.0 * ( r + 2.0 * r * n - 2.0)) * Tphi + (pow(r, 2.0)));
	
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

int main(){
		
	random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> dist(1000, 9999);
			
	cpp_int numeroTotal;
		
	long double mcd;
	
	long double valor1;
	long double valor2;
				
	cout << fixed << setprecision(0);
		
	long double r;
	long double p;
	long double n;
	long double iteraciones;
	long double phiValor;
	long double Tphi;
	
	bool salida = true;
	long double contadorEnteros = 0;
	long double factores;
	
	bool salidaPrograma = true;
	bool escribir;
	long double numeroTemporal;
	long double numeroDividido;
	
	long double tn;
	long double bn;
		
	long double contarParesOrdenados;
	long double numeroPolinomial;
		
	while(salidaPrograma){
		
		cout << "------------------------" << endl << endl;
		
		cout << "Introduce número de iteraciones: ";
		cin >> iteraciones;
		
		cout << endl << "Introduce el valor de p: ";
		cin >> p;
		
		cout << endl;
		
		numeroTotal = 1;
		vector<long double> array5;
		
		auto start = chrono::high_resolution_clock::now();
		
		for(long double iter = 0; iter < iteraciones; iter++){
		
			vector<long double> array1;
			vector<long double> array2;
			vector<long double> array3;
			vector<long double> array4;
		
			r = dist(gen);
			n = dist(gen);
	
			contarParesOrdenados = 0;
		
			numeroPolinomial = formulaNumPolinomial(r, p, n);
					
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
		
				Tphi--;
		
			}
		
			if(contarParesOrdenados == 0){
				
				numeroTotal *= static_cast<cpp_int>(numeroPolinomial);
				array5.push_back(numeroPolinomial);
			
			}else if(contarParesOrdenados == 1){
			
				numeroTotal *= static_cast<cpp_int>(array1[0]) * static_cast<cpp_int>(array2[0]);
			
				array5.push_back(array1[0]);
				array5.push_back(array2[0]);
					
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
							
						numeroTotal *= static_cast<cpp_int>(array4[x]);
						array5.push_back(array4[x]);
		
					}
			
				}else{
										
					for(long double i = 0; i < array4.size(); i++){
					
						numeroDividido = numeroPolinomial / array4[i];
					
						while(true){
						
							if(esEntero(numeroDividido) && numeroDividido != 1){
													
								numeroTotal *= static_cast<cpp_int>(array4[i]);
								array5.push_back(array4[i]);
								numeroDividido = numeroDividido/array4[i];
							
							}else{
							
								break;
							
							}
					
						}
					
					}
				
				}
			
			
			}
			
		}
		
		cout <<"Número multipolinomial: " << numeroTotal << endl << endl;
		cout << "Factores: ";
		
		sort(array5.begin(), array5.end());
		
		for(long double fact = 0; fact < array5.size(); fact++){
			
			cout << array5[fact] << " ";
			
		}
		
		cout << endl << endl;
		
		auto end = chrono::high_resolution_clock::now();
	
		chrono::duration<double> elapsed = end - start;
	
		cout << fixed << setprecision(8);
	
		cout << "Tiempo transcurrido: " << elapsed.count() << " segundos" << endl;
		
		cout << fixed << setprecision(0);
						
	}
	
	return 0;
	
}
