#include<iostream>
#include "tower.h"
#include <cmath>
using namespace std;

int main () {
	
	int n,y=0, ini=1, fin=3, aux=2;
	char x;
	bool game = true, v;

	system("clear");
	cout << endl << "	Entroduce el numero de disco" << endl;
	cin >> n;

	Tower t(n);
	
	while(y!=6){

		cout << endl << "		TOWER OF HANOI" << endl;
		cout << endl << endl << "		Opciones " << endl << endl << "	1. Jugar" << endl << "	2. Mostrar paso a paso " << endl << "	3. Mostrar los pasos" << endl << "	4. Mostrar el numero de pasos minimos" << endl << "	5. Ayuda sobre al juego" << endl << "	6. Salir" << endl;
		cin >> y;

		system("clear");
		switch(y){
			case 1:
				cout << t;
				while(game){
					cin >> x;
					switch(x){
						case 'a':
							t.setCursor(t.getCursor(),x);  
							t.follow(x);
							system("clear");
							cout << t;
							break;
						case 'd':
							t.setCursor(t.getCursor(),x);
							t.follow(x);
							system("clear");
							cout << t;
							break;
						case 'w':   
							t.setMoviendo(t.getCursor());
							system("clear");
							cout << t;
							break;
						case 's':
							t.setMoviendo(t.getCursor());
							system("clear");
							cout << t;
							break;
						default:
							cout << endl << endl << "  el movimiento introducido es invalido, intentalo de nuevo." << endl;
							break;
					}
					game = !(t.getTablero(0,2)==1);
				}
				if (!game){
					cout << endl << "	HAS GANADO"<< endl << endl << endl; 
					if(t.getCont() == pow(2,n)-1)	cout << "	Has conseguido terminar el tower de hanoi con los minimos pasos ! ( " << pow(2,n)-1 << " pasos )" << endl;
					else	cout << "	Has utilizado " << t.getCont() << " pasos." << endl << endl << "	He necesita " << pow(2,n)-1 << " pasos como minimo para colocar todos los discos al final del tablero." << endl << endl;
				}
				t.~Tower();
				t.reset(n);
				break;
			case 2:
				v=false;
				system("clear");
				cout << endl << endl;
				for(int i=0; i<t.getN(); i++){
					for(int j=0; j<3; j++){
						cout << "  " << t.getTablero(i,j);	
					}
					cout << endl;
				}
				cout << endl << "  1  2  3" << endl << endl << "  posicion inicial";
				cin.ignore();
				cin.get();
		 		t.ToH(n,ini,fin,aux,v);
				t.~Tower();
				t.reset(n);
				break;
			case 3:
				v=true;
				system("clear");
		 		t.ToH(n,ini,fin,aux,v);
				cout << endl;
				break;
			case 4:
				cout << endl << endl << "  se necesita " << pow(2,n)-1 << " pasos como minimo para colocar todos los discos al final del tablero."<< endl << endl; 
				break;
			case 5:
				system("clear");
				t.mostrarAyuda();
				cout << endl<< endl;
				break;
			case 6:
				break;
			default:
				cout << endl << endl << "  no existe dicha opcion, intentalo de nuevo." << endl;
				break;
		}
	}
	
	return 0;
}

