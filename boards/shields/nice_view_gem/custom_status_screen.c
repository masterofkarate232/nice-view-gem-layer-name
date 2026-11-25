#include <zephyr/kernel.h>
#include <zmk/display.h>
#include "widgets/screen.h"

lv_obj_t *zmk_display_status_screen(void) {
    struct zmk_widget_screen *widget = k_malloc(sizeof(*widget));
    zmk_widget_screen_init(widget, lv_scr_act());
    return zmk_widget_screen_obj(widget);
}   
