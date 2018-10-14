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

#define RGBC_DEFAULT_MIN_CLEAR			0
#define RGBC_DEFAULT_MAX_CLEAR			1000
#define RGBC_STABILIZATION_DEF_RUNS		4
#define RGBC_STABILIZATION_WAIT_MS		10
#define RGBC_STABILIZATION_HYST_CLEAR		30
#define RGBC_STABILIZATION_MATCH_NO		3

struct cash_tcs3490 {
	int red;
	int green;
	int blue;
	int clear;
};

int cash_rgbc_read_inst(struct cash_tcs3490 *tcsvl_final);
int cash_input_rgbc_start(bool start);
bool cash_input_is_rgbc_alive(void);
int cash_input_rgbc_init(void);

