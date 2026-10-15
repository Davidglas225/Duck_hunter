#include "Hunter.hpp"
#include "em_device.h"
#include "em_cmu.h"
#include "em_gpio.h"
#include "em_usart.h"
#include <cstdio>

Hunter::Hunter() : position(0), lastChar('\0') {}

void Hunter::initHunter() {
    CMU_ClockEnable(cmuClock_GPIO, true);
    CMU_ClockEnable(cmuClock_UART0, true);

    GPIO_PinModeSet(gpioPortF, 7, gpioModePushPull, 1);

    GPIO_PinModeSet(gpioPortE, 0, gpioModePushPull, 1);
    GPIO_PinModeSet(gpioPortE, 1, gpioModeInput, 0);

    USART_InitAsync_TypeDef uart0_init = USART_INITASYNC_DEFAULT;
    USART_InitAsync(UART0, &uart0_init);

    UART0->ROUTE = UART_ROUTE_LOCATION_LOC1 | UART_ROUTE_TXPEN | UART_ROUTE_RXPEN;
}

void Hunter::checkButtonsAndUpdatePosition() {
    if (UART0->STATUS & USART_STATUS_RXDATAV)
    {
        lastChar = (char)(UART0->RXDATA);
        if (lastChar == 'b' && position > 0)
        {
            position--;
        }
        else if (lastChar == 'j' && position < 6)
        {
            position++;
        }
    }
    else
    {
        lastChar = '\0';
    }
}

bool Hunter::shoot() {
    if (lastChar == 'a')
    {
        lastChar = '\0';
        return true;
    }
    return false;
}

int Hunter::getPosition() const {
    return position;
}
