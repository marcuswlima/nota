#include <iostream>
#include <cmath>
using namespace std;

/*Calcular o MDC de dois números*/
int CalcMdc(int x, int y);
/*Apresenta o resto da divisão de 2 números*/
int GetRemainder(int, int);
/*Indica se a divisão de 2 números gera resto*/
bool HasRemainder(int, int);
/*Indica se o número é par*/
bool IsEven(int);
/*Indica se o número é primo*/
bool IsPrime(int entrou);
/*Calcula a potência (recursividade)*/
int CalcPower(int base, int expoent);
/*Calcula a hipotenusa para 2 lados de um triâgulo*/
double CalcHypotenuse(double c1, double c2);
/*Calcula o fatorial de um número*/
long CalcFatorial(long numero);
/*Calcula o numero de um inteiro*/
double CalcCatalan(long numero);
/*Calcula as 2 raizes de uma equação 2g*/
string CalcRealRoots(int a, int b, int c);
/*Gera um inteiro aleatório dentro de uma faixa de inteiros*/
int GerarInteiro(int menor, int maior);
