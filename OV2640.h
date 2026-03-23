#ifndef OV2640_H
#define OV2640_H

// NOTE: based on SoCXin CH32V307 DVP example

#include <stdbool.h>
#include <stdint.h>

#define OV2640_SCCB_ID 0X60

#define OV2640_MID 0X7FA2
#define OV2640_PID 0X2642

// JPEG PIXEL 1024 * 768
#define OV2640_DEF_WIDTH 1024
#define OV2640_DEF_HEIGHT 768

// Max resolution UXGA 1600×1200
#define OV2640_MAX_WIDTH 1600
#define OV2640_MAX_HEIGHT 1200

/* NOTE: examples on using size, crop and scaling:
    // For RAW10 full resolution:
    OV2640_SetResolution(platform, OV2640_RES_UXGA);  // 1632x1220 sensor readout
    OV2640_SetRAW10Mode(platform);  // Bypasses DSP, outputs full frame

    // For RAW10 cropped:
    OV2640_SetResolution(platform, OV2640_RES_UXGA);
    OV2640_SetCrop(platform, 100, 100, 640, 480);  // Crop to 640x480 @ (100,100)
    OV2640_SetRAW10Mode(platform);

    // For JPEG cropped then scaled:
    OV2640_SetResolution(platform, OV2640_RES_UXGA);
    OV2640_SetCrop(platform, 100, 100, 1280, 960);  // First crop sensor to 1280x960
    OV2640_SetJpegMode(platform);
    OV2640_SetOutSize(platform, 640, 480);  // Then DSP scales cropped region to 640x480
*/

// TODO: check, PCLK = 400 kHz??
// Skipping SetSpeed should left default initialization
/*
    Bank 1 (0x11 = CLKRC): Value 0x01 (Xclk_Div = 1)
    Bit 7 = 0: PLL frequency doubler is OFF
    Bits 5:0 = 1: Clock divider = (1+1) = 2
    System clock (sysclk) = XVCLK / 2
    Bank 0 (0xD3 = R_DVP_SP): Value 30 (0x1E) (Pclk_Div = 30)
    Bit 7 = 0: Manual mode (not auto)
    Formula for RGB565/YUV (your final mode per 0xDA = 0x09):
    PCLK = sysclk / Pclk_Div
    2. Resulting PCLK:
    plain
    Copy
    PCLK = XVCLK / 2 / 30 = XVCLK / 60
    With a typical 24 MHz XVCLK:
    sysclk = 12 MHz
    PCLK = 400 kHz (0.4 MHz)

    For video, use values like:
    Xclk_Div = 0 (no input division, or 0x80 to enable PLL doubler)
    Pclk_Div = 2 or 4 for manageable PCLK speeds (12-24 MHz with 24 MHz input).
 */
#define OV2640_DEF_PCLK_DIV 30
#define OV2640_DEF_XCLK_DIV 1

// Resolution modes for COM7 register
typedef enum OV2640_Resolution {
    OV2640_RES_UXGA = 0x00, // 1600x1200 (full array: 1632x1220)
    OV2640_RES_CIF = 0x01,  // 400x296 (sub-sampled)
    OV2640_RES_SVGA = 0x04  // 800x600 (sub-sampled)
} OV2640_Resolution_t;

struct OV2640_Platform {
    int (*sccbReadReg)(uint8_t sccbId, uint8_t regAddr, uint8_t *data);
    int (*sccbWriteReg)(uint8_t sccbId, uint8_t regAddr, uint8_t data);

    void (*setResetPin)(bool value);
    void (*setPwdnPin)(bool value);

    void (*delayMs)(int ms);
    void (*debugPrint)(const char *fmt, ...);
};

bool OV2640_HardwareReset(const struct OV2640_Platform *platform);
bool OV2640_SoftwareReset(const struct OV2640_Platform *platform);
bool OV2640_SetDefInit(const struct OV2640_Platform *platform);

bool OV2640_DefInit(const struct OV2640_Platform *platform);

bool OV2640_SetJpegMode(const struct OV2640_Platform *platform);

/* NOTE: SetOutSize() function writes to DSP registers
    (0x5A, 0x5B, 0x5C — the Zoom Output Window registers).
    However, in RAW10 mode 0x05, 0x01 which bypasses the DSP entirely.
    When the DSP is bypassed, the zoom/scaling registers have no effect
    because the data path goes directly from Sensor → Output, skipping the DSP block.
*/
bool OV2640_SetOutSize(const struct OV2640_Platform *platform, uint16_t width, uint16_t height);

bool OV2640_SetSpeed(const struct OV2640_Platform *platform, uint8_t Pclk_Div, uint8_t Xclk_Div);

bool OV2640_SetResolution(const struct OV2640_Platform *platform, OV2640_Resolution_t res);

/*
 * Set hardware cropping window (works for both RAW and processed modes)
 *
 * Constraints (from datasheet):
 * - Horizontal: 2-pixel granularity (registers store value/2)
 * - Vertical: 4-line granularity for UXGA (registers store value/2, but each unit = 2 lines)
 * - Actual range depends on resolution mode (UXGA: up to 1632x1220, SVGA: up to 818x610)
 *
 * For RAW mode (DSP bypassed): This sets the sensor readout window directly
 * For RGB/YUV/JPEG mode: This sets the input window to DSP (DSP may scale it further via
 * SetOutSize)
 */
bool OV2640_SetCrop(const struct OV2640_Platform *platform, uint16_t x, uint16_t y, uint16_t width,
                    uint16_t height);

#endif // OV2640_H
