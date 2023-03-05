#pragma once

#include <iostream>
#include <cmath>
#include <fstream>
#include <cstdlib>
#include <assert.h>
#include <vector>
#include <algorithm>

#include "random.h"

using namespace std;
#define _USE_MATH_DEFINES

int M=pow(10,6); 	//Total Number of throws
int N=100; 		//Total Number of blocks
int L=int(M/N); 	//Number of throws in each block

double error(const vector<double> ave1, const vector<double> ave2, const int n){
	if(n==0){
		return 0;}
	else{
		return sqrt((ave2[n]-pow(ave1[n],2))/n);}
}
	

template <typename T> vector<T> ReadData( const char* filename) {
	vector<T> v;
	ifstream fin(filename);
	if (!fin) { 
		cerr <<"Non esiste il file"<< filename <<endl;
		exit(-1);
	}
	else {
		while(!fin.eof()) {
			T a;
			fin >> a;
			v.push_back(a);
			// assert( !(fin.eof() )&& "Lettura file finita" );	
		}
	}
	fin.close();
	return v;
}

template <typename T> void Printfile(const vector<T> &v, const char* filename){
	ofstream outf(filename);
	for(T elem: v){outf<<elem<<"\n";}
	outf.close();
}

template <typename T> void Printfile_2(const vector<T> &v1,const vector<T> &v2, const char* filename){
	ofstream outf(filename);
	if(v1.size() != v2.size()){
		cerr <<"Error: vectors with different sizes\n";}
	else{
		for(int i=0; i<int(v1.size()); i++){
			outf<< v1[i] <<","<< v2[i] <<"\n";}
	}
	outf.close();
}	

void pray_the_sun(Random &rnd){
   int seed[4];
   int p1, p2;
   ifstream Primes("Primes");
   if (Primes.is_open()){
      Primes >> p1 >> p2 ;
   } else cerr << "PROBLEM: Unable to open Primes" << endl;
   Primes.close();

   ifstream input("seed.in");
   string property;
   if (input.is_open()){
      while ( !input.eof() ){
         input >> property;
         if( property == "RANDOMSEED" ){
            input >> seed[0] >> seed[1] >> seed[2] >> seed[3];
            rnd.SetRandom(seed,p1,p2);
         }
      }
      input.close();
   } else cerr << "PROBLEM: Unable to open seed.in" << endl;	
}


	
	
	
	
	
	
	
	
	
	
	
	
