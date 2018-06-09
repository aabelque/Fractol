/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_thread.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aabelque <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/06/06 10:51:08 by aabelque          #+#    #+#             */
/*   Updated: 2018/06/09 11:27:09 by aabelque         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

void			send_thread(t_env *e)
{
	int			i;
	t_thrdata	data[NB_THR];

	i = 0;
	while (i < NB_THR)
	{
		data[i] = (t_thrdata){i, e->smth, &e->fra, &e->img, &e->ptf};
		if (pthread_create(&e->thread[i], NULL, e->func[e->fractol], &data[i]))
			ft_error("thread not create");
		i++;
	}
	i = 0;
	while (i < NB_THR)
	{
		if (pthread_join(e->thread[i], NULL) != 0)
			ft_error("thread not join");
		i++;
	}
}
