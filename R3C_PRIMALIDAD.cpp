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
	
	long double resultado = pow(r, 2.0) * (pow(n,2.0) + n + p) - (2.0 * n + 1.0) * r + 1.0;
	
	return resultado;
	
}

long double phi(long double Tphi, long double r, long double p, long double n){
	
	long double resultado = sqrt((1.0-(4.0*p)) * pow(Tphi, 2.0) + (2.0*(r+2.0*r*n-2.0)) * Tphi + (pow(r, 2.0)));
	
	return resultado;
	
}

int main(){
		
	cout << fixed << setprecision(0);
		
	long double r;
	long double p;
	long double n;
	
	bool compuesto;
	
	bool salidaPrograma = true;
	
	long double phi_;
	long double Tphi;
	bool primalidad;
	
	while(salidaPrograma){
	
		compuesto = false;
	
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
	
		cout << "Introduce valor n: ";
		cin >> n;
					
		auto start = chrono::high_resolution_clock::now();
					
		cout << endl << "Número Polinomial: " << formulaNumPolinomial(r, p, n) << endl << endl;
			
		Tphi = 1;
		
		primalidad = true;
		
		while(true){
				
			phi_ = phi(Tphi, r, p, n);
				
			if (isnan(phi_)) {
					
				break;
			
			}
						
			if(esEntero(phi_)){
								
				cout << "Es compuesto" << endl;
				
				compuesto = true;
				
				primalidad = false;
				break;
																				
			}
			
			Tphi++;
			
		}
		
		if(compuesto == false){
		
			Tphi = -1;
		
			phi_ = 0;
		
			while(true){
				
				phi_ = phi(Tphi, r, p, n);
				
				if (isnan(phi_)) {
					
					break;
			
				}
						
				if(esEntero(phi_)){
								
					cout << "Es compuesto" << endl;
				
					primalidad = false;
					break;
																				
				}
			
				Tphi--;
			
			}
		
		}
		
		if(primalidad){
	
			cout <<"Es primo" << endl;
		
		}
			
		auto end = chrono::high_resolution_clock::now();
	
		chrono::duration<double> elapsed = end - start;
		
		cout << fixed << setprecision(10);
		
		cout << endl << "Tiempo transcurrido: " << elapsed.count() << " segundos" << endl;
		
		cout << fixed << setprecision(0);
		
	}
	
	return 0;
	
}
