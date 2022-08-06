#include <iostream>
#include <string.h>
#include <cstdlib>
#include <fstream>
#include <string>


using namespace std ;

struct login{
	
 char name[200];
 char password[200]; 
 int cargo ;
	
};

void createUser( string n , string p , int t ){
	
	login log ; 
	
	fstream dataUser("login.dat",ios::out|ios::in );
	
		dataUser.seekp( 0 , dataUser.end);
		 
			strcpy( log.name , n.c_str() ); 
			strcpy( log.password , p.c_str() ); 
			log.cargo = t ; 
			
		dataUser.write( (const char * ) (&log), sizeof(login) );
	
	dataUser.close();
	
	
}

bool userExist( string n ){
	
	login log ; 
	
	fstream dataUser("login.dat",ios::in|ios::out);
	
		dataUser.read((char *)(&log),sizeof(login));
		
		while( dataUser && !dataUser.eof() ) {
			
			if( strcmp( log.name , n.c_str() ) == 0 ){
				dataUser.close();
				return true;
			} 
			
			dataUser.read((char *)(&log),sizeof(login));
		}
	
	dataUser.close();
	return false ;
	
}

bool loginUser( string n , string p ){
	
	login log ; 
	fstream dataUser("login.dat",ios::in|ios::out);
	
	dataUser.read((char *)(&log),sizeof(login));
		
		while( dataUser && !dataUser.eof() ) {
			
			if( strcmp( log.name , n.c_str() ) == 0 && strcmp ( log.password , p.c_str() )  == 0 ){
				dataUser.close();
				return true;
			} 
			
			dataUser.read((char *)(&log),sizeof(login));
		}
		
	
	
	dataUser.close(); 
	
}

int main ( ){
	
	int op  ,  t ; 
	string  senha , nome ;
	
	fstream dataUser("login.dat",ios::out|ios::app );
	dataUser.close();
	
	do{
		
		cout << "------------Cadastro Usuario----------" << endl; 
		cout << "1-login \n2- Registrar "<< endl; 
		cin >> op ; 
		
		if( op == 1 ){
			
			cout << "Digite seu nome " << endl;
			cin.ignore();
			getline(cin , nome );
			cout << "Digite sua senha " << endl; 
			getline( cin , senha );
			
				if( loginUser( nome , senha ) ) {
					cout << "Logado com sucesso" << endl;
				}else{
					cout << "Nome de usuario ou senha invalidos, tente novamente " << endl;
				}
			
		}
		
		if( op ==  2 ){
			
			cout << "Digite seu nome " << endl;
			cin.ignore();
			getline(cin , nome );
			cout << "Digite sua senha  " << endl; 
			getline( cin , senha ); 
			cout << "Voce eh admin ou Usuario {1 - adm 2 - user}" << endl; 
			cin >> t ;
			
				if( !userExist( nome ) ){
					createUser( nome , senha , t) ;
					cout << "Usuario cadastrado com sucesso " << endl;
				}else{
					cout << "Usuario ja existe na aplicacao " << endl;
				}
			
			
		}
		
		system("pause");
		system("cls"); 
	
	}while( op  != 0 );
	
	
}

