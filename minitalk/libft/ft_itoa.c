/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afailde- <afailde-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/27 08:56:59 by afailde-          #+#    #+#             */
/*   Updated: 2024/03/19 12:44:35 by afailde-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_digit_count(long int i)
{
	int	count;

	count = 0;
	if (i < 0)
	{
		i *= -1;
		count++;
	}
	while (i > 0)
	{
		i /= 10;
		count++;
	}
	return (count);
}

char	*ft_itoa(int n)
{
	char	*str;
	int		i;
	long	numb;

	if (n == 0)
		return (ft_strdup("0"));
	numb = (long)n;
	i = ft_digit_count(numb);
	str = ft_calloc((i + 1), sizeof(char));
	if (!str)
		return (NULL);
	i--;
	if (numb < 0)
	{
		str[0] = '-';
		numb = numb * -1;
	}
	while (numb > 0)
	{
		str[i--] = numb % 10 + '0';
		numb = numb / 10;
	}
	return (str);
}

/* int main()
{
	int num = 123487;

	char *str = ft_itoa(num);
	free(str);
	printf("%s\n");
} */
