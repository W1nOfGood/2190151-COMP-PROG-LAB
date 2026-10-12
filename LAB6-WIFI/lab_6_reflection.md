# Lab 6 Reflection

**Q1.** A weather station on an M5Stack. It fetches live temperature, rain chance and PM2.5 from a weather API and shows them on the LCD. It is useful because we can see at a glance whether to take an umbrella or wear a mask, without a phone.

**Q2.** Libraries use string processing inside, so knowing it helps us understand and debug them. Manual parsing is also useful on a small microcontroller with little RAM, when we need only one value from a big response (like the Bitcoin price) or the data is not clean JSON. It avoids adding a whole library.

**Q3.** The delay gives the server time to recover. Without it, the M5Stack would send many requests very quickly, which looks like a DoS attack, so the server may block our IP. It also wastes power and could crash the device.

**Q4.** Auto-connect is better for a weather station on a roof. After a power cut it reconnects by itself, with nobody there to press a button. Manual control is better for a battery-powered sensor that connects only once an hour to upload data, because staying connected drains the battery.
