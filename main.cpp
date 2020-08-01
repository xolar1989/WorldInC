#include <iostream>



#include "WirtualLife/Swiat.cpp"
#include "WirtualLife/Organizm.cpp"
#include "WirtualLife/Organizmy/Zwierze.cpp"
#include "WirtualLife/Organizmy/Roslina.cpp"






#include "conio.h"




using namespace std ;


int main() {

    srand( (int)time(0) );

    char odp ;
    bool moc  = false ;

    cout<<"Czy super moc(napisz 't') ?"<<endl ;
    cin>>odp ;
    if(odp == 't'){
        moc = true ;
    }
    Swiat mojSwiat = Swiat(15,15 ) ;
    mojSwiat.start(moc);

       while(!mojSwiat.GAMEOVER()){

           mojSwiat.RysujSwiat() ;

           mojSwiat.WykonajTure() ;

           system("cls") ;

           mojSwiat.zapiszPlik() ;

       }

    mojSwiat.RysujSwiat() ;
       _getch() ;



    return 0;
}