/* Generated by libfsm */

#include LF_HEADER

#include <stddef.h>

#include <fsm/fsm.h>

struct fsm *
class_space_fsm(const struct fsm_options *opt)
{
	struct fsm *fsm;
	size_t i;

	struct fsm_state *s[2] = { 0 };

	fsm = fsm_new(opt);
	if (fsm == NULL) {
		return NULL;
	}

	for (i = 0; i < 2; i++) {
		s[i] = fsm_addstate(fsm);
		if (s[i] == NULL) {
			goto error;
		}
	}

	if (!fsm_addedge_literal(fsm, s[0], s[1], '\t')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\n')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\v')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\f')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], '\r')) { goto error; }
	if (!fsm_addedge_literal(fsm, s[0], s[1], ' ')) { goto error; }

	fsm_setstart(fsm, s[0]);
	fsm_setend(fsm, s[1], 1);

	return fsm;

error:

	fsm_free(fsm);

	return NULL;
}

