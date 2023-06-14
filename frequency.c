#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//TODO: polish this up
//
#define DEFAULT_SIZE 50

struct data
{
	char *value;
	int frequency;
};

struct frequencies
{
	struct data **data;
	int size;
	int contents;
};

void add_or_increment(char *value, struct frequencies *frequencies)
{
	if (!frequencies->data)
	{
		frequencies->data = malloc(sizeof(struct data*) * 50);

		frequencies->size = DEFAULT_SIZE;
		frequencies->contents = 0;
	}
       	else if (frequencies->size == frequencies->contents - 1)
	{
		frequencies->data = realloc(frequencies->data, sizeof(struct data*) * (frequencies->size + DEFAULT_SIZE));
		
		frequencies->size += DEFAULT_SIZE;
	}

	for (int i = 0; i < frequencies->contents; i++)
	{
		const char *compare = frequencies->data[i]->value;

		if (!strcmp(compare, value))
		{
			frequencies->data[i]->frequency++;
			return;
		}
	}

	/* This is a new string */
	char *copy = strdup(value);
	frequencies->data[frequencies->contents] = malloc(sizeof(struct data));
	frequencies->data[frequencies->contents]->value = copy;
	frequencies->data[frequencies->contents]->frequency = 1;
	frequencies->contents++;
}

void frequencies_destroy(struct frequencies *frequencies)
{
	for (int i = 0; i < frequencies->contents; i++)
	{
		/* Free the strings themselves */
		free(frequencies->data[i]->value);
		/* Free the data objects */
		free(frequencies->data[i]);
	}

	/* finally free the array */
	free(frequencies->data);
}

void print_frequencies(struct frequencies *frequencies)
{
	for (int i = 0; i < frequencies->contents; i++)
	{
		printf("string :  %s frequency : %d \n", frequencies->data[i]->value, frequencies->data[i]->frequency);
	}

}

void tokenize_and_analyze(char *to_tokenize, struct frequencies *frequencies)
{
	char *token = NULL;

	token = strtok(to_tokenize, " ,.");

	while (token)
	{
		printf(" %s \n", token);
		add_or_increment(token, frequencies);
		token = strtok(NULL, " ,.");
	}
}

int main(int argc, char *argv[])
{
	char *to_copy = "This is the string that we are going to use to test our code. Our code might be broken. We are going to use this then try reading the string from user input to test. As you can see, this is a very simple string";

	char *to_tokenize = strdup(to_copy);
	char *to_free = to_tokenize;

	struct frequencies *frequency = malloc(sizeof(struct frequencies));

	tokenize_and_analyze(to_tokenize, frequency);

	print_frequencies(frequency);

	frequencies_destroy(frequency);

	free(frequency);
	free(to_free);
	return 0;
}
