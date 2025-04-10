#ifndef OV2640_H
#define OV2640_H

// NOTE: based on SoCXin CH32V307 DVP example

#include <stdbool.h>
#include <stdint.h>

#define OV2640_SCCB_ID 0X60

#define OV2640_MID 0X7FA2
#define OV2640_PID 0X2642

// JPEG PIXEL 1024 * 768
#define OV2640_JPEG_HEIGHT	768
#define OV2640_JPEG_WIDTH	1024

struct OV2640_Platform {
    int (*sccbReadReg)(uint8_t sccbId, uint8_t regAddr, uint8_t *data);
    int (*sccbWriteReg)(uint8_t sccbId, uint8_t regAddr, uint8_t data);

    void (*setResetPin)(bool value);
    void (*setPwdnPin)(bool value);

    void (*delayMs)(int ms);
    void (*debugPrint)(const char *fmt, ...);
};

bool OV2640_FullReset(const struct OV2640_Platform *platform);
bool OV2640_SetDefInit(const struct OV2640_Platform *platform);

bool OV2640_DefInit(const struct OV2640_Platform *platform);

bool OV2640_SetJpegMode(const struct OV2640_Platform *platform);
bool OV2640_SetOutSize(const struct OV2640_Platform *platform, uint16_t width, uint16_t height);
bool OV2640_SetSpeed(const struct OV2640_Platform *platform, uint8_t Pclk_Div, uint8_t Xclk_Div);

#endif // OV2640_H
