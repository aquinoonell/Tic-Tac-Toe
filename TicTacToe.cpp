#include <iostream>
#include <string>
using namespace std;

  const int ROW = 3;
  const int COLUM = 3;
  char arr[ROW][COLUM] = {{'1','2','3'},{'4','5','6'},{'7','8','9'}};
  bool tie = false;
  int row;
  int colum;
  char token = 'x';
  string n1,n2;
  
void displayFunc();
void arrayMath();
bool functionThree();

int main() {
  cout << "Enter the name of the first player: ";
  cin >> n1;
  cout << "Enter the name of the second player: ";
  cin >> n2;

  cout<<n1<<" is player one. \n";
  cout<<n2<<" is player two. \n";

  while(!functionThree()){
    displayFunc();
    arrayMath();
    functionThree();
  }
  
  displayFunc();
  if(token == 'x' && ::tie == false){
    cout << n1 << " Wins!!" << endl;
  }
  else if(token == 'O' && ::tie == false){
    cout << n2 << " Wins!!" << endl;
  }
  else{
    cout << " It's a draw!" << endl;
  }
}

void arrayMath(){
  int digit;
  
  if (token == 'x'){
    cout << n1 <<  " enter the your move: ";
    cin >> digit; 
  }
  if (token == 'O'){
    cout << n2 << " enter your move: ";
    cin >> digit;
  }

  if (digit == 1){
    row = 0;
    colum = 0;
  }
  if (digit == 2){
    row = 0;
    colum = 1;
  }
  if (digit == 3){
    row = 0;
    colum = 2;
  }
  if (digit == 4){
    row = 1;
    colum = 0;
  }
  if (digit == 5){
    row = 1;
    colum = 1;
  }
  if (digit == 6){
    row = 1;
    colum = 2;
  }
  if (digit == 7){
    row = 2;
    colum = 0;
  }
  if (digit == 8){
    row = 2;
    colum = 1;
  }
  if (digit == 9){
    row = 2;
    colum = 2;
  }
  else if (digit < 0 ||digit > 9){
    cout << "Invalid input!!" << endl;
  }

 if(token == 'x' && arr[row][colum] !='x' && arr[row][colum] !='O'){
  arr[row][colum]='x';
  token = 'O';
 }
 else if(token == 'O' && arr[row][colum] != 'x' && arr[row][colum] !='O'){
   arr[row][colum] = 'O';
   token = 'x';
 }
  else{
    cout << "There is no empty space!" <<endl;
    arrayMath();
  }
}

void displayFunc(){
  cout << "\n\n\tTic Tac Toe\n\n";
  cout << "     |     |     " << endl;
  cout << "  " << arr[0][0] << "  |  " << arr[0][1] << "  |  " << arr[0][2] << endl;

  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;

  cout << "  " << arr[1][0] << "  |  " << arr[1][1] << "  |  " << arr[1][2] << endl;

  cout << "_____|_____|_____" << endl;
  cout << "     |     |     " << endl;

  cout << "  " << arr[2][0] << "  |  " << arr[2][1] << "  |  " << arr[2][2] << endl;
  cout << "     |     |     " << endl << endl;
}

bool functionThree(){
  for (int i = 0; i < 3; i++){
    if(arr[i][0] == arr[i][1] && arr[i][0] == arr[0][2] || arr[0][i] == arr[1][i] && arr[0][i] == arr[2][i])
    return true;
  }
  if(arr[0][0] == arr[1][1] && arr[1][1] == arr[2][2] || arr[0][2] == arr[1][1] && arr[1][1] == arr [2][0]){
    return true;
  }

  for (int i = 0; i < 3; i ++){
    for(int j = 0; j < 3; j++){
      if(arr[i][j] != 'x' && arr [i][j] !='O'){
        return false;
      }
    }
  }
  ::tie = true;
  return false;
}
