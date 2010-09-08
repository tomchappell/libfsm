/* $Id$ */

#include <assert.h>
#include <stdio.h>
#include <string.h>

#include <fsm/fsm.h>
#include <fsm/exec.h>
#include <fsm/graph.h>

#include "internal.h"

int fsm_exec(const struct fsm *fsm, int (*fsm_getc)(void *opaque), void *opaque) {
	struct fsm_state *state;
	int c;

	assert(fsm != NULL);
	assert(fsm_getc != NULL);

	/* TODO: check prerequisites; that it has literal edges (or any), DFA, etc */

	/* TODO: pass struct of callbacks to call during each event; transitions etc */

	assert(fsm_isdfa(fsm));
	assert(fsm->start != NULL);
	state = fsm->start;

	while ((c = fsm_getc(opaque)) != EOF) {
		state = state->edges[(unsigned char) c];
		if (state == NULL) {
			return 0;
		}
	}

	if (!state->end) {
		return 0;
	}

	return state->id;
}

int fsm_sgetc(void *opaque) {
	const char **s = opaque;
	char c;

	assert(s != NULL);

	c = **s;

	if (c == '\0') {
		return EOF;
	}

	(*s)++;

	return c;
}
