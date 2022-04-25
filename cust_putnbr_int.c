/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cust_putnbr_int.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hiyamamo <hiyamamo@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/25 11:07:40 by hiyamamo          #+#    #+#             */
/*   Updated: 2022/04/25 11:08:27 by hiyamamo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	count_digits_int(int n)
{
	int	count;

	count = 1;
	while (n > 9)
	{
		count++;
		n /= 10;
	}
	return (count);
}

int	put_int_min(void)
{
	write(1, "-2147483648", 11);
	return (11);
}

int	cust_putnbr_int(int n)
{
	int		digit;
	char	each_int;
	int		count;

	count = 0;
	if (n == -2147483648)
		return (put_int_min());
	else
	{
		if (n < 0)
		{
			write(1, "-", 1);
			count += 1;
			n *= -1;
		}
		digit = count_digits_int(n);
		count += digit;
		while (digit-- > 0)
		{
			each_int = n / base_ten_power(digit) + '0';
			write(1, &each_int, 1);
			n %= base_ten_power(digit);
		}
	}
	return (count);
}
