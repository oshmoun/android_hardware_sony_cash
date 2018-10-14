/*
 * Micro Communicator for Projection uC
 * a High-Speed Serial communications server
 *
 * Input devices module
 *
 * Copyright (C) 2018 AngeloGioacchino Del Regno <kholk11@gmail.com>
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#define ITERATE_MAX_DEVS	9

enum {
	THREAD_TOF,
	THREAD_RGBC,
	THREAD_MAX
};


enum {
	FD_TOF,
	FD_RGBC,
	FD_MAX
};

bool ucithread_run[THREAD_MAX];
pthread_t uci_pthreads[THREAD_MAX];
struct pollfd uci_pfds[FD_MAX];
struct epoll_event uci_pollevt[FD_MAX];
int uci_pollfd[FD_MAX];
int uci_pfdelay_ms[FD_MAX];

static const char sysfs_input_str[] = "/sys/class/input/input";
static const char devfs_input_str[] = "/dev/input/event";

int cash_input_threadman(bool start, int threadno, void *(thread_func)(void *));
int cash_set_parameter(char* path, char* value, int value_len);

