# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>

void	remove_quote(char *value)
{
	char	*copy;
	char	*ptr_copy;
	bool	single_quoted;
	bool	double_quoted;

	single_quoted = false;
	double_quoted = false;
	copy = strdup(value);
	ptr_copy = copy;
	while (*ptr_copy)
	{
		printf("ptr_copy: %i\n", *ptr_copy);
		printf("ptr_copy: %s\n", ptr_copy);
		printf("*ptr_copy == '\"': %d\n", *ptr_copy == '\"');
		if (*ptr_copy == '\'' && !double_quoted)
		{
			printf("single quote found\n");
			single_quoted = !single_quoted;
		}
		else if (*ptr_copy == '"' && !single_quoted)
		{
			printf("double quote found\n");
			double_quoted = !double_quoted;
		}
		else
			*value++ = *ptr_copy;
		ptr_copy++;
	}
	*value = '\0';
	free(copy);
}

int main()
{
    char input[] = "\"this$PATH\"";
    printf("Before: %s\n", input);
    remove_quote(input);
    printf("After: %s\n", input);
    return 0;
}
