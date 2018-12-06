/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_do_op.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: efischer <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/16 11:23:21 by efischer          #+#    #+#             */
/*   Updated: 2018/09/16 21:03:30 by efischer         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_DO_OP_H
# define FT_DO_OP_H

int		ft_non_priority_calcul(int *nbr, int *i, char *str, int *j);
int		ft_do_op(int nb1, char op, int nb2);
int		ft_calcul(int *nbr, char *op);

#endif
