#include "autocomplete.h"

#include <stddef.h>
#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

/**
 * This function is called with a pointer to space to an autocomplete_t that
 * should be initialized. You should add code to this function to set up
 * whatever data structure you use to keep track of past inputs.
 *
 * \param a A pointer to allocated space for an autocomplete_t
 */
void autocomplete_init(autocomplete_t* a) {
  // TODO: Implement me!
    a = (struct autocomplete*)malloc(sizeof(struct autocomplete));
    a->isEnd = 0;
    for (int i = 0; i < ALPHABET; i++) {
        a ->val[i] = NULL;
    }
  // What you do here depends on your data structure. You may only need to set
  // a pointer to NULL, or it could be something more complex.
}

 struct autocomplete *makeNode(void)
{
    struct autocomplete *node = NULL;
    node = (struct autocomplete*)malloc(sizeof(struct autocomplete));
        node -> isEnd = 0;
        for (int i = 0; i < ALPHABET; i++) {
             node->val[i] = NULL;
    }
        return node;
}
/**
 * This function is called to add a new line to the autocomplete structure. The
 * caller retains ownership of the memory pointed to by `line`, so you should
 * copy this memory if you need to store it in a data structure.
 *
 * \param a     A pointer to an allocated and initialized autocomplete_t
 * \param line  A pointer to a string that should be added to the autocomplete
 *              data structure. The autocomplete structure does *not* take 
 *              ownership of this memory.
 */


void autocomplete_add_line(autocomplete_t* a, char* line) {
  // TODO: Implement me!
    struct autocomplete* cur = a;
    int len = strlen(line);
    for(int i = 0; i < len; i ++){
        if(cur->val[*line - 'a'] == NULL){
            cur->val[*line - 'a'] = makeNode();
    }
        cur = cur ->val[*line - 'a'];
    }
    cur->isEnd = 1;
  // The string `line` should be added to the autocomplete structure so it is
  // suggested in the future. Make sure you do not use the memory that holds
  // `line` in your structure though; it may be reused. You can use `strdup` to
  // duplicate it if you need a copy.
}



int isLastWord(struct autocomplete* cur){
    for(int i = 0; i < ALPHABET; i ++){
        if(cur->val[i]){
            return 0;
        }
    }
    return 1;
}

char* append(char* s, char c)
{
    size_t len = strlen(s);
    char *temp = malloc(len + 1 + 1);
    strcpy(temp, s);
    temp[len] = c;
    temp[len + 1] = '\0';
    return temp;
}

void autocomplete_help(struct autocomplete* cur, char** output, int n, int m, char * str){
    if(n >= m){
        return;
    }
    if(cur -> isEnd){
        output[n] = str;
    }
    if(isLastWord(cur)) {
        return;
    }
    for(int i = 0; i < ALPHABET; i++){
        if(cur->val[i]){
            str = append(str, 'a'+ i);
            autocomplete_help(cur->val[i], output, n, m, str);
        }
    }
    n++;
}


/**
 * This function is called to request up to `N` suggestions from the
 * autocomplete data structure. The function should write pointers to the
 * suggested strings into the `output` array and return the number of
 * suggestions that were returned.
 *
 * \param a       A pointer to an allocated and initialized autocomplete_t
 * \param input   A string input that should be used to search for suggestions
 * \param output  An array that can hold up to `N` suggestions. The autocomplete
 *                suggestions should be written into this array. The caller does
 *                *not* take ownership of the strings written into this array.
 * \param N       The maximum number of suggestions that can be written into
 *                the `output` array.
 *
 * \returns The number of suggestions written into the `output` array.
 */
size_t autocomplete_get_suggestions(autocomplete_t* a, char* input, char** output, size_t N) {
  // TODO: Implement me.
    
    if (input == NULL) {
        return 0;
    }
    struct autocomplete* cur = a;
    char *str;
    int len = strlen(input);
    for(int i = 0; i < len; i ++){
        if(cur->val[*input - 'a'] == NULL){
            return 0;
        }
            cur = cur->val[*input - 'a'];
        }
    if (cur->isEnd && isLastWord(cur)){
        return 1;
    }
    if (isLastWord(cur) == 0){
        autocomplete_help(cur, output, 0, N, str);
    }
    
//    while(*input){
//        cur = cur ->val[*input - 'a'];
//        // if we reach the end of Trie
//        if (cur == NULL) {
//            output[0] = input;
//            return 1;
//        }
//        input++;

    
    return sizeof(output);
}
  
    
  // See the placeholder code below for an example of how autocomplete
  // suggestions can be returned.
  
//  if(N == 1) {
//    output[0] = "Hello";
//    return 1;
//  } else if(N >= 2) {
//    output[0] = "Hello";
//    output[1] = "World";
//    return 2;
//  }
//
//  return 0;




/**
 * This function cleans up any memory used for the autocomplete data structure.
 * Once this function returns, the memory pointed to by `a` should be usable as
 * an autocomplete data structure only if it is passed to autocomplete_init.
 * 
 * \param a  A pointer to an allocated and initialized autocomplete_t structure.
 */
void autocomplete_shutdown(autocomplete_t* a) {
  // TODO: Implement me!
  
  // Make sure you free any memory you allocated for your data structure.
}
