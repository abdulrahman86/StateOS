#include "test.h"

static void proc()
{
	        tsk_stop();
}

static void test()
{
	unsigned event;

	tsk_t *tsk6 = wrk_detached(6, proc, 512);    ASSERT(tsk6);
	event = tsk_join(tsk6);                      ASSERT_failure(event);

	tsk_t *tsk7 = tsk_detached(7, proc);         ASSERT(tsk7);
	event = tsk_join(tsk7);                      ASSERT_failure(event);

	tsk_t *tsk8 = wrk_detached(8, proc, 512);    ASSERT(tsk8);
	event = tsk_join(tsk8);                      ASSERT_failure(event);

	tsk_t *tsk9 = tsk_detached(9, proc);         ASSERT(tsk9);
	event = tsk_join(tsk9);                      ASSERT_failure(event);
}

extern "C"
void test_task_create_5()
{
	TEST_Notify();
	TEST_Call();
}
