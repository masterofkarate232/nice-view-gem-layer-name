#include <zephyr/kernel.h>
#include "layer.h"
#include "../assets/custom_fonts.h"

void draw_layer_status(lv_obj_t *canvas, const struct status_state *state) {
    char text[10] = {};
    if (state->layer_label == NULL) {
        sprintf(text, "Layer %i", state->layer_index);
    } else {
        strncpy(text, state->layer_label, 9);
        to_uppercase(text);
    }

    lv_draw_label_dsc_t dsc;

    // Pass 1: shadow (offset slightly)
    init_label_dsc(&dsc, LVGL_BACKGROUND, &custom_font_shadow, LV_TEXT_ALIGN_CENTER);
    canvas_draw_text(canvas, 2, LAYER_CANVAS_SIZE, CANVAS_SIZE, &dsc, text);

    // Pass 2: outline (dilated)
    init_label_dsc(&dsc, LVGL_FOREGROUND, &custom_font_outline, LV_TEXT_ALIGN_CENTER);
    canvas_draw_text(canvas, 0, LAYER_CANVAS_SIZE, CANVAS_SIZE, &dsc, text);

    // Pass 3: main fill
    init_label_dsc(&dsc, LVGL_FOREGROUND, &custom_font_44, LV_TEXT_ALIGN_CENTER);
    canvas_draw_text(canvas, 0, LAYER_CANVAS_SIZE, CANVAS_SIZE, &dsc, text);
}