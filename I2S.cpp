#include "I2S.h"

void I2S_Init(i2s_mode_t MODE, int SAMPLE_RATE, i2s_bits_per_sample_t BPS) {
  i2s_config_t i2s_config = {
    .mode = (i2s_mode_t)(I2S_MODE_MASTER | MODE),
    .sample_rate = SAMPLE_RATE,
    .bits_per_sample = BPS,
    .channel_format = I2S_CHANNEL_FMT_RIGHT_LEFT, //I2S_CHANNEL_FMT_ONLY_RIGHT,
    .communication_format = (i2s_comm_format_t)(I2S_COMM_FORMAT_I2S | I2S_COMM_FORMAT_I2S_MSB),
    .intr_alloc_flags = 0,
    .dma_buf_count = 16,
    .dma_buf_len = 60
  };
  i2s_pin_config_t pin_config;
  pin_config.bck_io_num = TWATCH_INMP441_IIS_BCK;
  pin_config.ws_io_num = TWATCH_INMP441_IIS_WS;
  if (MODE == I2S_MODE_RX) {
    pin_config.data_out_num = I2S_PIN_NO_CHANGE;
    pin_config.data_in_num = TWATCH_INMP441_IIS_DIN;
  }
  else if (MODE == I2S_MODE_TX) {
    pin_config.data_out_num = PIN_I2S_DOUT;
    pin_config.data_in_num = I2S_PIN_NO_CHANGE;
  }
  i2s_driver_install(I2S_NUM_0, &i2s_config, 0, NULL);
  i2s_set_pin(I2S_NUM_0, &pin_config);
  //最终设置: 16k, 16位，单声道
  i2s_set_clk(I2S_NUM_0, SAMPLE_RATE, BPS, I2S_CHANNEL_MONO);
}

int I2S_Read(char* data, int numData) {
  return i2s_read_bytes(I2S_NUM_0, (char *)data, numData, portMAX_DELAY);
}

void I2S_Write(char* data, int numData) {
    i2s_write_bytes(I2S_NUM_0, (const char *)data, numData, portMAX_DELAY);
}

void I2S_uninstall()
{
  i2s_driver_uninstall(I2S_NUM_0);
  }
