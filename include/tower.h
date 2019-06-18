#ifndef __TOWER_H
#define __TOWER_H

#include <iostream>

using namespace std;

class Tower{
	
	private:
		int **tablero;
		int *moviendo;
		bool *cursor;
		int n;
		int cont;
	public:
		Tower(int _n);
		~Tower();
		
		void setTablero(int disco, int col);
		void setTablero(int disco);
		void setMoviendo(int pos);
		void setMoviendo(int pos, char c);
		void setCursor(int pos, char c);
		void setCont();
		int getTablero(int fil, int col);
		int getMoviendo(int pos);
		int getCursor();
		bool getCursor(int pos);
		int getN();
		int getCont();
		void follow(char c);
		void ToH (int n, int ini, int fin, int aux, bool v);
		void mostrar(int n, int fin);
		void mostrarAyuda();	
		void reset(int _n);
		
		friend ostream& operator << (ostream& output, const Tower& t);
};

inline ostream& operator << (ostream& output, Tower& t){

	output << endl;
	for(int i=0; i<3; i++) output << "  " << t.getCursor(i);
	output << endl << endl;

	for(int i=0; i<3; i++) output << "  " << t.getMoviendo(i);
	output << endl << endl;

	for(int i=0; i<t.getN(); i++){
		for(int j=0; j<3; j++)	output << "  " << t.getTablero(i,j);
		output << endl;
	}
	output << endl;
	return output;
}

#endif
