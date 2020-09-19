#include <iostream>
#include "Editor.h"
#include "Constants.h"

int main() {
	Editor* editor = new Editor();
	editor->init(WINDOW_WIDTH, WINDOW_HEIGHT);

	while (editor->isRunning()) {
		editor->processInput();
		editor->update();
		editor->render();
	}

	editor->destroy();

	return 0;
}
