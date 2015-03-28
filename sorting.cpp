/*
* Can Guney Aksakalli
* Comparing Quicksort, Insertion Sort and Radix Sort
*/

#include <iostream>
#include <iomanip>
#include <ctime>
#include <fstream>
#include <stdlib.h>
#include <string>
#define SIZE 1000 // array size
using namespace std;

struct mystruct{
	int number;
	string word;
};

int readData(const char *fileName, mystruct *a); //file reading returns n that contains number of integer information
void writeData(const char *fileName, mystruct *a, int n); //file writing

//sorting functions:
void quicksort(mystruct *inputs, int N);
void insertionsort(mystruct *inputs,int n);
void radixsort(mystruct *inputs,int n);

int main(){

	mystruct A[SIZE];
	clock_t sort_start_clk;
	int n;

	//Quicksort, data1.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data1.txt", A);
		quicksort(A,n);
	}
	writeData("quicksort1.txt",A,n);
	cout<<"Quicksort (data1.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	//Quicksort, data2.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data2.txt", A);
		quicksort(A,n);
	}
	writeData("quicksort2.txt",A,n);
	cout<<"Quicksort (data2.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	//Quicksort, data3.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data3.txt", A);
		quicksort(A,n);
	}
	writeData("quicksort3.txt",A,n);
	cout<<"Quicksort (data3.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	//Radixsort, data1.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data1.txt", A);
		radixsort(A,n);
	}
	writeData("radixsort1.txt",A,n);
	cout<<"Radixsort (data1.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	//Radixsort, data2.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data2.txt", A);
		radixsort(A,n);
	}
	writeData("radixsort2.txt",A,n);
	cout<<"Radixsort (data2.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	//Radixsort, data3.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data3.txt", A);
		radixsort(A,n);
	}
	writeData("radixsort3.txt",A,n);
	cout<<"Radixsort (data3.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	//Insertionsort, data1.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data1.txt", A);
		insertionsort(A,n);
	}
	writeData("insertionsort1.txt",A,n);
	cout<<"Insertionsort (data1.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	//Insertionsort, data2.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data2.txt", A);
		insertionsort(A,n);
	}
	writeData("insertionsort2.txt",A,n);
	cout<<"Insertionsort (data2.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	//Insertionsort, data3.txt
	sort_start_clk= clock();
	for(int i=0;i<1000;i++){
		n=readData("data3.txt", A);
		insertionsort(A,n);
	}
	writeData("insertionsort3.txt",A,n);
	cout<<"Insertionsort (data3.txt) duration :"<<((clock()-sort_start_clk)/(CLOCKS_PER_SEC/1000))<<endl;

	return 0;
}



int readData(const char *fileName, mystruct *a)
{
	fstream file;
	file.open(fileName , ios::in);
	int tmp;
	int n=0;
	while(file >> tmp){
		a[n].number=tmp;
		file >> a[n].word;
		n++;
	}
	file.close();
	return n;
}

void writeData(const char *fileName, mystruct *a, int n)
{
	ofstream myfile(fileName,ios::out);
	int i=0;
	while(i<n){
		myfile<<a[i].number<<"\t"<<a[i].word<<endl;
		i++;
	}
	myfile.close();
}

//sorting functions:
void quicksort(mystruct *inputs, int N)
{
	int i, j;
	mystruct t,v;
	if( N <= 1 ) return;
	// Partition elements
	v = inputs[0];
	i = 0;
	j = N;
	while(1)
	{
		while(inputs[++i].number > v.number && i < N) { }
		while(inputs[--j].number < v.number ) { }
		if( i >= j ) break;
		t = inputs[i];
		inputs[i] = inputs[j];
		inputs[j] = t;
	}
	t = inputs[i-1];
	inputs[i-1] = inputs[0];
	inputs[0] = t;
	quicksort(inputs, i-1);
	quicksort(inputs+i, N-i);
}

void insertionsort(mystruct *inputs,int n)
{
	int k;
	for(k=1;k<n;++k)
	{
		mystruct key=inputs[k];
		int i=k-1;
		while((i>=0) && (key.number > inputs[i].number))
		{
			inputs[i+1]=inputs[i];
			--i;
		}
		inputs[i+1]=key;
	}
}


void radixsort(mystruct *inputs,int n)
{
	mystruct b[n];
	int i,m=0,exp=1;


	for(i=0;i<n;i++)
	{
		if(inputs[i].number > m)
		m=inputs[i].number;
	}

	while(m/exp>0)
	{
		int bucket[10]={0};

		for(i=0;i<n;i++)
		bucket[inputs[i].number/exp%10]++;

		for(i=8;i>=0;i--)
		bucket[i]+=bucket[i+1];

		for(i=n-1;i>=0;i--)
		b[--bucket[inputs[i].number/exp%10]]=inputs[i];

		for(i=0;i<n;i++)
		inputs[i]=b[i];

		exp*=10;
	}
}
