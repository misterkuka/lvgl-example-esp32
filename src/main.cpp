#include <Arduino.h>
#include <TFT_eSPI.h>
#include <lvgl.h>

/* Screen resolution */
static const uint16_t screenWidth = 480;
static const uint16_t screenHeight = 320;

#define LCD_CS 27
#define LCD_DC 13
#define LCD_RST 4
#define LCD_BL 26
#define SPI_MOSI 23
#define SPI_SCK 18
#define SPI_MISO 19 // Not used
/* Buffer: size in bytes = pixels * sizeof(lv_color_t) */

static uint8_t buf[320 * 20 * sizeof(lv_color_t)];

TFT_eSPI tft = TFT_eSPI(); // TFT instance

// Flush callback for LVGL9
void my_disp_flush(lv_display_t *disp, const lv_area_t *area, uint8_t *px_map)
{
    uint32_t w = area->x2 - area->x1 + 1;
    uint32_t h = area->y2 - area->y1 + 1;

    // Push pixels to TFT
    tft.setAddrWindow(area->x1, area->y1, w, h);
    tft.pushColors((uint16_t *)px_map, w * h, true);

    // Let LVGL know flushing is done
    lv_display_flush_ready(disp);
}

void lcd_init_pins()
{
    pinMode(LCD_CS, OUTPUT);
    pinMode(LCD_DC, OUTPUT);
    pinMode(LCD_RST, OUTPUT);
    pinMode(LCD_BL, OUTPUT);
    pinMode(SPI_MOSI, OUTPUT);
    pinMode(SPI_SCK, OUTPUT);

    digitalWrite(LCD_CS, HIGH);
    digitalWrite(LCD_DC, HIGH);
}

void setup()
{
    lcd_init_pins();
    lv_init();
    tft.begin();
    tft.setRotation(3);
    // tft.flush();
    // tft.setSwapBytes(true);

    digitalWrite(LCD_BL, HIGH);

    // Create display
    lv_display_t *disp = lv_display_create(screenWidth, screenHeight);

    // Set buffer
    lv_display_set_buffers(disp, buf, nullptr, sizeof(buf), LV_DISPLAY_RENDER_MODE_PARTIAL);
    // Set flush callback
    lv_display_set_flush_cb(disp, my_disp_flush);

    // Get active screen
    lv_obj_t *scr = lv_display_get_screen_active(disp);
    // lv_disp_set_rotation(disp, LV_DISP_ROTATION_270);

    // Create label
    lv_obj_t *label = lv_label_create(scr);
    lv_label_set_text(label, "Kakauko");
    lv_obj_center(label);

    // Create button
    lv_obj_t *btn = lv_btn_create(scr);
    lv_obj_set_pos(btn, 10, 10);
    lv_obj_set_size(btn, 120, 50);

    lv_obj_t *blabel = lv_label_create(btn);
    lv_label_set_text(blabel, "Etykieta");
    lv_obj_center(blabel);


    // LINE
     static lv_point_precise_t line_points[] = { {5, 5}, {70, 70}, {120, 10}, {180, 60}, {240, 10} };

    /*Create style*/
    static lv_style_t style_line;
    lv_style_init(&style_line);
    lv_style_set_line_width(&style_line, 8);
    lv_style_set_line_color(&style_line, lv_palette_main(LV_PALETTE_BLUE));
    lv_style_set_line_rounded(&style_line, true);

    /*Create a line and apply the new style*/
    lv_obj_t * line1;
    line1 = lv_line_create(lv_screen_active());
    lv_line_set_points(line1, line_points, 5);     /*Set the points*/
    lv_obj_add_style(line1, &style_line, 0);
    lv_obj_center(line1);
}

void loop()
{
    lv_timer_handler();
    delay(5);
}
