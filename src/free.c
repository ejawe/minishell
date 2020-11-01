/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 10:51:13 by user42            #+#    #+#             */
/*   Updated: 2020/10/22 17:23:58 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minishell.h"

void	free_array(char **array)
{
	int i;

	i = 0;
	while (array[i])
	{
		free(array[i]);
		array[i] = NULL;
		i++;
	}
	free(array);
	array = NULL;
}

void	ft_free_n_null(char **str)
{
	char *temp;

	temp = *str;
	free(temp);
	*str = NULL;
}

void	free_all(void)
{
	if (g_env)
		ft_lstclear(&g_env, (void *)ft_freestr);
	if (g_export)
		ft_lstclear(&g_export, (void *)ft_freestr);
	if (g_env_tab)
		free_array(g_env_tab);
	if (g_line)
		ft_free_n_null(&g_line);
	if (g_str)
		ft_free_n_null(&g_str);
}
