#include "Header.h"
//Prints beginning menu
int display_menu(void)
{
	int choice = 0;

	printf("Welcome to Yahtzee! \n\n");
	printf("1. Rule of Yahtzee.\n");
	printf("2. Play a game!\n");
	printf("3. Quit Game.\n\n");

	printf("Please choose an option from the menu: ");
	scanf("%d", &choice);

	if ((choice > 3) || (choice < 1))
	{
		system("cls");
		display_menu();
	}
	else
	{
		return choice;
	}

}

//Prints game rules and combos
void game_rules(void)
{
	printf("The scorecard used for Yahtzee is composed of two sections. A upper section and a lower section.\n");
	printf("A total of thirteen boxes or thirteen scoring combinations are divided amongst the sections.\n");
	printf("The upper section consists of boxes that are scored by summing the value of the dice matching the faces of the box.\n");
	printf("If a player rolls four 3's, then the score placed in the 3's box is the sum of the dice which is 12.\n");
	printf("Once a player has chosen to score a box, it may not be changed and the combination is no longer in play for future rounds.\n");
	printf("If the sum of the scores in the upper section is greater than or equal to 63, then 35 more points are added to the players overall score as a bonus.\n");
	printf("The lower section contains a number of poker like combinations.\n\n");
	printf("Chart of combos:\n ");
	display_chart();
}

//chart of combos
void display_chart(void)
{
	printf("|   Name     |       Combination        |                Score                 |\n");
	printf("|3-of-a-kind |   3 dice with same face  | Sum of all face values on the 5 dice |\n");
	printf("|4-of-a-kind |   4 dice with same face  | Sum of all face values on the 5 dice |\n");
	printf("|Full house  |  One pair & 3-of-a-kind  |                  25                  |\n");
	printf("|Sml straight|   A sequence of 4 dice   |                  30                  |\n");
	printf("|Lrg straight|   A sequence of 5 dice   |                  40                  |\n");
	printf("|Yahtzee     |5 dice with the same face |                  50                  |\n");
	printf("|Chance      |   Any sequence of dice   | Sum of all face values on the 5 dice |\n");
}

//quits the game
void exit_game(void)
{
	printf("Thank you for playing!\n");
	exit(1);
}

//Creates random numbers between 1-6
int roll_die(void)
{
	int die_value = 0;

	die_value = (rand() % 6) + 1;

	return die_value;
}

//Shows the random numbers that were generated
void display_roll(int die1, int die2, int die3, int die4, int die5)
{
	printf("                 Die 1    Die 2    Die 3    Die 4    Die 5 \n\n");
	printf("                 [ %d ]", die1);
	printf("	  [ %d ]", die2);
	printf("    [ %d ]", die3);
	printf("    [ %d ]", die4);
	printf("    [ %d ]\n\n", die5);
}

//Gets what combo the player wants to do
int get_combination(void)
{
	int combination = 0;
	printf("\n                             Combination choices                       \n");
	printf("          [1]Ones  [2]Twos  [3]Threes   \n  [4]Fours  [5]Fives  [6]Sixes\n"
		"          [7] 3-of-a-kind  [8] 4-of-a-kind  [9]Full house   \n  [10]Sml straight  [11]Lrg straight  [12]Yahtzee\n  [13]Chance\n");
	printf("Combination: ");
	scanf(" %d", &combination);
	--combination;
	return combination;
}

//Check if the combo the player selected is valid
int check_combination(int combination_selection, int combinations_list)
{
	int check = 0;
	if ((combination_selection < 0) || (combination_selection > 12))
	{
		return -1;
	}
	else
	{
		if (combinations_list < 1)
		{
			return 1;
		}
		else
			return -1;
	}
}


void sequential_search(int list[13], int size, int target, int *found_ptr, int *index_ptr)
{
	int index = 0;

	*found_ptr = 0;
	*index_ptr = -1;

	while ((index < size) && ((*found_ptr) != 1))
	{
		if (target == list[index])
		{
			*found_ptr = 1;
			*index_ptr = index;
		}
		else
		{
			index++;
		}
	}

}

//Asks if the user wants to use the current role to choose a combo from
int use_roll(int *use_roll_combination, int count)
{
	int combination = 0;
	char yes_no;

	if (count < 3)
	{
		printf("Use this roll for a scoring combinatination? (Y/N) ");
		scanf(" %c", &yes_no);

		if ((yes_no == 'y') || (yes_no == 'Y'))
		{
			combination = 1;
			*use_roll_combination = combination;
			return 1;
		}
		else if ((yes_no == 'n') || (yes_no == 'N'))
		{

			combination = 0;
			*use_roll_combination = combination;
			return 0;
		}
		else
		{
			return -1;
		}
	}
	else
	{
		return 1;
	}
}

//Clears the screan
void pause_clear(void)
{
	system("pause");
	system("cls");
}

//Figures out which player is currently playing
void determine_player(int count, int *player)
{
	if (((count + 1) % 2) == 0)
	{
		*player = PLAYER1;
	}
	else if (((count + 1) % 2) == 1)
	{
		*player = PLAYER2;
	}
}

//Rolls the dice again if the user chooses to do so
int roll_again(int roll[5], int face_values[7], int length_roll, int length_face_values)
{
	int number_held = 0, temp_1 = 0, index = 0, face_count_copy[7] = { 0 };

	for (index = 0; index < length_roll; index++)
	{
		printf("Roll die %d again (Y/N)?  ", index + 1);
		scanf(" %c", &temp_1);
		printf("\n");
		if ((temp_1 == 'y') || (temp_1 == 'Y'))
		{
			roll[index] = roll_die();
		}
		face_values[roll[index]]++;
	}


}


void print_array(int list[13], int stop_value)
{
	int index = 0;
	for (index = 0; index < stop_value; index++)
	{
		printf("List[%d]: %d\n", index, list[index]);
	}
}

//Adds the integers of the array
int sum_integers(int number_to_sum, int face_value_array[7])
{
	int index = 0, sum = 0;
	for (index = 0; index < face_value_array[number_to_sum]; index++)
	{
		sum += number_to_sum;
		printf("SUM: %d\n", sum);
	}
	return sum;
}


void sort_list_ascending(int list[], int length)
{
	int index = 0, temp = 0, passes = 0;
	while (length > passes)
	{
		for (index = 0; index < (length - 1); index++)
		{
			if (list[index] > list[index + 1])
			{
				temp = list[index];
				list[index] = list[index + 1];
				list[index + 1] = temp;
			}
		}
		passes++;
	}
}


void sort_list_descending(int list[], int length)
{
	int index = 0, temp = 0, pass = 0;
	while (length > pass)
	{
		for (index = 0; index < (length - 1); index++)
		{
			if (list[index] < list[index + 1])
			{
				temp = list[index + 1];
				list[index + 1] = list[index];
				list[index] = temp;
			}
		}
		pass++;
	}
}

//If combo choice is valid determines amount of points to be awarded to player
int determine_upper_section_points(int combination_selection, int upper_point_values[4], int face_count[7], int length, int score_from_player)
{
	int points = 0, index = 0, face_count_sorted[7] = { 0 }, accumulator = 0;

	for (index = 0; index < length; index++)
	{
		face_count_sorted[index] = face_count[index];
	}

	sort_list_descending(face_count_sorted, length);

	if ((face_count_sorted[0] >= FOUR_OF_A_KIND) && ((combination_selection == 7)))
	{
		for (index = 0; index < length; index++)
		{
			score_from_player += (face_count[index] * index);
		}
		return score_from_player;
	}

	else if ((face_count_sorted[0] >= THREE_OF_A_KIND) && ((combination_selection == 7) || (combination_selection == 6)))
	{
		for (index = 0; index < length; index++)
		{
			score_from_player += (face_count[index] * index);
		}
		return score_from_player;
	}

	else if ((face_count_sorted[0] == 5) && (combination_selection == 11))
	{
		score_from_player += YAHTZEE_POINTS;
		return score_from_player;
	}

	else if (combination_selection == 12)
	{
		for (index = 0; index < length; index++)
		{
			score_from_player += (face_count[index] * index);
		}
		return score_from_player;
	}

	else if (((face_count_sorted[0] > 2) && (face_count_sorted[1] > 1)) && (combination_selection == 8))
	{
		score_from_player += FULL_HOUSE_POINTS;
		return score_from_player;
	}

	else if (combination_selection == 10)
	{
		accumulator = 0;
		for (index = 0; index < length; index++)
		{
			if (face_count[index] == 1)
			{
				accumulator += 1;
			}
		}
		if (accumulator == 5)
		{
			score_from_player += LRG_STRAIGHT_POINTS;
			return score_from_player;
		}

	}

	else if ((combination_selection == 9) || (combination_selection == 10))
	{
		accumulator = 0;
		for (index = 0; index < length; index++)
		{
			if (face_count[index] == 1)
			{
				accumulator += 1;
			}
		}
		for (index = 0; index < length; index++)
		{
			if (face_count[index] == 2)
			{
				accumulator += 1;
				break;
			}
		}
		if (accumulator == 4)
		{
			score_from_player += SML_STRAIGHT_POINTS;
			return score_from_player;
		}

	}

	else
		return score_from_player;
}


void print_winner(int total_player1_score, int total_player2_score)
{
	printf("                 Player 1 score: %d     Player 2 score: %d\n\n", total_player1_score, total_player2_score);
	if (total_player1_score > total_player2_score)
	{
		printf("                               Player 1 wins!!!!!!!!!!!!\n\n");
	}
	else if (total_player1_score == total_player2_score)
	{
		printf("                     Well it appears we have a tie....\n\n");
	}
	else if (total_player2_score > total_player1_score)
	{
		printf("                               Player 2 wins!!!!!!!!!!!\n\n");
	}

}


void reset_face_count(int list[7], int length)
{
	int index = 0;
	for (index = 0; index < (length); index++)
	{
		list[index] = 0;
	}
}