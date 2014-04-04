//	#Stanciu Catalin 322CA - Tema 1 PC
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h> 
#include <sys/types.h>
#include <sys/stat.h>
#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10000
//Transformare checksum in sir binar pentru afisarea in log
char *int2bin(int a, char *buffer, int buf_size) {
	buffer += (buf_size - 1);
	int i = 0;
	for (i = 7; i >= 0; i--) {
		*buffer-- = (a & 1) + '0';
		a >>= 1;
	}
	return buffer;
}
void printSubstringToFile(FILE* f, char*buf, int buf_size) {
	int i;
	for (i = 0; i < buf_size; i++) {
		fprintf(f, "%c", buf[i]);
	}
}
//fucntia calculeaza checsumul pentru un sir de caractere;
char checksum(char * s) {
	char x;
	x = s[0];
	int i = 0;
	for (i = 1; i < strlen(s); i++) {
		x = x ^ s[i];
	}
	return x;
}
//functia sender
void sender(char * file) {
	srand(time(NULL));
	int rand_len = rand() % 59 + 1;
	msg s; /* cadru de trimis */
	msg *t = (msg*) malloc(sizeof(msg));
	char buffer[70] = " "; /* buffer pentru date */
	int next_frame_to_send = 0; /* initializare sequence number */

	int f = open(file, O_RDONLY); //deschidere fisier pentru citire;

	FILE *g = fopen("log.txt", "w");
	fclose(g); //creare fisier log.txt sau golirea acestuia.

	time_t timer; //initializarea timpului.
	struct tm * timeinfo;
	
	char check;
	char nfts;
	int seq_recv = 0;
	char check_recv;
	char bin[9];
	int len;
	len = read(f, buffer, rand_len); //citirea unui sir de caractere
	int i;
	while (1) {
		s.len = len; // adauga lungimea payloadului

		nfts = next_frame_to_send; //transforma next frame to send in caracter pe 8 biti

		check = checksum(buffer); //calculeaza checksum-ul pentru buffer
		strcpy(s.payload, ""); //goleste payloadul

		s.payload[0] = nfts;
		s.payload[1] = check;
		for (i = 2; i < 62; i++) {
			s.payload[i] = buffer[i - 2];
		}

		int2bin((int) (check), bin, 8);

		g = fopen("log.txt", "a");

		time(&timer);
		timeinfo = localtime(&timer);
		fprintf(g,
				"\n%s[sender] Am trimis urmatorul pachet:\nSeq No:%d\nPayload:%s\n",
				asctime(timeinfo), next_frame_to_send, buffer);
		fprintf(g, "Checksum:");
		printSubstringToFile(g, bin, 8);
		fprintf(g,
				"\n-----------------------------------------------------------------------------\n");
		fclose(g);
		if (len < rand_len) {
			s.len = len;
		}
		send_message(&s);
		t = receive_message_timeout(100); //asteapta ack
		if (t != NULL) {
			seq_recv = (int) (t->payload[0]);
			check_recv = t->payload[1];
			if (seq_recv == next_frame_to_send && check == check_recv) {
				rand_len = rand() % 59 + 1;
				len = read(f, buffer, rand_len);
				if (len < 1) {
					return;
				}
				next_frame_to_send++; /* avans contor*/
			}
		}

	}
}

int main(int argc, char** argv) {
	init(HOST, PORT);

	char * file = argv[1];
	sender(file);

	return 0;
}
