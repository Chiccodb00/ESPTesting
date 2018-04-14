/*
 *  This program is used to dump data out of the EPROM.
 *  It can only read from addresses 0 to 63, but it can be expanded to read more
 *
 *  Created on: 13 apr 2018
 *      Author: Chiccodb00
 */

#include <stdio.h>
#include <freertos/FreeRTOS.h>
#include <freertos/task.h>
#include "esp_wifi.h"
#include "esp_system.h"

void app_main(void) {
    //Initialize addreses output pins
    gpio_set_direction(GPIO_NUM_26, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_21, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_22, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_23, GPIO_MODE_OUTPUT);
    gpio_set_direction(GPIO_NUM_32, GPIO_MODE_OUTPUT);
    //Initialize data input pins
    gpio_set_direction(GPIO_NUM_12, GPIO_MODE_INPUT);
    gpio_set_direction(GPIO_NUM_25, GPIO_MODE_INPUT);
    gpio_set_direction(GPIO_NUM_14, GPIO_MODE_INPUT);
    gpio_set_direction(GPIO_NUM_15, GPIO_MODE_INPUT);
    gpio_set_direction(GPIO_NUM_16, GPIO_MODE_INPUT);
    gpio_set_direction(GPIO_NUM_17, GPIO_MODE_INPUT);
    gpio_set_direction(GPIO_NUM_18, GPIO_MODE_INPUT);
    gpio_set_direction(GPIO_NUM_19, GPIO_MODE_INPUT);

    int readByte[8];
    int u1 = 0;
    int u2 = 0;
    int u3 = 0;
    int u4 = 0;
    int u5 = 0;
    while(1){
    	//Estimate address (this is a really bad way to count in binary)
    	u1++;
    	if(u1==2){
    		u1=0;
    		u2++;
    	}
    	if(u2==2){
    		u2=0;
    		u3++;
    	}
    	if(u3==2){
			u3=0;
			u4++;
		}
    	if(u4==2){
    	    u4=0;
    	    u5++;
    	}
    	if(u5==2){
			u5=0;
			u1=0;
		}
    	int num = u1 + u2 * 2 + u3 * 4 + u4 * 8 + u5 * 16; //Convert the address from binary to a decimal number
    	//Write address to outputs
    	gpio_set_level(GPIO_NUM_26, u1);
    	gpio_set_level(GPIO_NUM_21, u2);
    	gpio_set_level(GPIO_NUM_22, u3);
    	gpio_set_level(GPIO_NUM_23, u4);
    	gpio_set_level(GPIO_NUM_32, u5);
    	//Read EEPROM byte
    	readByte[0] = gpio_get_level(GPIO_NUM_12);
    	readByte[1] = gpio_get_level(GPIO_NUM_13);
    	readByte[2] = gpio_get_level(GPIO_NUM_14);
    	readByte[3] = gpio_get_level(GPIO_NUM_15);
    	readByte[4] = gpio_get_level(GPIO_NUM_16);
    	readByte[5] = gpio_get_level(GPIO_NUM_17);
    	readByte[6] = gpio_get_level(GPIO_NUM_18);
    	readByte[7] = gpio_get_level(GPIO_NUM_19);
        //Prints out to the terminal
    	printf("%d;", num);
    	for(int i = 8; i>0 ;i--){
    		printf("%d",readByte[i]);
    	}
    	printf("\n");
        //Wait (adjust this value based on the read rime of the EPROM)
        vTaskDelay(200 / portTICK_PERIOD_MS);

    }


}
