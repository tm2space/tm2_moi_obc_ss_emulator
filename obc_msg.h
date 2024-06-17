/************************************************************************
 *
 * Copyright (c) 2024 TakeMe2Space as represented by the
 * All Rights Reserved.
 *
 ************************************************************************/


#include <stdint.h>

#ifndef OBC_SS_TLM_MSG_H
#define OBC_SS_TLM_MSG_H

typedef struct OBC_TlmData_t
{
    int8_t active_sensor_count;
    int8_t mission_mode;
    int8_t voltage_5v; // abs(V * 10)
    int8_t voltage_3v;

    uint16_t current_5v; // abs(Amp * 1000)
    uint16_t current_3v;
    int16_t  pi_temperature;
    int16_t  board_temperature; // celcius * 100

    float   al_lux;
    int32_t red_lux;
    int32_t green_lux;
    int32_t blue_lux;
    int32_t ir_lux;

    float mag_uT_x;
    float mag_uT_y;
    float mag_uT_z;

    float gyro_dps_x;
    float gyro_dps_y;
    float gyro_dps_z;

    float accel_ms2_x;
    float accel_ms2_y;
    float accel_ms2_z;

    float uv_a;
    float uv_b;
    float uv_c;
    float uv_temp;

    uint32_t ss_lux;
    int32_t  ss_temperature;

    int8_t   sc_voltage; // abs(V * 10)
    int8_t   padding;
    uint16_t sc_ckt_resistance; // (Ohms *100)
    uint16_t sc_current;        // abs(Amp * 1000)
    uint16_t sc_power;          // abs(W * 1000)

    uint32_t timeepoch;
} OBC_TlmData;

#endif /* OBC_SS_TLM_MSG_H */