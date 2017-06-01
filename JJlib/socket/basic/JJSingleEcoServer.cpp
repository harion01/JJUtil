#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>

#include <stdio.h>
#include <errno.h>



using namespace std;



int main(void){
	struct sockaddr_in server_adder, client_adder;
	int server_fd, client_fd;
	int portno;
	char buff[1024]; 
	socklen_t cli_len;
	
	//create server socket
	server_fd = socket(AF_INET, SOCK_STREAM, 0);
	if(server_fd < 0){
		cout << "server socket create fail!" << endl;
		//todo : check errno and errmsg.
		//todo : use try / catch exception
		return -1;
	}
	
	//setup server_adder information
	bzero((char*) &server_adder, sizeof(server_adder));
	portno = 1234;
	
	server_adder.sin_family = AF_INET;
	server_adder.sin_addr.s_addr = INADDR_ANY;
	server_adder.sin_port = htons(portno);

	//bind port to serverfd with server_adder information
	if(bind(server_fd, (struct sockaddr*)&server_adder, sizeof(server_adder)) < 0){
		cout << "server port bind fail!" << endl;
		//todo : check errno and errmsg.
		//todo : use try / catch exception
		return -1;
	}

	//open port for listen - now client can connect this port
	if(listen(server_fd, 10) < 0){
		cout << "server port bind fail!" << endl;
		//todo : check errno and errmsg.
		//todo : use try / catch exception
		return -1;
	}

	client_fd = accept(server_fd, (struct sockaddr*)&client_adder, &cli_len);
	if(client_fd < 0){
		perror ("accept");
		cout << "accept client fail!" << endl;
		//todo : check errno and errmsg.
		//todo : use try / catch exception
		return -1;
	}

	cout << "server : got connection from [" << inet_ntoa(client_adder.sin_addr) << 
		"] port [" << portno << "]" << endl;
	
	memset(buff, 0x00, sizeof(buff));
	       ssize_t recv(int server_fd, void *buf, size_t len, int flags);
	
	//todo : check options of send
	recv(client_fd, buff, sizeof(buff), MSG_WAITALL);

	cout << "server got message [" << buff << "]" << endl;
	
	//todo : check options of send
	send(client_fd, buff, sizeof(buff), MSG_CONFIRM);

	close(client_fd);
	close(server_fd);

	return 0;
}
