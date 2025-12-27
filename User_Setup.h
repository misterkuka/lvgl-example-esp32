#define USER_SETUP_INFO "ST7796"
#define ST7796_DRIVER  // Define driver
#define TFT_WIDTH  320
#define TFT_HEIGHT 480

// #define LCD_CS 27
// #define LCD_DC 13
// #define LCD_RST 4
// #define LCD_BL 26
// #define SPI_MOSI 23
// #define SPI_SCK 18
// #define SPI_MISO 19 // Not used

// Pin Definitions
#define TFT_CS   27
#define TFT_DC   13
#define TFT_RST  4
#define TFT_BL   26
#define TFT_MOSI 23
#define TFT_SCLK 18
#define TFT_MISO 19

// Font/Speed Settings
#define LOAD_GLCD
#define SPI_FREQUENCY 40000000 // 40MHz