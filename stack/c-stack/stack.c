#include "stdio.h"
#include "stdlib.h"
#include <stddef.h>
#include "string.h"


typedef struct stack_t {
	size_t len;
	size_t size;
	char *data;
} stack_t;

stack_t stack() {
	stack_t s;
	s.len = 0;
	s.size = 0;
	s.data = malloc(0);
	return s;
}

void push(stack_t *s, char elem) {
	s->size += sizeof(char);
	s->data = (char*)realloc(s->data, s->size);
	s->data[s->len] = elem;
	s->len++;
}

void pop(stack_t *s) {
	s->size -= sizeof(char);
	s->data[s->len] = 0;
	s->data = (char*)realloc(s->data, s->size);
	s->len--;
}

void printStack(stack_t *s) {
	for (size_t i=0; i < s->len; i++) {
		printf("%c\n", s->data[i]);
	}
}

int parseParan(const char* paran) {
	stack_t s = stack();

	size_t counter = 0;
	for (size_t i=0; i < strlen(paran); i++) {
		if (paran[i] == '(') {
			push(&s, paran[i]);
			counter++;
		} else if (paran[i] == ')') {
			if (s.len == 0) {
				return 0;
			}
			if (s.data[s.len -1] != '(') {
				return 0;
			}
			pop(&s);
			counter--;
		}
	}

	return counter != 0 ? 0 : 1;
}

int main() {
	const char works[] = "(())()";
	const char broken[] = "(((()";
	const char bad_seq[] = "))((";

	printf("1 means paranthesis is balanced and 0 means its not.\n");
	printf("Paranthesis: %s, value: %d\n",works, parseParan(works));
	printf("Paranthesis: %s, value: %d\n",broken, parseParan(broken));
	printf("Paranthesis: %s, value: %d\n",bad_seq, parseParan(bad_seq));
}
