#include <stdio.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (*(s1 + i) == *(s2 + i))
	{
		if (*(s1 + i) == '\0')
			return (*(s1 + i) - *(s2 + i));
		i++;
	}
	return (*(s1 + i) - *(s2 + i));
}

void	ft_advanced_sort_string_tab(char **tab, int(*cmp)(char *, char *));

int main(void)
{
	char	*tab[] = {"iugh93jg", "aiugfwgweg0brw", "zh8hgr3", (void *)0};

	for (int i = 0; i < 4; i++)
		printf("%s\n", tab[i]);

	printf("--------\n");

	ft_advanced_sort_string_tab(tab, &ft_strcmp);

	for (int i = 0; i < 3; i++)
		printf("%s\n", tab[i]);
}
