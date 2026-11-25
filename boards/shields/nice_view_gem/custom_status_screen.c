#include <stdbool.h>
#include <zephyr/kernel.h>
#include <zmk/display.h>

#if !IS_ENABLED(CONFIG_ZMK_SPLIT) || IS_ENABLED(CONFIG_ZMK_SPLIT_ROLE_CENTRAL)
#include "widgets/screen.h"
#else
#include "widgets/screen_peripheral.h"
#endif

static struct zmk_widget_screen widget;

lv_obj_t *zmk_display_status_screen(void) {
    zmk_widget_screen_init(&widget, lv_scr_act());
    return zmk_widget_screen_obj(&widget);
}   
