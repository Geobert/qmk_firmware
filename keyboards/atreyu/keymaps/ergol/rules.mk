# Bootloader selection
BOOTLOADER = rp2040
ENCODER_ENABLE = no
OLED_ENABLE = yes
EXTRAKEY_ENABLE = yes
MOUSEKEY_ENABLE = yes
WPM_ENABLE = yes
CAPS_WORD_ENABLE = yes

LTO_ENABLE = yes

CONSOLE_ENABLE = no
COMMAND_ENABLE = no

SRC += features/layer_lock.c
