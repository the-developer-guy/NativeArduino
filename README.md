# NativeArduino
Native drivers for Arduino boards (or to be more precise, for the microcontrollers commonly found on Arduino boards)

## Why?
Not just "why not?".

Arduino is a great platform for beginners and "lazy" pros too. I know, once I made a current logger in 15 minutes with an Arduino and an I2C current sensor for a professional project. It worked GREAT!

But sometimes you just want to stay. STM32 HAL is wonderful, but many people get used to the really simple Arduino functions, and it can be a limiting factor! analogWrite() and tone() are easy to use, but lack the fine control. digitalWrite() is a huge function compared to what it actually does. And sometimes you need a smaller, faster, more versatile driver.

Yes, "just move to a bigger microcontroller" exists. I always encourage people to choose the right tool for the job like "don't use SoftwareSerial if you need 2 UART ports, use a board with enought peripherals", but most frameworks waste precious CPU time, untapped possibilites exist.

The goal is to provide a usable driver pack for the common boards while explaining the depth of the hardware for those, who want to learn.