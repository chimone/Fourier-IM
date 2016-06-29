#include <winsock2.h>
#include <windows.h>
#include <iostream>

using namespace std;

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

void initWSA();
SOCKET createSocket();

int main(int argc, char** argv) {
	SOCKET s;
	
	initWSA();
	s = createSocket();
	
	return 0;
}

void initWSA(){
	long rc;
	WORD version;
	WSADATA wsa;
	
	version = (2<<8)+1;
	rc = WSAStartup(version, &wsa);
	
	if(rc != 0) {
		cout<<"Fehler! \n";
		return 1;
	}
}

SOCKET createSocket(){
	SOCKET s;
	s = socket(AF_INET, SOCK_STREAM, 0);
	if(s == INVALID_SOCKET){
		cout<<"Fehler beim Erstellen des sockets!";
		return 1;
	}
	return s;
}
