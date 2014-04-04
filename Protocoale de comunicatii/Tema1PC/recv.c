//	Stanciu Catalin 322CA Tema1 PC 2014
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h> 
#include "lib.h"

#define HOST "127.0.0.1"
#define PORT 10001

char *int2bin(int a, char *buffer, int buf_size) {
	buffer += (buf_size - 1);
	int i = 0;
	for (i = 7; i >= 0; i--) {
		*buffer-- = (a & 1) + '0';
		a >>= 1;
	}
	return buffer;
}
char checksum(char * s) {
	char x;
	x = s[0] ^ s[1];
	int i = 0;
	for (i = 2; i < strlen(s); i++) {
		x = x ^ s[i];
	}
	return x;
}
void receive(char * file) {
	int seq_no; //seq_nr frame expected; // cadru asteptat
	int contor = 0;
	msg r;
	msg t;

	time_t timer; //timp
	struct tm * timeinfo;
	time(&timer);
	timeinfo = localtime(&timer);

	FILE * g = fopen(file, "w");
	fclose(g); //creare fisier;
	char buffer[70];
	char check;
	char tocheck;
	char oldcheck;
	FILE* f;
	int fd;
	fd = open(file, O_WRONLY);
	char bin[9];
	int buff_len;
	while (recv_message(&t) > 0) {

			buff_len = t.len;
			strncpy(buffer, t.payload + 2, buff_len);
			check = checksum(buffer);
			seq_no = (int) (t.payload[0]);
			tocheck = t.payload[1];
			r.payload[0] = seq_no;
			r.payload[1] = tocheck;
			r.len = 2;
			if (seq_no == contor) {
				if (check == tocheck) {
					send_message(&r);		//trimitere ack
					contor++;
					write(fd, buffer, buff_len);
					f = fopen("log.txt", "a");
					int2bin((int) (tocheck), bin, 8);
					time(&timer);
					timeinfo = localtime(&timer);
					fprintf(f,
							"%s[Reciver]:Am primit urmatorul pachet:.\nSeq no.:%d\nPayload:%s\nChecksum:%s\n-----------------------------------------------------------------------------\n",
							asctime(timeinfo), seq_no, buffer, bin);
					fclose(f);
					oldcheck = tocheck;
				} else {
					r.payload[0] = contor;
					r.payload[1] = oldcheck;
					send_message(&r); 			//trimitere ack
					f = fopen("log.txt", "a");
					int2bin((int) (oldcheck), bin, 8);
					time(&timer);
					timeinfo = localtime(&timer);
					fprintf(f,
							"[CHECKSUM ERROR %s[receiver] Am primit urmatorul pachet:\nSeq No: %d\nPayload: %s\nAm calculat checksum si am detectat eroare. Voi trimite ACK pentru Seq No %d\n(ultimul cadru corect pe care l-am primit)\n-----------------------------------------------------------------------------\n[dd-mm-yyyy hh:mm:ss] [receiver] Trimit ACK:\nSeq No: %d\nChecksum: %s\n-----------------------------------------------------------------------------\n",
							asctime(timeinfo), seq_no, buffer, contor, contor,
							bin);
					fclose(f);
				}
			} else {
				r.payload[0] = contor;
				r.payload[1] = oldcheck;
				send_message(&r); 			//trimitere ack
				f = fopen("log.txt", "a");
				int2bin((int) (oldcheck), bin, 8);
				time(&timer);
				timeinfo = localtime(&timer);
				fprintf(f,
						"[SEQ ERROR%s[receiver] Am primit urmatorul pachet:\nSeq No: %d\nPayload: %s\nAm calculat checksum si am detectat eroare. Voi trimite ACK pentru Seq No %d\n(ultimul cadru corect pe care l-am primit)\n-----------------------------------------------------------------------------\n[dd-mm-yyyy hh:mm:ss] [receiver] Trimit ACK:\nSeq No: %d\nChecksum: %s\n-----------------------------------------------------------------------------\n",
						asctime(timeinfo), seq_no, buffer, contor, contor, bin);
				fclose(f);

			}
		
	}
	close(fd);
}


int main(int argc, char** argv) {
	init(HOST, PORT);
	
	receive(argv[1]);

	return 0;
}
