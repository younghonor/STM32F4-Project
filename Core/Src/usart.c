
#include "main.h"
#include "cmsis_os.h"

extern SemaphoreHandle_t uartTxCompleteSem;

void MX_USART1_DMA_Send(uint8_t *pData, uint16_t Size) {
    // 等待上一次发送完成信号量
    if (xSemaphoreTake(uartTxCompleteSem, pdMS_TO_TICKS(1000)) == pdTRUE) {
        // 配置DMA发送
        LL_DMA_DisableChannel(DMA2, LL_DMA_STREAM_7); // 禁止DMA Stream
        LL_DMA_SetMemoryAddress(DMA2, LL_DMA_STREAM_7, (uint32_t)pData);
        LL_DMA_SetDataLength(DMA2, LL_DMA_STREAM_7, Size);
        // 使能传输完成中断
        LL_DMA_EnableIT_TC(DMA2, LL_DMA_STREAM_7);
        // 重新使能DMA Stream
        LL_DMA_EnableChannel(DMA2, LL_DMA_STREAM_7);
        // 使能USART的DMA发送请求
        LL_USART_EnableDMAReq_TX(USART1);
    } else {
        // 超时处理，表明上一次发送可能卡死
    }
}
