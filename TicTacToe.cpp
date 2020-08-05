#include<iostream>
#include<string>
using namespace std;
void board_print(char arr[]);
bool check_win(char arr[]);
bool cell_checking(char arr[], int cell_no);
int main() {

	string player1, player2;
	int player1_turn , player2_turn;
	char choice;
	do {
		char array[9] = { '1' , '2' , '3' , '4' , '5' , '6' , '7' , '8' , '9' };
		board_print(array);
		cout << "Enter the Name of Player 1: ";
        getline(cin ,player1 , '\n');
	    cout << "Enter Name of Player 2: ";
	     cin >> player2;
		int turns = 0;
		while (true) {
			
			cout << endl << player1 << "'s Turn\n";
			cout << "Enter Your Turn --> From Cell No 1 to 9(Available Only): ";
			cin >> player1_turn;
            
			while (cell_checking(array, player1_turn)) {
				cout << "Cell is Already Filled_up\n";
				cout << "Enter "<< player1 <<"'s term again: ";
				cin >> player1_turn;
			}

			array[player1_turn - 1] = 'X';

			system("CLS");
			board_print(array);
			if (check_win(array)) {
				cout << "Congratulations\n" << player1 << " Has Won\n";
				break;
			}
			if (turns == 4) {
				cout << "Game Over\n Game is Tie in Both Players\n";
				break;
			}

			cout << endl << player2 << "'s Term\n";
			cout << "Enter Your Turn --> From Cell No 1 to 9(Available Only) : ";
			cin >> player2_turn;
			
			while (cell_checking(array, player2_turn)) {
				cout << "Cell is Already Filled_up\n";
				cout << "Enter "<< player2 << "'s term again: ";
				cin >> player2_turn;
			}

			array[player2_turn - 1] = 'O';

			system("CLS");
			board_print(array);
			
			if (check_win(array)) {
			cout << "Congratulations\n" << player2 << " Has Won\n";
				break;
			}
			turns++;

		}


		cout << "Wanna to Play Again? (Press y if yes)";
		cin >> choice;
		system("CLS");
	} 
	while (choice == 'y' || choice == 'Y');

	cout << "Hope That You Would Enjoy it";
	return 0;
}


void board_print(char arr[]) {
	int i = 0;
		cout << "\n\t\tTIC_TAC_TOE \n\n";
		cout << "Game Rule \n";
		cout << "If Cells are Equal in Horizontally, Vertically or Diganolly\nThen Player will be Winner\n\n";
	while(i < 9){
 	cout << "     |     |\n";
	cout << "  " << arr[i] << "  |" << "  " << arr[i+1] << "  |" << "  " << arr[i+2] << endl;
	if (i<6)
	cout << "_____|_____|_____\n";
	else cout << "     |     |\n";

	i += 3;
	}
}

bool cell_checking(char arr[], int cell) {
	if (arr[cell - 1] == 'X' || arr[cell - 1] == 'O') return true;

	return false;
}
bool check_win(char arr[]) {
	int s = 0;
	int t = 0;
	
	if (arr[0] == arr[4] && arr[4] == arr[8]) return true;
	if (arr[2] == arr[4] && arr[4] == arr[6]) return true;

	while (s < 8) {
	
		if (arr[s] == arr[s + 1] && arr[s+1]== arr[s + 2]) return true;
		if (arr[t] == arr[t + 3] && arr[t+3]== arr[t + 6]) return true;
	
		s += 3;
		t += 1;
	}

	return false;
}

