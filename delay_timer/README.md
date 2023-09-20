# Delay_timer

Trong STM32F103C8 có 4 bộ Timer trong đó:

Timer 1: Là bộ Advanced – control Timer hay là bộ Timer điều khiển nâng cao, có nhiều chức năng nhất

3 bộ Timer chung là Timer 2,3,4 Có chức năng tương tự nhau và độc lập với nhau

- Khoi tao timer dem moi 1us VD: fapb2 = 72 mhz. prescaler = 72 -1, ARR = 0xFFFF -1 
72
- Truyen timer do vao delay Init VD: DELAY_TIM_Init(&htim1)
- Su dung thu vien hal
