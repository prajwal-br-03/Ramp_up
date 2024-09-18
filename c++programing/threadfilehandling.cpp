#include <iostream>
#include <fstream>
#include <string>
#include <mutex>
#include <thread>


using namespace std;
mutex mut1;



void addtexttofile(string filename){
    ofstream fout;
    string sin;
    lock_guard<mutex> lock(mut1);
    cout<<"Enter the text to insert into the file"<<endl;
    fout.open(filename,ios::app);
    while(fout){
    	getline(cin, sin);
       	if(sin == "-1"){
	 	break;
	 }
	 fout<<sin<<endl;
    }
    if(!fout){
    	cerr<<"Error opening file for writing:"<<endl;
	return;
    }

	fout.close();

}
void showfile(string filename){
	string line;
	ifstream fin;
	lock_guard<mutex> lock(mut1);
	fin.open(filename);
	while(fin){
		getline(fin, line);
		cout<<line<<endl;
	}
	fin.close();

}

int main(){

	string fname;
	string sin;
	cout<<"Enter the file name"<<endl;
	cin>>fname;
	int option;
	cout<<"select an option"<<endl;
	cout<<"Press 1 to insert into the file"<<endl;
	cout<<"Press 2 to show the content of file"<<endl;
	cin>>option;
	if(option == 1){
		addtexttofile(fname);
	}else if(option == 2){
		showfile(fname);
	}else{
		cout<<"invalid option"<<endl;
	}
        thread t1(addtexttofile,fname);
	thread t2(showfile,fname);
	thread t3(addtexttofile,fname);
        t1.join();
	t3.join();
	t2.join();
	return 0;
}

