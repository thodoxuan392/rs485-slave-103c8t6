/*
 * rfid.h
 *
 *  Created on: Dec 17, 2023
 *      Author: xuanthodo
 */

#ifndef INC_DEVICE_RFID_H_
#define INC_DEVICE_RFID_H_

#include <stdbool.h>
#include <stdint.h>

#define RFID_ID_MAX_LENGTH	15

typedef enum {
	RFID_SUCCESS = 0x00,
	RFID_ERROR_NOT_AVAILABLE = 0x70,
	RFID_ERROR_INVALID_FORMAT = 0x71,
	RFID_ERROR_ID_NOT_MATCHED = 0x72,
	RFID_ERROR_AUTHEN_FAILED = 0x73,
	RFID_ERROR_CANNOT_WRITE = 0x74,
	RFID_ERROR_CANNOT_READ = 0x75,
}RFID_Error_t;

typedef enum {
	RFID_ID_1 = 0,
	RFID_ID_2,
	RFID_ID_3,
	RFID_ID_MAX
}RFID_Id_t;


typedef struct {
	uint8_t id[RFID_ID_MAX_LENGTH];
	uint8_t id_len;
	uint8_t code;
	uint8_t type;
	uint8_t isUsed;
}RFID_t;



void RFID_init(void);
void RFID_run(void);
bool RFID_isDetected();
void RFID_clearDetected();
bool RFID_isPlaced();
void RFID_get(RFID_t * rfid);
RFID_Error_t RFID_set(RFID_t * rfid);
bool RFID_isError();
RFID_Error_t RFID_getError();
void RFID_test(void);

#endif /* INC_DEVICE_RFID_H_ */
