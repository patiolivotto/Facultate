#include <iostream>
#include <stdio.h>
#include "code.h"
#include <string.h>
#include <stdlib.h>

int main(){
Stack<int,100> a;
char * s=(char *)malloc(1*sizeof(char));
char c;
int q,w;
FILE *f=fopen("in.txt","rt");
 fscanf(f,"%c",&c);
while ((!feof(f))) {
     s[0]=c;
     if (atoi(s)!=0){
        a.push(atoi(s));
        }
        else {
            if (strcmp(s,"+")==0){
                if (a.isEmpty()){
                    std::cout<<"Eroare 1,forma gresita.";
                    return 0;
                }
                else
                {
                    q=a.pop();
                    if (a.isEmpty()){
                    std::cout<<"Eroare 2,forma gresita.";
                    return 0;
                }else{
                w=a.pop();
                a.push(q+w);
                
                      }
                }
            }
            else
            {
                if (strcmp(s,"*")==0){
                if (a.isEmpty()){
                    std::cout<<"Eroare 3,forma gresita.";
                    return 0;
                }else{
                    q=a.pop();
                    if (a.isEmpty()){
                    std::cout<<"Eroare 4,forma gresita.";
                    return 0;
                }
                else
                {
                w=a.pop();
                a.push(q*w);
                      }
                }
            }else{
                if (strcmp(s,"-")==0){
                if (a.isEmpty()){
                    std::cout<<"Eroare 5,forma gresita.";
                    return 0;
                }else{
                    q=a.pop();
                    if (a.isEmpty()){
                    std::cout<<"Eroare 6,forma gresita.";
                    return 0;
                }else{
                w=a.pop();
                a.push(w-q);
                      }
                }
            }else{
                if (strcmp(s,"/")==0){
                if (a.isEmpty()){
                    std::cout<<"Eroare 7,forma gresita.";
                    return 0;
                }else{
                    q=a.pop();
                    if (a.isEmpty()){
                    std::cout<<"Eroare 8,forma gresita.";
                    return 0;
                }else{
                w=a.pop();
                a.push(w/q);
                      }
                }
            }
            else{ 
				if (strcmp("\n",s)!=0){
				std::cout<<"Eroare 9, forma gresita.";
				return 0; 
            }
            }
            }
            }
            }
        }
       fscanf(f,"%c",&c);
    }

if (a.nrval()==0) {
    std::cout<<"CORECT,si valoarea este:"<<a.pop();
}else {
    std::cout<<"Eroare 10,forma nu e corecta.";
    std::cout<<a.pop()<<"\n";
    }




return 0;
}
