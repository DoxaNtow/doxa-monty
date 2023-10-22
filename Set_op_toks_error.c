#include "monty.h"

/**
 * set_op_tok_error - Sets last element of op_tokns to be an error code.
 * @error_code: Integer to store as a string in op_tokns.
 */
void set_op_tok_error(int error_code)
{
    int toks_len = 0, i = 0;
    char *exit_str = NULL;
    char **new_toks = NULL;


    toks_len = token_arr_len();
    new_toks = malloc(sizeof(char *) * (toks_len + 2));
    if (!op_tokns)
    {
        malloc_error();
        return;
    }
    while (i < toks_len)
    {
        new_toks[i] = op_tokns[i];
        i++;
    }
    exit_str = get_int(error_code);
    if (!exit_str)
    {
        free(new_toks);
        malloc_error();
        return;
    }
    new_toks[i++] = exit_str;
    new_toks[i] = NULL;
    free(op_tokns);
    op_tokns = new_toks;
}
