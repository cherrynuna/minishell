/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjhang <jjhang@student.42seoul.kr>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/11 18:14:57 by inryu             #+#    #+#             */
/*   Updated: 2024/06/15 21:40:16 by jjhang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_execute.h"

void	num_qm(t_pars_tree *tree, \
				t_expand_word *exp, t_execute *ms_exe, int start)
{
	char	*word;

	word = NULL;
	word = tree->word;
	exp->head = ft_substr(word, 0, start);
	exp->key = ft_substr(word, start + 1, 1);
	exp->toe = ft_substr(word, start + 2, ft_strlen(word) - start - 2);
	if ((word)[start + 1] == '0')
		exp->val = ft_strdup("diveshell");
	else
		key_obj(exp, ms_exe);
}

char	*merge_strings(t_expand_word *exp)
{
	char	*res;
	char	*temp;

	temp = ft_strjoin(exp->val, exp->toe);
	res = ft_strjoin(exp->head, temp);
	if (res == NULL)
		error_handler(NULL, NULL, 12);
	free(temp);
	return (res);
}

void	key_obj(t_expand_word *exp, t_execute *ms_exe)
{
	t_env_lst		*key_obj;

	if (ft_strcmp(exp->key, "") == 0)
	{
		exp->val = ft_strdup("$");
		return ;
	}
	key_obj = ft_getenv_from_node(ms_exe->env_lst, exp->key);
	if (key_obj == NULL)
		key_obj = ft_getenv_from_node(ms_exe->builtin_env_lst, exp->key);
	if (key_obj == NULL || (key_obj != NULL && key_obj->content == NULL))
		exp->val = ft_strdup("");
	else
		exp->val = ft_strdup(key_obj->content);
}

static void	free_to_exp(t_expand_word *exp, t_pars_tree *tree)
{
	int	idx;
	int	len;

	len = 0;
	idx = 0;
	while (tree != NULL && tree->word[idx] != '\0')
	{
		if (tree->word[idx] != ' ' && tree->word[idx] != '\t')
			len++;
		idx++;
	}
	if (len == 0)
		tree->type = SKIP;
	free(exp->head);
	free(exp->key);
	free(exp->toe);
	free(exp->val);
}

void	replace_d(t_pars_tree *tree, t_execute *ms_exe, int *start, int len)
{
	t_expand_word	exp;
	char			*word;

	word = tree->word;
	while (ft_isalnum((word)[*start + len]) || (word)[*start + len] == '_')
		len++;
	if ((word)[*start + 1] == '?')
		len = 2;
	if (ft_isdigit((word)[*start + 1]))
		num_qm(tree, &exp, ms_exe, *start);
	else
	{
		exp.head = ft_substr(word, 0, *start);
		exp.key = ft_substr(word, *start + 1, len - 1);
		exp.toe = ft_substr
			(word, *start + len, ft_strlen(word) - *start - len);
		key_obj(&exp, ms_exe);
	}
	if (ft_strlen(exp.val) == 0)
		(*start) -= 1;
	free(word);
	tree->word = merge_strings(&exp);
	free_to_exp(&exp, tree);
}
