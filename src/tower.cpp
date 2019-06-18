#include "tower.h"

Tower::Tower(int _n){

	reset(_n);
}

Tower::~Tower(){

	for(int i=0; i<n; i++)	delete [] tablero[i];
	delete [] tablero;
	delete [] moviendo;
	delete [] cursor;
	n = 0;
	cont = 0;
}

void Tower::setTablero(int disco){

	for(int i=0; i<this->n; i++)	for(int j=0; j<3; j++)	if(tablero[i][j] == disco)	tablero[i][j] = 0;
}

void Tower::setTablero(int disco, int col){

	bool x = false;

	for(int i=n-1; i>=0 && !x; i--){
		if(tablero[i][col] == 0){
			tablero[i][col] = disco;
			x = true;
		}
	}
}

void Tower::setMoviendo(int pos){

	bool x = true, m = true;
	int y = this->n-1, i = 0;

	if(moviendo[pos] == 0){
		while(i < this->n && x){
			if(tablero[i][pos] != 0){
				moviendo [pos] = tablero[i][pos];
				tablero[i][pos] = 0;
				x = false;
			}
			i++;
		}
		if(x)	moviendo[pos] = 0;
		this->setCont();
	}else{
		for(int i=this->n-1; i>=0; i--)	if(tablero[i][pos]!=0) y=i-1;

		if(y != this->n-1)	if(moviendo[pos] > tablero[y+1][pos])	m=false;

		if(y == this->n-1){
			tablero[y][pos] = moviendo[pos];
			moviendo[pos] = 0;
		}else{
			if(m){
				tablero[y][pos] = moviendo[pos];
				moviendo[pos] = 0;
			}
		}
	}
}

void Tower::setMoviendo(int pos, char c){

	if(c == 'a'){
		if(pos == 2){
			moviendo[pos] = moviendo[pos-2];
			moviendo[pos-2] = 0;
		}else{
			moviendo[pos] = moviendo[pos+1];
			moviendo[pos+1] = 0;
		}
	}

	if(c == 'd'){
		if(pos == 0){
			moviendo[pos] = moviendo[pos+2];
			moviendo[pos+2] = 0;
		}else{
			moviendo[pos] = moviendo[pos-1];
			moviendo[pos-1] = 0;
		}
	}
}

void Tower::setCursor(int pos, char c){

	if(c == 'a'){
		cursor[pos] = false;
		if(pos == 0)	cursor[pos+2] = true;
		else	cursor[pos-1] = true;
	}

	if(c == 'd'){
		cursor[pos] = false;
		if(pos == 2)	cursor[pos-2] = true;
		else	cursor[pos+1] = true;
	}

}

void Tower::setCont(){

	cont++;
}

int Tower::getTablero(int fil, int col){

	return tablero[fil][col];
}

int Tower::getMoviendo(int pos){

	return moviendo[pos];
}

int Tower::getCursor(){

	int aux;

	for(int i=0; i<3; i++)	if(cursor[i] == true)	aux = i;

	return aux;
}

bool Tower::getCursor(int pos){

	return cursor[pos];
}

int Tower::getN(){

	return n;
}

int Tower::getCont(){
	
	return cont;
}

void Tower::follow(char c){

	this->setMoviendo(this->getCursor(), c);
}

void Tower::ToH (int n, int ini, int fin, int aux, bool v) {

	if(!v){
		if (n == 1){
			mostrar(n,fin);
			cout << endl << "  1  2  3" << endl << endl << "  mover el disco 1 de "<< ini << " a "<< fin << endl;
			cin.get();
		}
		else{
			ToH(n-1, ini, aux, fin,v);
			mostrar(n,fin);
			cout << endl << "  1  2  3" << endl <<  endl << "  mover el disco " << n << " de "<< ini << " a "<< fin << endl;
			cin.get();
			ToH(n-1, aux, fin, ini, v);
		}
	}else{
		if (n == 1)	cout << endl << "  mover el disco 1 de "<< ini << " a "<< fin << endl;
		else{
			ToH(n-1, ini, aux, fin, v);
			cout <<  endl << "  mover el disco " << n << " de "<< ini << " a "<< fin << endl;
			ToH(n-1, aux, fin, ini, v);
		}
	}

}

void Tower::mostrar(int n, int fin){

	system("clear");
	this->setTablero(n);
	this->setTablero(n,fin-1);

	cout << endl << endl;
	for(int i=0; i<this->getN(); i++){
		for(int j=0; j<3; j++)	cout << "  " << this->getTablero(i,j);
		cout << endl;
	}
}

void Tower::mostrarAyuda(){

	cout << endl << endl << endl;
	for(int i=0; i<3; i++) cout << "  " << this->getCursor(i);
	cout << "	_____ cursor (posicion donde apuntas)" << endl << endl;

	for(int i=0; i<3; i++) cout << "  " << this->getMoviendo(i);
	cout << "	_____ el disco que estas moviendo" << endl << endl;

	for(int i=0; i<this->getN(); i++){
		for(int j=0; j<3; j++)	cout << "  " << this->getTablero(i,j);

		cout << "	_____tablero" << endl;
	}

	cout << endl << endl << endl << "  Utiliza  'a' / 'd'  para mover el curso"<< endl;
	cout << endl << "  Utiliza  'w' / 's'  para sacar y colocar los discos"<< endl;
}

void Tower::reset(int _n){
	
	this->n = _n;
	cont = 0;
	tablero = new int*[this->n];
	moviendo = new int[3];
	cursor = new bool[3];

	for(int i=0; i<n; i++)	tablero[i] = new int[3];

	for(int i=0; i<3; i++){
		moviendo[i] = 0;
		cursor[i] = false;
	}
	cursor[0] = true;

	for(int i=n-1; i>=0; i--)	for(int j=0; j<3; j++)	tablero[i][j] = 0;

	for(int i=n-1; i>=0; i--)	tablero[i][0] = i+1;
}

