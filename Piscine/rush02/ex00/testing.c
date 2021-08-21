#include <stdlib.h>
#include <stdio.h> // <------------------------------------------------

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define TRUE 1
#define FALSE 0

int	is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (TRUE);
	return (FALSE);
}

int	is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (TRUE);
	return (FALSE);
}

char    *ft_strcpy(char *dest, char *src)
{
        int     i;

        i = 0;
        while (*(src + i) != '\0')
        {
                *(dest + i) = *(src + i);
                i++;
        }
        *(dest + i) = '\0';
        return (dest);
}

int main(void)
{
    int         fd;
	int			ret;
	char		ch;
	int			digit_size;
	int			text_size;
	int			is_space_started;
	int			is_double_dot_started;

    
    fd = open("numbers.dict", O_RDONLY);
	ret = read(fd, &ch, 1);
    int lines = 0;
    while (ret != 0)
    {   
        lines++;     
        ret = read(fd, &ch, 1);
    }
    close(fd);


    char **digits;
    char **texts;

    digits = (char**)malloc(sizeof(char*) * lines);
    texts = (char**)malloc(sizeof(char*) * lines);


	is_space_started = FALSE;
	is_double_dot_started = FALSE;
	digit_size = 0;
	text_size = 0;

    fd = open("numbers.dict", O_RDONLY);
	ret = read(fd, &ch, 1);
    lines = 0;
    while (ret != 0)
    {
        if (ch == ' ' && !is_double_dot_started)
			is_space_started = TRUE;
		if (is_digit(ch) && !is_space_started && !is_double_dot_started)
			digit_size++;

		is_space_started = FALSE;
		if (ch == ' ' && is_double_dot_started)
			is_space_started = TRUE;

		if (is_printable(ch) && !is_space_started && is_double_dot_started)
			text_size++;

		if (ch == ':')
		{
			is_double_dot_started = TRUE;
			is_space_started = FALSE;
		}

		if (ch == '\n')
		{
            lines++;
			//ft_list_push_back_alloc(&dict, digit_size+1, text_size+1);
			printf("digit_size=%d\ttext_size=%d\n", digit_size, text_size);
            digits[lines] = (char *)malloc(sizeof(char) * (digit_size + 1));
            texts[lines] = (char *)malloc(sizeof(char) * (text_size + 1));
			
            text_size = 0;
			digit_size = 0;
			is_space_started = FALSE;
			is_double_dot_started = FALSE;
		}
        ret = read(fd, &ch, 1);
    }
    close(fd);


    lines = 0;
    fd = open("numbers.dict", O_RDONLY);
	ret = read(fd, &ch, 1);
    int q1 = 0;
    int q2 = 0;
    while (ret != 0)
    {
        if (ch == ' ' && !is_double_dot_started)
			is_space_started = TRUE;
		if (is_digit(ch) && !is_space_started && !is_double_dot_started)
            digits[q1++] = ch;        
        digits[q1] = '\0';

		is_space_started = FALSE;
		if (ch == ' ' && is_double_dot_started)
			is_space_started = TRUE;

		if (is_printable(ch) && !is_space_started && is_double_dot_started)
			texts[q2++] = ch;
        texts[q2] = '\0';

		if (ch == ':')
		{
			is_double_dot_started = TRUE;
			is_space_started = FALSE;
		}

		if (ch == '\n')
		{
			//ft_list_push_back_alloc(&dict, digit_size+1, text_size+1);
			printf("digits=%s\ttexts=%s\n", digits[lines], texts[lines]);

            lines++;
			is_space_started = FALSE;
			is_double_dot_started = FALSE;
		}
        ret = read(fd, &ch, 1);
    }
    close(fd);
}