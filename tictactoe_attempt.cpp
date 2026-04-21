 /*
    modello griglia:
    | X | O | X |
    -------------
    | X | O | X |
    -------------
    | X | O | X |
*/
#include <iostream>
using namespace std;

void stampaGriglia(char griglia[3][3]){
    for(int i=0; i<3; i++){ //la i sono le righe
        for(int j=0; j<3; j++){ //la j sono le colonne
            cout<<"| "<< griglia[i][j] << " ";
        }
        cout<<"|"<<endl;
        cout<<"-------------"<<endl;
    }
}
void giocata(char griglia[3][3], int r, int c, char simbolo){
    griglia[r][c]=simbolo;
}
bool controllo(char griglia[3][3], char simbolo){
    if((griglia[0][0]==simbolo && griglia[0][1]==simbolo && griglia[0][2]==simbolo) || //controllo righe
       (griglia[1][0]==simbolo && griglia[1][1]==simbolo && griglia[1][2]==simbolo) ||
       (griglia[2][0]==simbolo && griglia[2][1]==simbolo && griglia[2][2]==simbolo) ||
       (griglia[0][0]==simbolo && griglia[1][0]==simbolo && griglia[2][0]==simbolo) || //controllo colonne
       (griglia[0][1]==simbolo && griglia[1][1]==simbolo && griglia[2][1]==simbolo) ||
       (griglia[0][2]==simbolo && griglia[1][2]==simbolo && griglia[2][2]==simbolo) ||
       (griglia[0][0]==simbolo && griglia[1][1]==simbolo && griglia[2][2]==simbolo) || //controllo diagonali
       (griglia[0][2]==simbolo && griglia[1][1]==simbolo && griglia[2][0]==simbolo)){
       return true;
    }else{
        return false;
    }
}

int main(){
    char simbolo1, simbolo2;
    int r, c;
    char griglia[3][3]; //creo una matrice 3x3 per rappresentare la griglia del gioco
    //inizializzo la griglia con spazi vuoti
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            griglia[i][j]=' ';
        }
    }
     
    bool finito=false;
    cout<<"Inserisci simbolo giocatore 1: " << endl;
    cin>> simbolo1;
    cout<<"Inserisci simbolo giocatore 2: " << endl;
    cin>> simbolo2;
    do{
        stampaGriglia(griglia);
        cout<<"Turno giocatore 1" << endl;
        cout<<"Inserisci coordinate (riga e colonna) in cui vuoi giocare:" << endl;
        cin>> r >> c;
        giocata(griglia, r, c, simbolo1);
        if(controllo(griglia, simbolo1)){
            cout<<"Giocatore 1 ha vinto!" << endl;
            finito=true;
        }else{
            stampaGriglia(griglia);
            cout<<"Turno giocatore 2" << endl;
            do{
                cout<<"Inserisci coordinate (riga e colonna) in cui vuoi giocare:" << endl;
                cin>> r >> c;
                if(griglia[r][c]!=' '){
                cout<<"Casella occupata, riprova!" << endl;
                }else{
                    giocata(griglia, r, c, simbolo2);
                }
            }while(griglia[r][c]!=' ');
        }
        if(controllo(griglia, simbolo2)){
            cout<<"Giocatore 2 ha vinto!" << endl;
            finito=true;
        }

       
    }while(!finito); //finchè uno dei due non ha vinto
    return 0;
}