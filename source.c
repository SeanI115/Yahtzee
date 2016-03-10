//Sean Inouye
//11461599
//Cpts 121
//Text based version of the game Yahtzee!

#include "Header.h"

int main(void)
{
	int menu_response = 0, i = 0, roll[5] = { 0 }, upper_point_values[4] = { 25, 30, 40, 50 }, count = 0, roll_count = 0,
		combinations_player1[13] = { 0 }, face_count[7] = { 0 }, combinations_player2[13] = { 0 }, *ptr_die_1 = NULL,
		*ptr_die_2 = NULL, *ptr_die_3 = NULL, *ptr_die_4 = NULL, *ptr_die_5 = NULL, use_roll_selection = -1, *ptr_roll_selection = NULL,
		player = 0, *ptr_player = NULL, total_player1_points = 0, total_player2_points = 0, *ptr_combination_selection = NULL,
		combination_selection = 0, checked_combination = 0, point_value = 0, sum = 0;

	ptr_player = &player;
	ptr_combination_selection = &combination_selection;
	ptr_die_1 = &roll[0], ptr_die_2 = &roll[1], ptr_die_3 = &roll[2], ptr_die_4 = &roll[3], ptr_die_5 = &roll[4];
	srand((unsigned int)time(NULL));
	
	menu_response = display_menu();
	if (menu_response == 1)
	{
		game_rules();
		pause_clear();
		main();
	}
	else if (menu_response == 3)
	{
		system("cls");
		exit_game();
	}
	else
	{
		pause_clear();
		do
		{
			count++;
			do
			{
				determine_player(count, ptr_player);
				printf("Player = %d\n", player);
				roll_count++;
				printf("Roll #%d\n\n", roll_count);
				if (roll_count == 1)
				{
					for (i = 0; i < 5; i++)
					{
						roll[i] = roll_die();
						face_count[roll[i]]++;
					}
				}
				display_roll(*ptr_die_1, *ptr_die_2, *ptr_die_3, *ptr_die_4, *ptr_die_5);
				use_roll(&use_roll_selection, roll_count);

				if ((use_roll_selection == 1) || (roll_count == 3))
				{
					if (player == PLAYER1)
					{
						combination_selection = get_combination();
						checked_combination = check_combination(combination_selection, combinations_player1[combination_selection]);
						while (checked_combination == -1)
						{
							system("cls");
							printf("Roll #%d\n\n", roll_count);
							display_roll(*ptr_die_1, *ptr_die_2, *ptr_die_3, *ptr_die_4, *ptr_die_5);
							printf("Sorry! Not a valid choice. Please try again.\n");
							combination_selection = get_combination();
							checked_combination = check_combination(combination_selection, combinations_player1[combination_selection]);
						}
						combinations_player1[combination_selection]++;
						pause_clear();
					}
					else if (player == PLAYER2)
					{
						combination_selection = get_combination();
						checked_combination = check_combination(combination_selection, combinations_player2[combination_selection]);
						while (checked_combination == -1)
						{
							system("cls");
							printf("Roll #%d\n\n", roll_count);
							display_roll(*ptr_die_1, *ptr_die_2, *ptr_die_3, *ptr_die_4, *ptr_die_5);
							printf("Sorry! Not a valid choice. Please try again.\n");
							combination_selection = get_combination();
							checked_combination = check_combination(combination_selection, combinations_player2[combination_selection]);
						}
						combinations_player2[combination_selection]++;
						pause_clear();
					}
					checked_combination = 0;

				}
				else if (use_roll_selection == 0)
				{
					reset_face_count(face_count, 7);
					roll_again(roll, face_count, ROLL, 7);

					pause_clear();
				}
			} while (((roll_count < 3) && (checked_combination != 1)) && use_roll_selection == 0);
			roll_count = 0;

			if (player == PLAYER1)
			{
				if (combination_selection < 7)
				{
					sum = sum_integers(combination_selection + 1, face_count);
					total_player1_points += sum;
				}
				else if (combination_selection >= 7)
				{
					total_player1_points = determine_upper_section_points(combination_selection, upper_point_values, face_count, 7, total_player1_points);
				}
			}
			else if (player == PLAYER2)
			{
				if (combination_selection < 7)
				{
					sum = 0;
					sum = sum_integers(combination_selection + 1, face_count);
					total_player2_points += sum;
				}
				else if (combination_selection >= 7)
				{
					total_player2_points = determine_upper_section_points(combination_selection, upper_point_values, face_count, 7, total_player2_points);
				}
			}
			printf("Scores\n");
			printf("Player 1 Score = %d\n", total_player1_points);
			printf("Player 2 Score = %d\n", total_player2_points);
			reset_face_count(face_count, 7);
			pause_clear();
		} while (count < 26);

	}
	print_winner(total_player1_points, total_player2_points);
					
	return 0;
}