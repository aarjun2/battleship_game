#include "definitions.h" 


struct stats {
	int total_hits;
	int total_misses;
	int total_shots;
	int hits_misses_ratio;
	int won_loss; //0: loss, 1: win
};

int main(void) {
	struct stats player_1_stats;
	struct stats player_2_stats;
	char player1_board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	char player2_board[NUMBER_OF_ROWS][NUMBER_OF_COLUMNS];
	int counter[2][5];
	int check_coordinate[1000][3];
	int coordinate_index = 0;
	char str_carrier[11];
	char str_battleship[9];
	char str_cruiser[7];
	char str_submarine[7];
	char str_destroyer[5];
	int ret = -1;
	int player1_total = 0;
	int player2_total = 0;
	int player1_hits = 0;
	int player2_hits = 0;
	int player1_misses = 0;
	int player2_misses = 0;
	// intialize game board 
	initialize_game_board(player1_board);
	initialize_game_board(player2_board);
	



	//initialize counter 
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 5; j++) {
			counter[i][j] = 0;
		}
	}
	//initialize coordinate 
	/*for (int i = 0; i < 1000; i++) {
		strcpy(check_coordinate[i],"\0");
	}*/

	FILE* infile = NULL;
	infile = fopen("battleship.log", "w");

	welcome_screen();
	printf("\n enter to start game \n"); 
	char space = '\0';
	scanf("%c", &space);
	system("cls");

	int option = display_menu();
	//player 1 manual board
	if (option == 1) {
		do {
			printf("\n Please enter the five cells to place the Carrier across: \n");
			scanf("%s", &str_carrier);
			ret = check_row_valid(str_carrier, 10);
			if (ret == 1)
			{
				// check for check_column_valid
				ret = check_column_valid(str_carrier, 10);
			}
			if (ret == 0) {
				for (int i = 0; i < 10 && ret == 0;) {
					if (check_placement(player1_board, str_carrier[i] - '0', str_carrier[i + 1] - '0') == 0) {
						manually_place_carrier_on_board(player1_board, str_carrier[i] - '0', str_carrier[i + 1] - '0');
						i = i + 2;
					}
					else {
						ret = -1;
						printf("\n invalid placement \n");
					}
				}
			}
		} while (ret != 0);

		ret = -1;

		do {
			printf("\n Please enter the four cells to place the battleship across: \n");
			scanf("%s", &str_battleship);
			ret = check_row_valid(str_battleship, 8);
			if (ret == 1)
			{
				// check for check_column_valid
				ret = check_column_valid(str_battleship, 8);
			}
			if (ret == 0) {
				for (int i = 0; i < 8 && ret == 0;) {
					if (check_placement(player1_board, str_battleship[i] - '0', str_battleship[i + 1] - '0') == 0) {
						manually_place_battleship_on_board(player1_board, str_battleship[i] - '0', str_battleship[i + 1] - '0');
						i = i + 2;
					}
					else {
						ret = -1;
						printf("\n invalid placement \n");
					}
				}
			}
		} while (ret != 0);

		ret = -1;

		do {
			printf("\n Please enter the three cells to place the Cruiser across: \n");
			scanf("%s", &str_cruiser);
			ret = check_row_valid(str_cruiser, 6);
			if (ret == 1)
			{
				// check for check_column_valid
				ret = check_column_valid(str_cruiser, 6);
			}
			if (ret == 0) {
				for (int i = 0; i < 6 && ret == 0;) {
					if (check_placement(player1_board, str_cruiser[i] - '0', str_cruiser[i + 1] - '0') == 0) {
						manually_place_cruiser_on_board(player1_board, str_cruiser[i] - '0', str_cruiser[i + 1] - '0');
						i = i + 2;
					}
					else {
						ret = -1;
						printf("\n invalid placement \n");
					}
				}
			}
		} while (ret != 0);

		ret = -1;

		do {
			printf("\n Please enter the three cells to place the submarine across: \n");
			scanf("%s", &str_submarine);
			ret = check_row_valid(str_submarine, 6);
			if (ret == 1)
			{
				// check for check_column_valid
				ret = check_column_valid(str_submarine, 6);
			}
			if (ret == 0) {
				for (int i = 0; i < 6 && ret == 0;) {
					if (check_placement(player1_board, str_submarine[i] - '0', str_submarine[i + 1] - '0') == 0) {
						manually_place_submarine_on_board(player1_board, str_submarine[i] - '0', str_submarine[i + 1] - '0');
						i = i + 2;
					}
					else {
						ret = -1;
						printf("\n invalid placement \n");
					}
				}
			}
		} while (ret != 0);

		ret = -1;

		do {
			printf("\n Please enter the four cells to place the destoryer across: \n");
			scanf("%s", &str_destroyer);
			ret = check_row_valid(str_destroyer, 4);
			if (ret == 1)
			{
				// check for check_column_valid
				ret = check_column_valid(str_destroyer, 4);
			}
			if (ret == 0) {
				for (int i = 0; i < 4 && ret == 0;) {
					if (check_placement(player1_board, str_destroyer[i] - '0', str_destroyer[i + 1] - '0') == 0) {
						manually_place_destroyer_on_board(player1_board, str_destroyer[i] - '0', str_destroyer[i + 1] - '0');
						i = i + 2;
					}
					else {
						ret = -1;
						printf("\n invalid placement \n");
					}
				}
			}
		} while (ret != 0);

	}
	//player 1 random board

	if (option == 2) {
		ret = -1;
		do {
			get_carrier(str_carrier);
			ret = -1;
			int i = 0;
			for (i = 0; i < 10 && ret == -1;) {
				if (check_placement(player1_board, str_carrier[i] - '0', str_carrier[i + 1] - '0') == 0) {
					//manually_place_carrier_on_board(player2_board, str_carrier[i] - '0', str_carrier[i + 1] - '0');
					i = i + 2;
				}
				else {
					ret = -2;
					printf("\n invalid placement \n");
				}
			}
			if (i == 10 && ret == -1) {
				ret = 0;
				for (int j = 0; j < 10;) {
					manually_place_carrier_on_board(player1_board, str_carrier[j] - '0', str_carrier[j + 1] - '0');
					j = j + 2;
				}
			}
		} while (ret != 0);

		ret = -1;

		do {
			get_battleship(str_battleship);
			ret = -1;
			int i = 0;
			for (i = 0; i < 8 && ret == -1;) {
				if (check_placement(player1_board, str_battleship[i] - '0', str_battleship[i + 1] - '0') == 0) {
					//manually_place_battleship_on_board(player2_board, str_battleship[i] - '0', str_battleship[i + 1] - '0');
					i = i + 2;
				}
				else {
					ret = -2;
					printf("\n invalid placement \n");
				}
			}
			if (i == 8 && ret == -1) {
				ret = 0;
				for (int j = 0; j < 8;) {
					manually_place_battleship_on_board(player1_board, str_battleship[j] - '0', str_battleship[j + 1] - '0');
					j = j + 2;
				}
			}
		} while (ret != 0);

		ret = -1;

		do {
			get_cruiser(str_cruiser);
			ret = -1;
			int i = 0;
			for (i = 0; i < 6 && ret == -1;) {
				if (check_placement(player1_board, str_cruiser[i] - '0', str_cruiser[i + 1] - '0') == 0) {
					//manually_place_cruiser_on_board(player2_board, str_cruiser[i] - '0', str_cruiser[i + 1] - '0');
					i = i + 2;
				}
				else {
					ret = -2;
					printf("\n invalid placement \n");
				}
			}
			if (i == 6 && ret == -1) {
				ret = 0;
				for (int j = 0; j < 6;) {
					manually_place_cruiser_on_board(player1_board, str_cruiser[j] - '0', str_cruiser[j + 1] - '0');
					j = j + 2;
				}
			}
		} while (ret != 0);

		ret = -1;

		do {
			get_submarine(str_submarine);
			printf("\n sub = %s", str_submarine);
			ret = -1;
			int i = 0;
			for (i = 0; i < 6 && ret == -1;) {
				if (check_placement(player1_board, str_submarine[i] - '0', str_submarine[i + 1] - '0') == 0) {
					//manually_place_submarine_on_board(player2_board, str_submarine[i] - '0', str_submarine[i + 1] - '0');
					i = i + 2;
				}
				else {
					ret = -2;
					printf("\n invalid placement \n");
				}
			}
			if (i == 6 && ret == -1) {
				ret = 0;
				for (int j = 0; j < 6;) {
					manually_place_submarine_on_board(player1_board, str_submarine[j] - '0', str_submarine[j + 1] - '0');
					j = j + 2;
				}
			}
		} while (ret != 0);

		ret = -1;

		do {
			get_destroyer(str_destroyer);
			ret = -1;
			int i = 0;
			for (i = 0; i < 4 && ret == -1;) {
				if (check_placement(player1_board, str_destroyer[i] - '0', str_destroyer[i + 1] - '0') == 0) {
					//manually_place_destroyer_on_board(player2_board, str_destroyer[i] - '0', str_destroyer[i + 1] - '0');
					i = i + 2;
				}
				else {
					ret = -2;
					printf("\n invalid placement \n");
				}
			}
			if (i == 4 && ret == -1) {
				ret = 0;
				for (int j = 0; j < 4;) {
					manually_place_destroyer_on_board(player1_board, str_destroyer[j] - '0', str_destroyer[j + 1] - '0');
					j = j + 2;
				}
			}
		} while (ret != 0);
	}
	

	///**********************player 2 board generation start
	ret = -1;
	do {
		get_carrier(str_carrier);
		ret = -1;
		int i = 0;
		for (i = 0; i < 10 && ret == -1;) {
			if (check_placement(player2_board, str_carrier[i] - '0', str_carrier[i + 1] - '0') == 0) {
				//manually_place_carrier_on_board(player2_board, str_carrier[i] - '0', str_carrier[i + 1] - '0');
				i = i + 2;
			}
			else {
				ret = -2;
				printf("\n invalid placement \n");
			}
		}
		if (i == 10 && ret == -1) {
			ret = 0;
			for (int j = 0; j < 10;) {
					manually_place_carrier_on_board(player2_board, str_carrier[j] - '0', str_carrier[j + 1] - '0');
					j = j + 2;
				}
		}
	} while (ret != 0);

	ret = -1;

	do {
		get_battleship(str_battleship);
		ret = -1;
		int i = 0;
		for (i = 0; i < 8 && ret == -1;) {
			if (check_placement(player2_board, str_battleship[i] - '0', str_battleship[i + 1] - '0') == 0) {
				//manually_place_battleship_on_board(player2_board, str_battleship[i] - '0', str_battleship[i + 1] - '0');
				i = i + 2;
			}
			else {
				ret = -2;
				printf("\n invalid placement \n");
			}
		}
		if (i == 8 && ret == -1) {
			ret = 0;
			for (int j = 0; j < 8;) {
					manually_place_battleship_on_board(player2_board, str_battleship[j] - '0', str_battleship[j + 1] - '0');
					j = j + 2;
				}
		}
	} while (ret != 0);

	ret = -1;

	do {
		get_cruiser(str_cruiser);
		ret = -1;
		int i = 0;
		for (i = 0; i < 6 && ret == -1;) {
			if (check_placement(player2_board, str_cruiser[i] - '0', str_cruiser[i + 1] - '0') == 0) {
				//manually_place_cruiser_on_board(player2_board, str_cruiser[i] - '0', str_cruiser[i + 1] - '0');
				i = i + 2;
			}
			else {
				ret = -2;
				printf("\n invalid placement \n");
			}
		}
		if (i == 6 && ret == -1) {
			ret = 0;
			for (int j = 0; j < 6;) {
					manually_place_cruiser_on_board(player2_board, str_cruiser[j] - '0', str_cruiser[j + 1] - '0');
					j = j + 2;
				}
		}
	} while (ret != 0);

	ret = -1;

	do {
		get_submarine(str_submarine);
		printf("\n sub = %s", str_submarine);
		ret = -1;
		int i = 0;
		for (i = 0; i < 6 && ret == -1;) {
			if (check_placement(player2_board, str_submarine[i] - '0', str_submarine[i + 1] - '0') == 0) {
				//manually_place_submarine_on_board(player2_board, str_submarine[i] - '0', str_submarine[i + 1] - '0');
				i = i + 2;
			}
			else {
				ret = -2;
				printf("\n invalid placement \n");
			}
		}
		if (i == 6 && ret == -1) {
			ret = 0;
			for (int j = 0; j < 6;) {
					manually_place_submarine_on_board(player2_board, str_submarine[j] - '0', str_submarine[j + 1] - '0');
					j = j + 2;
			}
		}
	} while (ret != 0);

	ret = -1;

	do {
		get_destroyer(str_destroyer);
		ret = -1;
		int i = 0;
		for (i = 0; i < 4 && ret == -1;) {
			if (check_placement(player2_board, str_destroyer[i] - '0', str_destroyer[i + 1] - '0') == 0) {
				//manually_place_destroyer_on_board(player2_board, str_destroyer[i] - '0', str_destroyer[i + 1] - '0');
				i = i + 2;
			}
			else {
				ret = -2;
				printf("\n invalid placement \n");
			}
		}
		if (i == 4 && ret == -1) {
			ret = 0;
			for (int j = 0; j < 4;) {
				manually_place_destroyer_on_board(player2_board, str_destroyer[j] - '0', str_destroyer[j + 1] - '0');
				j = j + 2;
			}
		}
	} while (ret != 0);
	///*******************player 2 end

	// select who goes first 
	ret = select_who_starts_first();
	if (ret == 1) {
		printf("\n player 1 goes first \n");
	}
	if (ret == 2) {
		printf("\n player 2 goes first \n");
	}

	//print player 1 board
	player1_total = get_total_positions(player1_board);
	display_board(player1_board);

	//print player 2 board
	player2_total = get_total_positions(player2_board);
	display_player2_board(player2_board);

	int loopend = 0, row = 0, column = 0;
	do {	
		char target[3];
		if (ret == 1) {
			// choose a target to hit 
			printf("\n Enter a target: ");
			scanf("%s", &target);
			if (target_exists(check_coordinate, target, &coordinate_index) == 1) {
				printf("\n target already chosen, try again \n");
				continue;
			}
			fwrite(target, sizeof(target), 1, infile);
			if (update_board(player2_board, target[0] - '0', target[1] - '0', 2, counter) == 1) {
				player1_hits = player1_hits + 1;
				char* ptr = "hits";
				fwrite(ptr, sizeof(ptr), 1, infile);
			}
			else {
				player1_misses = player1_misses+ 1;
				char* ptr = "miss";
				fwrite(ptr, sizeof(ptr), 1, infile);
			}
		} 
		if (ret == 2) {
			get_random_position(&row, &column);
			if (update_board(player1_board, row, column, 1, counter) == 1) {
				player2_hits = player2_hits + 1;
			}
			else {
				player2_misses = player2_misses + 1;
			}
		}
		if (ret == 2) {
			ret = 1;
		}
		else {
			ret = 2;
		}
		system("cls");
		// display the board
		display_board(player1_board);
		display_2_finalboard(player2_board);

		//find if ship was sunk
		is_ship_sunk(counter);
		if (counter[0][0] == 5) {
			char *ptr = "player 1 carrier is sunk";
			fwrite(ptr, sizeof(ptr), 1, infile);
		}
		if (counter[0][1] == 4) {
			char *ptr = "player 1 battleship is sunk";
			fwrite(ptr, sizeof(ptr), 1, infile);
		}
		if (counter[0][2] == 3) {
			char *ptr = "player 1 cruiser is sunk";
			fwrite(ptr, sizeof(ptr), 1, infile);
		}
		if (counter[0][3] == 3) {
			char *ptr = "player 1 submarine is sunk";
			fwrite(ptr, sizeof(ptr), 1, infile);
		}
		if (counter[0][4] == 2) {
			char *ptr = "player 1 destroyer is sunk";
			fwrite(ptr, sizeof(ptr), 1, infile);
		}

		//identify the winner
		if (player1_hits == player1_total) {
			printf("\n player 1 wins \n");
			loopend = 1;
		}
		if (player2_hits == player2_total) {
			printf("\n player 2 wins \n");
			loopend = 1;
		}
		} while (loopend != 1);

		//write stats to file
		player_1_stats.total_hits = player1_hits; 
		player_1_stats.total_misses = player1_misses;
		player_1_stats.total_shots = player1_hits+player1_misses;
		player_1_stats.hits_misses_ratio = player1_hits/(player1_hits + player1_misses);
		if (player1_hits == player1_total) {
			player_1_stats.won_loss = 1;
		} 
		else {
			player_1_stats.won_loss = 0;
		}
		player_2_stats.total_hits = player2_hits;
		player_2_stats.total_misses = player2_misses;
		player_2_stats.total_shots = player2_hits + player2_misses;
		player_2_stats.hits_misses_ratio = player2_hits / (player2_hits + player2_misses);
		if (player2_hits == player2_total) {
			player_2_stats.won_loss = 1;
		}
		else {
			player_2_stats.won_loss = 0;
		}
		
		fwrite(&player_1_stats, sizeof(struct stats), 1, infile);
		fwrite(&player_2_stats, sizeof(struct stats), 1, infile);
		if (fwrite != 0)
			printf("contents to file written successfully !\n");
		else
			printf("error writing file !\n");
		fclose(infile);

		return 0;
	}