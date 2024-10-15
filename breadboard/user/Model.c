#include "Model.h"
#include "IMU.h"
#include "MPU6050.h"
#include "nnom.h"
#include "weights.h"

nnom_model_t* model = NULL;

extern float IMU_Data_mGyro[IMU_DateLength_MAX][3];
extern float IMU_Data_mAcc[IMU_DateLength_MAX][3];
#define SCALE (pow(2, INPUT_1_OUTPUT_DEC))

#ifdef NNOM_USING_STATIC_MEMORY
	uint8_t static_buf[1024 * 8];
#endif

void Model_Load(void) {
	#ifdef NNOM_USING_STATIC_MEMORY
		nnom_set_static_buf(static_buf, sizeof(static_buf)); 
	#endif
	model = nnom_model_create();
}

void Model_InputData(void) {
	const double scale = SCALE;
	for(uint16_t i = 0; i < IMU_DateLength_MAX; i++){
		nnom_input_data[i*3] = (int8_t)round(IMU_Data_mGyro[i][0] * scale);
		nnom_input_data[i*3+1] = (int8_t)round(IMU_Data_mGyro[i][1] * scale);
		nnom_input_data[i*3+2] = (int8_t)round(IMU_Data_mGyro[i][2] * scale);
	}
}

void Model_Run(void) {
	model_run(model);
}

// 模型输出的最大值必须大于此值，否则无法判别
#define OUPUT_THRESHOLD 103 
int8_t Model_GetOutput(void) {
	int8_t max_output = -128;
	int8_t result = 0;
	
	for(uint8_t i = 0; i < 13; i++){
		printf("Output[%d] = %.2f %% \r\n", i, (nnom_output_data[i] / 127.0)*100);
		
		if(nnom_output_data[i] >= max_output){
			max_output = nnom_output_data[i] ;
			result = i;
		}
	}
	
	if(max_output >= OUPUT_THRESHOLD){
		return result;
	} else{
		return -1;
	}
}
