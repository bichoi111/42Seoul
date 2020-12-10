#include <stdlib.h>

int	str_len(char *c)
{
	int i;
	i = 0;
	while (c[i])
		i++;
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	char *str_tmp;
	char *cset_tmp;
	char *word_address;
	int len; // charset과 일치한 길이를 센다.
	int cset_cnt;

	
	word_address = str; // 단어의 주소를 저장해둔다.
	cset_cnt = 0;
	str_tmp = str;
	while (*str)
	{
		cset_tmp = charset;
		len = 0;
		while (*str_tmp == *cset_tmp && *cset_tmp != 0 && *str_tmp != 0)
		{
			len++;
			str_tmp++;
			cset_tmp++
		}
		if (len == str_len(cset_tmp)) // 구분자가 일치
		{
			cset_cnt += 1;
			str = str_tmp; // str애는 구분자 바로 다음 주소
			word_address = str;
		}
		else // 구분자가 일치하지 않을 경우엔 단어임. 단어의 갯수는 (구분자 - 1)
			str++;
			
	}
}
