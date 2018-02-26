#if !defined(AUTOCOMPLETE_H)
#define AUTOCOMPLETE_H

#include <stddef.h>
#include <stdbool.h>

#define ALPHABET 26

typedef struct autocomplete {
  // TODO: Add fields to this struct to hold your autocomplete structure
    struct autocomplete *val[ALPHABET];
    int isEnd;
    
} autocomplete_t;

/**
 * This function is called with a pointer to space to an autocomplete_t that
 * should be initialized. You should add code to this function to set up
 * whatever data structure you use to keep track of past inputs.
 *
 * \param a A pointer to allocated space for an autocomplete_t
 */
void autocomplete_init(autocomplete_t* a);

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
void autocomplete_add_line(autocomplete_t* a, char* line);

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
size_t autocomplete_get_suggestions(autocomplete_t* a, char* input, char** output, size_t N);

/**
 * This function cleans up any memory used for the autocomplete data structure.
 * Once this function returns, the memory pointed to by `a` should be usable as
 * an autocomplete data structure only if it is passed to autocomplete_init.
 * 
 * \param a  A pointer to an allocated and initialized autocomplete_t structure.
 */
void autocomplete_shutdown(autocomplete_t* a);

#endif
