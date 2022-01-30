#include <stdlib.h>

int	c_is_sep(char c, char *charset)
{
	int	i;

	i = 0;
	while (charset[i] != '\0')
	{
		if (c == charset[i])
			return (1);
		i++;
	}
	if (c == '\0')
		return (1);
	return (0);
}

int	count_word(char *str, char *charset)
{
	int	i;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (c_is_sep(str[i], charset) == 0
			&& c_is_sep(str[i + 1], charset) == 1)
			word++;
		i++;
	}
	return (word);
}

void	write_word(char *dest, char *src, char *charset)
{
	int	i;

	i = 0;
	while (c_is_sep(src[i], charset) == 0)
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
}

void	insplit(char **split, char *str, char *charset)
{
	int	i;
	int	j;
	int	word;

	i = 0;
	word = 0;
	while (str[i] != '\0')
	{
		if (c_is_sep(str[i], charset) == 1)
			i++;
		else
		{
			j = 0;
			while (c_is_sep(str[i + j], charset) == 0)
				j++;
			split[word] = (char *)malloc(sizeof(char) * (j + 1));
			write_word(split[word], str + i, charset);
			word ++;
			i += j;
		}
	}
}

char	**ft_split(char *str, char *charset)
{
	char	**result;
	 int	word_n;

	word_n = count_word(str, charset);
	result = (char **)malloc(sizeof(char *) * (word_n + 1));
	result[word_n] = 0;
	insplit(result, str, charset);
	return (result);
}