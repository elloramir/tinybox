// Copyright 2023 Elloramir.
// Use of this source code is governed by a MIT
// license that can be found in the LICENSE file.

#include "os.h"
#include "render.h"

int entry_point ( void ) {
	os_create_window(800, 600, "TinyBox Engine");
	render_init();

	Image cat = render_load_image("data/cat.jpg");

	while (!os_window_should_close()) {
		if (os_window_is_visible()) {
			render_frame();
			render_set_image(cat);
			render_set_color((Color){ 0.5, 0.25, 0.25, 1 });
			render_push_rec(-1, -1, 2, 2, 0, 1, 0, 1);
			render_flush();
			os_swap_buffers();
		}
		else {
			os_sleep(17);
		}
	}
	return 0;
}