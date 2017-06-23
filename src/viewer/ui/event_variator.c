#include "rt_ui.h"
#include "rt_ui_display.h"
#include "rt_tree.h"

void	event_click_variator(t_rt *rt, t_rtnode *node)
{
	rt->viewer.layer_event_focus = node;
	/*v->load += 0.1;
	if (v->load > 1.0)
		v->load = 1.0;
	if (v->load < 0.0)
		v->load = 0.0;*/
}

void	event_onclick_variator(t_rt *rt)
{
	t_layer_variator *v;
	int value;

	v = ((t_layer_variator *)(rt->viewer.layer_event_focus->content));
	//v->pos.x = 0.1;
	//v->pos.y = 0.1;
	//v->load = 0.1;
	//v->load = rt->viewer.mouse.x / rt->viewer.layer->x;
	value = rt->viewer.mouse.x - v->gen[0].pos.x;
	v->load = ((float)value) / ((float)v->gen[0].dim.x);
	if (v->load < 0.0)
		v->load = 0.0;
	if (v->load > 1.0)
		v->load = 1.0;
	value, v->gen[0].dim.x);
}

void	event_noclick_variator(t_rt *rt)
{
	rt->viewer.layer_event_focus = 0;
}
