#include "rt_tree.h"
#include <stdio.h>

static int tree_found(void *a, void *b)
{
	if (*(int *)a == *(int *)b)
		return (1);
	return (0);
}

static t_rtnode *findn(t_rtnode *node, int (*f)(void *, void *),
                t_rtnode **nxt, void *env)
{
        t_rtnode        *ret;

        if (!node)
                return (NULL);
        if ((!nxt || (*nxt != node)) && f(&(node->flags), env))
                return (node);
        if (nxt)
                *nxt = (*nxt)->parent;
        while (nxt && ((*nxt)->parent != *nxt) && (!(*nxt)->next))
                *nxt = (*nxt)->parent;
        ret = NULL;
        if (node->childs)
                ret = findn(node->childs, f, NULL, env);
        if (!ret)
                ret = findn(node->next, f, NULL, env);
        return (ret);
}

static t_rtnode                *tree_findd(t_rtnode *node, int (*f)(void *, void *), void *env)
{
        t_rtnode        *ret;
        t_rtnode        *it;

        ret = NULL;
        if (!node)
                return (NULL);
        it = node;
        while (!ret && node)
        {
                ret = findn(node, f, &it, env);
                if (!it)
                         break ;
                node = it->next;
        }
        return (ret);
}

t_rtnode	*tree_found_node_with_id(t_rtnode *node, int id)
{
	return (tree_findd(node, &tree_found, &id));
}
