#include <GL/glut.h>

float metro1PositionX = -1.5f; // Initial position of the first metro rail
float metro2PositionX = 1.5f;  // Initial position of the second metro rail
float speed = 0.01f;           // Speed of the metro rails
bool isRunning = true;         // Flag to control the movement (start/stop)

// Function to draw a single metro cabin from the top view with windows, wheels, and color
void drawCabinTopView(float offset) {
    glPushMatrix();
    glTranslatef(offset, 0.0f, 0.0f);

    // Metro cabin top
    glColor3f(0.8f, 0.8f, 0.8f); // Light grey
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.1f);
        glVertex2f(0.3f, -0.1f);
        glVertex2f(0.3f, 0.1f);
        glVertex2f(-0.3f, 0.1f);
    glEnd();


    // // Windows
    // glColor3f(0.1f, 0.6f, 0.9f); // Blue for windows
    // for (float i = -0.24f; i <= 0.24f; i += 0.12f) {
    //     glBegin(GL_QUADS);
    //         glVertex2f(i - 0.04f, 0.04f);
    //         glVertex2f(i + 0.04f, 0.04f);
    //         glVertex2f(i + 0.04f, -0.04f);
    //         glVertex2f(i - 0.04f, -0.04f);
    //     glEnd();
    // }

    // Wheels
    glColor3f(0.2f, 0.2f, 0.2f); // Dark grey for wheels
    glBegin(GL_QUADS);
        glVertex2f(-0.24f, -0.12f);
        glVertex2f(-0.18f, -0.12f);
        glVertex2f(-0.18f, -0.14f);
        glVertex2f(-0.24f, -0.14f);

        glVertex2f(0.18f, -0.12f);
        glVertex2f(0.24f, -0.12f);
        glVertex2f(0.24f, -0.14f);
        glVertex2f(0.18f, -0.14f);
    glEnd();

    glPopMatrix();
}

// Function to draw the front head engine of the metro rail
void drawFrontHeadEngine() {
    glPushMatrix();

    // Engine body
    glColor3f(0.9f, 0.1f, 0.1f); // Red for engine
    glBegin(GL_QUADS);
        glVertex2f(-0.36f, -0.1f);
        glVertex2f(0.3f, -0.1f);
        glVertex2f(0.3f, 0.1f);
        glVertex2f(-0.36f, 0.1f);
    glEnd();

    // Windows on the engine
    glColor3f(0.1f, 0.6f, 0.9f); // Blue for windows
    glBegin(GL_QUADS);
        glVertex2f(-0.2f, 0.02f);
        glVertex2f(-0.1f, 0.02f);
        glVertex2f(-0.1f, -0.02f);
        glVertex2f(-0.2f, -0.02f);

        glVertex2f(0.04f, 0.02f);
        glVertex2f(0.14f, 0.02f);
        glVertex2f(0.14f, -0.02f);
        glVertex2f(0.04f, -0.02f);
    glEnd();

    // Wheels on the engine
    glColor3f(0.2f, 0.2f, 0.2f); // Dark grey for wheels
    glBegin(GL_QUADS);
        glVertex2f(-0.3f, -0.12f);
        glVertex2f(-0.24f, -0.12f);
        glVertex2f(-0.24f, -0.14f);
        glVertex2f(-0.3f, -0.14f);

        glVertex2f(0.18f, -0.12f);
        glVertex2f(0.24f, -0.12f);
        glVertex2f(0.24f, -0.14f);
        glVertex2f(0.18f, -0.14f);
    glEnd();

    glPopMatrix();
}

// Function to draw the rail tracks from the top view
void drawRailTracksTopView() {
    // Tracks for first rail
    glColor3f(0.2f, 0.2f, 0.2f); // Dark grey for rails
    glBegin(GL_LINES);
        glVertex2f(-1.5f, -0.15f);
        glVertex2f(1.5f, -0.15f);
        glVertex2f(-1.5f, 0.15f);
        glVertex2f(1.5f, 0.15f);
    glEnd();

    // Sleepers for first rail
    glColor3f(0.5f, 0.35f, 0.05f); // Brown for sleepers
    for (float i = -1.5f; i <= 1.5f; i += 0.1f) {
        glBegin(GL_QUADS);
            glVertex2f(i - 0.02f, -0.18f);
            glVertex2f(i + 0.02f, -0.18f);
            glVertex2f(i + 0.02f, 0.18f);
            glVertex2f(i - 0.02f, 0.18f);
        glEnd();
    }

    // Tracks for second rail
    glBegin(GL_LINES);
        glVertex2f(-1.5f, -0.6f);
        glVertex2f(1.5f, -0.6f);
        glVertex2f(-1.5f, -0.3f);
        glVertex2f(1.5f, -0.3f);
    glEnd();

    // Sleepers for second rail
    for (float i = -1.5f; i <= 1.5f; i += 0.1f) {
        glBegin(GL_QUADS);
            glVertex2f(i - 0.02f, -0.63f);
            glVertex2f(i + 0.02f, -0.63f);
            glVertex2f(i + 0.02f, -0.27f);
            glVertex2f(i - 0.02f, -0.27f);
        glEnd();
    }
}

// Function to draw the complete metro from the top view
void drawMetroTopView(int direction) {
    if (direction == 1) {
        drawFrontHeadEngine();
        for (int i = 0; i < 4; i++) {
            drawCabinTopView(-0.8f + i * 0.64f); // Closely spaced cabins
        }
    } else {
        glPushMatrix();
        glScalef(-1.0f, 1.0f, 1.0f); // Flip the second metro
        drawFrontHeadEngine();
        for (int i = 0; i < 4; i++) {
            drawCabinTopView(-0.8f + i * 0.64f); // Closely spaced cabins
        }
        glPopMatrix();
    }
}

// Function to update the scene
void update(int value) {
    if (isRunning) {
        metro1PositionX += speed;
        metro2PositionX -= speed;

        if (metro1PositionX > 1.5f) {
            metro1PositionX = -1.5f; // Reset position when it goes out of view
        }

        if (metro2PositionX < -1.5f) {
            metro2PositionX = 1.5f; // Reset position when it goes out of view
        }
    }

    glutPostRedisplay(); // Request redisplay
    glutTimerFunc(16, update, 0); // Call update function after 16ms
}

// Display function
void display() {
    glClear(GL_COLOR_BUFFER_BIT); // Clear the window

    // Draw the rail tracks
    drawRailTracksTopView();

    // Draw the first metro rail from the top view
    glPushMatrix();
    glTranslatef(metro1PositionX, 0.15f, 0.0f); // Move the first metro
    drawMetroTopView(1); // Draw the first metro
    glPopMatrix();

    // Draw the second metro rail from the top view
    glPushMatrix();
    glTranslatef(metro2PositionX, -0.45f, 0.0f); // Move the second metro
    drawMetroTopView(2); // Draw the second metro in opposite direction
    glPopMatrix();

    glutSwapBuffers(); // Swap buffers
}

// Keyboard function to control speed and start/stop
void keyboard(unsigned char key, int x, int y) {
    if (key == '+') {
        speed += 0.005f; // Increase speed
    }
    if (key == '-') {
        speed = (speed > 0.005f) ? speed - 0.005f : 0.005f; // Decrease speed
    }
    if (key == 's' || key == 'S') {
        isRunning = !isRunning; // Toggle start/stop
    }
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800, 600);
    glutCreateWindow("Metro Rails with Controls");

    glClearColor(0.68f, 0.85f, 0.9f, 1.0f); // Background color (light blue)

    glutDisplayFunc(display); // Set display callback
    glutKeyboardFunc(keyboard); // Set keyboard callback
    glutTimerFunc(16, update, 0); // Set timer callback

    glutMainLoop(); // Enter the main loop
    return 0;
}
