//Program for UDP client...
#include<sys/types.h>
#include<sys/socket.h>
#include<stdio.h>
#include<string.h>
#include<netinet/in.h>
#include<arpa/inet.h>
#include<unistd.h>
#include<netdb.h>
#include<fcntl.h>
#define PORT_NUM 1500
#define SERVER_IP "192.168.56.1"
int main() {
int sock;
int len;
char out_buf[100];
char in_buf[100];
struct sockaddr_in server;
sock=socket(AF_INET, SOCK_DGRAM, 0);
server.sin_family=AF_INET;
server.sin_port=htons(PORT_NUM);
server.sin_addr.s_addr=inet_addr(SERVER_IP);
len=sizeof(struct sockaddr_in);
strcpy(out_buf, "Hello..Mr.Server..I am connenting with u..");
sendto(sock, out_buf, (strlen(out_buf)+1), 0, (struct sockaddr*)&server, len);
recvfrom(sock, in_buf, sizeof(in_buf), 0, (struct sockaddr*)&server, &len);
printf("Received from Server...Mesg='%s'\n", in_buf);
close(sock);
}