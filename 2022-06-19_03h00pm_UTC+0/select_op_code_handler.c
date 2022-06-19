#include "monty.h"
#include <string.h>

void (*select_op_code_handler(char *op_code))(stack_t **, unsigned int)
{
        instruction_t ops[] = {
            {"pall", op_pall},
            {"pint", op_pint},
            {"pop", op_pop}
        };
        size_t len = sizeof(ops) / sizeof(instruction_t);
        size_t i = 0;

        while (i < len && strcmp(ops[i].opcode, op_code) != 0)
            i++;

        if (i == len)
            return (NULL);

        return (ops[i].f);
}