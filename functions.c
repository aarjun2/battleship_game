#include "definitions.h"
void welcome_screen() {
	printf("Welcome to Battleship\nRules of the Game:\nplayer1 is you\nplayer2 is the computer\nThe object of Battleship is to try and sink all of the other player's before they sink all of your ships. All of the other player's ships are somewhere on his/her board.  You try and hit them by calling out the coordinates of one of the squares on the board.  The other player also tries to hit your ships by calling out coordinates.  Neither you nor the other player can see the other's board so you must try to guess where they are.  Each board in the physical game has two grids:  the lower (horizontal) section for the player's ships and the upper part (vertical during play) for recording the player's guesses.\n");
}
int display_menu() {
	int option = 0;
	printf("\n please select from the following options\n");
	printf("\n 1. manually generate the board\n");
	printf("\n 2. randomly generate the board\n");
	scanf("%d", &option);
	return option;
}
void initialize_game_board(char arr[][NUMBER_OF_COLUMNS]) {
	for (int row = 0; row < (NUMBER_OF_ROWS); row++) {
		for (int column = 0; column < (NUMBER_OF_COLUMNS); column++) {
			arr[row][column] = '-';
		}
	}
}

int select_who_starts_first() {
	return rand() % 2 + 1;
}
int is_valid_placement(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	if (arr[row_index][column_index] != '-') {
		return 0;
	}
	else {
		return 1;
	}
}
void print_carrier() {
	printf("\n Please enter the five cells to place the Carrier across:\n");
}
void print_battleship() {
	printf("\n Please enter the four cells to place the Battleship across:\n");
}
void print_cruiser() {
	printf("\n Please enter the four cells to place the Cruiser across:\n");
}
void print_submarine() {
	printf("\n Please enter the four cells to place the Submarine across:\n");
}
void print_destroyer() {
	printf("\n Please enter the four cells to place the Destoryer across:\n");
}
int check_placement(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	if (arr[row_index][column_index] == '-') {
		return 0;
	}
	else {
		return 1;
	}
}
void manually_place_carrier_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	arr[row_index][column_index] = 'c';
}
void manually_place_battleship_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	arr[row_index][column_index] = 'b';
}
void manually_place_cruiser_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	arr[row_index][column_index] = 'r';
}
void manually_place_submarine_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	arr[row_index][column_index] = 's';
}
void manually_place_destroyer_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	arr[row_index][column_index] = 'd';
} 

void get_random_position(int* row, int* column) {
	*row = rand() % 10;
	*column = rand() % 10;
}

int get_random_direction() {
	int direction = 0;
	direction = rand() % 2; 
	return direction;
}

void get_carrier(char arr[]) {
	int row = 0, column = 0, index = 0;
	get_random_position(&row, &column);
	if (column >= 7) {
		column = column - (column % 5);
	}
	if (row >= 7) {
		row = row - (row % 5);
	}
	int direction = get_random_direction();
	if (direction == 0) {
		for (int i = 0; i < 10; i++) {
			if (i % 2 == 0) {
				arr[index] = row + '0';
			}
			else {
				arr[index] = column + '0';
				column++;
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
	if (direction == 1) {
		for (int i = 0; i < 10; i++) {
			if (i % 2 == 1) {
				arr[index] = row + '0';
				row++;
			}
			else {
				arr[index] = column + '0';
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
}

void get_battleship(char arr[]) {
	int row = 0, column = 0, index = 0;
	get_random_position(&row, &column);
	if (column >= 7) {
		column = column - (column % 6);
	}
	if (row >= 7) {
		row = row - (row % 6);
	}
	int direction = get_random_direction();
	if (direction == 0) {
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 0) {
				arr[index] = row + '0';
			}
			else {
				arr[index] = column + '0';
				column++;
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
	if (direction == 1) {
		for (int i = 0; i < 8; i++) {
			if (i % 2 == 1) {
				arr[index] = row + '0';
				row++;
			}
			else {
				arr[index] = column + '0';
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
}

void get_cruiser(char arr[]) {
	int row = 0, column = 0, index = 0;
	get_random_position(&row, &column);
	if (column >= 8) {
		column = column - (column % 7);
	}
	if (row >= 8) {
		row = row - (row % 7);
	}
	int direction = get_random_direction();
	if (direction == 0) {
		for (int i = 0; i < 6; i++) {
			if (i % 2 == 0) {
				arr[index] = row + '0';
			}
			else {
				arr[index] = column + '0';
				column++;
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
	if (direction == 1) {
		for (int i = 0; i < 6; i++) {
			if (i % 2 == 1) {
				arr[index] = row + '0';
				row++;
			}
			else {
				arr[index] = column + '0';
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
}

void get_submarine(char arr[]) {
	int row = 0, column = 0, index = 0;
	get_random_position(&row, &column);
	if (column >= 8) {
		column = column - (column % 7);
	}
	if (row >= 8) {
		row = row - (row % 7);
	}
	int direction = get_random_direction();
	if (direction == 0) {
		for (int i = 0; i < 6; i++) {
			if (i % 2 == 0) {
				arr[index] = row + '0';
			}
			else {
				arr[index] = column + '0';
				column++;
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
	if (direction == 1) {
		for (int i = 0; i < 6; i++) {
			if (i % 2 == 1) {
				arr[index] = row + '0';
				row++;
			}
			else {
				arr[index] = column + '0';
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
}

void get_destroyer(char arr[]) {
	int row = 0, column = 0, index = 0;
	get_random_position(&row, &column);
	if (column >= 9) {
		column = column - (column % 8);
	}
	if (row >= 9) {
		row = row - (row % 8);
	}
	int direction = get_random_direction();
	if (direction == 0) {
		for (int i = 0; i < 4; i++) {
			if (i % 2 == 0) {
				arr[index] = row + '0';
			}
			else {
				arr[index] = column + '0';
				column++;
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
	if (direction == 1) {
		for (int i = 0; i < 4; i++) {
			if (i % 2 == 1) {
				arr[index] = row + '0';
				row++;
			}
			else {
				arr[index] = column + '0';
			}
			index = index + 1;
		}
		arr[index] = '\0';
	}
}


void display_board(char arr[][NUMBER_OF_COLUMNS]) {
	printf("\n player 1 board \n");
	printf(" ");
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (int row = 0; row < (NUMBER_OF_ROWS); row++) {
		printf("%d", row);
		printf(" ");
		for (int column = 0; column < (NUMBER_OF_COLUMNS); column++) {
			printf(" %c", arr[row][column]);
		}
		printf("\n");
	}
}

void display_player2_board() {
	printf("\n player 2 board \n");
	printf(" ");
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (int row = 0; row < (NUMBER_OF_ROWS); row++) {
		printf("%d", row);
		printf(" ");
		for (int column = 0; column < (NUMBER_OF_COLUMNS); column++) {
			printf(" -");
		}
		printf("\n");
	}
}

void display_2_finalboard (char arr[][NUMBER_OF_COLUMNS]) {
	printf("\n battleship board \n");
	printf(" ");
	for (int i = 0; i < NUMBER_OF_COLUMNS; i++) {
		printf(" %d", i);
	}
	printf("\n");
	for (int row = 0; row < (NUMBER_OF_ROWS); row++) {
		printf("%d", row);
		printf(" ");
		for (int column = 0; column < (NUMBER_OF_COLUMNS); column++) {
			if (arr[row][column] == 'm' || arr[row][column] == '*') {
				printf(" %c", arr[row][column]);
			}
			else {
				printf(" -");
			}
		}
		printf("\n");
	}
}

int check_shot(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index) {
	if (arr[row_index][column_index] == 'c' || arr[row_index][column_index] == 'b' || arr[row_index][column_index] == 'r' || arr[row_index][column_index] == 's' || arr[row_index][column_index] == 'd') {
		return 0;
	}
	else {
		return 1;
	}
}
int update_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index, int player_number, int counter[][5]) {
	int hits = 0;
	if (check_shot(arr, row_index, column_index) == 0) {
		update_counter(arr, row_index, column_index, player_number, counter);
		arr[row_index][column_index] = '*';
		hits = 1;
	}
	else {
		arr[row_index][column_index] = 'm';
		hits = 0;
	}
	return hits;
}

int check_row_valid(char str[], int size)
{
	int searchindex = str[0] - '0';
	int number;
	int loopend = size - 1;
	int flag = 0;

	for (int i = 1; (i <= loopend) && (flag == 0); i++)
	{
		if (i % 2 == 0)
		{
			number = str[i] - '0';
			if (searchindex != number)
			{
				flag = 1;
			}
		}
	}

	if (flag == 0)
	{
		int sequence = (str[1]) - '0';
		for (int i = 2; i <= loopend && (flag == 0); i++)
		{
			if (i % 2 == 1)
			{
				number = str[i] - '0';
				if ((sequence + 1) != number)
				{
					flag = 1;
				}
				else
				{
					sequence = sequence + 1;
				}
			}
		}

	}
	return flag;
}
int check_column_valid(char str[], int size)
{
	int searchindex;
	int number;
	int loopend = size - 1;
	int flag = 0;

	int sequence = (str[0]) - '0';
	for (int i = 1; i <= loopend && (flag == 0); i++)
	{
		if (i % 2 == 0)
		{
			number = str[i] - '0';
			if ((sequence + 1) != number)
			{
				flag = 1;
			}
			else
			{
				sequence = sequence + 1;
			}
		}
	}
	if (flag == 0)
	{
		searchindex = str[1] - '0';
		for (int i = 2; (i <= loopend) && (flag == 0); i++)
		{
			if (i % 2 == 1)
			{
				number = str[i] - '0';
				if (searchindex != number)
				{
					flag = 1;
				}
			}
		}
	}

	return flag;
}

int get_total_positions(char arr[][NUMBER_OF_COLUMNS]) {
	int total = 0;
	for (int row = 0; row < (NUMBER_OF_ROWS); row++) {
		for (int column = 0; column < (NUMBER_OF_COLUMNS); column++) {
			if (arr[row][column] == 'c' || arr[row][column] == 'b' || arr[row][column] == 'r' || arr[row][column] == 's' || arr[row][column] == 'd') {
				total = total + 1;
			}
		}
	}
	return total;
}

// player 1 and 2 update counter
void update_counter(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index, int player_number, int counter[][5]) {
	if (arr[row_index][column_index] == 'c' && player_number == 1) {
		counter[0][0] = counter[0][0] + 1;
	}
	if (arr[row_index][column_index] == 'b' && player_number == 1) {
		counter[0][1] = counter[0][1] + 1;
	}
	if (arr[row_index][column_index] == 'r' && player_number == 1) {
		counter[0][2] = counter[0][2] + 1;
	}
	if (arr[row_index][column_index] == 's' && player_number == 1) {
		counter[0][3] = counter[0][3] + 1;
	}
	if (arr[row_index][column_index] == 'd' && player_number == 1) {
		counter[0][4] = counter[0][4] + 1;
	}
	if (arr[row_index][column_index] == 'c' && player_number == 2) {
		counter[1][0] = counter[1][0] + 1;
	}
	if (arr[row_index][column_index] == 'b' && player_number == 2) {
		counter[1][1] = counter[1][1] + 1;
	}
	if (arr[row_index][column_index] == 'r' && player_number == 2) {
		counter[1][2] = counter[1][2] + 1;
	}
	if (arr[row_index][column_index] == 's' && player_number == 2) {
		counter[1][3] = counter[1][3] + 1;
	}
	if (arr[row_index][column_index] == 'd' && player_number == 2) {
		counter[1][4] = counter[1][4] + 1;
	}
}

void is_ship_sunk(int counter[][5]) {
	if (counter[0][0] == 5) {
		printf("\n player 1 carrier is sunk \n");
	}
	if (counter[0][1] == 4) {
		printf("\n player 1 battleship is sunk \n");
	}
	if (counter[0][2] == 3) {
		printf("\n player 1 cruiser is sunk \n");
	}
	if (counter[0][3] == 3) {
		printf("\n player 1 submarine is sunk \n");
	}
	if (counter[0][4] == 2) {
		printf("\n player 1 destroyer is sunk \n");
	}
	if (counter[1][0] == 5) {
		printf("\n player 2 carrier is sunk \n");
	}
	if (counter[1][1] == 4) {
		printf("\n player 2 battleship is sunk \n");
	}
	if (counter[1][2] == 3) {
		printf("\n player 2 cruiser is sunk \n");
	}
	if (counter[1][3] == 3) {
		printf("\n player 2 submarine is sunk \n");
	}
	if (counter[1][4] == 2) {
		printf("\n player 2 destroyer is sunk \n");
	}
}

int target_exists(char arr[][3], char target[], int *coordinate_index) {
	int flag = 0;
	if (*coordinate_index == 0) {
		strcpy(arr[0], target);
		*coordinate_index = *coordinate_index + 1;
		return flag;
	}
	for (int i = 0; i < *coordinate_index && flag == 0; i++) {
		if (strcmp(arr[i],target) == 0) {
			flag = 1;
		}
	}
	if (flag == 0) {
		strcpy(arr[*coordinate_index], target);
		*coordinate_index = *coordinate_index + 1;
	}
	return flag;
}