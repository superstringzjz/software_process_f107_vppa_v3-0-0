#include "class_board.h"

CProcessBorad::CProcessBorad(void){
}

CProcessBorad::~CProcessBorad(void){
	int i = 0;
	for(i = 0;i<9;i++){
		io_out[i] = 0;
		io_in[i] = 0;
	}
	dac1_raw = 0;
	dac2_raw = 0;

}

bool CProcessBorad::board_init(void){
	bool status;
	/**************************************************************/
	status = bsp_electronic_io_init(); //bsp回调函数
	status = bsp_mechanical_io_init(); //bsp回调函数
	status = bsp_dac_init();           //bsp回调函数
	/**************************************************************/
	return status;
}

void CProcessBorad::board_io_scan(){
	io_in[1] = bsp_mechanical_input_1_read();
	io_in[2] = bsp_mechanical_input_2_read();
	io_in[3] = bsp_electronic_input_1_read();
	io_in[4] = bsp_electronic_input_2_read();
	io_in[5] = bsp_electronic_input_3_read();
	io_in[6] = bsp_electronic_input_4_read();
}

void CProcessBorad::board_io_set(){
	bsp_mechanical_output_1_set(io_out[1]);
	bsp_mechanical_output_2_set(io_out[2]);
	bsp_mechanical_output_3_set(io_out[3]);
	bsp_mechanical_output_4_set(io_out[4]);
	bsp_electronic_output_1_set(io_out[5]);
	bsp_electronic_output_2_set(io_out[6]);
	bsp_electronic_output_3_set(io_out[7]);
	bsp_electronic_output_4_set(io_out[8]);
}
void CProcessBorad::board_dac_set(){
	bsp_dac_channel1_output(dac1_raw);
	bsp_dac_channel2_output(dac2_raw);
}
