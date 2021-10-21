#include<iostream>
using namespace std;
main(){
float PN,PF=0; //PN prezzo netto //PF prezzo finale
cout << "ins.PN:";cin >>PN;
if(PN>100)PN-=0.35*PN;
PF=PN+PN*0.2;
cout << PF;
}//fine main
