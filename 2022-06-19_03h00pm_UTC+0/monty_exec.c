#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

void monty_exec(FILE *fp)
{
    char *line = NULL;
    size_t line_size;
    ssize_t len;
    char *op_code = NULL, *op_code_arg = NULL;
    unsigned int line_number = 0;
    stack_t *stack = NULL;
    void (*op_code_handler)(stack_t **, unsigned int);

    /* read a line */
    while ((len = getline(&line, &line_size, fp)) != -1)
    {
        line[len - 1] = '\0';
        line_number += 1;

        op_code = strtok(line, " ");
        op_code_arg = strtok(NULL, " ");

        if (op_code == NULL)
            continue; /* skip empty line */

        /* find the the opcode handler */
        if (strcmp(op_code, "push") == 0)
        {
            op_push(&stack, line_number, op_code_arg);
            continue;
        }
        
        op_code_handler  = select_op_code_handler(op_code);

        if (op_code_handler)
            op_code_handler(&stack, line_number);
        else
        {
            free_stack(&stack);
            fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
            exit(EXIT_FAILURE);
        }
    }

    free_stack(&stack);
}
