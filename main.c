#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include "/usr/local/include/zmq.h"

#include "obc_msg.h"

void *context, *requester_tlm;
int zmq_linger_time_ms = 2000;

OBC_TlmData tlmData;
int main()
{
    // ZMQ Protocol
    context = zmq_ctx_new();
    requester_tlm = zmq_socket(context, ZMQ_PUB);
    zmq_setsockopt(requester_tlm, ZMQ_LINGER, &zmq_linger_time_ms, sizeof(zmq_linger_time_ms));
    if (zmq_bind(requester_tlm, "ipc:///tmp/obc_ss") == 0)
        printf("zmq created for obc tlm sensors\n");
    else
    {
        printf("zmq bind failed %s for obc tlm sensors\n", zmq_strerror(zmq_errno()));
        return -1;
    }

    // Run the stream
    do
    {
        sleep(1);

        // sample data
        tlmData.active_sensor_count = 10;
        tlmData.mission_mode = 1;
        tlmData.voltage_5v = 51; // abs(V * 10)
        tlmData.voltage_3v = 33;

        tlmData.current_5v = 256; // abs(Amp * 1000)
        tlmData.current_3v = 20;
        tlmData.pi_temperature = 2432;
        tlmData.board_temperature = 2122; // celcius * 100

        tlmData.al_lux = 200000;
        tlmData.red_lux = 120000;
        tlmData.green_lux = 230;
        tlmData.blue_lux = 3400;
        tlmData.ir_lux = 5600;

        tlmData.mag_uT_x = 45.1;
        tlmData.mag_uT_y = 45.32;
        tlmData.mag_uT_z = 45.6;

        tlmData.gyro_dps_x = 0.23;
        tlmData.gyro_dps_y = 1.232;
        tlmData.gyro_dps_z = 0;

        tlmData.accel_ms2_x = 0;
        tlmData.accel_ms2_y = 0;
        tlmData.accel_ms2_z = 0;

        tlmData.uv_a = 1;
        tlmData.uv_b = 0;
        tlmData.uv_c = 2;
        tlmData.uv_temp = 55.66;

        tlmData.ss_lux = 14000;
        tlmData.ss_temperature = 65333;

        tlmData.sc_voltage = 41; // abs(V * 10)
        tlmData.padding = 0;
        tlmData.sc_ckt_resistance = 200; // (Ohms *100)
        tlmData.sc_current = 220;        // abs(Amp * 1000)
        tlmData.sc_power = 1000;         // abs(W * 1000)

        tlmData.timeepoch = time(NULL);

        zmq_send(requester_tlm, &tlmData, sizeof(OBC_TlmData), 0);
    } while (1);
    return 0;
}