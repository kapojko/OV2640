#include "OV2640.h"

/* Start Camera list of initialization configuration registers */
// const uint8_t OV2640_InitRegTbl[][2] =
const uint8_t OV2640_InitRegTbl[] =
{
    0xff, 0x00, 0x2c, 0xff,	0x2e, 0xdf,	0xff, 0x01,	0x3c, 0x32,

    0x11, 0x00,	0x09, 0x02,	0x04, 0xD8,	0x13, 0xe5,	0x14, 0x48,	0x2c, 0x0c,	0x33, 0x78,	0x3a, 0x33,	0x3b, 0xfB,

    0x3e, 0x00,	0x43, 0x11,	0x16, 0x10,

    0x39, 0x92,

    0x35, 0xda,	0x22, 0x1a,	0x37, 0xc3,	0x23, 0x00,	0x34, 0xc0,	0x36, 0x1a,	0x06, 0x88,	0x07, 0xc0,	0x0d, 0x87,	0x0e, 0x41,	0x4c, 0x00,

    0x48, 0x00,	0x5B, 0x00,	0x42, 0x03,

    0x4a, 0x81,	0x21, 0x99,

    0x24, 0x40,	0x25, 0x38,	0x26, 0x82,	0x5c, 0x00,	0x63, 0x00,	0x46, 0x00,	0x0c, 0x3c,

    0x61, 0x70,	0x62, 0x80,	0x7c, 0x05,

    0x20, 0x80,	0x28, 0x30,	0x6c, 0x00,	0x6d, 0x80,	0x6e, 0x00,	0x70, 0x02,	0x71, 0x94,	0x73, 0xc1,	0x3d, 0x34,	0x5a, 0x57,

    0x12, 0x00,

    0x17, 0x11, 0x18, 0x75,	0x19, 0x01,	0x1a, 0x97,	0x32, 0x36,	0x03, 0x0f,	0x37, 0x40,

    0x4f, 0xca,	0x50, 0xa8,	0x5a, 0x23,	0x6d, 0x00,	0x6d, 0x38,

    0xff, 0x00,	0xe5, 0x7f,	0xf9, 0xc0,	0x41, 0x24,	0xe0, 0x14,	0x76, 0xff,	0x33, 0xa0,	0x42, 0x20,	0x43, 0x18,	0x4c, 0x00,	0x87, 0xd5,	0x88, 0x3f,	0xd7, 0x03,	0xd9, 0x10,	0xd3, 0x82,

    0xc8, 0x08,	0xc9, 0x80,

    0x7c, 0x00,	0x7d, 0x00,	0x7c, 0x03,	0x7d, 0x48,	0x7d, 0x48,	0x7c, 0x08,	0x7d, 0x20,	0x7d, 0x10,	0x7d, 0x0e,

    0x90, 0x00,	0x91, 0x0e,	0x91, 0x1a,	0x91, 0x31,	0x91, 0x5a,	0x91, 0x69,	0x91, 0x75,	0x91, 0x7e,	0x91, 0x88,	0x91, 0x8f,	0x91, 0x96,	0x91, 0xa3,	0x91, 0xaf,	0x91, 0xc4,	0x91, 0xd7,	0x91, 0xe8,	0x91, 0x20,

    0x92, 0x00,	0x93, 0x06,	0x93, 0xe3,	0x93, 0x05,	0x93, 0x05,	0x93, 0x00,	0x93, 0x04,	0x93, 0x00,	0x93, 0x00,	0x93, 0x00,	0x93, 0x00,	0x93, 0x00,	0x93, 0x00,	0x93, 0x00,

    0x96, 0x00,	0x97, 0x08,	0x97, 0x19,	0x97, 0x02,	0x97, 0x0c,	0x97, 0x24,	0x97, 0x30,	0x97, 0x28,	0x97, 0x26,	0x97, 0x02,	0x97, 0x98,	0x97, 0x80,	0x97, 0x00,	0x97, 0x00,

    0xc3, 0xef,

    0xa4, 0x00,	0xa8, 0x00,	0xc5, 0x11,	0xc6, 0x51,	0xbf, 0x80,	0xc7, 0x10,	0xb6, 0x66,	0xb8, 0xA5,	0xb7, 0x64,	0xb9, 0x7C,	0xb3, 0xaf,	0xb4, 0x97,	0xb5, 0xFF,	0xb0, 0xC5,	0xb1, 0x94,	0xb2, 0x0f,	0xc4, 0x5c,

    0xc0, 0xc8,	0xc1, 0x96,	0x8c, 0x00,	0x86, 0x3d,	0x50, 0x00,	0x51, 0x90,	0x52, 0x2c,	0x53, 0x00,	0x54, 0x00,	0x55, 0x88,

    0x5a, 0x90,	0x5b, 0x2C,	0x5c, 0x05,

    0xd3, 0x02,

    0xc3, 0xed,	0x7f, 0x00,

    0xda, 0x09,

    0xe5, 0x1f,	0xe1, 0x67,	0xe0, 0x00,	0xdd, 0x7f,	0x05, 0x00,
};

/* YUV422 */
// const uint8_t OV2640_YUV422RegTbl[][2] =
const uint8_t OV2640_YUV422RegTbl[] =
{
    0xFF, 0x00,	0xDA, 0x10,	0xD7, 0x03,	0xDF, 0x00,	0x33, 0x80,	0x3C, 0x40,	0xe1, 0x77,	0x00, 0x00,
};

/* JPEG */
/* TODO: check
    Also, a discrepancy check: In your JPEG table, you write to 0xDA while in Bank 1 (0xFF=0x01). According to the datasheet, 0xDA (IMAGE_MODE) is a Bank 0 register. If your code actually works, this implies either:
    The register map differs from the preliminary datasheet, or
    Your JPEG table relies on the preceding YUV422 table leaving the bank at 0, or
    It's a typo in the snippet (should be a different register)
*/
// const uint8_t OV2640_JPEGRegTbl[][2] =
const uint8_t OV2640_JPEGRegTbl[] =
{
    0xff, 0x01,	0xe0, 0x14,	0xe1, 0x77,	0xe5, 0x1f,	0xd7, 0x03,	0xda, 0x10,	0xe0, 0x00,
};

/* RGB565 */
// const uint8_t OV2640_RGB565RegTbl[][2] =
const uint8_t OV2640_RGB565RegTbl[] =
{
    0xFF, 0x00,	0xDA, 0x09,	0xD7, 0x03,	0xDF, 0x02,	0x33, 0xa0,	0x3C, 0x00,	0xe1, 0x67,
    0xff, 0x01,	0xe0, 0x00,	0xe1, 0x00,	0xe5, 0x00,	0xd7, 0x00,	0xda, 0x00,	0xe0, 0x00,
};

/* RAW10 Bayer */
const uint8_t OV2640_RAW10RegTbl[] =
{
    // === Bank 0: DSP/Sensor Interface ===
    0xFF, 0x00,     // Select DSP bank
    0x05, 0x01,     // R_BYPASS: Bypass DSP, sensor out directly (CRITICAL!)
    0xDA, 0x04,     // IMAGE_MODE: RAW10 output (01 in bits 3:2)
    0xD7, 0x03,     // R_DVP_SP: Output speed control
    0xDF, 0x02,     // Format control (from RGB565)
    0x33, 0xa0,     // Timing (from RGB565 - uncompressed)
    0x3C, 0x00,     // Timing (from RGB565 - uncompressed)
    0xe1, 0x67,     // DSP control (from RGB565)

    // === Bank 1: Disable Compression ===
    0xff, 0x01,     // Select Sensor bank
    0xe0, 0x00,     // Disable JPEG-related functions
    0xe1, 0x00,     // Clear compression control
    0xe5, 0x00,     // Clear compression control
    0xd7, 0x00,     // Reset output speed
    0xda, 0x00,     // Reset image mode
    0xe0, 0x00,     // Double reset for safety
};

bool OV2640_HardwareReset(const struct OV2640_Platform *platform) {
    // Power on and reset OV2640
    platform->setPwdnPin(false); //POWER ON
    platform->delayMs(10);
    platform->setResetPin(false); //Reset OV2640
    platform->delayMs(10);
    platform->setResetPin(true); //Reset End

    platform->delayMs(50);

    return true;
}

bool OV2640_SoftwareReset(const struct OV2640_Platform *platform) {
    platform->sccbWriteReg(OV2640_SCCB_ID, 0xFF, 0x01); //Register Bank Select Sensor address
    platform->sccbWriteReg(OV2640_SCCB_ID, 0x12, 0x80); //Reset All Register

    platform->delayMs(50);

    return true;
}

bool OV2640_SetDefInit(const struct OV2640_Platform *platform) {
    int res;

    //Read MID
    uint8_t mid0, mid1;
    res = platform->sccbReadReg(OV2640_SCCB_ID, 0x1C, &mid1);
    platform->sccbReadReg(OV2640_SCCB_ID, 0x1D, &mid0);

    if (res != 0) {
        platform->debugPrint("OV2640 SCCB read error: %d\r\n", res);
        return false;
    }

    uint16_t mid = (mid1 << 8) | mid0;
    if (mid != OV2640_MID) {
        platform->debugPrint("OV2640_MID error: %x\r\n", mid);
        return false;
    }

    //Read PID
    uint8_t pid0, pid1;
    platform->sccbReadReg(OV2640_SCCB_ID, 0x0A, &pid1);
    platform->sccbReadReg(OV2640_SCCB_ID, 0x0B, &pid0);

    uint16_t pid = (pid1 << 8) | pid0;
    if (pid != OV2640_PID) {
        platform->debugPrint("OV2640_PID error: %x\r\n", pid);
        return false;
    }

    // Write initial registers
    for (unsigned i = 0; i < sizeof(OV2640_InitRegTbl) / 2; i++) {
        platform->sccbWriteReg(OV2640_SCCB_ID, OV2640_InitRegTbl[2*i], OV2640_InitRegTbl[2*i+1]);
    }

    platform->debugPrint("OV2640 init OK: MID=%x PID=%x\r\n", mid, pid);

    return true;
}

bool OV2640_DefInit(const struct OV2640_Platform *platform) {
    bool ok = true;

    ok &= OV2640_HardwareReset(platform);
    ok &= OV2640_SoftwareReset(platform);
    ok &= OV2640_SetDefInit(platform);

    ok &= OV2640_SetJpegMode(platform);
    ok &= OV2640_SetOutSize(platform, OV2640_DEF_WIDTH, OV2640_DEF_HEIGHT);
    ok &= OV2640_SetSpeed(platform, OV2640_DEF_PCLK_DIV, OV2640_DEF_XCLK_DIV);

    return ok;
}

bool OV2640_SetYUV422Mode(const struct OV2640_Platform *platform) {
    bool ok = true;

    //YUV422
    for (unsigned i = 0; i < (sizeof(OV2640_YUV422RegTbl) / 2); i++) {
        platform->sccbWriteReg(OV2640_SCCB_ID, OV2640_YUV422RegTbl[2*i], OV2640_YUV422RegTbl[2*i+1]);
    }

    return ok;
}

bool OV2640_SetJpegMode(const struct OV2640_Platform *platform) {
    bool ok = true;

    //YUV422
    for (unsigned i = 0; i < (sizeof(OV2640_YUV422RegTbl) / 2); i++) {
        platform->sccbWriteReg(OV2640_SCCB_ID, OV2640_YUV422RegTbl[2*i], OV2640_YUV422RegTbl[2*i+1]);
    }

    //JPEG
    for (unsigned i = 0; i < (sizeof(OV2640_JPEGRegTbl) / 2); i++) {
        platform->sccbWriteReg(OV2640_SCCB_ID, OV2640_JPEGRegTbl[2*i], OV2640_JPEGRegTbl[2*i+1]);
    }

    return ok;
}

bool OV2640_SetRGB565Mode(const struct OV2640_Platform *platform) {
    bool ok = true;

    //RGB565
    for (unsigned i = 0; i < (sizeof(OV2640_RGB565RegTbl) / 2); i++) {
        platform->sccbWriteReg(OV2640_SCCB_ID, OV2640_RGB565RegTbl[2*i], OV2640_RGB565RegTbl[2*i+1]);
    }

    return ok;
}

bool OV2640_SetRAW10Mode(const struct OV2640_Platform *platform) {
    bool ok = true;

    //RAW10
    for (unsigned i = 0; i < (sizeof(OV2640_RAW10RegTbl) / 2); i++) {
        platform->sccbWriteReg(OV2640_SCCB_ID, OV2640_RAW10RegTbl[2*i], OV2640_RAW10RegTbl[2*i+1]);
    }

    return ok;
}

bool OV2640_SetResolution(const struct OV2640_Platform *platform, OV2640_Resolution_t res) {
    platform->sccbWriteReg(OV2640_SCCB_ID, 0xFF, 0x01);  // Bank 1 (Sensor)

    uint8_t com7;
    platform->sccbReadReg(OV2640_SCCB_ID, 0x12, &com7);  // Read current COM7

    com7 &= ~0x70;  // Clear bits [6:4]
    com7 |= (res << 4) & 0x70;  // Set new resolution (shift enum to position)
    platform->sccbWriteReg(OV2640_SCCB_ID, 0x12, com7);

    // Set appropriate default window registers for the selected resolution
    // These ensure the sensor outputs the correct active area for the mode
    if (res == OV2640_RES_UXGA) {
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x17, 0x11);  // HREFST[7:0]
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x18, 0x75);  // HREFEND[7:0] (UXGA width)
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x19, 0x01);  // VSTRT[7:0]
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x1A, 0x97);  // VEND[7:0] (UXGA height)
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x32, 0x36);  // REG32: PCLK div 2 + window LSBs
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x03, 0x0F);  // COM1: 1 dummy frame + V window LSBs
    }
    else if (res == OV2640_RES_SVGA) {
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x17, 0x11);  // HREFST[7:0]
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x18, 0x43);  // HREFEND[7:0] (adjusted for 800px)
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x19, 0x00);  // VSTRT[7:0] (starts at 0)
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x1A, 0x97);  // VEND[7:0]
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x32, 0x09);  // REG32: PCLK div 4 + window LSBs
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x03, 0x0A);  // COM1: 0x0A for SVGA
    }
    else if (res == OV2640_RES_CIF) {
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x17, 0x11);  // HREFST[7:0]
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x18, 0x43);  // HREFEND[7:0] (same as SVGA)
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x19, 0x00);  // VSTRT[7:0]
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x1A, 0x97);  // VEND[7:0]
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x32, 0x09);  // REG32: same as SVGA
        platform->sccbWriteReg(OV2640_SCCB_ID, 0x03, 0x06);  // COM1: 0x06 for CIF per datasheet
    }

    return true;
}

bool OV2640_SetCrop(const struct OV2640_Platform *platform,
                    uint16_t x, uint16_t y,
                    uint16_t width, uint16_t height) {

    // Validate constraints
    if ((x % 2) || (width % 2)) return false;      // Horizontal must be even
    if ((y % 4) || (height % 4)) return false;     // Vertical must be multiple of 4 for UXGA

    // Convert to register values (divide by 2 for horizontal, divide by 2 for vertical)
    // Note: Vertical LSBs go to COM1[3:2] and COM1[1:0]
    uint16_t href_st = x / 2;
    uint16_t href_end = (x + width) / 2;
    uint16_t vstrt = y / 2;  // Each unit = 2 lines
    uint16_t vend = (y + height) / 2;

    platform->sccbWriteReg(OV2640_SCCB_ID, 0xFF, 0x01);  // Bank 1

    // Horizontal window (MSBs in 0x17/0x18, LSBs in 0x32)
    platform->sccbWriteReg(OV2640_SCCB_ID, 0x17, href_st & 0xFF);       // HREFST[7:0]
    platform->sccbWriteReg(OV2640_SCCB_ID, 0x18, href_end & 0xFF);      // HREFEND[7:0]

    // Vertical window (MSBs in 0x19/0x1A, LSBs in COM1[3:0])
    platform->sccbWriteReg(OV2640_SCCB_ID, 0x19, vstrt & 0xFF);         // VSTRT[7:0]
    platform->sccbWriteReg(OV2640_SCCB_ID, 0x1A, vend & 0xFF);          // VEND[7:0]

    // Read current COM1 and REG32 to preserve other bits
    uint8_t com1;
    platform->sccbReadReg(OV2640_SCCB_ID, 0x03, &com1);
    com1 &= ~0x0F;  // Clear bits [3:0]
    com1 |= (vstrt >> 8) & 0x03;        // VSTRT[9:8] -> COM1[1:0]
    com1 |= ((vend >> 6) & 0x0C);       // VEND[9:8] -> COM1[3:2] (shifted)
    platform->sccbWriteReg(OV2640_SCCB_ID, 0x03, com1);

    uint8_t reg32;
    platform->sccbReadReg(OV2640_SCCB_ID, 0x32, &reg32);
    reg32 &= ~0x3F;  // Clear bits [5:0] (window LSBs)
    reg32 |= (href_st >> 8) & 0x07;     // HREFST[10:8] -> REG32[2:0]
    reg32 |= ((href_end >> 5) & 0x38);  // HREFEND[10:8] -> REG32[5:3] (shifted)
    platform->sccbWriteReg(OV2640_SCCB_ID, 0x32, reg32);

    return true;
}

bool OV2640_SetOutSize(const struct OV2640_Platform *platform, uint16_t width, uint16_t height) {
    if ((width % 4) || (height % 4)) {
        return false;
    }

    uint16_t outSizeWidth = width / 4;
    uint16_t outSizeHeight = height / 4;

    platform->sccbWriteReg(OV2640_SCCB_ID, 0XFF, 0X00);
    platform->sccbWriteReg(OV2640_SCCB_ID, 0XE0, 0X04);
    platform->sccbWriteReg(OV2640_SCCB_ID, 0X5A, outSizeWidth & 0XFF);
    platform->sccbWriteReg(OV2640_SCCB_ID, 0X5B, outSizeHeight & 0XFF);

    uint8_t t = (outSizeWidth >> 8) & 0X03;
    t |= (outSizeHeight >> 6) & 0X04;
    platform->sccbWriteReg(OV2640_SCCB_ID, 0X5C, t);

    platform->sccbWriteReg(OV2640_SCCB_ID, 0XE0, 0X00);

    return true;
}

bool OV2640_SetSpeed(const struct OV2640_Platform *platform, uint8_t Pclk_Div, uint8_t Xclk_Div) {
    platform->sccbWriteReg(OV2640_SCCB_ID, 0XFF, 0X00);
    platform->sccbWriteReg(OV2640_SCCB_ID, 0XD3, Pclk_Div);

    platform->sccbWriteReg(OV2640_SCCB_ID, 0XFF, 0X01);
    platform->sccbWriteReg(OV2640_SCCB_ID, 0X11, Xclk_Div);

    return true;
}
