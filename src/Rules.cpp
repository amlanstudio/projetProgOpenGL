#include "Homepage.hpp"
#include "GLFW/glfw3.h"

State displayRulespage(GLuint* texture, glm::vec2 cursorPosition, bool mousePressed){

        printf("x: %f, y: %f \n", cursorPosition.x, cursorPosition.y);

        // glPushMatrix();

        glScalef(0.873f, 0.873f, 0.873f);
    
        glEnable(GL_TEXTURE_2D);  // activation du texturing
        glEnable(GL_BLEND);  // activation la transparence
        glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);  // gere la transparence

        // ----- MON DESSIN -----

        glBindTexture(GL_TEXTURE_2D, texture[9]); //application de ma texture 1
        glColor3f(1.,1.,1.);
        
        //Rules bg
        glPushMatrix();
        glScalef(260,151.5,0);
        drawSquare();    
        glPopMatrix();  
        
        //Bouton Return Menu

        return State::Homepage;

}