#include <stdbool.h>
#include <zmk/display.h>
#include "widgets/screen.h"

static struct zmk_widget_screen widget;

lv_obj_t *zmk_display_status_screen(void) {
    zmk_widget_screen_init(&widget, lv_scr_act());
    return zmk_widget_screen_obj(&widget);
}   
