/////////////////////////////////////////////////////////////////////////////
// INTEGRITY INSTRUCTIONS

// Explicitly state the level of collaboration on this question
// Examples:
//   * I discussed ideas with classmate(s) [include name(s)]
//   * I worked together with classmate(s) in the lab [include name(s)]
//   * Classmate [include name] helped me debug my code
//   * I consulted website [include url]
//   * None
// A "None" indicates you completed this question entirely by yourself
// (or with assistance from course staff)
/////////////////////////////////////////////////////////////////////////////
// INTEGRITY STATEMENT: 
// I received help from the following sources:

// none

// Name: Diwen Zhu
// login ID: d55zhu
/////////////////////////////////////////////////////////////////////////////

#include <string.h>
#include "hangman-io.h"
#include "words.h"
#include "cs136.h"

bool char_in_word(const char *word, int word_len, char c) {
  assert(word);
  assert(word_len);
  int i=0;
  while(*(word+i)) {
    if (*(word+i) == c) {
      return true;
    }
    ++i;
  }
  return false;
}

void operate_hangman(const char *word, int word_length) {
  char guess[26] = {0};
  int strike=0;
  print_hangman(strike);
  while(1) {
    printf("%s", letter_prompt);
    for(int i=0; i<word_length; ++i) {
      if(*(word+word_length) == ' ') {
        printf(" ");
      } else if (guess[*(word+i)-'A']) {
        printf("%c", *(word+i));
      } else {
        printf("*");
      } 
    }
    printf("\n");
    char c = 0;
    scanf("%c", &c);
    while (c == '\n') {
      scanf("%c", &c);
    }
    if (! ((c>='A' && c<='Z') || (c>='a' && c<='z'))) { 
      printf(not_a_letter, c);
      print_hangman(strike);
      continue;
    } 
    if(c>='a' && c<='z') {
      c = c-'a'+'A';
    }
    if (guess[c-'A']) {
      printf(already_guessed_letter, c);
      print_hangman(strike);
      continue;
    } else {
      guess[c-'A']++;
    }
    if (!char_in_word(word, word_length, c)) {
      printf(not_in_word, c);
      strike++;
      if(strike<max_strikes) {
        printf(not_last_guess, max_strikes-strike);
        print_hangman(strike);
        continue;
      } else {
        print_hangman(max_strikes);
        printf(game_over, word);
        return;
      }
    } 
    if (guess[c-'A'] && char_in_word(word, word_length, c)) {
      int i=0;
      for(; i<word_length; ++i) {
        if(!guess[*(word+i)-'A']) {
          break;
        }
      }
      if(i == word_length) {
        printf(congratulations, word);
        return;
      } else {
        print_hangman(strike);
      }
    }
  }
}

int main(void) {
  while(1) {
    printf(enter_game_number, max_words);     //ask for number input
    int w = 0;
    scanf("%d", &w);
    while (w>max_words || w<1) {      // if number is invalid
      printf("%s", invalid_game_number);
      printf(enter_game_number, max_words);
      scanf("%d", &w);
    }
    const char *word = NULL;
    word=get_word(w);      //get the word and its word_length
    int word_length = 0;
    while(*(word+word_length)) {
      word_length++;
    }
    operate_hangman(word, word_length);
    printf("%s", play_again);
    char again = 0;
    scanf("%c", &again);
    while (again == '\n') {
      scanf("%c", &again);
    }
    while(again!='N' && again!='n' && again!='Y' && again!='y') {
      printf("%s", invalid_play_again_response);
      printf("%s", play_again);
      scanf("%c", &again);
      while (again == '\n') {
        scanf("%c", &again);
      }
    }
    if(again == 'n' || again == 'N') {
      return 0;
    }
  }
}

