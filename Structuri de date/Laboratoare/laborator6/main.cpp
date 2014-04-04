#include <stdio.h>
#include <string.h>
#include <iostream>
#include "linked_list.h"
#include "hashtable.h"
#include "string.h"
#define VMAX 17
#define P 13
unsigned int ii=20;

unsigned int hfunc(int key) {
    return (14 * key) % 20;
}

unsigned int hfunc2(std::string key)
{
	unsigned int hash = 5381;


	for (unsigned i=0;i<key.size();i++)
		hash = ((hash << 5) + hash) + (int)key[i];

	return hash;
}
unsigned int hash_fct(char *str)
{
        unsigned int hash = 5381;
        int c;
 
        while ( (c = *str ++) != 0 ) {
                hash = ((hash << 5) + hash) + c;
        }
 
        return hash;
}
int hfunc3(char* key) {
    int hkey = 0;
    for (unsigned int i = 0; i < strlen(key); i++)
        hkey = (hkey * P + key[i]) % VMAX;
    return hkey;
}

//Hashtable<int, double> hid(ii, hfunc);
Hashtable<char *, char *> his(ii, hfunc3);

int main() {
	char * k1=new char;
	char * k2=new char;
		//k1= new char;
	//k1="qwe";
	
		strcpy(k1,"qwe");
		strcpy(k2,"qwe2222");
	his.put(k1,k2);
	his.put(k2,k1);
	strcpy(k2,"qwe3333");
	his.put(k1,k2);
	//hid.put(k1,8);
	std::cout<<his.get(k1)<<"\n";
	std::cout<<his.get(k2)<<"\n";
	std::cout<<hash_fct(k1)<<"\n";
	std::cout<<hash_fct(k2)<<"\n";
	//std::cout<<hid.get(k1)<<"\n";
  /* hid.put(80, 7.9);
    hid.put(2, 11);
    hid.put(2, 22);
    hid.put(2, 33);
    printf("%.3lf\n", hid.get(80));
    hid.put(80, 13);
    printf("%.3lf\n", hid.get(80));
    printf("%.3lf\n", hid.get(2));
    printf("%d\n", hid.hasKey(5));
    printf("%d\n", hid.hasKey(2));
    printf("%.3lf\n", hid.get(5));
    */
  

    return 0;
}
