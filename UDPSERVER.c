//Program for UDP server...
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
int main() {
int sock;
int len;
char out_buf[100];
char in_buf[100];
struct sockaddr_in server,client;
sock=socket(AF_INET, SOCK_DGRAM, 0);
server.sin_family=AF_INET;
server.sin_port=htons(PORT_NUM);
server.sin_addr.s_addr=htonl(INADDR_ANY);
len=sizeof(struct sockaddr_in);
bind(sock, (struct sockaddr *)&server,len);
printf("Server is waiting...\n");
recvfrom(sock, in_buf, sizeof(in_buf), 0, (struct sockaddr*)&client, &len);
printf("Request accepted....\n");
printf("Received from client...Mesg='%s'\n", in_buf);
strcpy(out_buf, "Hi... Mr. Client..I hv gt ur message");
sendto(sock, out_buf, (strlen(out_buf)+1), 0, (struct sockaddr*)&client, len);
close(sock);
}