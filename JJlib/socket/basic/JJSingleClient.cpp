#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <netdb.h>


using namespace std;

int main(void){

	int sockfd, portno;
	struct sockaddr_in server_addr;

	char buff[1024];
	memset(buff,0x00,sizeof(buff));
	portno = 1234;
	
	//create socket
	sockfd = socket(AF_INET, SOCK_STREAM, 0);
	if(sockfd < 0){
		cout << "socket create fail!" << endl;
		return -1;
	}
	
	bzero((char*)&server_addr, sizeof(server_addr));

	server_addr.sin_family = AF_INET;
	server_addr.sin_port = htons(portno);
	server_addr.sin_addr.s_addr = inet_addr("127.0.0.1");

	if(connect(sockfd, (struct sockaddr*)&server_addr, sizeof(server_addr)) < 0){
		cout << "connect error" << endl;
	}
	cout << "server connect success" << endl;

	
	cout << "enter the message " << endl;
	cin >> buff ;
	send(sockfd, buff, sizeof(buff), MSG_CONFIRM);
	cout << "send msg!" << endl;

	memset(buff,0x00,sizeof(buff));
	
        recv(sockfd, buff, sizeof(buff), MSG_WAITALL);
	cout << "recv msg! [" << buff << "]" << endl;


	close(sockfd);


	return 0;
}
