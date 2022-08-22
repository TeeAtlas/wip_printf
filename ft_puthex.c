/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: taboterm <taboterm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:10:04 by taboterm          #+#    #+#             */
/*   Updated: 2022/08/22 13:51:43 by taboterm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(long n, char *base, int base_len)
{
	int			i;

	i = 0;
	if (n < 0)
	{
		i += write(1, "-", 1);
		n = -(n);
	}
	if (n == 0)
	{
		return (write(1, "0", 1), i + 1);
	}
	if (n >= base_len)
	{
		i += ft_puthex(n / base_len, base, base_len);
		i += write(1, &base[n % base_len], 1);
	}
	else if (n < base_len)
		i += write(1, &base[n], 1);
	return (i);
}

// int	main()
// {   
// 	int i = ft_printf("%x %x %x %x %x", 0, 40, -23, -2147483647, 7);
// 	ft_printf("\n");
// 	printf("%d\n", i);
// }