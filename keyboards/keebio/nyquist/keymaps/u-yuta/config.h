#pragma once

// Mod-Tap for SHIFT keys
#define LSPO_KEYS KC_LSFT, KC_LSFT, KC_INT1  // Tap -> Underscore

// Solve SHIFT ignored in Windows Remote Desktop
#define USB_POLLING_INTERVAL_MS 10

#define TAPPING_TERM 200
#define TAPPING_TERM_PER_KEY
#define COMBO_TERM 40

// Delay between pressing a wheel key and wheel movement, by default 80
#undef  MOUSEKEY_WHEEL_DELAY
#define MOUSEKEY_WHEEL_DELAY 50
