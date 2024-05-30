#include<iostream>
#include<Windows.h>
#include<conio.h>
#include<stdio.h>
#include<cmath>
#include<stdlib.h>
#include<string.h>
using namespace std;

void gotoxy(int x, int y);
void marco(int x1, int y1, int x2, int y2);
void menu();
void color();
void marcoYtitulo();
void integrantes();
int BinarioOctal(long long);
int BinarioDecimal(long long);
int main()
{
	int opc;
	long long NumeroBinario;
	int NumeroOctal, NumeroDecimal;
	long int i=0;
    char NumOctal[1000];
	do
	{
		color();
		marcoYtitulo();
		menu();
		integrantes();
		gotoxy(4,7); cout<<"Elija una de las siguientes conversiones: ";
		cin>>opc;
		switch(opc)
		{
			
			case 1:
				long long n;
				marco (82,7,111,13);
				gotoxy(87,9); cout<<"Los numeros binarios";
				gotoxy(90,10); cout<<"se escriben";
				gotoxy(87,11); cout<<"con digitos  0  y  1 ";
				gotoxy(41,10); cout<<"Conversion de binario a decimal.";
				gotoxy(41,11); cout<<"Ingresa un numero binario: ";
				cin>>n;
				gotoxy(41,13); cout<<n<<" en binario = "<<BinarioDecimal(n)<<" en decimal.";
				gotoxy(40,30);cout<<"   ";
				break;
			case 2:
				marco (82,7,111,13);
				gotoxy(87,9); cout<<"Los numeros octales";
				gotoxy(90,10); cout<<"se escriben";
				gotoxy(86,11); cout<<"con digitos del 0 al 7";
				gotoxy(41,10); cout<<"Conversion de octal a binario.";
				gotoxy(41,11); cout<<"Ingrese un numero octal: ";
				cin>>NumOctal;
        		gotoxy(41,13); cout<<"Conversion a binario: ";
        		while(NumOctal[i])
        		{
                	switch(NumOctal[i])
                	{
                        case '0' : cout<<"000";
                                break;
                        case '1' : cout<<"001";
                                break;
                        case '2' : cout<<"010";
                                break;
                        case '3' : cout<<"011";
                                break;
                        case '4' : cout<<"100";
                                break;
                        case '5' : cout<<"101";
                                break;
                        case '6' : cout<<"110";
                                break;
                        case '7' : cout<<"111";
                                break;
                        default : gotoxy(41,13);cout<<"  Numero octal invalido: "<<NumOctal[i];
                        		  gotoxy(43,14);cout<<" Enter para continuar.";
                                break;
               		}
                	i++;
        		}
				gotoxy(40,30);cout<<"   ";
				break;
			case 3:
				marco (82,7,111,13);
				gotoxy(87,9); cout<<"Los numeros binarios";
				gotoxy(90,10); cout<<"se escriben";
				gotoxy(87,11); cout<<"con digitos  0  y  1 ";
				gotoxy(41,10); cout<<"Conversion de binario a octal.";
				gotoxy(41,11); cout<<"Ingrese un numero binario: ";
				cin>>NumeroBinario;
				gotoxy(41,13); cout<<NumeroBinario<<" en binario = "<<BinarioOctal(NumeroBinario)<<" en octal.";
				gotoxy(40,30);cout<<"   ";
				break;
			case 4:	
				gotoxy(68,10);cout<<"Enter para salir.";
				gotoxy(40,30);cout<<"   ";
				break;
			default:
				gotoxy(68,10);cout<<"Opcion inexistente.";
				gotoxy(61,11);cout<<"Dar enter para elegir otra opcion.";
				gotoxy(40,30);cout<<"   ";
				break;
		}
		system("pause");
		system("cls");
	}
	while(opc!=4);
	cout<<" ";
	return 0;	
}
//Funciones
void menu()
{
	gotoxy(6, 10); cout<<"1.-Binario-Decimal."<<endl;
	gotoxy(6, 11); cout<<"2.-Octal-Binario."<<endl;
	gotoxy(6, 12); cout<<"3.-Binario-Octal."<<endl;
	gotoxy(6, 13); cout<<"4.-Salir."<<endl;
}
//Funcion BINARIO A DECIMAL
int BinarioDecimal(long long n)
{
	int NumeroDecimal = 0, i = 0, residuo;
	while(n!=0)
	{
		residuo = n%10;
		n/=10;
		NumeroDecimal += residuo*pow(2, i);
		++i;
	}
	return NumeroDecimal;
}

//Funcion BINARIO A OCTAL
int BinarioOctal(long long NumeroBinario)
{
	int NumeroOctal = 0, NumeroDecimal = 0, i = 0;
	while(NumeroBinario != 0)
	{
		NumeroDecimal += (NumeroBinario%10)*pow(2, i);
		++i;
		NumeroBinario/=10;
	}
	i=1;
	while(NumeroDecimal !=0)
	{
		NumeroOctal +=(NumeroDecimal%8)*i;
		NumeroDecimal/=8;
		i*= 10;
	}
	return NumeroOctal;
}
//Funciones de los marcos.
void gotoxy(int x, int y)
{
	HANDLE hcon;
	hcon = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD dwPos;
	dwPos.X = x;
	dwPos.Y = y;
	SetConsoleCursorPosition(hcon, dwPos);
}

void marco(int x1, int y1, int x2, int y2)
{
	int i;
	for(i=x1; i<x2; i++)
	{
		gotoxy(i, y1); printf("%c", 205);
		gotoxy(i, y2); printf("%c", 205);
	}
	for(i=y1; i<y2; i++)
	{
		gotoxy(x1, i); printf("%c", 186);
		gotoxy(x2, i); printf("%c", 186);
	}
	gotoxy(x1, y1); printf("%c", 201);
	gotoxy(x1, y2); printf("%c", 200);
	gotoxy(x2, y1); printf("%c", 187);
	gotoxy(x2, y2); printf("%c", 188);
}

void color()
{
	system("COLOR 1F");
}

void marcoYtitulo()
{
	//Marco exterior y central
	marco(0,0,119,29);
	marco(30,1,89,4);
	//Marcos izquierda SUPERIOR
	marco (25,1,29,4);
	marco (20,1,24,4);
	marco (16,1,19,4);
	marco (12,1,15,4);
	marco (9,1,11,4);
	marco (6,1,8,4);
	marco (3,1,5,4);
	marco (1,1,2,4);
	//Marcos derecha SUPERIOR
	marco (90,1,94,4);
	marco (95,1,99,4);
	marco (100,1,103,4);
	marco (104,1,107,4);
	marco (108,1,110,4);
	marco (111,1,113,4);
	marco (114,1,116,4);
	marco (117,1,118,4);
	//Marcos izquierda y central INFERIORES
	marco (1,27,3,28);
	marco (4,27,7,28);
	marco (8,27,12,28);
	marco (13,27,16,28);
	marco (17,27,19,28);
	marco (20,27,23,28);
	marco (24,27,28,28);
	marco (29,27,34,28);
	marco (35,27,39,28);
	marco (40,27,46,28);
	marco (47,27,51,28);
	marco (52,27,55,28);
	marco (56,27,63,28);
	//Marcos derecha INFERIORES
	marco (116,27,118,28);
	marco (112,27,115,28);
	marco (107,27,111,28);
	marco (103,27,106,28);
	marco (100,27,102,28);
	marco (96,27,99,28);
	marco (91,27,95,28);
	marco (85,27,90,28);
	marco (80,27,84,28);
	marco (73,27,79,28);
	marco (68,27,72,28);
	marco (64,27,67,28);
	
	//Marcos izquierda y central CENTRO
	marco (1,16,3,17);
	marco (4,16,7,17);
	marco (8,16,12,17);
	marco (13,16,16,17);
	marco (17,16,19,17);
	marco (20,16,23,17);
	marco (24,16,28,17);
	marco (29,16,34,17);
	marco (35,16,39,17);
	marco (40,16,46,17);
	marco (47,16,51,17);
	marco (52,16,55,17);
	marco (56,16,63,17);
	//Marcos derecha CENTRO
	marco (116,16,118,17);
	marco (112,16,115,17);
	marco (107,16,111,17);
	marco (103,16,106,17);
	marco (100,16,102,17);
	marco (96,16,99,17);
	marco (91,16,95,17);
	marco (85,16,90,17);
	marco (80,16,84,17);
	marco (73,16,79,17);
	marco (68,16,72,17);
	marco (64,16,67,17);		
	//Título
	gotoxy(43,2); cout<<"C  O  N  V  E  R  S  I  O  N  E  S";
}

void integrantes()
{
	gotoxy(48, 19);cout<<"I N T E G R A N T E S:";
	gotoxy(20, 22);cout<<"1.-";
	gotoxy(20, 23);cout<<"2.-";
	gotoxy(20, 24);cout<<"3.-";
	gotoxy(61, 22);cout<<"4.-";
	gotoxy(61, 23);cout<<"5.-";
	gotoxy(61, 24);cout<<"6.-";
}
