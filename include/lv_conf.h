#ifndef LV_CONF_H
#define LV_CONF_H

/*====================
   Graphical settings
 *====================*/
#define LV_COLOR_DEPTH 16  // 16-bit color (RGB565)
#define LV_COLOR_16_SWAP 0 // Do not swap bytes
#define LV_HOR_RES_MAX 320 // Horizontal resolution
#define LV_VER_RES_MAX 480 // Vertical resolution

/*====================
   Memory settings
 *====================*/
#define LV_MEM_SIZE (64 * 1024) // 32 KB memory for LVGL
#define LV_MEM_CUSTOM 1         // Use LVGL built-in allocator
#define LV_USE_MEM_DEBUG 0

/*====================
   Feature usage
 *====================*/
#define LV_USE_ST7796 0       // Enable ST7796 driver
#define LV_USE_THEME_DEFAULT 1 // Minimal default theme
#define LV_USE_LOG 1           // Disable logging

/*====================
   Font usage
 *====================*/
#define LV_FONT_DEFAULT &lv_font_montserrat_14 // Default font

/*====================
   Timing settings
 *====================*/
#define LV_TICK_CUSTOM 0  // Use built-in tick source
#define LV_REFR_PERIOD 30 // Refresh every 30 ms (~33 FPS)

#endif /*LV_CONF_H*/
