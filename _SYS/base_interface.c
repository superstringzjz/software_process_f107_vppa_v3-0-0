#include "base_interface.h"
#include "class_board.h"

CProcessBorad* m_board = NULL;

bool base_interface_init(void){
	bool status;
	m_board = new CProcessBorad();
	status = m_board->board_init();
	return status;
}
void base_io_scan(void){
	m_board->board_io_scan();
}
void base_io_set(void){
	m_board->board_io_set();
}
void base_dac_set(void){
	m_board->board_dac_set();
}

void base_dac_1_raw_set(u16 value){
	m_board->dac1_raw = value;
}
void base_dac_2_raw_set(u16 value){
	m_board->dac2_raw = value;
}

u16  base_dac_1_raw_read(void){
	return m_board->dac1_raw;
}
u16  base_dac_2_raw_read(void){
	return m_board->dac2_raw;
}
void base_io_signale_set(u8 bit,bool status){
	m_board->io_out[bit] = status;
}
bool base_io_signale_read(u8 bit){
	return m_board->io_in[bit];
}
