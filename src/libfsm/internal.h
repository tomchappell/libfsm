/* $Id$ */

#ifndef INTERNAL_H
#define INTERNAL_H

#include <limits.h>

#include <fsm/fsm.h>


/* TODO: +2 for SOL, EOL */
/* TODO: +lots for FSM_EDGE_* */
enum fsm_edge_type {
	FSM_EDGE_EPSILON = UCHAR_MAX + 1
};

#define FSM_EDGE_MAX FSM_EDGE_EPSILON

struct fsm_edge {
	struct state_set *sl;
};

struct fsm_state {
	unsigned int end:1;

	struct fsm_edge edges[FSM_EDGE_MAX + 1];

	void *opaque;

	struct fsm_state *next;
};


struct fsm {
	struct fsm_state *sl;
	struct fsm_state *start;
};


#endif

