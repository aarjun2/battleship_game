#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
#define NUMBER_OF_ROWS 10 
#define NUMBER_OF_COLUMNS 10
void welcome_screen();
int display_menu();
void initialize_game_board(char arr[][NUMBER_OF_COLUMNS]);
int select_who_starts_first();
int is_valid_placement(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);
void print_carrier();
void print_battleship();
void print_cruiser();
void print_submarine();
void print_destroyer();
int check_placement(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);
void manually_place_carrier_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);
void manually_place_battleship_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);
void manually_place_cruiser_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);
void manually_place_submarine_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);
void manually_place_destroyer_on_board(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);
void get_random_position(int* row, int* column);
int get_random_direction();
void get_carrier(char arr[]);
void get_battleship(char arr[]);
void get_cruiser(char arr[]);
void get_submarine(char arr[]);
void get_destroyer(char arr[]);
void display_board(char arr[][NUMBER_OF_COLUMNS]);
void display_player2_board();
void display_2_finalboard(char arr[][NUMBER_OF_COLUMNS]);
int check_shot(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index);
int check_row_valid(char str[], int size);
int check_column_valid(char str[], int size);
int get_total_positions(char arr[][NUMBER_OF_COLUMNS]);
void update_counter(char arr[][NUMBER_OF_COLUMNS], int row_index, int column_index, int player_number, int counter[][5]);
void is_ship_sunk(int counter[][5]);
int target_exists(char arr[][3], char target[], int* coordinate_index);