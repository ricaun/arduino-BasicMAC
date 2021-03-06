#ifndef _lmic_arduino_hal_config_h_
#define _lmic_arduino_hal_config_h_

#if !defined(CFG_eu868) && !defined(CFG_as923) && !defined(CFG_il915) && !defined(CFG_kr920) && !defined(CFG_us915) && !defined(CFG_au915) && !defined(CFG_cn470)
#define CFG_au915 1
#endif

#define CFG_autojoin

// This is the SX1272/SX1273 radio, which is also used on the HopeRF
// RFM92 boards.
//#define BRD_sx1272_radio 1
// This is the SX1276/SX1277/SX1278/SX1279 radio, which is also used on
// the HopeRF RFM95 boards.
//#define BRD_sx1276_radio 1
#if !defined(BRD_sx1272_radio) && !defined(BRD_sx1276_radio) && !defined(BRD_sx1262_radio) && !defined(BRD_sx1261_radio)
#define BRD_sx1276_radio 1
#endif




// 16 μs per tick
// LMIC requires ticks to be 15.5μs - 100 μs long


#if !defined(US_PER_OSTICK_EXPONENT)
#define US_PER_OSTICK_EXPONENT 4
#endif

#define US_PER_OSTICK (1 << US_PER_OSTICK_EXPONENT)
#define OSTICKS_PER_SEC (1000000 / US_PER_OSTICK)

/*
#define CFG_DEBUG
#define CFG_DEBUG_VERBOSE
#define DEBUG_TX
#define DEBUG_RX
*/

// Uncomment this to disable all code related to beacon tracking.
// Requires ping to be disabled too
//#define DISABLE_CLASSB

// This allows choosing between multiple included AES implementations.
// Make sure exactly one of these is uncommented.
//
// This selects the original AES implementation included LMIC. This
// implementation is optimized for speed on 32-bit processors using
// fairly big lookup tables, but it takes up big amounts of flash on the
// AVR architecture.
//#define USE_ORIGINAL_AES
//
// This selects the AES implementation written by Ideetroon for their
// own LoRaWAN library. It also uses lookup tables, but smaller
// byte-oriented ones, making it use a lot less flash space (but it is
// also about twice as slow as the original).
//#define USE_IDEETRON_AES

#if !defined(USE_ORIGINAL_AES) && !defined(USE_IDEETRON_AES) 
#define USE_IDEETRON_AES
#endif

#endif // _lmic_arduino_hal_config_h_
