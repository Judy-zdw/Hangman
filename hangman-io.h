#include "cs136.h"

// This hangman-io module provides constant strings
// for printing within the hangman game

extern const int max_strikes;

extern const char *enter_game_number;
extern const char *invalid_game_number ;
extern const char *letter_prompt;
extern const char *not_a_letter;
extern const char *already_guessed_letter;
extern const char *not_in_word;
extern const char *not_last_guess;
extern const char *play_again;
extern const char *invalid_play_again_response;
extern const char *game_over;
extern const char *congratulations;

// print_hangman(strike) prints the hangman picture
//   for the given number of strikes
// requires: 0 <= strike <= max_strikes
void print_hangman(int strike);

//char_in_word(word, word_len, c) determines if c is one of the character in word which has length word_len
// requires: word is not NULL, and word_len>0
//time: O(n), n is word_len
bool char_in_word(const char *word, int word_len, char c);

//operate_hangman(word, word_length) considers four situations based on user's input when the target word in hangman game is word with length word_length. 
//requires: word is not NULL, and word_length >0
//effects: read input and produce output
//time: O(n), n is word_length
void operate_hangman(const char *word, int word_length);
