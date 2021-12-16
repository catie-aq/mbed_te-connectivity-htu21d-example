/*
 * Copyright (c) 2021, Koncepto.io
 * SPDX-License-Identifier: Apache-2.0
 */
#include "htu21d/htu21d.h"
#include "mbed.h"

namespace {
#define WAIT 1000ms
}

using namespace sixtron;

static DigitalOut led1(LED1);

int main()
{
    HTU21D::ErrorType err;
    htud21d_user_reg_t reg;
    HTU21D sensor(I2C1_SDA, I2C1_SCL);
    double result;

    sensor.soft_reset();

    printf("\n\n----------------------\n");
    printf("--- HTU21D(F) Demo ---\n");

    err = sensor.read_user_register(&reg);

    if (err == HTU21D::ErrorType::Ok) {
        printf("User register status:\n");
        printf("Battery low: %s\nHeater: %s\nOTP reload: %s\n\n",
                reg.end_of_battery ? "TRUE" : "FALSE",
                reg.enable_heater ? "ON" : "OFF",
                reg.disable_otp_reload ? "DISABLED" : "ENABLED");

        reg.resolution = MeasurementResolution::RH_12_Temp_14;
        sensor.write_user_register(&reg);
    }

    while (true) {
        led1 = !led1;

        printf("-----\n");

        err = sensor.read_temperature(&result);
        if (err == HTU21D::ErrorType::Ok) {
            printf("Temperature: %f°C\n", result);
        }

        err = sensor.read_humidity(&result);
        if (err == HTU21D::ErrorType::Ok) {
            printf("Relative humidity: %f%%\n", result);
        }

        ThisThread::sleep_for(WAIT);
    }
}
