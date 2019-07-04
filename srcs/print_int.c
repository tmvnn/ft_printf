/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_int.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lbellona <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 15:28:01 by lbellona          #+#    #+#             */
/*   Updated: 2018/12/19 18:26:51 by lbellona         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_printf.h"

void    print_sign(t_pf *pf)
{
	if (pf->flag.plus || pf->flag.space)
	{
		pf->buff[pf->ib++] = pf->flag.plus ? '+' : ' ';
		//pf->num_of_c += pf->flag.plus ? write(1, "+", 1) : write(1, " ", 1);
	}
	else if (pf->is_neg)
	{
		pf->buff[pf->ib++] = '-';
		//pf->num_of_c += write(1, "-", 1);
	}
}

void    print_width(t_pf *pf)
{
	int i;

	i = -1;
	(pf->flag.plus || pf->flag.space || pf->is_neg) ? pf->flag.fwidth-- : 0;
	while (pf->flag.fwidth - pf->n_len > ++i)
	{
		pf->buff[pf->ib++] = pf->flag.zero ? '0' : ' ';
		//pf->num_of_c += pf->flag.zero ? write(1, "0", 1) : write(1, " ", 1);
	}
}

void	put_num_2_buff(t_pf *pf)
{
	int i;

	i = -1;
	while (pf->out[++i])
		pf->buff[pf->ib++] = pf->out[i];
}

void	print_inum(t_pf *pf)
{
	if (pf->flag.zero)
	{
		print_sign(pf);
		print_width(pf);
		put_num_2_buff(pf);
		//pf->num_of_c += write(1, pf->out, pf->n_len);
	}
	else if(pf->flag.minus)
	{
		print_sign(pf);
		put_num_2_buff(pf);
		//pf->num_of_c += write(1, pf->out, pf->n_len);
		print_width(pf);
	}
	else
	{
		print_width(pf);
		print_sign(pf);
		put_num_2_buff(pf);
		//pf ->num_of_c += write(1, pf->out, pf->n_len);
	}
}
