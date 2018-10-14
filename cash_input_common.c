
#include <sys/poll.h>
#include <sys/epoll.h>
#include <errno.h>
#include <stdbool.h>
#include <pthread.h>

#include <log/log.h>

#include "cash_input_common.h"


/* Start/stop threads */
int cash_input_threadman(bool start, int threadno, void *(thread_func) (void *))
{
	int ret = -1;

	if (start == false) {
		ucithread_run[threadno] = false;
		return 0;
	};

	ucithread_run[threadno] = true;

	if (threadno < THREAD_MAX) {
		ret = pthread_create(&uci_pthreads[threadno], NULL,
				thread_func, NULL);
		if (ret != 0) {
			ALOGE("Cannot create thread.");
			return -ENXIO;
		}
	}

	return ret;
}

int cash_set_parameter(char* path, char* value, int value_len) {
	int fd, rc;

	fd = open(path, O_WRONLY);
	if (fd < 0) {
		ALOGD("Cannot open %s", path);
		return -1;
	}

	rc = write(fd, value, value_len);
	if (rc < value_len) {
		ALOGW("ERROR! Cannot write value %s to %s", value, path);
		return -1;
	}
	close(fd);
	return 0;
}
