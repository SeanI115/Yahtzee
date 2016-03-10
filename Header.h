#ifndef HEADER_H
#define HEADER_H
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <windows.h>

#define YES_OR_NO_LIMIT 3
#define ROLL 5
#define PLAYER1 1
#define PLAYER2 2
#define COMBINATIONS 13
#define THREE_OF_A_KIND 3
#define FOUR_OF_A_KIND 4
#define YAHTZEE 5
#define FULL_HOUSE_POINTS 25
#define SML_STRAIGHT_POINTS 30
#define LRG_STRAIGHT_POINTS 40
#define YAHTZEE_POINTS 50

void game_rules(void);
int roll_die(void);
int get_combination(void);
int check_combination(int combination_selection, int combinations_array);
int roll_again(int roll[5], int face_values[7], int length_roll, int length_face_values);
int sum_integers(int number_to_sum, int face_value_array[7]);
int use_roll(int *use_roll_combination, int count);
int determine_upper_section_points(int combination_selection, int upper_point_values[4], int face_count[7], int length, int score_from_player);
void display_rules(void);
void display_chart(void);
void display_roll(int die1, int die2, int die3, int die4, int die5);
void sequential_search(int list[13], int size, int target, int *found_pointer, int *index_pointer);
void sort_list_ascending(int list[], int length);
void sort_list_descending(int list[], int length);
void exit_game(void);
void determine_player(int count, int *player);
void print_array(int list[13], int stop_value);
void pause_clear(void);
void print_winner(int total_player1_score, int total_player2_score);
void reset_face_count(int list[7], int length);


#endif