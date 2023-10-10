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
#include <vector>
#include <iomanip>
#include <cmath>
#include <chrono>
#include <vector>
#include <thread>
#include <boost/multiprecision/cpp_dec_float.hpp>
#include <boost/multiprecision/cpp_int.hpp>
#include <boost/multiprecision/cpp_complex.hpp>
#include <boost/multiprecision/cpp_bin_float.hpp>

using namespace std;
using boost::multiprecision::cpp_dec_float_100;
using boost::multiprecision::cpp_int;

long double F1(long double s, long double x, long double p){
	
	long double f1 = pow(s, 2.0)*pow(x, 2.0) + s*(s-2.0)*x + p*pow(s, 2.0) -s + 1.0;
	return f1;
	
}
long double F2(long double p, long double rAst, long double M){
	
	long double f2 = ((4.0*p-1.0) * pow(rAst, 2.0) + pow(M, 2.0))/4.0;
	return f2;
	
}

long double phi(long double Tphi, long double p, long double s, long double x){
		
	long double phi_ = sqrt((1.0 - 4.0 * p) * pow(Tphi, 2.0) + 2.0 * (s + 2.0 * s * x - 2.0) * Tphi + pow(s, 2.0));
	return phi_;
	
}

long double phi_2(long double p, long double Tphi, long double M, long double rAst){
		
	long double phi_ = sqrt((1.0 - 4.0 * p) * pow(Tphi, 2.0) + 2.0 * M * Tphi + pow(rAst, 2.0));
	return phi_;
	
}

bool esEntero(long double numero) {
		
    return numero == static_cast<long long int>(numero);
    
}

long double t_pos_f1(long double s, long double To, long double O){
	
	long double t = -s + To + O;
	
	return t;
	
}

long double t_neg_f1(long double s, long double To, long double O){
	
	long double t = -s + To - O;
	
	return t;
	
}

long double b_f1(long double To){
	
	long double b = 2.0 * To; 

	return b;
	
}

long double t_pos_f2(long double r_ast, long double To, long double O){
	
	long double t = -r_ast + To + O;
	
	return t;
	
}

long double t_neg_f2(long double r_ast, long double To, long double O){
	
	long double t = -r_ast + To - O;
	
	return t;
	
}

long double b_f2(long double To){
		
	return 2.0 * To;
	
}

long double factores(long double t, long double b, long double p){
	
	double factores = pow(t, 2.0) - t * b + p * pow(b, 2.0);
	return factores;
	
}

long double rAste(long double r, long double s, long double T){
	
	long double r_ast = r * s * (T + 1.0) + r - s;
	return r_ast;
	
}

long double MFuncion(long double x, long double rAst, long double s, long double r, long double T){
	
	long double M = 2.0 * x * rAst + (s - 2.0) * (r * T + r - 1.0) + r; 
	return M;
	
}

long double calcularMCD(long double a, long double b) {
   
    if (b == 0) {
        return a;
    }
    
    return calcularMCD(b, fmod(a, b));

}

cpp_dec_float_100 powFunc(const cpp_dec_float_100& base, const cpp_dec_float_100& exponent){
	
    return pow(base, exponent);
    
}

cpp_dec_float_100 formulaNumPolinomial(const cpp_dec_float_100& r, const cpp_dec_float_100& p, const cpp_dec_float_100& n){
	
    cpp_dec_float_100 resultado = powFunc(n, 2.0) + (r-2)*n + p* powFunc(r, 2.0) - r + 1;
    return resultado;
    
}

cpp_dec_float_100 calculo_n(cpp_dec_float_100 s, cpp_dec_float_100 r, cpp_dec_float_100 x, cpp_dec_float_100 p, cpp_dec_float_100 T){
	
	
	cpp_dec_float_100 tramo1 = (s*((r-1.0)*s+r)*pow(x,2.0) + ((r-1)*pow(s,2.0)-(r-2.0)*s-r) * x + s*((r-1.0)*s+r)*p-(r-1.0)*s);
	cpp_dec_float_100 tramo2 = (pow(s, 2.0) *( pow(x, 2.0)+ x + p) -(2.0*x + 1)*s +1.0)*T*r;
	
	return tramo1 + tramo2;
	
}

void factorizacionCompleta(vector<long double> array3, long double factor_f1_f2){
	
	vector<long double> array4;
	
	bool salida = true;
	
	int contadorEnteros = 0;
	
	long double factores;
		
	array3.push_back(factor_f1_f2);
	
	bool escribir;
	
	long double numeroTemporal;
	
	long double numeroDividido;
		
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
	
		if(numeroTemporal == factor_f1_f2){
			
			for(long double x = 0; x < array4.size(); x++){
		
				cout << "Factor: " << array4[x] << endl;
		
			}
			
		}else{
													
			for(long double i = 0; i < array4.size(); i++){
					
				numeroDividido = factor_f1_f2 / array4[i];
					
				while(true){
						
					if(esEntero(numeroDividido) && numeroDividido != 1){
						
						cout << "Factor: " << array4[i] << endl;
						numeroDividido = numeroDividido/array4[i];
							
					}else{
							
						break;
							
					}
					
				}
					
			}
				
		}
	}			
}

int main(){
			
	cout << fixed << setprecision(0);
		
	long double Tphi;
	long double r;
	long double p;
	long double s;
	long double T;
	long double x;
	long double t_pos_f1_calculada;
	long double t_neg_f1_calculada;
	long double b_pos_f1_calculada;
	long double b_neg_f1_calculada;
	long double b_f1_calculada;
	long double rAst;
	long double M;
	long double t_pos_f2_calculada;
	long double t_neg_f2_calculada;
	long double b_f2_calculada;
	long double mcd;
	long double b_pos_f2_calculada;
	long double b_neg_f2_calculada;
	cpp_dec_float_100 n;
	cpp_dec_float_100 numeroPolinomial;
	cpp_int numeroPolinomialEntero;
	
	long double phiCalculada;
	
	bool salidaPrograma = true;
	
	while(salidaPrograma){
	
		vector<long double> array1;
		vector<long double> array2;
	
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
		
		if(s == 0){
			
			cout << "El valor de r no puede ser 0" << endl;
			
			continue;
			
		}
	
		cout << "Introduce valor x: ";
		cin >> x;
		
		cout << "Introduce valor T: ";
		cin >> T;
		
		auto start = chrono::high_resolution_clock::now();
		
		n = calculo_n(s, r, x, p, T);
			
		numeroPolinomial = formulaNumPolinomial(r, p, n);
		
		numeroPolinomialEntero = static_cast<cpp_int>(round(numeroPolinomial));
		
		cout << endl << "Número Polinomial: " << numeroPolinomialEntero << endl << endl;
			
		for(long double dominio = 0; dominio < 2; dominio++){
		
			if(dominio == 0){
					
				Tphi = 1;
					
			}else{	
					
				Tphi = -1;
				
			}
			
			while(true){
				
				phiCalculada = phi(Tphi, p, s, x);
				
				if(isnan(phiCalculada)) {
										
					break;
			
				}
		
				if(esEntero(phiCalculada)){
									
					t_pos_f1_calculada = t_pos_f1(s, Tphi, phiCalculada);
					t_neg_f1_calculada = t_neg_f1(s, Tphi, phiCalculada);
					b_f1_calculada = b_f1(Tphi);
										
					mcd = calcularMCD(t_pos_f1_calculada, b_f1_calculada);		
								
					t_pos_f1_calculada = t_pos_f1_calculada/mcd;
					b_pos_f1_calculada = b_f1_calculada/mcd;
														
					mcd = calcularMCD(t_neg_f1_calculada, b_f1_calculada);
										
					t_neg_f1_calculada = t_neg_f1_calculada/mcd;
					b_neg_f1_calculada = b_f1_calculada/mcd;
										
					array1.push_back(factores(t_pos_f1_calculada, b_pos_f1_calculada, p));
					array1.push_back(factores(t_neg_f1_calculada, b_neg_f1_calculada, p));
				
				}
								
				if(dominio == 0){
				
					Tphi++;
					
				}else{
						
					Tphi--;
					
				}
			
			}
		 
		}
		 
		 rAst = rAste(r, s, T);
		 
		 M = MFuncion(x, rAst, s, r, T);
		 		 
		 for(long double dominio = 0; dominio < 2; dominio++){
		
			if(dominio == 0){
					
				Tphi = 1;
					
			}else{

				Tphi = -1;
				
			}
			
		 
			while(true){
			 
				phiCalculada = phi_2(p, Tphi, M, rAst);
				
				if(isnan(phiCalculada)) {
					
					break;
			
				}
			
				if(esEntero(phiCalculada)){
									
					t_pos_f2_calculada = t_pos_f2(rAst, Tphi, phiCalculada);
					t_neg_f2_calculada = t_neg_f2(rAst, Tphi, phiCalculada);
					b_f2_calculada = b_f2(Tphi);
					
					mcd = calcularMCD(t_pos_f2_calculada, b_f2_calculada);		
				
					t_pos_f2_calculada = t_pos_f2_calculada/mcd;
					b_pos_f2_calculada = b_f2_calculada/mcd;
				
				
					mcd = calcularMCD(t_neg_f2_calculada, b_f2_calculada);
				
					t_neg_f2_calculada = t_neg_f2_calculada/mcd;
					b_neg_f2_calculada = b_f2_calculada/mcd;

					array2.push_back(factores(t_pos_f2_calculada, b_pos_f2_calculada, p));
					array2.push_back(factores(t_neg_f2_calculada, b_neg_f2_calculada, p));
				
				}
			 			 
				if(dominio == 0){
				
					Tphi++;
					
				}else{
					
					Tphi--;
					
				}
			 
			}
		
		}
		 
		factorizacionCompleta(array1, F1(s, x, p));
		factorizacionCompleta(array2, F2(p, rAst, M));
		
		auto end = chrono::high_resolution_clock::now();
	
		chrono::duration<double> elapsed = end - start;
	
		cout << fixed << setprecision(8);
	
		cout << endl << "Tiempo transcurrido: " << elapsed.count() << " segundos" << endl;
		
		cout << fixed << setprecision(0);
		
		}
			
		return 0;
	
}
