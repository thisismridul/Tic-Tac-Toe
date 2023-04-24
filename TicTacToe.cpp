#include <bits/stdc++.h>
using namespace std;

//Declaring variables Globally
// playing spaces stored in the array spaces:
    char spaces[3][3] = { {'1', '2', '3'}, {'4', '5', '6'}, {'7', '8', '9'} };
    int row;
    int column;
    char token = 'X';
    bool tie = false;
//Globally defining players' name:
    string name1 = "";
    string name2 = "";
    

void functionOne(){
    
    

    // Game Structure:
    cout<< "   |   |   \n";
    cout<< " "<<spaces[0][0]<<" | "<<spaces[0][1]<<" | "<<spaces[0][2]<<"  \n";
    cout<< "___|___|___\n";
    cout<< "   |   |   \n";
    cout<< " "<<spaces[1][0]<<" | "<<spaces[1][1]<<" | "<<spaces[1][2]<<"  \n";
    cout<< "___|___|___\n";
    cout<< "   |   |   \n";
    cout<< " "<<spaces[2][0]<<" | "<<spaces[2][1]<<" | "<<spaces[2][2]<<"  \n";
    cout<< "   |   |   \n";

}

void functionTwo(){

    int digit;

    if(token == 'X'){
        cout << name1 << " Please Enter:";
        cin >> digit;
    }
    if(token == 'O'){
        cout << name2 << " Please Enter:";
        cin >> digit;
    }

    if(digit == 1){
        row = 0;
        column = 0;
    }
    if(digit == 2){
        row = 0;
        column = 1;
    }
    if(digit == 3){
        row = 0;
        column = 2;
    }
    if(digit == 4){
        row = 1;
        column = 0;
    }
    if(digit == 5){
        row = 1;
        column = 1;
    }
    if(digit == 6){
        row = 1;
        column = 2;
    }
    if(digit == 7){
        row = 2;
        column = 0;
    }
    if(digit == 8){
        row = 2;
        column = 1;
    }
    if(digit == 9){
        row = 2;
        column = 2;
    }
    else if(digit<1 && digit>9) {
        cout << "Invalid !!" << endl;
    }
    
    if( token=='X' && spaces[row][column]!='X' && spaces[row][column]!='O' ){
        spaces[row][column]='X';
        token = 'O';
    }
    else if( token=='O' && spaces[row][column]!='X' && spaces[row][column]!='O' ){
        spaces[row][column]='O';
        token = 'X';
    }
    else{
        cout << "There's no empty space!";
        functionTwo();
    }
    functionOne();
}

//function for winning condition:
bool functionThree(){
    for ( int i=0 ; i<3 ; i++){
        if( spaces[i][0]==spaces[i][1] && spaces[i][0]==spaces[i][2] || 
            spaces[0][i]==spaces[1][i] && spaces[0][i]==spaces[2][i]){
            return true;
        }
    }
    if( spaces[0][0]==spaces[1][1] && spaces[1][1]==spaces[2][2] || 
        spaces[0][2]==spaces[1][1] && spaces[1][1]==spaces[2][0]){
            return true;
        }
    
    int count=0;
    for( int i=0 ; i<3 ; i++ ){
        for ( int j=0 ; j<3 ; j++ ){
            if( spaces[i][j]!='X' && spaces[i][j]!='O' ){
                count++;
                return false;
            }
        }
    }
    if(count==0){
        ::tie=true;
        return true;
    }
    return false;
}

int main(){

    // for entering first player's name:
    
    cout << "Enter the name of first Player:" << endl ;
    getline( cin , name1 );

    // for entering second player's name:
    
    cout << "Enter the name of second Player:" << endl;
    getline( cin , name2 );

    cout << name1 << " is Player 1, so he/she will play first." << endl;
    cout << name2 << " is Player 2, so he/she will play second." << endl;


    while(!functionThree()){
        functionOne();
        functionTwo();
        functionThree();
    }

    if(token=='X' && ::tie==false){
        cout << name2 << " Wins!!" << endl;
    }
    else if(token=='O' && ::tie==false){
        cout << name1 << " Wins!!" << endl;
    }
    else{
        cout << "It's a Tie.";
    }
    
}